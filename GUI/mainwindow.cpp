﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream> // debugging tool
#include <cmath>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "astm.h"
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <QMessageBox>
#include <QDir>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QSettings>


//  DA LIST  //

//// 1. CHANGE DECLINATION
//// 2. CHANGE RECTASTENCE
//// 3. CHANGE LONGITUDE
//// 4. CHANGE LATITUDE
//// 5. LOCAL AND UNIVERSAL TIME
//// 6. CHANGE DATE TO LST
//// 7. CALCULATE OBJECT HEIGHT
//// 8. CALCULATE AZIMUTH
//// 9. GALACTIC COORDINATES
//// 10. SET CURRENT TIME
//// 11. REFRACTION
//// 12. GRAPH
//// 13. CLICK MAIN BUTTON
//// 14. LOAD CITIES
//// 15. COUNTRIES AND CITIES
//// 16. FIND OBJECT
//// 17. OPTIONS
//// 18. SAVED OBJECTS

/*
const double G = 0.0048481368110953596e-6 ; // constant to change parallax to distance in au.
const double f = 0.0033528106710763545 ; // Earth's flatness ~ 1/300
const double a = 4.26352124542639e-05 ; // Earth's bigger radius in au.
// all this for later
*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	// Version //

	version = new QLabel(this);
	statusBar() -> addPermanentWidget(version);
	version -> setText(VERSION_STRING) ;


	// Load countries to box //

	QDir directory("/usr/local/Data/Observatories/") ;

	QStringList ct = directory.entryList( QStringList() << "*", QDir::Files ) ;

	foreach(QString filename, ct)
		{

		ui -> Box_country -> addItem(filename) ;

		}


	// set current time

	on_pushButton_2_clicked() ;

	int to ; // time offset

	std::time_t t = std::time(0);   // get time now
	std::tm* local = std::localtime(&t);

	to = (local -> tm_gmtoff) / 3600 ;

	ui -> time_zone -> setValue(to) ;

	// load saved objects

	QFile file("/usr/local/Data/saved.txt") ;
	QString loaded, obj ;
	int num ;

	file.open(QFile::ReadOnly | QFile::Text) ;

	QTextStream in(&file) ;

	while( in.atEnd() != 1)
		{

		loaded = in.readLine() ;
		num = loaded.indexOf('|') ;

		obj = loaded.left(num) ;
		obj.replace('_', ' ') ;

		ui -> listWidget -> addItem( obj ) ;

		}

	file.flush() ;
	file.close() ;

	// settings

		// load location used last time

	int cou, cit ; // country, city

	QSettings settings("Star-height", "Star-height") ;

	cou = settings.value("Country").toInt() ;
	cit = settings.value("City").toInt() ;

	ui -> Box_country -> setCurrentIndex(cou) ;
	ui -> Box_city -> setCurrentIndex(cit) ;

}

MainWindow::~MainWindow()
{
	int cou, cit ; // country, city

	cou = ui -> Box_country -> currentIndex() ;
	cit = ui -> Box_city -> currentIndex() ;

	QSettings settings("Star-height", "Star-height") ;

	settings.setValue("Country", cou) ;
	settings.setValue("City", cit) ;

	qDebug() << "\nThank you for using Star-height\n\nSee you next time!\n" ;

    delete ui;
}


std::string cmd_out(std::string cmd) // https://www.jeremymorgan.com/tutorials/c-programming/how-to-capture-the-output-of-a-linux-command-in-c/
	{

	std::string data ;
	FILE * stream ;
	const int max_buffer = 256 ;
	char buffer[max_buffer] ;
	cmd.append(" 2>&1") ;

	stream = popen(cmd.c_str(), "r") ;

	if (stream)
		{
		while (!feof(stream))

			if (fgets(buffer, max_buffer, stream) != NULL)
				data.append(buffer) ;

		pclose(stream) ;
		}

	return data ;	// I have no idea what the fuck any of it means

	}

////   1. CHANGE DECLINATION    ////

void MainWindow::on_dec_deg_textChanged(const QString &arg1)	// declination hours
{
    d_d = arg1.toDouble() ;

    if (d_d < 0)
        d = d_d - d_m - d_s ;

    else
        d = d_d + d_m + d_s ;
}

void MainWindow::on_dec_min_textChanged(const QString &arg1)	// minutes
{
    d_m = arg1.toDouble() / 60 ;

    if (d_d < 0)
        d = d_d - d_m - d_s ;

    else
        d = d_d + d_m + d_s ;
}

void MainWindow::on_dec_sec_textChanged(const QString &arg1)	// seconds
{
    d_s = arg1.toDouble() / 3600 ;

    if (d_d < 0)
        d = d_d - d_m - d_s ;

    else
        d = d_d + d_m + d_s ;
}


////   2. CHANGE RECTASTENCE  ////

void MainWindow::on_ra_h_textChanged(const QString &arg1)	// right ascention hours
{
	re_h = arg1.toDouble() ;
    a = re_h + re_m + re_s ;
}

void MainWindow::on_ra_m_textChanged(const QString &arg1)	// minutes
{
    re_m = arg1.toDouble() / 60 ;
    a = re_h + re_m + re_s ;
}

void MainWindow::on_ra_s_textChanged(const QString &arg1)	// seconds
{
    re_s = arg1.toDouble() / 3600 ;
    a = re_h + re_m + re_s ;
}

////   3. CHANGE LONGITUDE    ////

void MainWindow::on_lon_textChanged(const QString &arg1)	// longitude from gui
{
	l = arg1.toDouble() / 15 ;
    if ( ui -> comboBox -> currentIndex() == 1 )
        l = -l ;

}

void MainWindow::on_comboBox_currentIndexChanged(int index)	// east/west
{
    if (index == 1)
        l = - abs(l) ;

    else
        l = abs(l) ;
}

////   4. CHANGE LATITUDE     ////

void MainWindow::on_lat_textChanged(const QString &arg1)
{
    phi = arg1.toDouble() ;
}

////   5. LOCAL AND UNIVERSAL TIME    ////

void MainWindow::on_LT_timeChanged(const QTime &time)	// when time is changed
{
    H = time.hour() ;
    M = time.minute() ;
	S = time.second() ;
	LMST = H + double( M ) * 0.0166666666666 + double( S ) * 0.0002777777777777777 ;

	UT = fmod(LMST - ui -> time_zone -> value(), 24.0) ;

	if (UT < 0) // sets UT time and day to day before
		{

		UT += 24.0 ;

		int sec ;
		sec = int( D_D(1970, 1, 1, 0, 0, 0, date_year, date_mon, date_day, 0, 0, 0) * 86400 - 86400 ) ;
		time_t now = (time_t)sec ;
		struct tm *t = localtime(&now);

		year = t -> tm_year + 1900 ;
		mon2 = t -> tm_mon + 1 ;
		day2 = t -> tm_mday ;

		}

	else
		{

		year = ui -> Date -> date().year() ;
		mon2 = ui -> Date -> date().month() ;
		day2 = ui -> Date -> date().day() ;

		}

}

void MainWindow::on_time_zone_valueChanged(int arg1)	// when you change time zone
{

	UT = fmod(LMST - arg1, 24.0) ;

	if (UT < 0) // sets UT time and day to day before
		{

		UT += 24.0 ;

		int sec ;
		sec = int( D_D(1970, 1, 1, 0, 0, 0, date_year, date_mon, date_day, 0, 0, 0) * 86400 - 86400 ) ;
		time_t now = (time_t)sec ;
		struct tm *t = localtime(&now);

		year = t -> tm_year + 1900 ;
		mon2 = t -> tm_mon + 1 ;
		day2 = t -> tm_mday ;

		}

	else
		{

		year = ui -> Date -> date().year() ;
		mon2 = ui -> Date -> date().month() ;
		day2 = ui -> Date -> date().day() ;

		}

}

void MainWindow::on_Date_dateChanged(const QDate &date)	// change date
{
    year = date.year() ;
	mon2 = date.month() ;
    day2 = date.day() ;

	date_year = date.year() ;
	date_mon = date.month() ;
	date_day = date.day() ;

	UT = fmod(LMST - ui -> time_zone -> value(), 24) ;

	if (UT < 0) // sets UT time and day to day before
		{

		UT += 24.0 ;

		int sec ;
		sec = int( D_D(1970, 1, 1, 0, 0, 0, date_year, date_mon, date_day, 0, 0, 0) * 86400 - 86400 ) ;
		time_t now = (time_t)sec ;
		struct tm *t = localtime(&now);

		year = t -> tm_year + 1900 ;
		mon2 = t -> tm_mon + 1 ;
		day2 = t -> tm_mday ;

		}

}

////   6. CHANGE DATE TO LST      ////

double date2LST(double l, int year, int mon2, int day2, double hour)	// local sidereal time
	{																	// but the truth is this is local mean sidereal time

	double gmst, lst ;
	int h, m, s, gh, gm, gs ;

	h = int(hour) ;
	m = int( (hour - h ) * 60 ) ;
	s = int( (hour - h) * 3600 - m * 60 ) ;

	gmst = GMST(year, mon2, day2, h, m, s) ;

	gh = int(gmst) ;
	gm = int( (gmst - gh ) * 60 ) ;
	gs = int( (gmst - gh) * 3600 - gm * 60 ) ;

	lst = fmod(gmst + l, 24) ;

	if (lst < 0)
		lst += 24.0 ;

	return lst ;

    }

////   7. CALCULATE OBJECT HEIGHT     ////

double dec2height (double dec, double t, double phi)
        {

        double h ;      // height
        double S_h ;    // sin h

        t = t * PI / 12 ;
        dec = dec * PI / 180 ;
        phi = phi * PI / 180 ;

        S_h = sin(phi) * sin(dec) + cos(phi) * cos(dec) * cos(t) ;
		h = asin(S_h) ;

        return h ;

        }

////   8. CALCULATE AZIMUTH   ////

double hour2azm (double dec, double h, double phi, double t)
        {

        double A ;      // azimuth
		double C_A, S_A ;    // cos A, sin A

		h = h * PI / 180 ;	// radian masetrace
        dec = dec * PI / 180 ;
        phi = phi * PI / 180 ;
        t = t * PI / 12 ;

		C_A = (  sin(dec) - cos(PI * 0.5 - h) * sin(phi) ) / ( cos(phi) * sin(PI * 0.5 - h)  ) ;
		S_A = sin(t) * cos(dec) / cos(h) ;

		A = atan2(S_A, C_A) ;

		A *= 180 / PI ;

		if (A < 0)
			A += 360 ;

		return A ;

        }


////    9. GALACTIC COORDINATES    ////

double p2B (double d, double a, double dG, double aG)	// calculates latitude in galactic coordinates
	{

	double B ;

	d *= PI / 180 ;
	a *= PI / 12 ;

	B = asin( sin(d) * sin(dG) + cos(d) * cos(dG) * cos(a - aG) ) ;

	return B ;
	}

double p2L (double d, double a, double dG, double aG, double theta, double B)	// calculates longitude in galactic coordinates
	{

	double L, sTh, cTh;

	d *= PI / 180 ;	// change to radians
	a *= PI / 12 ;

	sTh = cos(d) * sin(a - aG) / cos(B) ;
	cTh = sin(d) / ( cos(B) * cos(dG) ) - tan(B) * tan(dG) ;

	if ( (sTh >= 0) and (cTh > 0) )	// shit tone of ifs because asin(x) doesn't work for 360 degrees
		{
		L = theta - asin(sTh) ;
		if (L < 0)
			L += 2 * PI ;
		}

	else if ( (sTh > 0) and (cTh <= 0) )
		{
		L = theta - acos(cTh) ;
		if (L < 0)
			L += 2 * PI ;
		}

	else if ( (sTh <= 0) and (cTh < 0) )
		{
		L = theta - asin(sTh) ;
		if (L < 0)
			L += 2 * PI ;
		}

	else if ( (sTh < 0)  and (cTh >= 0) )
		{
		L = theta - acos(cTh) ;
		if (L < 0)
			L += 2 * PI ;
		}

	return L ;

	}


////    10. SET CURRENT TIME    ////

void MainWindow::on_pushButton_2_clicked()
{

	int tz = ui -> time_zone -> value() ;
	ui -> time_zone -> setValue(0) ;

	std::time_t now = time(NULL) ;
	tm *ltm = localtime(&now) ;

	year = 1900 + ltm -> tm_year ;
	mon2 = 1 + ltm -> tm_mon ;
	day2 = ltm -> tm_mday ;

	ui -> Date -> setDate( QDate(year, mon2, day2) ) ; // sets current date

	H = ltm -> tm_hour ;
	M = ltm -> tm_min ;
	S = ltm -> tm_sec ;

	UT = H + double( M ) * 0.0166666666666 + double( S ) * 0.0002777777777777777 - ui -> time_zone -> value() ;
	ui -> LT -> setTime( QTime(H, M, S) ) ; // sets current local time

	ui -> time_zone -> setValue(tz) ;

}


////   11. REFRACTION    ////

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1) // wave length
	{

	wl = arg1.toDouble() * 1e-3 ;

	}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1) // temperature
	{

	if ( ui -> comboBox_3 -> currentIndex() == 0)
		T = arg1.toDouble() - 273.15 ;

	else if ( ui -> comboBox_3 -> currentIndex() == 1)
		T = arg1.toDouble() ;

	else
		T = ( ( ui -> lineEdit_2 -> text() ).toDouble() - 32 ) / 1.80 ;

	}


void MainWindow::on_comboBox_3_activated(int index)
	{

	if (index == 0)
		T = ( ui -> lineEdit_2 -> text() ).toDouble() - 273.15 ;

	else if (index == 1)
		T = ( ui -> lineEdit_2 -> text() ).toDouble() ;

	else
		T = ( ( ui -> lineEdit_2 -> text() ).toDouble() - 32 ) / 1.80 ;

	}

void MainWindow::on_lineEdit_textChanged(const QString &arg1) // pressure
	{

	pressure = arg1.toDouble() ;

	}

double MainWindow::ref(double height) // calculating refraction
	{

	double A, z, z_0 ;

	A = 1.032653141e-4 * pressure * ( 1 + 0.0057 / (wl * wl) ) / ( T + 273 ) ;
	B = 1 / A ;

	z = PI * 0.5 - height ;
	z_0 = z - 0.01 ;

	for ( int c = 0; c < 20; c++ )
		z_0 = z - A * tan(z_0) ;

	if (height < 0)
		z_0 = 2 * z - z_0 ;

	return z_0 ;

	}


////   12. GRAPH    ////

void MainWindow::on_pushButton_4_clicked()
{

	double elev, azim ;
	std::string grph ;

	int h, m ; // hour, minute, day, month
	double j ;
	std::string e ; // elevation

	QDate cday ;

	// plot elevation //

	QFile elevation("/usr/local/Data/Height.txt") ;
	elevation.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text) ;

	elevation.resize(0) ;

	QTextStream output(&elevation) ;

	for (double i = -5; i <= 5; i += 0.166666666666666)
		{

		LST = date2LST(l, year, mon2, day2, UT + i) ;
		t = LST - a ;

		elev = dec2height(d, t, phi) ;

		grph = "" ;

		if (LMST + i < 0)
			{

			j = LMST + i + 24 ;

			cday = ui -> Date -> date() ;

			cday = cday.addDays(-1) ;

			h = int(j) ;
			m = int( (j - h) * 60 ) ;

			grph.append( std::to_string(cday.day()) + "-" + std::to_string(cday.month()) + "-" ) ;
			grph.append( std::to_string(cday.year()) + " " ) ;
			grph.append( std::to_string(h) + ":" + std::to_string(m) + ", " ) ;

			}

		else if (LMST + i > 24)
			{

			j = LMST + i - 24 ;

			cday = ui -> Date -> date() ;

			cday = cday.addDays(+1) ;

			h = int(j) ;
			m = int( (j - h) * 60 ) ;

			grph.append( std::to_string(cday.day()) + "-" + std::to_string(cday.month()) + "-" ) ;
			grph.append( std::to_string(cday.year()) + " " ) ;
			grph.append( std::to_string(h) + ":" + std::to_string(m) + ", " ) ;

			}

		else
			{

			h = int(LMST + i) ;
			m = int( (LMST + i - h) * 60 ) ;

			cday = ui -> Date -> date() ;

			grph.append( std::to_string(cday.day()) + "-" + std::to_string(cday.month()) + "-" ) ;
			grph.append( std::to_string(cday.year()) + " " ) ;
			grph.append( std::to_string(h) + ":" + std::to_string(m) + ", " ) ;

			}

		e = std::to_string(90 - ref(elev) * 180 / PI) ;
		std::replace( e.begin(), e.end(), ',', '.') ;

		grph.append(e) ;
		grph.append("\n") ;

		output << QString::fromStdString(grph) ;

		}

	LST = date2LST(l, year, mon2, day2, UT) ;
	t = LST - a ;
	elev = dec2height(d, t, phi) ;
	azim = hour2azm (d, elev, phi, t) ;

	QString azimuth_plot ;
	azimuth_plot = QString::number(azim) + " 1\n" ;

	output << azimuth_plot ;
	output << a * 15 << " " << d ;
	elevation.close() ;

	system("/usr/local/Data/Plot.gnu") ;

	el = new Elevation(this) ;
	azimuth = new Azimuth(this) ;
	aladin = new View(this) ;

	if (ui -> Object_name -> text() == "")
		{

		el -> setWindowTitle("Elevation of " + QString::number(a) + "  " + QString::number(d) ) ;
		azimuth -> setWindowTitle("Azimuth of " + QString::number(a) + "  " + QString::number(d) ) ;
		aladin -> setWindowTitle( QString::number(a) + "  " + QString::number(d) ) ;

		}

	else
		{

		el -> setWindowTitle("Elevation of " + ui -> Object_name -> text()) ;
		azimuth -> setWindowTitle("Azimuth of " + ui -> Object_name -> text()) ;
		aladin -> setWindowTitle( ui -> Object_name -> text() ) ;

		}

	el -> show() ;
	azimuth -> show() ;	
	aladin -> show() ;

}


////   13. CLICK MAIN BUTTON    ////

void MainWindow::on_pushButton_clicked()
{

	// maximum elevation //

    if (d <= phi )
		max_height = 90 - phi + d ; // degrees

    else
        max_height = 90 - d + phi ;

	mhd = int( max_height ) ;
	mhm = abs( (max_height - mhd) * 60 ) ;
	mhs = fmod( abs( (max_height - mhd) * 3600 - mhm * 60 ), 60.0 ) ;

	if ( (max_height < 0) and (mhd == 0) )
		ui -> max_h_deg-> setText("-" + QString::number( mhd ) ) ;

	else
		ui -> max_h_deg-> setText( QString::number( mhd ) ) ;

	ui -> max_h_m -> setText(QString::number( mhm ) ) ;
	ui -> max_h_s -> setText(QString::number( mhs, 'f', 1 ) ) ;

	// LST //

    LST = date2LST(l, year, mon2, day2, UT) ;

	L_H = int(LST) ;	// LST hour
	L_M = int( ( LST - L_H ) * 60 ) ;	// minute
	L_S = int( ( (LST - L_H) * 3600 - L_M * 60) ) ; // second

	ui -> label_7 -> setText( QString::number(L_H) ) ;	// I'm just too lazy to change label numbers to some names
    ui -> label_9 -> setText( QString::number(L_M) ) ;
	ui -> label_35 -> setText( QString::number(L_S) ) ;

	// time to/from max elevation //

	double angle = a - LST ;
	double ang_h, ang_m, ang_s ;

	if ( ( angle <= 12 && angle >= 0 ) || angle < -12 )
		{

		ui -> in_was -> setText("In") ;
		ui -> ago -> setText("") ;
		
		if(angle < 0)
			angle += 24 ;

		}

	else
		{

		ui -> in_was -> setText("Was") ;
		ui -> ago -> setText("ago") ;
		
		if(angle > 0)
			angle -= 24 ;
			
		angle = abs(angle) ;
	
		}
		
	angle /= 1.0027379093382884 ; // angle was in sidereal time and we want solar time
				
	ang_h = int(angle) ;
	ang_m = int( (angle - ang_h) * 60) ;
	ang_s = int( (angle - ang_h) * 3600 - ang_m * 60 ) ;

	ui -> t_h -> setText( QString::number( ang_h ) ) ;
	ui -> t_m -> setText( QString::number( ang_m ) ) ;
	ui -> t_s -> setText( QString::number( ang_s ) ) ;

	// azimuth and elevation //
	
	t = LST - a ;

	if (t < 0)
		t += 24 ;

	h = dec2height(d, t, phi) ;
	A = hour2azm (d, h, phi, t) ;
	elevation = h * 180 / PI ;

	c_h_d = int(elevation) ;
	c_h_m = abs( int( (elevation - c_h_d) * 60 ) ) ;
	c_h_s = fmod( abs( (elevation - c_h_d) * 3600 - c_h_m * 60 ), 60.0 ) ;

	if ( (h < 0) and (c_h_d == 0) )
		ui -> label_20 -> setText( "-" + QString::number( c_h_d ) ) ;

	else
		ui -> label_20 -> setText( QString::number( c_h_d ) ) ;

	ui -> label_22 -> setText( QString::number( c_h_m ) ) ;
	ui -> label_46 -> setText( QString::number( c_h_s, 'f', 1 ) ) ;

	ui -> label_25 -> setText( QString::number( int(A) ) ) ;
	ui -> label_27 -> setText( QString::number( int( ( A - int(A) ) * 60 ) ) ) ;

	// refraction //

	double R = 90 - ref(h) * 180 / PI ;

	c_h_d = int(R) ;
	c_h_m = abs( int( (R - c_h_d) * 60 ) ) ;
	c_h_s = fmod( abs( (R - c_h_d) * 3600 - c_h_m * 60 ), 60.0 ) ;

	if ( (R < 0) and (c_h_d == 0) )
		ui -> ref_deg -> setText( "-" + QString::number( c_h_d ) ) ;

	else
		ui -> ref_deg -> setText( QString::number( c_h_d ) ) ;

	ui -> ref_min -> setText( QString::number( c_h_m ) ) ;
	ui -> ref_sec -> setText( QString::number( c_h_s, 'f', 1 ) ) ;

	double R_max = 90 - ref(max_height * PI / 180) * 180 / PI ;

	mhd = int( R_max ) ;
	mhm = abs( (R_max - mhd) * 60 ) ;
	mhs = fmod( abs( (R_max - mhd) * 3600 - mhm * 60 ), 60.0 ) ;

	if ( (R_max < 0) and (mhd == 0) )
		ui -> max_ref_d-> setText("-" + QString::number( mhd ) ) ;

	else
		ui -> max_ref_d-> setText( QString::number( mhd ) ) ;

	ui -> max_ref_m -> setText(QString::number( mhm ) ) ;
	ui -> max_ref_s -> setText(QString::number( mhs, 'f', 1 ) ) ;

	// galactic coordinates //

	B = p2B(d, a, dG, aG) ;
	L = p2L(d, a, dG, aG, theta, B) ;

	ui -> galactic_b -> setText( QString::number(B * 180 / PI, 'f', 4) ) ;
	ui -> galactic_l -> setText( QString::number(L * 180 / PI, 'f', 4) ) ;

}


////   14. LOAD CITIES    ////

void MainWindow::on_Box_country_currentTextChanged(const QString &arg1)
{

	ui -> Box_city -> clear() ;

	std::string path = "/usr/local/Data/Observatories/" ;
	path.append(arg1.toStdString()) ;

	std::ifstream muhfile ;
	muhfile.open(path) ;

	if (muhfile.is_open())
		{

		std::string line, city ;
		std::size_t pos ;

		while (getline(muhfile, line))
			{

			pos = line.find(",") ;
			city = line.substr(0, pos) ;
			ui -> Box_city -> addItem(QString::fromStdString(city)) ;

			}

		muhfile.close();

		}

}

////    15. COUNTRIES AND CITIES    ////

void MainWindow::on_Box_city_currentTextChanged(const QString &arg1)
{

	std::string country, city, part, dl, sz, alt ;
	std::string path = "/usr/local/Data/Observatories/" ;
	QString qs = ui -> Box_country -> currentText() ;

	country = qs.toStdString() ;
	city = arg1.toStdString() ;
	path.append(country) ;

	std::ifstream muhfile ;
	muhfile.open(path) ;

	if (muhfile.is_open())
		{

		std::size_t pos, com_1, com_2 ;

		while (getline(muhfile, line))
			{

			pos = line.find(city) ;

			if (pos != std::string::npos)
				{

				com_1 = line.find(",") ;
				part = line.substr(com_1+1) ;
				com_2 = part.find(",") ;

				sz = part.substr(0, com_2) ; // latitude

				com_1 = part.find(",") ;
				part = part.substr(com_1+1) ;
				com_2 = part.find(",") ;

				dl = part.substr(0, com_2) ; // longitude

				com_1 = part.find(",") ;
				part = part.substr(com_1+1) ;


				alt = part.substr(0, com_2) ; // altitude

				ui -> alt -> setText( QString::fromStdString(alt) ) ;
				ui -> lat -> setText( QString::fromStdString(sz) ) ;
				ui -> lon -> setText( QString::fromStdString(dl) ) ;

				}

			}

		muhfile.close();

		}

}


////   16. FIND OBJECT    ////

void MainWindow::on_pushButton_3_clicked() // Look up object in simbad, check coordinates and steal them
{

	object = ui -> Object_name -> text() ;	// object name from gui

	object.replace("+", "%2B") ; // %2B is + in name of object in simbad url
	object.replace(' ', '+') ;

	// Download query //

	QString urly ;

	urly = "http://simbad.u-strasbg.fr/simbad/sim-script?submit=submit+script&script=output+script%3Doff%0D%0Aoutput+console%3Doff%0D%0A%0D%0Aformat+object+\"%25COO(A+D)+|%25OTYPE(S)|%25PM(A+D)|\"%2B%0D%0A\"%25RV(V)|%25PLX(V)|%25SP(S)|%25FLUXLIST(U%2CB%2CV%2CR%2CI%2CJ%2CH%2CK%3B+N+F%2C)\"%0D%0A%0D%0Aid+" ;
	urly += object ;

	QNetworkAccessManager manager;
	QNetworkReply *response = manager.get(QNetworkRequest(QUrl(urly)));
	QEventLoop event;
	connect(response,SIGNAL(finished()),&event,SLOT(quit()));
	event.exec();
	QString html = response->readAll(); // Source should be stored here

	FillData( html.toStdString() ) ;

}


// Fill data like parallax, cords, type etc

void MainWindow::FillData(std::string star)
{

	std::size_t found = star.find("|") ;

	if (found != std::string::npos)
		{

		std::size_t pos = star.find(" ") ;
		ui -> ra_h -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
		star.erase(0, pos + 1) ;

		if ( (star[0] != '+') && (star[0] != '-'))
			{
			pos = star.find(" ") ;
			ui -> ra_m -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> ra_m -> setText("0") ;

		if ( (star[0] != '+') && (star[0] != '-'))
			{
			pos = star.find(" ") ;
			ui -> ra_s -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> ra_s -> setText("0") ;

		pos = star.find(" ") ;
		ui -> dec_deg -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
		star.erase(0, pos + 1) ;

		if (star[0] != '|')
			{
			pos = star.find(" ") ;
			ui -> dec_min -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> dec_min -> setText("0") ;

		if (star[0] != '|')
			{
			pos = star.find(" ") ;
			ui -> dec_sec -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
			}

		else
			ui -> dec_sec -> setText("0") ;

		pos = star.find("|") ;
		star.erase(0, pos + 1) ;

		pos = star.find("|") ;
		ui -> type -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;

		pos = star.find("|") ;
		star.erase(0, pos + 1) ;

		pos = star.find(" ") ;
		ui -> prop_mot_a -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
		star.erase(0, pos + 1) ;

		pos = star.find("|") ;
		ui -> prop_mot_d -> setText( QString::fromStdString( star.substr(1, pos - 1) ) ) ;
		star.erase(0, pos + 1) ;

		pos = star.find("|") ;
		ui -> rad_vel -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
		star.erase(0, pos + 1) ;

		pos = star.find("|") ;
		ui -> parallax -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
		star.erase(0, pos + 1) ;

		pos = star.find("|") ;
		ui -> spec_type -> setText( QString::fromStdString( star.substr(0, pos) ) ) ;
		star.erase(0, pos + 1) ;

		if(star[0] == 'U')
			{
			pos = star.find(",") ;
			ui -> f_U -> setText( QString::fromStdString( star.substr(2, pos - 2) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> f_U -> setText( "~" ) ;

		if(star[0] == 'B')
			{
			pos = star.find(",") ;
			ui -> f_B -> setText( QString::fromStdString( star.substr(2, pos - 2) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> f_B -> setText( "~" ) ;

		if(star[0] == 'V')
			{
			pos = star.find(",") ;
			ui -> f_V -> setText( QString::fromStdString( star.substr(2, pos - 2) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> f_V -> setText( "~" ) ;


		if(star[0] == 'R')
			{
			pos = star.find(",") ;
			ui -> f_R -> setText( QString::fromStdString( star.substr(2, pos - 2) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> f_R -> setText( "~" ) ;


		if(star[0] == 'I')
			{
			pos = star.find(",") ;
			ui -> f_I -> setText( QString::fromStdString( star.substr(2, pos - 2) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> f_I -> setText( "~" ) ;

		if(star[0] == 'J')
			{
			pos = star.find(",") ;
			ui -> f_J -> setText( QString::fromStdString( star.substr(2, pos - 2) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> f_J -> setText( "~" ) ;

		if(star[0] == 'H')
			{
			pos = star.find(",") ;
			ui -> f_H -> setText( QString::fromStdString( star.substr(2, pos - 2) ) ) ;
			star.erase(0, pos + 1) ;
			}

		else
			ui -> f_H -> setText( "~" ) ;


		}

	else
		{

		QMessageBox::warning(this, "Object not found",
		"No such object was found. Please check again.") ;

		}

}

////   17. OPTIONS    ////

void MainWindow::on_actionAdd_observatory_triggered()
{
		opt_new_obs = new Options_new_obs(this) ;
		opt_new_obs -> show() ;
}



////   18. SAVED OBJECTS   ////

// save object //

void MainWindow::on_save_object_clicked()
{

	QString object ;


	object = ui -> Object_name -> text() ;

	object.replace(" ", "_") ;

	if(object == 0)
		object = "Position" ;

	object += "    " ;
	object += ui -> ra_h -> text() ;
	object += " " ;
	object += ui -> ra_m -> text() ;
	object += " " ;
	object += ui -> ra_s -> text() ;

	object += "    " ;
	object += ui -> dec_deg -> text() ;
	object += " " ;
	object += ui -> dec_min -> text() ;
	object += " " ;
	object += ui -> dec_sec -> text() ;

	ui -> listWidget -> addItem(object) ;

	object += " |" + ui -> type -> text() + "|" ;
	object += ui -> prop_mot_a -> text() + "  " ;
	object += ui -> prop_mot_d -> text() + "|" ;
	object += ui -> rad_vel -> text() + "|" ;
	object += ui -> parallax -> text() + "|" ;
	object += ui -> spec_type -> text() + "|" ;

	if (ui -> f_U -> text() != "~")
		object += "U " + ui -> f_U -> text() + "," ;

	if (ui -> f_B -> text() != "~")
		object += "B " + ui -> f_B -> text() + "," ;

	if (ui -> f_V -> text() != "~")
		object += "V " + ui -> f_V -> text() + "," ;

	if (ui -> f_R -> text() != "~")
		object += "R " + ui -> f_R -> text() + "," ;

	if (ui -> f_I -> text() != "~")
		object += "I " + ui -> f_I -> text() + "," ;

	if (ui -> f_J -> text() != "~")
		object += "J " + ui -> f_J -> text() + "," ;

	if (ui -> f_H -> text() != "~")
		object += "H " + ui -> f_H -> text() + "," ;


	QFile file("/usr/local/Data/saved.txt") ;

	file.open(QFile::WriteOnly | QFile::Text | QFile::Append) ;

	QTextStream out(&file) ;
	out << object ;
	out << "\n" ;

	file.flush() ;
	file.close() ;


}


// remove object //

void MainWindow::on_delete_object_clicked()
{

	int n, len ;
	n = ui -> listWidget -> currentRow() ;
	len = ui -> listWidget -> count() ;

	ui -> listWidget -> takeItem(n) ;

	QFile file("/usr/local/Data/saved.txt") ;

	QString loaded, st ;

	file.open(QFile::ReadWrite | QFile::Text) ;

	QTextStream in(&file) ;

	for (int i = 0; i < len; i++)
		{

		loaded = in.readLine() ;

		if (i != n)
			st.append(loaded + "\n") ;

		}

	file.resize(0) ;

	in << st ;

	file.flush() ;
	file.close() ;
}


// load object //

void MainWindow::on_pushButton_6_clicked()
{

	int numsel ;

	numsel = ui -> listWidget->currentRow() ;

	QFile file("/usr/local/Data/saved.txt") ;

	QString loaded, obj ;

	file.open(QFile::ReadOnly | QFile::Text) ;

	QTextStream in(&file) ;

	for (int i = 0; i < numsel; i++)
		in.readLine() ;

	loaded = in.readLine() ;

	file.flush() ;
	file.close() ;

	numsel = loaded.indexOf(" ") ;

	obj = loaded.left(numsel) ;

	if (obj != "Position")
		{

		obj.replace("_", " ") ;
		ui -> Object_name -> setText(obj) ;

		}

	loaded.remove(0, numsel + 4) ;
	loaded.replace("    ", " ") ;

	FillData( loaded.toStdString() ) ;

}


void MainWindow::on_clear_clicked()
{

	ui -> type -> setText("~") ;
	ui -> spec_type -> setText("~") ;
	ui -> parallax -> setText("~") ;
	ui -> rad_vel -> setText("~") ;
	ui -> prop_mot_a -> setText("~") ;
	ui -> prop_mot_d -> setText("~") ;
	ui -> f_U -> setText("~") ;
	ui -> f_B -> setText("~") ;
	ui -> f_V -> setText("~") ;
	ui -> f_R -> setText("~") ;
	ui -> f_I -> setText("~") ;
	ui -> f_J -> setText("~") ;
	ui -> f_H -> setText("~") ;
	ui -> Object_name -> setText("") ;

}


////    THAT'S ALL FOR NOW      ////



/*

         _nnnn_
        dGGGGMMb
       @p~qp~~qMb
       M|@||@) M|
       @,----.JM|
      JS^\__/  qKL
     dZP        qKRb
    dZP          qKKb
   fZP            SMMb
   HZM            MMMM
   FqM            MMMM
 __| ".        |\dS"qML
 |    `.       | `' \Zq
_)      \.___.,|     .'
\____   )MMMMMP|   .'
     `-'       `--'


*/





