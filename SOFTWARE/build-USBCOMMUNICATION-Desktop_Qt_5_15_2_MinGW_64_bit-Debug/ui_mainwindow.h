/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *posLineEdit;
    QLineEdit *velLineEdit;
    QLineEdit *accLineEdit;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *motionButton;
    QPushButton *runButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *senparamsButton;
    QPushButton *getButton;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *kpEdit;
    QLineEdit *kiEdit;
    QLineEdit *kdEdit;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_7;
    QPushButton *sendpidButton;
    QPushButton *tunningButton;
    QPushButton *requestButton;
    QGroupBox *groupBox_2;
    QCustomPlot *pidPlot;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QComboBox *serialComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QComboBox *baudComboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QComboBox *sizeComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QComboBox *parityComboBox;
    QGroupBox *groupBox_6;
    QLineEdit *sendEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_13;
    QPushButton *sendButton;
    QPushButton *clearButton;
    QGroupBox *groupBox;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_10;
    QCustomPlot *posPlot;
    QCustomPlot *velPlot;
    QCustomPlot *accPlot;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_11;
    QPushButton *savePIDButton;
    QPushButton *clearPIDButton;
    QVBoxLayout *verticalLayout_12;
    QPushButton *infoPIDButton;
    QPushButton *clearReceiveButton;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_9;
    QPushButton *openButton;
    QPushButton *closeButton;
    QGroupBox *groupBox_9;
    QWidget *widget;
    QVBoxLayout *verticalLayout_15;
    QLabel *portlabel;
    QLabel *vendorIDLabel;
    QLabel *productIDLabel;
    QLabel *manuLabel;
    QLabel *vendorLabel;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_16;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_17;
    QLabel *label_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1419, 814);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 361, 171));
        textBrowser = new QTextBrowser(groupBox_4);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 341, 131));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1130, 490, 211, 231));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 191, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        posLineEdit = new QLineEdit(layoutWidget);
        posLineEdit->setObjectName(QString::fromUtf8("posLineEdit"));

        verticalLayout->addWidget(posLineEdit);

        velLineEdit = new QLineEdit(layoutWidget);
        velLineEdit->setObjectName(QString::fromUtf8("velLineEdit"));

        verticalLayout->addWidget(velLineEdit);

        accLineEdit = new QLineEdit(layoutWidget);
        accLineEdit->setObjectName(QString::fromUtf8("accLineEdit"));

        verticalLayout->addWidget(accLineEdit);


        horizontalLayout->addLayout(verticalLayout);

        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 140, 191, 71));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        motionButton = new QPushButton(layoutWidget_4);
        motionButton->setObjectName(QString::fromUtf8("motionButton"));

        verticalLayout_3->addWidget(motionButton);

        runButton = new QPushButton(layoutWidget_4);
        runButton->setObjectName(QString::fromUtf8("runButton"));

        verticalLayout_3->addWidget(runButton);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        senparamsButton = new QPushButton(layoutWidget_4);
        senparamsButton->setObjectName(QString::fromUtf8("senparamsButton"));

        verticalLayout_4->addWidget(senparamsButton);

        getButton = new QPushButton(layoutWidget_4);
        getButton->setObjectName(QString::fromUtf8("getButton"));

        verticalLayout_4->addWidget(getButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 190, 331, 151));
        layoutWidget_2 = new QWidget(groupBox_7);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 20, 211, 121));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_6->addWidget(label_4);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        kpEdit = new QLineEdit(layoutWidget_2);
        kpEdit->setObjectName(QString::fromUtf8("kpEdit"));

        verticalLayout_5->addWidget(kpEdit);

        kiEdit = new QLineEdit(layoutWidget_2);
        kiEdit->setObjectName(QString::fromUtf8("kiEdit"));

        verticalLayout_5->addWidget(kiEdit);

        kdEdit = new QLineEdit(layoutWidget_2);
        kdEdit->setObjectName(QString::fromUtf8("kdEdit"));

        verticalLayout_5->addWidget(kdEdit);


        horizontalLayout_3->addLayout(verticalLayout_5);

        layoutWidget_3 = new QWidget(groupBox_7);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(240, 20, 82, 121));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        sendpidButton = new QPushButton(layoutWidget_3);
        sendpidButton->setObjectName(QString::fromUtf8("sendpidButton"));

        verticalLayout_7->addWidget(sendpidButton);

        tunningButton = new QPushButton(layoutWidget_3);
        tunningButton->setObjectName(QString::fromUtf8("tunningButton"));

        verticalLayout_7->addWidget(tunningButton);

        requestButton = new QPushButton(layoutWidget_3);
        requestButton->setObjectName(QString::fromUtf8("requestButton"));

        verticalLayout_7->addWidget(requestButton);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 350, 611, 411));
        pidPlot = new QCustomPlot(groupBox_2);
        pidPlot->setObjectName(QString::fromUtf8("pidPlot"));
        pidPlot->setGeometry(QRect(10, 30, 591, 371));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(1130, 10, 211, 241));
        layoutWidget_5 = new QWidget(groupBox_5);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 191, 211));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(layoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        serialComboBox = new QComboBox(layoutWidget_5);
        serialComboBox->setObjectName(QString::fromUtf8("serialComboBox"));

        horizontalLayout_4->addWidget(serialComboBox);


        verticalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(layoutWidget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        baudComboBox = new QComboBox(layoutWidget_5);
        baudComboBox->setObjectName(QString::fromUtf8("baudComboBox"));

        horizontalLayout_5->addWidget(baudComboBox);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_9 = new QLabel(layoutWidget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);

        sizeComboBox = new QComboBox(layoutWidget_5);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));

        horizontalLayout_6->addWidget(sizeComboBox);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(layoutWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        parityComboBox = new QComboBox(layoutWidget_5);
        parityComboBox->setObjectName(QString::fromUtf8("parityComboBox"));

        horizontalLayout_7->addWidget(parityComboBox);


        verticalLayout_8->addLayout(horizontalLayout_7);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(1130, 310, 211, 171));
        sendEdit = new QLineEdit(groupBox_6);
        sendEdit->setObjectName(QString::fromUtf8("sendEdit"));
        sendEdit->setGeometry(QRect(10, 30, 191, 51));
        layoutWidget1 = new QWidget(groupBox_6);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 90, 191, 71));
        verticalLayout_13 = new QVBoxLayout(layoutWidget1);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        sendButton = new QPushButton(layoutWidget1);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        verticalLayout_13->addWidget(sendButton);

        clearButton = new QPushButton(layoutWidget1);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        verticalLayout_13->addWidget(clearButton);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(630, 10, 491, 751));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 471, 711));
        verticalLayout_10 = new QVBoxLayout(layoutWidget2);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        posPlot = new QCustomPlot(layoutWidget2);
        posPlot->setObjectName(QString::fromUtf8("posPlot"));

        verticalLayout_10->addWidget(posPlot);

        velPlot = new QCustomPlot(layoutWidget2);
        velPlot->setObjectName(QString::fromUtf8("velPlot"));

        verticalLayout_10->addWidget(velPlot);

        accPlot = new QCustomPlot(layoutWidget2);
        accPlot->setObjectName(QString::fromUtf8("accPlot"));

        verticalLayout_10->addWidget(accPlot);

        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(390, 220, 211, 111));
        layoutWidget3 = new QWidget(groupBox_8);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 191, 91));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        savePIDButton = new QPushButton(layoutWidget3);
        savePIDButton->setObjectName(QString::fromUtf8("savePIDButton"));

        verticalLayout_11->addWidget(savePIDButton);

        clearPIDButton = new QPushButton(layoutWidget3);
        clearPIDButton->setObjectName(QString::fromUtf8("clearPIDButton"));

        verticalLayout_11->addWidget(clearPIDButton);


        horizontalLayout_8->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        infoPIDButton = new QPushButton(layoutWidget3);
        infoPIDButton->setObjectName(QString::fromUtf8("infoPIDButton"));

        verticalLayout_12->addWidget(infoPIDButton);

        clearReceiveButton = new QPushButton(layoutWidget3);
        clearReceiveButton->setObjectName(QString::fromUtf8("clearReceiveButton"));

        verticalLayout_12->addWidget(clearReceiveButton);


        horizontalLayout_8->addLayout(verticalLayout_12);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(1130, 250, 211, 58));
        verticalLayout_9 = new QVBoxLayout(layoutWidget4);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        openButton = new QPushButton(layoutWidget4);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        verticalLayout_9->addWidget(openButton);

        closeButton = new QPushButton(layoutWidget4);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout_9->addWidget(closeButton);

        groupBox_9 = new QGroupBox(centralwidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(380, 10, 241, 171));
        widget = new QWidget(groupBox_9);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 30, 141, 131));
        verticalLayout_15 = new QVBoxLayout(widget);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        portlabel = new QLabel(widget);
        portlabel->setObjectName(QString::fromUtf8("portlabel"));
        QFont font;
        font.setBold(true);
        portlabel->setFont(font);

        verticalLayout_15->addWidget(portlabel);

        vendorIDLabel = new QLabel(widget);
        vendorIDLabel->setObjectName(QString::fromUtf8("vendorIDLabel"));
        vendorIDLabel->setFont(font);

        verticalLayout_15->addWidget(vendorIDLabel);

        productIDLabel = new QLabel(widget);
        productIDLabel->setObjectName(QString::fromUtf8("productIDLabel"));
        productIDLabel->setFont(font);

        verticalLayout_15->addWidget(productIDLabel);

        manuLabel = new QLabel(widget);
        manuLabel->setObjectName(QString::fromUtf8("manuLabel"));
        manuLabel->setFont(font);

        verticalLayout_15->addWidget(manuLabel);

        vendorLabel = new QLabel(widget);
        vendorLabel->setObjectName(QString::fromUtf8("vendorLabel"));
        vendorLabel->setFont(font);

        verticalLayout_15->addWidget(vendorLabel);

        widget1 = new QWidget(groupBox_9);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 30, 77, 131));
        verticalLayout_14 = new QVBoxLayout(widget1);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(widget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_14->addWidget(label_16);

        label_11 = new QLabel(widget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_14->addWidget(label_11);

        label_12 = new QLabel(widget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_14->addWidget(label_12);

        label_17 = new QLabel(widget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_14->addWidget(label_17);

        label_13 = new QLabel(widget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_14->addWidget(label_13);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1419, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Received Data", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Control Parameters", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Velocity", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Accelometer", nullptr));
        motionButton->setText(QCoreApplication::translate("MainWindow", "MOTION", nullptr));
        runButton->setText(QCoreApplication::translate("MainWindow", "RUN", nullptr));
        senparamsButton->setText(QCoreApplication::translate("MainWindow", "SEND PARAMS", nullptr));
        getButton->setText(QCoreApplication::translate("MainWindow", "GET", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "PID Tunning", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Kp", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ki", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Kd", nullptr));
        sendpidButton->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
        tunningButton->setText(QCoreApplication::translate("MainWindow", "TUNING", nullptr));
        requestButton->setText(QCoreApplication::translate("MainWindow", "REQUEST", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "PID Tunning Graph", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Serial Port", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "COM", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "BaudRate", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "DataSize", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Parity", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Send Data", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Control Graph", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        savePIDButton->setText(QCoreApplication::translate("MainWindow", "Print PID", nullptr));
        clearPIDButton->setText(QCoreApplication::translate("MainWindow", "Clear PID", nullptr));
        infoPIDButton->setText(QCoreApplication::translate("MainWindow", "PID Info", nullptr));
        clearReceiveButton->setText(QCoreApplication::translate("MainWindow", "Clear Box", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "CLOSE", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "USB", nullptr));
        portlabel->setText(QCoreApplication::translate("MainWindow", "Not Connected!", nullptr));
        vendorIDLabel->setText(QCoreApplication::translate("MainWindow", "Not Connected!", nullptr));
        productIDLabel->setText(QCoreApplication::translate("MainWindow", "Not Connected!", nullptr));
        manuLabel->setText(QCoreApplication::translate("MainWindow", "Not Connected!", nullptr));
        vendorLabel->setText(QCoreApplication::translate("MainWindow", "Not Connected!", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "VendorID:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ProductID:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Manufacturer:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Vendor:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
