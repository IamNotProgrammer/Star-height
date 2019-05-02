#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

////    CHANGE DECLINATION  ////

void MainWindow::on_dec_deg_textChanged(const QString &arg1)
{
    d_d = arg1.toDouble() ;

    if (d_d < 0)
        d = d_d - d_m - d_s ;

    else
        d = d_d + d_m + d_s ;
}

void MainWindow::on_dec_min_textChanged(const QString &arg1)
{
    d_m = arg1.toDouble() / 60 ;

    if (d_d < 0)
        d = d_d - d_m - d_s ;

    else
        d = d_d + d_m + d_s ;
}

void MainWindow::on_dec_sec_textChanged(const QString &arg1)
{
    d_s = arg1.toDouble() / 3600 ;

    if (d_d < 0)
        d = d_d - d_m - d_s ;

    else
        d = d_d + d_m + d_s ;
}

////    CHANGE RECTASTENCE  ////

void MainWindow::on_ra_h_textChanged(const QString &arg1)
{
    re_h = arg1.toInt() ;
    a = re_h + re_m + re_s ;
}

void MainWindow::on_ra_m_textChanged(const QString &arg1)
{
    re_m = arg1.toDouble() / 60 ;
    a = re_h + re_m + re_s ;
}

void MainWindow::on_ra_s_textChanged(const QString &arg1)
{
    re_s = arg1.toDouble() / 3600 ;
    a = re_h + re_m + re_s ;
}

////    CHANGE LONGITUDE    ////

void MainWindow::on_lon_textChanged(const QString &arg1)
{
    l = arg1.toDouble() ;
    l /= 15 ;
    if ( ui -> comboBox -> currentIndex() == 1 )
        l = -l ;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 1)
        l = - abs(l) ;

    else
        l = abs(l) ;
}

////    CHANGE LATITUDE     ////

void MainWindow::on_lat_textChanged(const QString &arg1)
{
    phi = arg1.toDouble() ;
}

////    LOCAL AND UNIVERSAL TIME    ////

void MainWindow::on_LT_timeChanged(const QTime &time)
{
    H = time.hour() ;
    M = time.minute() ;
    LMST = H + double( M ) / 60 ;

    UT = LMST - ui -> time_zone -> value() ;
    if (UT < 0)
        UT += 24 ;
}

void MainWindow::on_time_zone_valueChanged(int arg1)
{
    UT = LMST - arg1 ;
    if (UT < 0)
        UT += 24 ;
}

void MainWindow::on_Date_dateChanged(const QDate &date)
{
    year = date.year() ;
    mon2 = date.month() ;
    day2 = date.day() ;
}

////    CHANGE DATE TO LST      ////

double date2LST(double l, int year, int mon2, int day2, double hour)
    {

    int month[12] ;
    int mon1, day1, dd ;
    double hour_S, a_a, LST ;	// hour_S equinox time, a_a is average alpha
    double dm = 0 ;

    double year_tab[15] =
    {

    17.5333333333,
    23.3500000000,
    5.2333333333,
    11.0333333333,
    16.9500000000,
    22.7500000000,
    4.5000000000,
    10.4833333333,
    16.2500000000,
    21.9666666666,
    3.8333333333,
    9.6166666666,
    15.5500000000,
    21.4000000000,
    3.1166666666,

    } ;

    hour_S = year_tab[year - 2010] ;

    month[0] = 31 ;

    if (year % 4 == 0 and year % 100 != 0 or year % 400 == 0)
        month[1] = 29 ;

    else
        month[1] = 28 ;

        month[2] = 31 ;
        month[3] = 30 ;
        month[4] = 31 ;
        month[5] = 30 ;
        month[6] = 31 ;
        month[7] = 31 ;
        month[8] = 30 ;
        month[9] = 31 ;
        month[10] = 30 ;
        month[11] = 31 ;

    mon1 = 3 ;
    day1 = 20 ;

    if (mon2 > mon1)
        {

        for (int i = mon1 + 1; i < mon2; i++)
            {

            dm = dm + month[i - 1] ;

            }

        a_a = ( ( dm + month[mon1 - 1] -  day1 + day2 ) * 24 + (hour - hour_S) ) / 365.242189 ;

        }
    else
        {

        a_a = ( (day2 - day1) / 24 + (hour - hour_S) ) / 365.242189 ;

        }

    LST = hour + l + a_a + 12 ;
    LST = fmod(LST, 24) ;

    return LST ;

    }

////    CALCULATE OBJECT HEIGHT     ////

double dec2height (double dec, double t, double phi)
        {

        double h ;      // height
        double S_h ;    // sin h

        t = t * PI / 12 ;
        dec = dec * PI / 180 ;
        phi = phi * PI / 180 ;

        S_h = sin(phi) * sin(dec) + cos(phi) * cos(dec) * cos(t) ;
        h = asin(S_h) * 180 / PI ;
        h = int(h * 1e4) / 1e4 ;

        return h ;

        }

////    CALCULATE AZIMUTH   ////

double hour2azm (double dec, double h, double phi, double t)
        {

        double A ;      // azimuth
        double C_A ;    // cos A

        h = h * PI / 180 ;
        dec = dec * PI / 180 ;
        phi = phi * PI / 180 ;
        t = t * PI / 12 ;


        C_A = (  sin(h) * cos(phi) - cos(dec) * cos(t) ) / ( cos(h) * sin(phi)  ) ;
        A = acos(C_A) * 180 / PI ;
        A = int(A * 1e4) / 1e4 ;

        if (t > PI)
                A = fmod(360 - A, 360) ;

        return A ;

        }

////    CLICK BUTTON    ////

void MainWindow::on_pushButton_clicked()
{
    if (d <= phi )
        max_height = 90 - phi + d ;

    else
        max_height = 90 - d + phi ;

    ui -> max_h_deg->setText(QString::number( int( max_height ) ) ) ;
    ui -> max_h_m ->setText(QString::number( int( abs(max_height - int( max_height )) * 60 ) ) ) ;

    LST = date2LST(l, year, mon2, day2, UT) ;

    L_H = int(LST) ;
    L_M = int( ( LST - L_H ) * 60 ) ;

    ui -> label_7 -> setText( QString::number(L_H) ) ;
    ui -> label_9 -> setText( QString::number(L_M) ) ;

    t = LST - a ;
    h = dec2height(d, t, phi) ;
    A = hour2azm (d, h, phi, t) ;

    ui -> label_20 -> setText( QString::number( int(h) ) ) ;
    ui -> label_22 -> setText( QString::number( int( abs( h - int(h) ) * 60 ) ) ) ;

    ui -> label_25 -> setText( QString::number( int(A) ) ) ;
    ui -> label_27 -> setText( QString::number( int( ( A - int(A) ) * 60 ) ) ) ;


    ////    TIME TO/FROM MAX HEIGHT     ////

    if (t < 0 or t > 12 )
        {

        ui -> in_was -> setText("In") ;
        ui -> ago -> setText("") ;

        if (t < 0)
            {

            t_r = abs(t) ;
            ui -> t_h -> setText( QString::number(int(t_r)) ) ;
            ui -> t_m -> setText( QString::number( int( ( t_r - int(t_r) ) * 60 ) ) ) ;

            }

        else
            {

            t_r = 24 - t ;
            ui -> t_h -> setText( QString::number(int(t_r)) ) ;
            ui -> t_m -> setText( QString::number( int( ( t - int(t_r) ) * 60 ) ) ) ;

            }

        }

    else
        {

        ui -> in_was -> setText("Was") ;
        ui -> ago -> setText("ago") ;
        ui -> t_h -> setText( QString::number(int(t)) ) ;
        ui -> t_m -> setText( QString::number( int( ( t - int(t) ) * 60 ) ) ) ;

        }

    //// MAKE DATA FOR PLOT     ////

    system("> /usr/local/Data/Height.txt") ;

    for (double i = t - 5; i < (t + 5); i += 0.1666666)
        {

        CT = LMST + i - t ;
        ch = dec2height (d, i, phi);
        height = "echo '" ;

        if (CT > 0 and CT < 24)
            {

            H = int(CT) ;
            M = int( (CT - H) * 60 ) ;
            height += std::to_string(day2) + "/" + std::to_string(mon2) + " " + std::to_string(H) + ":" + std::to_string(M) ;

            }
        else if (CT > 24)
            {

                        H = fmod(int(CT), 24)  ;
                        M = int( ( fmod(CT, 24) - H ) * 60 ) ;
                        height += std::to_string(day2 + 1) + "/" + std::to_string(mon2) + " " + std::to_string(H) + ":" + std::to_string(M) ;


            }

        else
            {

            CT += 24 ;
                        H = int(CT) ;
                        M = int( (CT - H) * 60 ) ;
                        height += std::to_string(day2 - 1) + "/" + std::to_string(mon2) + " " + std::to_string(H) + ":" + std::to_string(M) ;

            }

        std::string str = std::to_string(ch) ;
        std::replace( str.begin(), str.end(), ',', '.');
        height += ", " + str + "' >> /usr/local/Data/Height.txt";

        system( height.c_str() ) ;

        }


    ////    CALL GRAPH      ////

    system("/usr/local/Data/Plot_height.plt") ;

}


////    THAT'S ALL FOR NOW      ////
