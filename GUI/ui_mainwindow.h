/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *gridGroupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QDateEdit *Date;
    QTimeEdit *LT;
    QSpinBox *time_zone;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lat;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *lon;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QGroupBox *gridGroupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QLineEdit *ra_s;
    QLineEdit *dec_sec;
    QLineEdit *dec_deg;
    QLabel *label_17;
    QLabel *label_11;
    QLabel *label_18;
    QLineEdit *ra_m;
    QLabel *label_12;
    QLabel *label_14;
    QLineEdit *ra_h;
    QLabel *label_16;
    QLabel *label_13;
    QLineEdit *dec_min;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *pushButton;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_29;
    QLabel *max_h_deg;
    QLabel *label_31;
    QLabel *max_h_m;
    QLabel *label_33;
    QHBoxLayout *horizontalLayout_5;
    QLabel *in_was;
    QLabel *t_h;
    QLabel *label_34;
    QLabel *t_m;
    QLabel *label_36;
    QLabel *ago;
    QLabel *label_30;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(594, 659);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridGroupBox_2 = new QGroupBox(centralWidget);
        gridGroupBox_2->setObjectName(QString::fromUtf8("gridGroupBox_2"));
        gridGroupBox_2->setGeometry(QRect(20, 30, 218, 181));
        gridLayout_2 = new QGridLayout(gridGroupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        label_4 = new QLabel(gridGroupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(gridGroupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(gridGroupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        Date = new QDateEdit(gridGroupBox_2);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setProperty("showGroupSeparator", QVariant(false));
        Date->setMaximumDate(QDate(2024, 12, 31));
        Date->setMinimumDate(QDate(2010, 1, 1));
        Date->setCalendarPopup(true);
        Date->setTimeSpec(Qt::LocalTime);
        Date->setDate(QDate(2019, 5, 1));

        gridLayout_2->addWidget(Date, 2, 1, 1, 1);

        LT = new QTimeEdit(gridGroupBox_2);
        LT->setObjectName(QString::fromUtf8("LT"));
        LT->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        LT->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        LT->setProperty("showGroupSeparator", QVariant(false));
        LT->setCalendarPopup(true);

        gridLayout_2->addWidget(LT, 0, 1, 1, 1);

        time_zone = new QSpinBox(gridGroupBox_2);
        time_zone->setObjectName(QString::fromUtf8("time_zone"));
        time_zone->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        time_zone->setMinimum(-24);
        time_zone->setMaximum(24);
        time_zone->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout_2->addWidget(time_zone, 4, 1, 1, 1);

        gridGroupBox = new QGroupBox(centralWidget);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridGroupBox->setGeometry(QRect(250, 30, 321, 91));
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(14);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        label_2 = new QLabel(gridGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lat = new QLineEdit(gridGroupBox);
        lat->setObjectName(QString::fromUtf8("lat"));

        gridLayout->addWidget(lat, 1, 1, 1, 1);

        label = new QLabel(gridGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        comboBox = new QComboBox(gridGroupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(41, 16777215));

        gridLayout->addWidget(comboBox, 0, 2, 1, 1);

        lon = new QLineEdit(gridGroupBox);
        lon->setObjectName(QString::fromUtf8("lon"));

        gridLayout->addWidget(lon, 0, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 410, 213, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);

        horizontalLayout->addWidget(label_6);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout->addWidget(label_7);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout->addWidget(label_8);

        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        horizontalLayout->addWidget(label_9);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        horizontalLayout->addWidget(label_10);

        gridGroupBox_3 = new QGroupBox(centralWidget);
        gridGroupBox_3->setObjectName(QString::fromUtf8("gridGroupBox_3"));
        gridGroupBox_3->setGeometry(QRect(250, 130, 321, 80));
        gridLayout_3 = new QGridLayout(gridGroupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(4, 4, 4, 4);
        label_15 = new QLabel(gridGroupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 1, 0, 1, 1);

        ra_s = new QLineEdit(gridGroupBox_3);
        ra_s->setObjectName(QString::fromUtf8("ra_s"));

        gridLayout_3->addWidget(ra_s, 1, 5, 1, 1);

        dec_sec = new QLineEdit(gridGroupBox_3);
        dec_sec->setObjectName(QString::fromUtf8("dec_sec"));

        gridLayout_3->addWidget(dec_sec, 0, 5, 1, 1);

        dec_deg = new QLineEdit(gridGroupBox_3);
        dec_deg->setObjectName(QString::fromUtf8("dec_deg"));
        dec_deg->setMaxLength(3);

        gridLayout_3->addWidget(dec_deg, 0, 1, 1, 1);

        label_17 = new QLabel(gridGroupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 1, 4, 1, 1);

        label_11 = new QLabel(gridGroupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        label_18 = new QLabel(gridGroupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 1, 6, 1, 1);

        ra_m = new QLineEdit(gridGroupBox_3);
        ra_m->setObjectName(QString::fromUtf8("ra_m"));
        ra_m->setMaxLength(2);

        gridLayout_3->addWidget(ra_m, 1, 3, 1, 1);

        label_12 = new QLabel(gridGroupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 0, 2, 1, 1);

        label_14 = new QLabel(gridGroupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 0, 6, 1, 1);

        ra_h = new QLineEdit(gridGroupBox_3);
        ra_h->setObjectName(QString::fromUtf8("ra_h"));
        ra_h->setMaxLength(2);

        gridLayout_3->addWidget(ra_h, 1, 1, 1, 1);

        label_16 = new QLabel(gridGroupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 1, 2, 1, 1);

        label_13 = new QLabel(gridGroupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 0, 4, 1, 1);

        dec_min = new QLineEdit(gridGroupBox_3);
        dec_min->setObjectName(QString::fromUtf8("dec_min"));
        dec_min->setMaxLength(2);

        gridLayout_3->addWidget(dec_min, 0, 3, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 310, 211, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(horizontalLayoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        horizontalLayout_2->addWidget(label_19);

        label_20 = new QLabel(horizontalLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);

        horizontalLayout_2->addWidget(label_20);

        label_21 = new QLabel(horizontalLayoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);

        horizontalLayout_2->addWidget(label_21);

        label_22 = new QLabel(horizontalLayoutWidget_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);

        horizontalLayout_2->addWidget(label_22);

        label_23 = new QLabel(horizontalLayoutWidget_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font);

        horizontalLayout_2->addWidget(label_23);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 360, 221, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(horizontalLayoutWidget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font);

        horizontalLayout_3->addWidget(label_24);

        label_25 = new QLabel(horizontalLayoutWidget_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font);

        horizontalLayout_3->addWidget(label_25);

        label_26 = new QLabel(horizontalLayoutWidget_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font);

        horizontalLayout_3->addWidget(label_26);

        label_27 = new QLabel(horizontalLayoutWidget_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font);

        horizontalLayout_3->addWidget(label_27);

        label_28 = new QLabel(horizontalLayoutWidget_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);

        horizontalLayout_3->addWidget(label_28);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(222, 240, 151, 51));
        verticalGroupBox = new QGroupBox(centralWidget);
        verticalGroupBox->setObjectName(QString::fromUtf8("verticalGroupBox"));
        verticalGroupBox->setGeometry(QRect(30, 480, 201, 101));
        verticalLayout = new QVBoxLayout(verticalGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_29 = new QLabel(verticalGroupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font);

        horizontalLayout_4->addWidget(label_29);

        max_h_deg = new QLabel(verticalGroupBox);
        max_h_deg->setObjectName(QString::fromUtf8("max_h_deg"));
        max_h_deg->setFont(font);

        horizontalLayout_4->addWidget(max_h_deg);

        label_31 = new QLabel(verticalGroupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font);

        horizontalLayout_4->addWidget(label_31);

        max_h_m = new QLabel(verticalGroupBox);
        max_h_m->setObjectName(QString::fromUtf8("max_h_m"));
        max_h_m->setFont(font);

        horizontalLayout_4->addWidget(max_h_m);

        label_33 = new QLabel(verticalGroupBox);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font);

        horizontalLayout_4->addWidget(label_33);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        in_was = new QLabel(verticalGroupBox);
        in_was->setObjectName(QString::fromUtf8("in_was"));
        in_was->setFont(font);

        horizontalLayout_5->addWidget(in_was);

        t_h = new QLabel(verticalGroupBox);
        t_h->setObjectName(QString::fromUtf8("t_h"));
        t_h->setFont(font);

        horizontalLayout_5->addWidget(t_h);

        label_34 = new QLabel(verticalGroupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font);

        horizontalLayout_5->addWidget(label_34);

        t_m = new QLabel(verticalGroupBox);
        t_m->setObjectName(QString::fromUtf8("t_m"));
        t_m->setFont(font);

        horizontalLayout_5->addWidget(t_m);

        label_36 = new QLabel(verticalGroupBox);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font);

        horizontalLayout_5->addWidget(label_36);

        ago = new QLabel(verticalGroupBox);
        ago->setObjectName(QString::fromUtf8("ago"));
        ago->setFont(font);

        horizontalLayout_5->addWidget(ago);


        verticalLayout->addLayout(horizontalLayout_5);

        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(290, 320, 250, 250));
        label_30->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/Sauron.jpg")));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Date", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Time zone UT +", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Local Time", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Longitude \316\273", nullptr));
        label->setText(QApplication::translate("MainWindow", "Latitude \317\206", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "E", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "W", nullptr));

        label_6->setText(QApplication::translate("MainWindow", "LST:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "12", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "h", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "69", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "m", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Rectastence \316\261", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "m", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Declination \316\264", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "s", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\302\260", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\"", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "h", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "'", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Current  Height:", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "06", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\302\260", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "66", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "'", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "SMART's Azimuth:", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "03", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\302\260", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "33", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "'", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Calculate", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "Max Height:", nullptr));
        max_h_deg->setText(QApplication::translate("MainWindow", "04", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\302\260", nullptr));
        max_h_m->setText(QApplication::translate("MainWindow", "20", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "'", nullptr));
        in_was->setText(QApplication::translate("MainWindow", "Was", nullptr));
        t_h->setText(QApplication::translate("MainWindow", "20", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "h", nullptr));
        t_m->setText(QApplication::translate("MainWindow", "77", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "m", nullptr));
        ago->setText(QApplication::translate("MainWindow", "ago", nullptr));
        label_30->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
