#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>

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

void MainWindow::on_dec_deg_textChanged(const QString &arg1)
{
    d_d = arg1.toFloat() ;
    d = d_d ;
}

void MainWindow::on_dec_min_textChanged(const QString &arg1)
{
    d_m = arg1.toFloat() / 60 ;

    if (d_d < 0)
        d = d_d - d_m ;

    else
        d = d_d + d_m ;
}

void MainWindow::on_dec_sec_textChanged(const QString &arg1)
{
    d_s = arg1.toFloat() / 3600 ;

    if (d_d < 0)
        d = d_d - d_m - d_s ;

    else
        d = d_d + d_m + d_s ;
}

void MainWindow::on_lon_textChanged(const QString &arg1)
{
    l = arg1.toFloat() ;
    l /= 15 ;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 1)
        l = - abs(l) ;

    else
        l = abs(l) ;
}

void MainWindow::on_lat_textChanged(const QString &arg1)
{
    phi = arg1.toFloat() ;
}

void MainWindow::on_LT_timeChanged(const QTime &time)
{
    H = time.hour() ;
    M = time.minute() ;
    LMST = H + float( M ) / 60 ;
}

void MainWindow::on_time_zone_valueChanged(int arg1)
{
    UT = LMST - arg1 ;
}

void MainWindow::on_Date_dateChanged(const QDate &date)
{
    year = date.year() ;
    mon2 = date.month() ;
    day2 = date.day() ;
//  std::cout << year << mon2 << day2 << "\n" ;
}


float date2LST(float l, int year, int mon2, int day2, float hour)
        {

        int month[12] ;
        int mon1, day1 ;
        float hour_S, a_a, LST ;        // hour_S equinox time, a_a is average alpha
        float dm = 0 ;

        float year_tab[15] =
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
                a_a = ( (day2 - day1) / 24 + (hour - hour_S) ) / 365.242189 ;

        LST = hour + l + a_a + 12 ;
        LST = fmod(LST, 24) ;

        return LST ;

    }


float dec2height (float dec, float t, float phi)
        {

        float h ;      // height
        float S_h ;    // sin h

        t = t * PI / 12 ;
        dec = dec * PI / 180 ;
        phi = phi * PI / 180 ;

        S_h = sin(phi) * sin(dec) + cos(phi) * cos(dec) * cos(t) ;
        h = asin(S_h) * 180 / PI ;
        h = int(h * 1e4) / 1e4 ;

        return h ;

        }


float hour2azm (float dec, float h, float phi, float t)
        {

        float A ;      // azimuth
        float C_A ;    // cos A

        h = h * PI / 180 ;
        dec = dec * PI / 180 ;
        phi = phi * PI / 180 ;
        t = t * PI / 12 ;


        C_A = (  sin(h) * cos(phi) - cos(dec) * cos(t) ) / ( cos(h) * sin(phi)  ) ;
        A = acos(C_A) * 180 / PI ;
        A = int(A * 1e4) / 1e4 ;

        if (t > PI)
                A = 360 - A ;

        return A ;

        }



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
    std::cout << t << "\n" ;
    ui -> label_20 -> setText( QString::number( int(h) ) ) ;
    ui -> label_22 -> setText( QString::number( int( abs( h - int(h) ) * 60 ) ) ) ;

    ui -> label_25 -> setText( QString::number( int(A) ) ) ;
    ui -> label_27 -> setText( QString::number( int( ( A - int(A) ) * 60 ) ) ) ;

    if (t < 0 or t > 12 )
        ui -> in_was -> setText("In") ;

    else
        ui -> in_was -> setText("Was") ;

    // NIY MO REKTASCENJII!!!!!!!!!!

}



void MainWindow::on_ra_h_textChanged(const QString &arg1)
{
    re_h = arg1.toInt() ;
    a += re_h ;
}

void MainWindow::on_ra_m_textChanged(const QString &arg1)
{
    re_m = arg1.toFloat() / 60 ;
    a += re_h + re_m ;
}

void MainWindow::on_ra_s_textChanged(const QString &arg1)
{
    re_s = arg1.toFloat() / 3600 ;
    a += re_h + re_m + re_s ;
}
