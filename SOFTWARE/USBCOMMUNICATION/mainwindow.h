#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <cstring>

#include <QVector>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void serialport_read();


    void on_openButton_clicked();

    void on_sendButton_clicked();

    void on_sendpidButton_clicked();

    void on_tunningButton_clicked();

    void on_requestButton_clicked();

    void on_motionButton_clicked();

    void on_runButton_clicked();

    void on_senparamsButton_clicked();

    void on_getButton_clicked();


    void on_savePIDButton_clicked();

    void on_clearPIDButton_clicked();

    void on_infoPIDButton_clicked();

    void on_clearReceiveButton_clicked();

    void on_closeButton_clicked();

    void on_clearButton_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void updateSerialPort();
    void configAllButton(bool status);
    void plotConfig();
    void dataPIDProcessing(QByteArray &bdata, float * fKp, float *fKi, float *fKd);
    void Ascii2int(int *a, int *b, int *c, int *d);
    void AsciiConvertCase(int *a);
    void plotSetting(QCustomPlot  *plot, const char* xLabel, const char * yLabel);
    QSerialPort *mSerial;
    QList <QSerialPortInfo> mSerialPorts;
    QTimer *mSerialScanTimer;


    QSharedPointer<QCPGraphDataContainer> mDatapid;
    QSharedPointer<QCPGraphDataContainer> mDatapos;
    QSharedPointer<QCPGraphDataContainer> mDatavel;
    QSharedPointer<QCPGraphDataContainer> mDataacc;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
