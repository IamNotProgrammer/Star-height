/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
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
    QGroupBox *Date_and_Time;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QTimeEdit *LT;
    QSpinBox *time_zone;
    QLabel *label_5;
    QDateEdit *Date;
    QLabel *label_4;
    QGroupBox *Observer_Position;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lat;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *lon;
    QGroupBox *Star_Position;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *ra_h;
    QLabel *label_13;
    QLineEdit *ra_s;
    QLabel *label_15;
    QLineEdit *ra_m;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *dec_sec;
    QLabel *label_16;
    QLineEdit *dec_deg;
    QLineEdit *dec_min;
    QPushButton *pushButton;
    QGroupBox *Data;
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
    QGroupBox *Horiz_Coordinates;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_35;
    QGroupBox *Gal_coordinates;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_39;
    QLabel *galactic_b;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_40;
    QLabel *galactic_l;
    QLabel *label_32;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *Object_name;
    QLabel *label_37;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(591, 633);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Date_and_Time = new QGroupBox(centralWidget);
        Date_and_Time->setObjectName(QString::fromUtf8("Date_and_Time"));
        Date_and_Time->setGeometry(QRect(20, 0, 218, 181));
        gridLayout_2 = new QGridLayout(Date_and_Time);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        label_3 = new QLabel(Date_and_Time);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        LT = new QTimeEdit(Date_and_Time);
        LT->setObjectName(QString::fromUtf8("LT"));
        LT->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        LT->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        LT->setProperty("showGroupSeparator", QVariant(false));
        LT->setCalendarPopup(true);

        gridLayout_2->addWidget(LT, 0, 1, 1, 1);

        time_zone = new QSpinBox(Date_and_Time);
        time_zone->setObjectName(QString::fromUtf8("time_zone"));
        time_zone->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        time_zone->setMinimum(-24);
        time_zone->setMaximum(24);
        time_zone->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout_2->addWidget(time_zone, 3, 1, 1, 1);

        label_5 = new QLabel(Date_and_Time);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        Date = new QDateEdit(Date_and_Time);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setProperty("showGroupSeparator", QVariant(false));
        Date->setMinimumDateTime(QDateTime(QDate(1753, 1, 1), QTime(0, 0, 0)));
        Date->setMaximumDate(QDate(2024, 12, 31));
        Date->setMinimumDate(QDate(1753, 1, 1));
        Date->setCalendarPopup(true);
        Date->setTimeSpec(Qt::LocalTime);
        Date->setDate(QDate(2019, 12, 21));

        gridLayout_2->addWidget(Date, 1, 1, 1, 1);

        label_4 = new QLabel(Date_and_Time);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        Observer_Position = new QGroupBox(centralWidget);
        Observer_Position->setObjectName(QString::fromUtf8("Observer_Position"));
        Observer_Position->setGeometry(QRect(250, 0, 321, 91));
        gridLayout = new QGridLayout(Observer_Position);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(14);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        label_2 = new QLabel(Observer_Position);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lat = new QLineEdit(Observer_Position);
        lat->setObjectName(QString::fromUtf8("lat"));
        lat->setMaxLength(20);

        gridLayout->addWidget(lat, 1, 1, 1, 1);

        label = new QLabel(Observer_Position);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        comboBox = new QComboBox(Observer_Position);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(41, 16777215));

        gridLayout->addWidget(comboBox, 0, 2, 1, 1);

        lon = new QLineEdit(Observer_Position);
        lon->setObjectName(QString::fromUtf8("lon"));
        lon->setMaxLength(20);

        gridLayout->addWidget(lon, 0, 1, 1, 1);

        Star_Position = new QGroupBox(centralWidget);
        Star_Position->setObjectName(QString::fromUtf8("Star_Position"));
        Star_Position->setGeometry(QRect(250, 100, 321, 80));
        gridLayout_3 = new QGridLayout(Star_Position);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(4, 4, 4, 4);
        label_11 = new QLabel(Star_Position);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(Star_Position);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 0, 2, 1, 1);

        ra_h = new QLineEdit(Star_Position);
        ra_h->setObjectName(QString::fromUtf8("ra_h"));
        ra_h->setMaxLength(20);

        gridLayout_3->addWidget(ra_h, 1, 1, 1, 1);

        label_13 = new QLabel(Star_Position);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 0, 4, 1, 1);

        ra_s = new QLineEdit(Star_Position);
        ra_s->setObjectName(QString::fromUtf8("ra_s"));
        ra_s->setMaxLength(20);

        gridLayout_3->addWidget(ra_s, 1, 5, 1, 1);

        label_15 = new QLabel(Star_Position);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 1, 0, 1, 1);

        ra_m = new QLineEdit(Star_Position);
        ra_m->setObjectName(QString::fromUtf8("ra_m"));
        ra_m->setMaxLength(20);

        gridLayout_3->addWidget(ra_m, 1, 3, 1, 1);

        label_14 = new QLabel(Star_Position);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 0, 6, 1, 1);

        label_17 = new QLabel(Star_Position);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 1, 4, 1, 1);

        label_18 = new QLabel(Star_Position);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 1, 6, 1, 1);

        dec_sec = new QLineEdit(Star_Position);
        dec_sec->setObjectName(QString::fromUtf8("dec_sec"));
        dec_sec->setMaxLength(20);

        gridLayout_3->addWidget(dec_sec, 0, 5, 1, 1);

        label_16 = new QLabel(Star_Position);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 1, 2, 1, 1);

        dec_deg = new QLineEdit(Star_Position);
        dec_deg->setObjectName(QString::fromUtf8("dec_deg"));
        dec_deg->setMaxLength(20);

        gridLayout_3->addWidget(dec_deg, 0, 1, 1, 1);

        dec_min = new QLineEdit(Star_Position);
        dec_min->setObjectName(QString::fromUtf8("dec_min"));
        dec_min->setMaxLength(20);

        gridLayout_3->addWidget(dec_min, 0, 3, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 310, 131, 51));
        Data = new QGroupBox(centralWidget);
        Data->setObjectName(QString::fromUtf8("Data"));
        Data->setGeometry(QRect(20, 360, 221, 91));
        verticalLayout = new QVBoxLayout(Data);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_29 = new QLabel(Data);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_29->setFont(font);

        horizontalLayout_4->addWidget(label_29);

        max_h_deg = new QLabel(Data);
        max_h_deg->setObjectName(QString::fromUtf8("max_h_deg"));
        max_h_deg->setFont(font);

        horizontalLayout_4->addWidget(max_h_deg);

        label_31 = new QLabel(Data);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font);

        horizontalLayout_4->addWidget(label_31);

        max_h_m = new QLabel(Data);
        max_h_m->setObjectName(QString::fromUtf8("max_h_m"));
        max_h_m->setFont(font);

        horizontalLayout_4->addWidget(max_h_m);

        label_33 = new QLabel(Data);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font);

        horizontalLayout_4->addWidget(label_33);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        in_was = new QLabel(Data);
        in_was->setObjectName(QString::fromUtf8("in_was"));
        in_was->setFont(font);

        horizontalLayout_5->addWidget(in_was);

        t_h = new QLabel(Data);
        t_h->setObjectName(QString::fromUtf8("t_h"));
        t_h->setFont(font);

        horizontalLayout_5->addWidget(t_h);

        label_34 = new QLabel(Data);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font);

        horizontalLayout_5->addWidget(label_34);

        t_m = new QLabel(Data);
        t_m->setObjectName(QString::fromUtf8("t_m"));
        t_m->setFont(font);

        horizontalLayout_5->addWidget(t_m);

        label_36 = new QLabel(Data);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font);

        horizontalLayout_5->addWidget(label_36);

        ago = new QLabel(Data);
        ago->setObjectName(QString::fromUtf8("ago"));
        ago->setFont(font);

        horizontalLayout_5->addWidget(ago);


        verticalLayout->addLayout(horizontalLayout_5);

        Horiz_Coordinates = new QGroupBox(centralWidget);
        Horiz_Coordinates->setObjectName(QString::fromUtf8("Horiz_Coordinates"));
        Horiz_Coordinates->setGeometry(QRect(20, 190, 221, 171));
        verticalLayout_3 = new QVBoxLayout(Horiz_Coordinates);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_19 = new QLabel(Horiz_Coordinates);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        horizontalLayout_2->addWidget(label_19);

        label_20 = new QLabel(Horiz_Coordinates);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);

        horizontalLayout_2->addWidget(label_20);

        label_21 = new QLabel(Horiz_Coordinates);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMaximumSize(QSize(6, 16777215));
        label_21->setFont(font);

        horizontalLayout_2->addWidget(label_21);

        label_22 = new QLabel(Horiz_Coordinates);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);

        horizontalLayout_2->addWidget(label_22);

        label_23 = new QLabel(Horiz_Coordinates);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(27, 0));
        label_23->setFont(font);

        horizontalLayout_2->addWidget(label_23);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_24 = new QLabel(Horiz_Coordinates);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMaximumSize(QSize(72, 16777215));
        label_24->setFont(font);

        horizontalLayout_3->addWidget(label_24);

        label_25 = new QLabel(Horiz_Coordinates);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMaximumSize(QSize(28, 16777215));
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_25);

        label_26 = new QLabel(Horiz_Coordinates);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMaximumSize(QSize(8, 16777215));
        label_26->setFont(font);
        label_26->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_26);

        label_27 = new QLabel(Horiz_Coordinates);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMaximumSize(QSize(18, 16777215));
        label_27->setFont(font);
        label_27->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_27);

        label_28 = new QLabel(Horiz_Coordinates);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);

        horizontalLayout_3->addWidget(label_28);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(Horiz_Coordinates);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(73, 0));
        label_6->setFont(font);

        horizontalLayout->addWidget(label_6);

        label_7 = new QLabel(Horiz_Coordinates);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(20, 16777215));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        label_8 = new QLabel(Horiz_Coordinates);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(5, 16777215));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        label_9 = new QLabel(Horiz_Coordinates);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setEnabled(true);
        label_9->setMaximumSize(QSize(17, 16777215));
        label_9->setSizeIncrement(QSize(0, 0));
        label_9->setBaseSize(QSize(0, 0));
        label_9->setFont(font);
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setLineWidth(1);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);

        label_10 = new QLabel(Horiz_Coordinates);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(5, 16777215));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_10);

        label_35 = new QLabel(Horiz_Coordinates);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMaximumSize(QSize(84, 16777215));
        label_35->setFont(font);

        horizontalLayout->addWidget(label_35);


        verticalLayout_3->addLayout(horizontalLayout);

        Gal_coordinates = new QGroupBox(centralWidget);
        Gal_coordinates->setObjectName(QString::fromUtf8("Gal_coordinates"));
        Gal_coordinates->setGeometry(QRect(20, 450, 221, 111));
        verticalLayout_2 = new QVBoxLayout(Gal_coordinates);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_39 = new QLabel(Gal_coordinates);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMinimumSize(QSize(100, 0));
        label_39->setFont(font);

        horizontalLayout_6->addWidget(label_39);

        galactic_b = new QLabel(Gal_coordinates);
        galactic_b->setObjectName(QString::fromUtf8("galactic_b"));
        galactic_b->setFont(font);

        horizontalLayout_6->addWidget(galactic_b);

        label_30 = new QLabel(Gal_coordinates);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMaximumSize(QSize(12, 16777215));
        label_30->setFont(font);

        horizontalLayout_6->addWidget(label_30);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_40 = new QLabel(Gal_coordinates);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font);

        horizontalLayout_7->addWidget(label_40);

        galactic_l = new QLabel(Gal_coordinates);
        galactic_l->setObjectName(QString::fromUtf8("galactic_l"));
        galactic_l->setFont(font);

        horizontalLayout_7->addWidget(galactic_l);

        label_32 = new QLabel(Gal_coordinates);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMaximumSize(QSize(12, 16777215));
        label_32->setFont(font);

        horizontalLayout_7->addWidget(label_32);


        verticalLayout_2->addLayout(horizontalLayout_7);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 250, 131, 51));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 190, 131, 51));
        Object_name = new QLineEdit(centralWidget);
        Object_name->setObjectName(QString::fromUtf8("Object_name"));
        Object_name->setGeometry(QRect(390, 201, 181, 31));
        label_37 = new QLabel(centralWidget);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(310, 420, 181, 81));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_37->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 591, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(LT, Date);
        QWidget::setTabOrder(Date, time_zone);
        QWidget::setTabOrder(time_zone, lon);
        QWidget::setTabOrder(lon, comboBox);
        QWidget::setTabOrder(comboBox, lat);
        QWidget::setTabOrder(lat, dec_deg);
        QWidget::setTabOrder(dec_deg, dec_min);
        QWidget::setTabOrder(dec_min, dec_sec);
        QWidget::setTabOrder(dec_sec, ra_h);
        QWidget::setTabOrder(ra_h, ra_m);
        QWidget::setTabOrder(ra_m, ra_s);
        QWidget::setTabOrder(ra_s, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Star Height", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Local Time", nullptr));
        LT->setDisplayFormat(QCoreApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Time zone UT \302\261", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Longitude \316\273", nullptr));
        lat->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Latitude \317\206", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "E", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "W", nullptr));

        lon->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Dec \316\264", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        ra_h->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "'", nullptr));
        ra_s->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Ra \316\261", nullptr));
        ra_m->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\"", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        dec_sec->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "h", nullptr));
        dec_deg->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        dec_min->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Max Height:", nullptr));
        max_h_deg->setText(QCoreApplication::translate("MainWindow", "04", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        max_h_m->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "'", nullptr));
        in_was->setText(QCoreApplication::translate("MainWindow", "Was", nullptr));
        t_h->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "h", nullptr));
        t_m->setText(QCoreApplication::translate("MainWindow", "77", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        ago->setText(QCoreApplication::translate("MainWindow", "ago", nullptr));
        Horiz_Coordinates->setTitle(QCoreApplication::translate("MainWindow", "Horizontal coordinates", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "06", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "66", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "'", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Azimuth:", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "303", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "33", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "'", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "LST:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "69", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "80", nullptr));
        Gal_coordinates->setTitle(QCoreApplication::translate("MainWindow", "Galactic coordinates", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "Latitude B:", nullptr));
        galactic_b->setText(QCoreApplication::translate("MainWindow", "360", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Longitude L:", nullptr));
        galactic_l->setText(QCoreApplication::translate("MainWindow", "520", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Set current time", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Find object", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
