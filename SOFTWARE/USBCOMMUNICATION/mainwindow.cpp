#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QDebug>
#include <sstream>
#include <iostream>
#include <boost/format.hpp>
#include <QVector>

int maxlength = 0 ;
double PositionTemp = 0;
int k = 0, counter = 0;
double PositionRef;
double posMax = 0;
double posxl = 0;
QVector<double> a(201), b(201);
QVector<double> e(1001), f(1001);

QVector<double> c ={0,200}, d = {91.6667, 91.6667};


MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
       ui->setupUi(this);
       this->setWindowTitle("PID Tunning GUI");


       mSerial = new QSerialPort(this);
       updateSerialPort();

       ui->baudComboBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
       ui->baudComboBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
       ui->baudComboBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
       ui->baudComboBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
       ui->baudComboBox->setCurrentIndex(3);

       ui->sizeComboBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
       ui->sizeComboBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
       ui->sizeComboBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
       ui->sizeComboBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
       ui->sizeComboBox->setCurrentIndex(3);
       ui->serialComboBox->setCurrentIndex(1);
       ui -> kpEdit -> setText("30.00");
       ui -> kiEdit -> setText("00.01");
       ui -> kdEdit -> setText("00.78");
       ui -> posLineEdit -> setText("1440");
       ui -> accLineEdit -> setText("360");
       ui -> velLineEdit -> setText("360");

       QStringList parity = {"none"};
       ui -> parityComboBox -> addItems(parity);

       mSerialScanTimer = new QTimer(this);
       mSerialScanTimer->setInterval(5000);
       mSerialScanTimer->start();

       configAllButton(false);
       ui -> clearButton -> setEnabled(false);

       plotConfig();

       connect(mSerial, &QSerialPort::readyRead, this, &MainWindow::serialport_read);
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::updateSerialPort()
{
       mSerialPorts = QSerialPortInfo::availablePorts();
       ui->serialComboBox->clear();
       for(const QSerialPortInfo &port: mSerialPorts)
       {
           ui -> serialComboBox -> addItem(port.portName(),  port.systemLocation());
       }
}

void MainWindow::configAllButton(bool status)
{
   ui-> requestButton -> setEnabled(status);
   ui-> sendpidButton -> setEnabled(status);
   ui-> tunningButton -> setEnabled(status);
   ui-> motionButton -> setEnabled(status);
   ui -> runButton -> setEnabled(status);
   ui -> senparamsButton -> setEnabled(status);
   ui -> getButton -> setEnabled(status);
   ui -> sendButton -> setEnabled(status);
   ui -> clearPIDButton -> setEnabled(status);
   ui -> clearReceiveButton -> setEnabled(status);
   ui -> savePIDButton -> setEnabled(status);
   ui -> infoPIDButton -> setEnabled(status);
   ui -> closeButton -> setEnabled(status);


}

void MainWindow:: plotSetting(QCustomPlot  *plot, const char* xLabel, const char * yLabel)
{
       QFont legendFont = font();
       legendFont.setPointSize(8);
       plot  -> yAxis->setLabel(yLabel);
       plot  -> xAxis-> setLabel(xLabel);
       plot  -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
       plot  -> legend -> setVisible(true);
       plot  -> legend->setFont(legendFont);
       plot  -> legend->setSelectedFont(legendFont);
       plot  -> legend->setSelectableParts(QCPLegend::spItems);
}

void MainWindow::plotConfig()
{
           QPen pen;
           pen.setStyle(Qt::SolidLine);
           pen.setWidth(3);
           pen.setColor("#E2483E");
           QPen pen2;
           pen2.setStyle(Qt::SolidLine);
           pen2.setWidth(3);
           pen2.setColor("#5C97E3");
       //pid plot init//


       ui -> pidPlot -> addGraph();
       ui -> pidPlot -> graph(0) -> setLineStyle(QCPGraph::lsLine);
       ui->pidPlot->graph(0)->setPen(pen);
       ui->pidPlot->graph(0)->setName("Ref");

       ui -> pidPlot -> addGraph();
       ui -> pidPlot -> graph(1) -> setLineStyle(QCPGraph::lsLine);
       ui->pidPlot->graph(1)->setPen(pen2);
       ui->pidPlot->graph(1)->setName("Tunning");


       plotSetting(ui-> pidPlot, "Time", "Magnitude");


       //Position plot init//
       ui -> posPlot -> addGraph();
       ui -> posPlot -> graph(0) -> setLineStyle(QCPGraph::lsLine);
       ui -> posPlot -> graph(0) -> setName("Posititon Ref");
       ui -> posPlot ->graph(0)->setPen(pen);

       ui -> posPlot -> addGraph();
       ui -> posPlot -> graph(1) -> setPen(pen2);
       ui -> posPlot -> graph(1) -> setLineStyle(QCPGraph::lsLine);
       ui -> posPlot -> graph(1) -> setName("Posititon Act");

       plotSetting(ui-> posPlot, "Time", "Position");

       //Velocity plot init//
       ui -> velPlot -> addGraph();
       ui -> velPlot -> graph() -> setLineStyle(QCPGraph::lsLine);
       ui -> velPlot -> graph() -> setName("Velocity");
       plotSetting(ui-> velPlot, "Time", "Velocity");
       ui -> velPlot ->graph()->setPen(pen);


       //Acc plot init//
       ui -> accPlot -> addGraph();
       ui -> accPlot -> graph() -> setLineStyle(QCPGraph::lsStepLeft);
       ui -> accPlot -> graph() -> setName("Velocity");
       plotSetting(ui-> accPlot, "Time", "Accelometer");
       ui -> accPlot ->graph()->setPen(pen);


}

void MainWindow::dataPIDProcessing(QByteArray &bdata, float *fKp, float *fKi, float *fKd)
{
   QByteArray bKRev;
   bKRev.resize(2);
   bKRev.clear();


   bKRev.append(bdata[0]);
   bKRev.append(bdata[1]);
   bool bStatus;
   uint iKpRev1 = QString(bKRev).toUInt(&bStatus,16);
   bKRev.clear();

   bKRev.append(bdata[2]);
   bKRev.append(bdata[3]);
   bStatus = false;
   uint iKpRev2 = QString(bKRev).toUInt(&bStatus,16);
   bKRev.clear();

   bKRev.append(bdata[4]);
   bKRev.append(bdata[5]);
   bStatus = false;
   uint iKiRev1 = QString(bKRev).toUInt(&bStatus,16);
   bKRev.clear();

   bKRev.append(bdata[6]);
   bKRev.append(bdata[7]);
   bStatus = false;
   uint iKiRev2 = QString(bKRev).toUInt(&bStatus,16);
   bKRev.clear();

   bKRev.append(bdata[8]);
   bKRev.append(bdata[9]);
   bStatus = false;
   uint iKdRev1 = QString(bKRev).toUInt(&bStatus,16);
   bKRev.clear();

   bKRev.append(bdata[10]);
   bKRev.append(bdata[11]);
   bStatus = false;
   uint iKdRev2 = QString(bKRev).toUInt(&bStatus,16);
   bKRev.clear();

   *fKp = (float)iKpRev1 + (float)iKpRev2/100 ;
   *fKi = (float)iKiRev1 + (float)iKiRev2/100;
   *fKd = (float)iKdRev1 + (float)iKdRev2/100;
}

void MainWindow::Ascii2int(int *a, int *b, int *c, int *d)
{
   AsciiConvertCase(a);
   AsciiConvertCase(b);
   AsciiConvertCase(c);
   AsciiConvertCase(d);
}

void MainWindow::AsciiConvertCase(int *a)
{
   switch(*a)
   {
   case 48:
       *a = 0;
       break;
   case 49:
       *a = 1;
       break;
   case 50:
       *a = 2;
       break;
   case 51:
       *a = 3;
       break;
   case 52:
       *a = 4;
       break;
   case 53:
       *a = 5;
       break;
   case 54:
       *a = 6;
       break;
   case 55:
       *a = 7;
       break;
   case 56:
       *a = 8;
       break;
   case 57:
       *a = 9;
       break;
   case 97:
       *a = 10;
       break;
   case 98:
       *a = 11;
       break;
   case 99:
       *a = 12;
       break;
   case 100:
       *a = 13;
       break;
   case 101:
       *a = 14;
       break;
   case 102:
       *a = 15;
       break;
   case 65:
       *a = 10;
       break;
   case 66:
       *a = 11;
       break;
   case 67:
       *a = 12;
       break;
   case 68:
       *a = 13;
       break;
   case 69:
       *a = 14;
       break;
   case 70:
       *a = 15;
       break;
   default:
       break;
   }
}


void MainWindow::on_openButton_clicked()
{
       ui->openButton->setEnabled(false);
       QString serialLoc  =  ui->serialComboBox->currentData().toString();

       mSerial->setPortName(serialLoc);
       mSerial->setBaudRate(static_cast<QSerialPort::BaudRate>(ui->baudComboBox->itemData(ui->baudComboBox->currentIndex()).toInt()));
       mSerial->setDataBits(static_cast<QSerialPort::DataBits>(ui->sizeComboBox->itemData(ui->sizeComboBox->currentIndex()).toInt()));
       mSerial->setParity(QSerialPort::NoParity);
       mSerial->setStopBits(QSerialPort::OneStop);
       mSerial->setFlowControl(QSerialPort::NoFlowControl);

           if(mSerial->open(QIODevice::ReadWrite))
           {
                   QSerialPortInfo port = QSerialPortInfo(ui->serialComboBox->currentText());
                   ui -> productIDLabel -> setText(QString::number(port.productIdentifier(), 16));
                   ui -> vendorIDLabel -> setText(QString::number(port.vendorIdentifier(), 16));
                   ui -> vendorLabel -> setText(port.description());
                   ui -> manuLabel -> setText(port.manufacturer());
                   ui -> portlabel  -> setText(port.portName());
               QString text = "SERIAL: OK!\n";
               ui->textBrowser->insertPlainText(text);
           }
               else {
           QString text = "SERIAL: ERROR!\n";
           ui->textBrowser->insertPlainText(text);
       }

       configAllButton(true);
       ui->openButton->setEnabled(true);
}

void MainWindow::on_sendButton_clicked()
{
   if(mSerial-> isOpen())
       {
           QString str = ui ->sendEdit->text();
           str.append("\r\n");
           mSerial -> write(str.toLocal8Bit());
           ui -> clearButton -> setEnabled(true);
       }
       else
       {
           QString text = "Transmit mission failed!\n";
           ui->textBrowser->insertPlainText(text);
       }
}

void MainWindow::serialport_read()
{
      QString strDataRev;
      QString cmd = "Command recieved: ";
      QString data = "Data recieved:\n";
      QThread::msleep(30);
      QByteArray bDataRev = mSerial -> readAll();
      qDebug() << bDataRev.size() << "\n" ;
      if((bDataRev.size() < 17) && (bDataRev.size() >18))
      {
         bDataRev.clear();
      }
      else
      {
          strDataRev = (QString(bDataRev));
          QByteArray bTempDataRev = bDataRev;

          //QString temp = strDataRev;
          qDebug() << "Command: " << strDataRev << "\n" ;
          strDataRev.append("\n");

           if((strDataRev == "SPID\n") ||(strDataRev =="\u0002SPID\n"))
           {
               ui -> textBrowser -> insertPlainText(cmd);
               ui -> textBrowser -> insertPlainText(strDataRev);

               ui -> textBrowser -> insertPlainText(data);
               bTempDataRev.chop(2);
               bTempDataRev = bTempDataRev.right(8).toHex();

               float fKp, fKi, fKd;
               dataPIDProcessing(bTempDataRev, &fKp, &fKi, &fKd);

               QString text ="Kpset: " + QString::number(fKp) + "\n";
               ui -> textBrowser -> insertPlainText(text);

               text ="Kiset: " + QString::number(fKi) + "\n";
               ui -> textBrowser -> insertPlainText(text);

               text ="Kdset: " + QString::number(fKd) + "\n";
               ui -> textBrowser -> insertPlainText(text);

               //qDebug() << "PID Pramas: " << QString::number(fKp) << " " << QString::number(fKi) << " " << QString::number(fKd) << "\n" ;
           }

           if((strDataRev == "CTUN\n")||(strDataRev =="\u0002CTUN\n"))
           {
               ui -> textBrowser -> insertPlainText(cmd);
               ui -> textBrowser -> insertPlainText(strDataRev);
               QString text = "CTUN cmd completed \n";
               ui -> textBrowser -> insertPlainText(text);

           }

           if((strDataRev == "\u0002GRMS\n" )||( strDataRev == "GRMS\n") ||(strDataRev =="\u0002GRMS\n"))
           {
               //ui -> textBrowser -> insertPlainText(cmd);
               //ui -> textBrowser -> insertPlainText("GRMS \n");
               bTempDataRev.chop(2);
               bTempDataRev = bTempDataRev.right(8).toHex().toUpper();
               qDebug() << "Total:" << bTempDataRev << "\n" ;

               double bCount1;
               double bPosition1;

               int iCount5 = static_cast<quint8>(bTempDataRev[4]);
               int iCount6 = static_cast<quint8>(bTempDataRev[5]);
               int iCount7 = static_cast<quint8>(bTempDataRev[6]);
               int iCount8 = static_cast<quint8>(bTempDataRev[7]);
               int iPos5 = static_cast<quint8>(bTempDataRev[12]);
               int iPos6 = static_cast<quint8>(bTempDataRev[13]);
               int iPos7 = static_cast<quint8>(bTempDataRev[14]);
               int iPos8 = static_cast<quint8>(bTempDataRev[15]);

               Ascii2int( &iCount5,&iCount6, &iCount7, &iCount8);
               Ascii2int( &iPos5,&iPos6, &iPos7, &iPos8);

               bCount1= (double)((double)(iCount5*4096 +iCount6*256 + iCount7*16 + iCount8)/100);
               bPosition1= (double)(iPos5*4096 +iPos6*256 + iPos7*16 + iPos8);

               if((bPosition1 >= PositionTemp) && (bPosition1 != 0) && (bPosition1 < PositionRef) && (bCount1 != 0) && (bCount1 < maxlength -2))
                  {
                           e[counter] = bCount1;
                           f[counter] =bPosition1;
                            ui -> posPlot -> graph(1) ->setData(e, f);
                            ui->posPlot->rescaleAxes();
                            ui->posPlot->replot();
                            ui-> posPlot -> update();
                            qDebug() << "Positon: " <<bPosition1  << " " << "Count: " <<bCount1 << "\n" ;
                            PositionTemp = bPosition1;
                            counter ++;

                   }
               else if((bPosition1 < PositionTemp) || (bPosition1 = 0) || (bPosition1 > PositionRef) || (bCount1 = 0) || (bCount1 > maxlength -2))
               {
                   if(counter>2)
                   {
                       if(f[counter-1] < f[counter-2])
                       {
                           e[counter] = e[counter - 1] + 0.01;
                           f[counter] = f[counter -1] -1;
                       }
                       else if (f[counter -1] == f[counter-2])
                       {
                           e[counter] = e[counter - 1] + 0.01;
                           f[counter] = f[counter -1];
                       }
                       else
                       {
                           e[counter] = e[counter - 1] + 0.01;
                           f[counter] = f[counter -1] + 1;
                       }
                       ui -> posPlot -> graph(1) ->setData(e, f);
                       ui->posPlot->rescaleAxes();
                       ui->posPlot->replot();
                       ui-> posPlot -> update();
                       PositionTemp = f[counter];
                       counter ++;
                   }
               }
           }

           if((strDataRev == "\u0002GPID\n" )||( strDataRev == "GPID\n"))
           {
               //ui -> textBrowser -> insertPlainText(cmd);
               //ui -> textBrowser -> insertPlainText("GPID \n");
               bTempDataRev.chop(2);
               qDebug() << "Total:" << bTempDataRev << "\n" ;
               bTempDataRev = bTempDataRev.right(8).toHex().toUpper();
               qDebug() << "Total:" << bTempDataRev << "\n" ;

               long bCount;
               long bPosition;

               int iCount1 = static_cast<quint8>(bTempDataRev[4]);
               int iCount2 = static_cast<quint8>(bTempDataRev[5]);
               int iCount3 = static_cast<quint8>(bTempDataRev[6]);
               int iCount4 = static_cast<quint8>(bTempDataRev[7]);
               int iPos1 = static_cast<quint8>(bTempDataRev[12]);
               int iPos2 = static_cast<quint8>(bTempDataRev[13]);
               int iPos3 = static_cast<quint8>(bTempDataRev[14]);
               int iPos4 = static_cast<quint8>(bTempDataRev[15]);


               Ascii2int( &iCount1,&iCount2, &iCount3, &iCount4);
               Ascii2int( &iPos1,&iPos2, &iPos3, &iPos4);

               bCount= (double)(iCount1*4096 +iCount2*256 + iCount3*16 + iCount4);
               bPosition= (double)(iPos1*4096 +iPos2*256 + iPos3*16 + iPos4);
            qDebug() << "Positon: " <<bPosition  << " " << "Count: " <<bCount << "\n" ;
               if( (bPosition != 0) && (bPosition < 180) && (bCount != 0) && (bCount < 200))
                  {
                      a[k] = bCount;
                      b[k] =bPosition;
                      ui -> pidPlot -> graph(1) ->setData(a, b);
                      ui->pidPlot->rescaleAxes();
                      ui->pidPlot->replot();
                      ui-> pidPlot -> update();
                      qDebug() << "Positon: " <<bPosition  << " " << "Count: " <<bCount << "\n" ;

                       if(k>2)
                       {
                           if(b[k] > posMax)
                           {
                          posMax = b[k];
                           }
                       }
                       posxl = b[k];
                      k++;

                   }
               else
               {
                   if(k>2)
                   {
                       if(b[k-1] < b[k-2])
                       {
                           a[k] = a[k - 1] + 1;
                           b[k] = b[k -1] -1;
                       }
                       else if (b[k -1] == b[k-2])
                       {
                           a[k] = a[k - 1] + 1;
                           b[k] = b[k -1];
                       }
                       else
                       {
                           a[k] = a[k - 1] + 1;
                           b[k] = b[k -1] + 1;
                       }
                       ui -> pidPlot -> graph(1) ->setData(a, b);
                       ui->pidPlot->rescaleAxes();
                       ui->pidPlot->replot();
                       ui-> pidPlot -> update();
                       k++;
                       posxl = b[k];
                   }
               }
           }
       //clear data remain
          strDataRev.clear();
          bTempDataRev.clear();
          bDataRev.clear();
      }
      QScrollBar *sb = ui->textBrowser->verticalScrollBar();
      sb->setValue(sb->maximum());
}

void MainWindow::on_sendpidButton_clicked()
{
           QString temp;
           std::string result;
           std::ostringstream sstream;
           //reading params from Line Edit
           QString kp = ui ->kpEdit->text();
           QString ki = ui ->kiEdit->text();
           QString kd = ui ->kdEdit->text();

           //Kp convert
           QByteArray bKp;
           QStringList  list1 = kp.split(".");
           foreach (temp, list1)
           {
               result = (boost::format("%x") % temp.toInt()).str();
               bKp.append(" " + QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
           }
           qDebug() << bKp << "\n";

           //Ki convert
           QByteArray bKi;
           QStringList  list2 = ki.split(".");
           foreach (temp, list2)
           {
               result = (boost::format("%x") % temp.toInt()).str();
               bKi.append(" " +  QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
           }
           qDebug() << bKi << "\n";

           //Kd convert
           QByteArray bKd;
           QStringList  list3 = kd.split(".");
           foreach (temp, list3)
           {
               result = (boost::format("%x") % temp.toInt()).str();
               bKd.append(" " + QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
           }
           qDebug() << bKd << "\n";


           QByteArray bytes("02 53 50 49 44 00 00 00");
           bytes = QByteArray::fromHex(bytes);

           //merge params
           QByteArray temp2;
           temp2.append(bKp + bKi + bKd);
           bytes.append(temp2);


           //protocal last byte
           QByteArray temp_byte("00 00 16 03");
           temp_byte = QByteArray::fromHex(temp_byte);

           //send pid parmas
           bytes.append(temp_byte);
           bytes.replace(" ", "");
           qDebug() << bytes << "\n";
           mSerial->write(bytes);
           if(mSerial -> isWritable())
                   {
               QString text = "Send succeed \n";
               ui->textBrowser->insertPlainText(text);
                   }
}

void MainWindow::on_tunningButton_clicked()
{
           QByteArray str("02 43 54 55 4E 00 00 00 00 00 00 00 00 00 00 00 16 03");
           QByteArray t = str.replace(" ", "");
           QByteArray bytes = QByteArray::fromHex(t);
           mSerial->write(bytes);
           a.fill(0);
           b.fill(0);
           k = 0;
           ui -> pidPlot -> graph(0) -> setData(c,d);
           ui -> pidPlot -> graph(1) -> setData(a,b);
           ui->pidPlot->rescaleAxes();
           ui->pidPlot->replot();
           ui-> pidPlot -> update();
}

void MainWindow::on_requestButton_clicked()
{
           QByteArray str("02 47 50 49 44 00 00 00 00 00 00 00 00 00 00 00 16 03");
           QByteArray t = str.replace(" ", "");
           QByteArray bytes = QByteArray::fromHex(t);
           mSerial->write(bytes);
}

void MainWindow::on_motionButton_clicked()
{
   QString sPosRef = ui ->posLineEdit->text();
   QString sVelMax = ui ->velLineEdit->text();
   QString sAccMax = ui ->accLineEdit->text();

   double dPosRef = sPosRef.toDouble();
   double dVelMax = sVelMax.toDouble();
   double dAccMax = sAccMax.toDouble();

   double tacc = dVelMax / dAccMax;
   double tconst = (dPosRef - dAccMax*tacc*tacc)/dVelMax;
   maxlength = 2*tacc + tconst + 2;
   QVector<double> dtimevel = {0, tacc, tacc + tconst, 2*tacc + tconst, 2*tacc + tconst + 2 };
   QVector<double> vecVelPlot = {0, dVelMax, dVelMax, 0, 0};

   QVector<double> dtime = {0,  2*tacc + tconst + 2};
   QVector<double> vecPosRef ={dPosRef, dPosRef};

   QVector<double> dtimeacc = {0, tacc, tacc + tconst, 2*tacc + tconst, 2*tacc + tconst + 2};
   QVector<double> vecAccRef = {dAccMax, 0, -dAccMax, 0  };

   ui -> posPlot -> graph(0) ->setData(dtime, vecPosRef);
   ui -> posPlot->rescaleAxes();
   ui -> posPlot->replot();
   ui -> posPlot -> update();

   ui -> velPlot -> graph() ->setData(dtimevel, vecVelPlot);
   ui -> velPlot->rescaleAxes();
   ui -> velPlot->replot();
   ui -> velPlot -> update();

   ui -> accPlot -> graph() ->setData(dtimeacc, vecAccRef);
   ui -> accPlot->rescaleAxes();
   ui -> accPlot->replot();
   ui -> accPlot -> update();

}


void MainWindow::on_runButton_clicked()
{

   QByteArray str("02 43 52 55 4E 00 00 00 00 00 00 00 00 00 00 00 16 03");
   QByteArray t = str.replace(" ", "");
   QByteArray byte = QByteArray::fromHex(t);
   mSerial->write(byte);
   qDebug() << "Command CRUN sent\n" ;
   if(mSerial -> isWritable())
           {
       QString text = "Send succeed \n";
       ui->textBrowser->insertPlainText(text);
           }
}

void MainWindow::on_senparamsButton_clicked()
{
   QByteArray bDataMax;
   std::string result;

   QString sPosRef = ui ->posLineEdit->text();
   QString sVelMax = ui ->accLineEdit->text();
   QString sAccMax = ui ->velLineEdit->text();

   double dPosRef = sPosRef.toDouble();
   double dVelMax = sVelMax.toDouble();
   double dAccMax = sAccMax.toDouble();

   PositionRef = dPosRef;

   double hHex = 0;
   uint16_t bHex = (static_cast<uint16_t>(hHex));
   std::string strHex = (boost::format("%x") % bHex).str();
   //qDebug() << strHex << "\n" ;
   uint16_t bAccMax = (static_cast<uint16_t>(dAccMax));
   result = (boost::format("%x") % bAccMax).str();
   if(dAccMax <= 255)
   {
       bDataMax.append(" " +QByteArray::fromHex(QString::fromStdString(strHex).toUtf8()));
   }
   bDataMax.append(" " + QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
   result.clear();
   qDebug() << bAccMax << "\n" ;
   qDebug() << bDataMax << "\n" ;

   uint16_t bVelMax = (static_cast<uint16_t>(dVelMax));
   result = (boost::format("%x") % bVelMax).str();
   if(dVelMax <= 255)
   {
       bDataMax.append(" " +QByteArray::fromHex(QString::fromStdString(strHex).toUtf8()));
   }
   bDataMax.append(" " + QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
   result.clear();
   qDebug() << bVelMax << "\n" ;
   qDebug() << bDataMax << "\n" ;

   uint16_t bPosRef = (static_cast<uint16_t>(dPosRef));
   result = (boost::format("%x") % bPosRef).str();
   if(dPosRef <= 255)
   {
       bDataMax.append(" " +QByteArray::fromHex(QString::fromStdString(strHex).toUtf8()));
   }
   bDataMax.append(" " + QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
   result.clear();
   qDebug() << bPosRef << "\n" ;
   qDebug() << bDataMax << "\n" ;



   QByteArray bytes("02 43 53 45 54 00 00 00 00 00");
   bytes = QByteArray::fromHex(bytes);
   bytes.append(bDataMax);
   QByteArray temp_byte("16 03");
   temp_byte = QByteArray::fromHex(temp_byte);
   bytes.append(temp_byte);
   bytes.replace(" ", "");
   qDebug() << bytes << "\n";
   mSerial->write(bytes);
   if(mSerial -> isWritable())
           {
       QString text = "Send succeed \n";
       ui->textBrowser->insertPlainText(text);
           }
}

void MainWindow::on_getButton_clicked()
{
   QByteArray str("02 47 52 4D 53 00 00 00 00 00 00 00 00 00 00 00 16 03");
   QByteArray t = str.replace(" ", "");
   QByteArray byte = QByteArray::fromHex(t);
   e.fill(0);
   f.fill(0);
   counter = 0;
   PositionTemp = 0;
   mSerial->write(byte);
   qDebug() << "Command GRMS sent\n" ;
   if(mSerial -> isWritable())
           {
       QString text = "Send succeed \n";
       ui->textBrowser->insertPlainText(text);
           }
}


void MainWindow::on_savePIDButton_clicked()
{
   QString filename = QFileDialog::getSaveFileName(this,tr("Save pdf") , "", tr("Pdf files (*.pdf)"));

       if (!filename.isEmpty()) {
           ui->pidPlot->savePdf(filename);
       }
}

void MainWindow::on_clearPIDButton_clicked()
{
           ui->kpEdit->clear();
           ui->kiEdit->clear();
           ui->kdEdit->clear();
           QVector<double> emptx = {0}, empty ={0};
           ui -> pidPlot -> graph(0) -> setData(emptx,empty);
           ui -> pidPlot -> graph(1) -> setData(emptx,empty);
           ui->pidPlot->rescaleAxes();
           ui->pidPlot->replot();
           ui-> pidPlot -> update();
}

void MainWindow::on_infoPIDButton_clicked()
{
   double POT = ((posMax - posxl)/posxl)*100;
   double error = (posxl - 91.6667);

   QString info = QString("PID Tunning information: \n");
   info += QString("POT = " ) + QString::number(POT) + " %\n";
   info  += QString("Error = ") + QString::number(error) + " pulse\n";

   QMessageBox::information(this, "PID INFOMATION", info);
}

void MainWindow::on_clearReceiveButton_clicked()
{
       ui -> textBrowser -> clear();
}

void MainWindow::on_closeButton_clicked()
{
   if (mSerial->isOpen())
       {
           mSerial->close();
           QString text = "Serial Port: Close\n";
           ui->textBrowser->insertPlainText(text);
           configAllButton(false);
       }
}

void MainWindow::on_clearButton_clicked()
{
    ui->sendEdit->clear();
    ui -> clearButton -> setEnabled(false);

}
