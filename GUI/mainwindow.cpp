#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "astm.h"

double k = 1.0027379093382884 ;

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

	std::cout << l << "\n" ;

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
	S = time.second() ;
	LMST = H + double( M ) * 0.0166666666666 + double( S ) * 0.0002777777777777777 ;

    UT = LMST - ui -> time_zone -> value() ;

	if (UT < 0) // sets UT time and day to day before
		{

		UT += 24.0 ;
		year = system("date -d 'yesterday' +%Y") ;
		mon2 = system("date -d 'yesterday' +%m") ;
		day2 = system("date -d 'yesterday' +%d") ;

		}

}

void MainWindow::on_time_zone_valueChanged(int arg1)
{
    UT = LMST - arg1 ;

	if (UT < 0) // sets UT time and day to day before
		{

		UT += 24.0 ;
		year = system("date -d 'yesterday' +%Y") ;
		mon2 = system("date -d 'yesterday' +%m") ;
		day2 = system("date -d 'yesterday' +%d") ;

		}

	std::cout << UT << "\n" ;

}

void MainWindow::on_Date_dateChanged(const QDate &date)
{
    year = date.year() ;
    mon2 = date.month() ;
    day2 = date.day() ;

	UT = LMST - ui -> time_zone -> value() ;

	if (UT < 0) // sets UT time and day to day before
		{

		UT += 24.0 ;
		year = system("date -d 'yesterday' +%Y") ;
		mon2 = system("date -d 'yesterday' +%m") ;
		day2 = system("date -d 'yesterday' +%d") ;

		}

}

////    CHANGE DATE TO LST      ////

double date2LST(double l, int year, int mon2, int day2, double hour)
    {

	double gmst, lst ;
	int h, m, s ;

	h = int(hour) ;
	m = int( (hour - h ) * 60 ) ;
	s = int( ( (hour - h) * 60 - m ) * 60 ) ;

	gmst = GMST(year, mon2, day2, h, m, s) ;

	lst = gmst + l ;

	return gmst ;

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

////	GALACTIC COORDINATES	////


double p2B (double d, double a, double dG, double aG)
	{

	double B ;

	d = d * PI / 180 ;
	a = a * PI / 6 ;

	B = asin( sin(d) * sin(dG) + cos(d) * cos(dG) * cos(a - aG) ) ;

	return B ;
	}

double p2L (double d, double a, double dG, double aG, double theta, double B)
	{

	double L, sTL, cTL;

	d = d * PI / 180 ;
	a = a * PI / 6 ;

	sTL = - cos(d) * sin(a - aG) / cos(B) ;
	cTL = sin(d) / ( cos(B) * cos(dG) ) - tan(B) * tan(dG) ;

	if ( (sTL >= 0) and (cTL > 0) )
		{
		L = asin(sTL) ;
//		std::cout << "1\t" ;
		}

	else if ( (sTL > 0) and (cTL <= 0) )
		{
		L = acos(cTL) ;
//		std::cout << "2\t" ;
		}

	else if ( (sTL <= 0) and (cTL < 0) )
		{
		L = PI - asin(sTL) ;
//		std::cout << "3\t" ;
		}

	else if ( (sTL < 0)  and (cTL >= 0) )
		{
		L = 2 * PI - acos(cTL) ;
//		std::cout << "4\t" ;
		}

	return L ;

	}



/*
void graph()
    {

     system("/usr/local/Data/Plot_height.plt") ;

    }
*/


//// SET CURRENT TIME ////

void MainWindow::on_pushButton_2_clicked()
{

	std::time_t now = time(0) ;
	tm *ltm = localtime(&now) ;

	year = 1900 + ltm -> tm_year ;
	mon2 = 1 + ltm -> tm_mon ;
	day2 = ltm -> tm_mday ;

	H = ltm -> tm_hour ;
	M = ltm -> tm_min ;
	S = ltm -> tm_sec ;

	UT = H + double( M ) * 0.0166666666666 + double( S ) * 0.0002777777777777777 - ui -> time_zone -> value() ;

	ui -> LT -> setTime( QTime(H, M, S) ) ; // sets current local time
	ui -> Date -> setDate( QDate(year, mon2, day2) ) ; // sets current date

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
	L_S = int( ( (LST - L_H) * 3600 - L_M * 60) ) ;

    ui -> label_7 -> setText( QString::number(L_H) ) ;
    ui -> label_9 -> setText( QString::number(L_M) ) ;
	ui -> label_35 -> setText( QString::number(L_S) ) ;

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
			ui -> t_m -> setText( QString::number( int( ( t_r - int(t_r) ) * 60 ) ) ) ;

            }

        }

    else
        {

        ui -> in_was -> setText("Was") ;
        ui -> ago -> setText("ago") ;
        ui -> t_h -> setText( QString::number(int(t)) ) ;
        ui -> t_m -> setText( QString::number( int( ( t - int(t) ) * 60 ) ) ) ;

        }


	//// GALACTIC COORDINATES ////

	B = p2B(d, a, dG, aG) ;
	L = p2L(d, a, dG, aG, theta, B) ;

	ui -> galactic_b -> setText( QString::number(B * 180 / PI) ) ;
	ui -> galactic_l -> setText( QString::number(L * 180 / PI) ) ;


	//// MAKE DATA FOR PLOT ////
/*
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

    graph() ;
*/
}


////    THAT'S ALL FOR NOW      ////



