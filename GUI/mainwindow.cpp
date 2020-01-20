#include "mainwindow.h"
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


////    CHANGE RECTASTENCE  ////

void MainWindow::on_ra_h_textChanged(const QString &arg1)	// right ascention hours
{
    re_h = arg1.toInt() ;
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

////    CHANGE LONGITUDE    ////

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

////    CHANGE LATITUDE     ////

void MainWindow::on_lat_textChanged(const QString &arg1)
{
    phi = arg1.toDouble() ;
}

////    LOCAL AND UNIVERSAL TIME    ////

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

////    CHANGE DATE TO LST      ////

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

		h = h * PI / 180 ;	// radian masetrace
        dec = dec * PI / 180 ;
        phi = phi * PI / 180 ;
        t = t * PI / 12 ;


        C_A = (  sin(h) * cos(phi) - cos(dec) * cos(t) ) / ( cos(h) * sin(phi)  ) ;
        A = acos(C_A) * 180 / PI ;
		A = int(A * 1e4) / 1e4 ;	// I forgot what it does but it does something

        if (t > PI)
                A = fmod(360 - A, 360) ;

        return A ;

        }

////	GALACTIC COORDINATES	////


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



/*
void graph()
    {

     system("/usr/local/Data/Plot_height.plt") ;

    }
*/


//// SET CURRENT TIME ////

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

////    CLICK BUTTON    ////

void MainWindow::on_pushButton_clicked()
{

	//// maximum elevation ////

    if (d <= phi )
        max_height = 90 - phi + d ;

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



	//// LST ////

    LST = date2LST(l, year, mon2, day2, UT) ;

	L_H = int(LST) ;	// LST hour
	L_M = int( ( LST - L_H ) * 60 ) ;	// minute
	L_S = int( ( (LST - L_H) * 3600 - L_M * 60) ) ; // second

	ui -> label_7 -> setText( QString::number(L_H) ) ;	// I'm just too lazy to change label numbers to some names
    ui -> label_9 -> setText( QString::number(L_M) ) ;
	ui -> label_35 -> setText( QString::number(L_S) ) ;


	//// azimuth and elevation ////

    t = LST - a ;
    h = dec2height(d, t, phi) ;
    A = hour2azm (d, h, phi, t) ;

	c_h_d = int(h) ;
	c_h_m = abs( int( (h - c_h_d) * 60 ) ) ;
	c_h_s = fmod( abs( (h - c_h_d) * 3600 - c_h_m * 60 ), 60.0 ) ;

	if ( (h < 0) and (c_h_d == 0) )
		ui -> label_20 -> setText( "-" + QString::number( c_h_d ) ) ;

	else
		ui -> label_20 -> setText( QString::number( c_h_d ) ) ;

	ui -> label_22 -> setText( QString::number( c_h_m ) ) ;
	ui -> label_46 -> setText( QString::number( c_h_s, 'f', 1 ) ) ;

    ui -> label_25 -> setText( QString::number( int(A) ) ) ;
    ui -> label_27 -> setText( QString::number( int( ( A - int(A) ) * 60 ) ) ) ;


	////    TIME TO/FROM MAX ELEVATION     ////

    if (t < 0 or t > 12 )
        {

        ui -> in_was -> setText("In") ;
        ui -> ago -> setText("") ;

        if (t < 0)
            {

            t_r = abs(t) ;
			ui -> t_h -> setText( QString::number(int(t_r)) ) ;
			ui -> t_m -> setText( QString::number( int( ( t_r - int(t_r) ) * 60 ) ) ) ;
			ui -> t_s -> setText( QString::number( int( ( ( t_r - int(t_r) ) * 60 - int( ( t_r - int(t_r) ) * 60 ) ) * 60 ) ) ) ;

            }

        else
            {

            t_r = 24 - t ;
			ui -> t_h -> setText( QString::number(int(t_r)) ) ;
			ui -> t_m -> setText( QString::number( int( ( t_r - int(t_r) ) * 60 ) ) ) ;
			ui -> t_s -> setText( QString::number( int( ( ( t_r - int(t_r) ) * 60 - int( ( t_r - int(t_r) ) * 60 ) ) * 60 ) ) ) ;

            }

        }

    else
        {

        ui -> in_was -> setText("Was") ;
        ui -> ago -> setText("ago") ;
		ui -> t_h -> setText( QString::number(int(t)) ) ;
		ui -> t_m -> setText( QString::number( int( ( t - int(t) ) * 60 ) ) ) ;
		ui -> t_s -> setText( QString::number( int( ( ( t_r - int(t_r) ) * 60 - int( ( t_r - int(t_r) ) * 60 ) ) * 60 ) ) ) ;

        }

//	test() ;
	//// GALACTIC COORDINATES ////

	B = p2B(d, a, dG, aG) ;
	L = p2L(d, a, dG, aG, theta, B) ;

	ui -> galactic_b -> setText( QString::number(B * 180 / PI, 'f', 4) ) ;
	ui -> galactic_l -> setText( QString::number(L * 180 / PI, 'f', 4) ) ;

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


void MainWindow::on_Box_city_currentTextChanged(const QString &arg1)
{

	std::string country, city, part, dl, sz ;
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

//		std::cout << "here 1" << "\n" ;

		while (getline(muhfile, line))
			{

			pos = line.find(city) ;

			if (pos != std::string::npos)
				{

				com_1 = line.find(",") ;
				part = line.substr(com_1+1) ;
				com_2 = part.find(",") ;

				sz = line.substr(com_1+1, com_2) ; // szerokość
				dl = line.substr(com_1+com_2+2) ; // długość

				ui -> lat -> setText( QString::fromStdString(sz) ) ;
				ui -> lon -> setText( QString::fromStdString(dl) ) ;

				}

			}

		muhfile.close();

		}

}

void MainWindow::on_pushButton_3_clicked() // Look up object in simbad, check coordinates and steal them
{

	int space = 0 ;
	int n ;

	object = ui -> Object_name -> text() ;	// object name from gui
	url = object.toStdString() ;
	url.erase( remove_if( url.begin(), url.end(), isspace ), url.end() ) ;  // I don't know what it does

	command.append("wget -O /usr/local/Data/object.txt http://simbad.u-strasbg.fr/simbad/sim-basic?Ident=") ;	// make command
	command.append(url) ;
	command.append("\\&submit=SIMBAD+search") ;

	system(command.c_str()) ;

	command = "" ;	// clear command because it was just adding more and more url's


	star = cmd_out("grep -A 9 'coord\\.' /usr/local/Data/object.txt | head -n 10 | tail -n 1") ;

	std::size_t found = star.find("grey") ;

	if (found != std::string::npos) // get rid of gray text if there is any
		{

		n = star.length() ;
		star.erase(n-71, 72) ;

		while (true)
			{

			std::size_t delet_1 = star.find("<") ;
			std::size_t delet_2 = star.find(">") ;

			if (delet_1 != std::string::npos)
				star.erase(delet_1, delet_2 - delet_1 + 1) ;

			else
				break ;

			}

		}

	std::size_t pos = star.find("+") ;
	std::size_t apos = star.find("-") ;

	n = star.length() ;

	if (apos != std::string::npos) // if dec is positive it's negative
		pos = apos ;

	for (int i = 0; i < pos ; i++) // hoe many spaces in string "star"
		{

		if (star.at(i) == ' ')
			space++ ;

		}

	if (space == 3) //////////////// change values of right assecion /////////////////
		{

		ui -> ra_h -> setText( QString::fromStdString( star.substr(0, 2) ) ) ;
		ui -> ra_m -> setText( QString::fromStdString( star.substr(3, 2) ) ) ;
		ui -> ra_s -> setText( QString::fromStdString( star.substr(6, pos-7) ) ) ;

		}


	else if (space == 2)
		{

		ui -> ra_h -> setText( QString::fromStdString( star.substr(0, 2) ) ) ;
		ui -> ra_m -> setText( QString::fromStdString( star.substr(3, pos-4) ) ) ;
		ui -> ra_s -> setText( QString::number(0) ) ;

		}

	else
		{

		ui -> ra_h -> setText( QString::fromStdString( star.substr(0, pos-1) ) ) ;
		ui -> ra_m -> setText( QString::number(0) ) ;
		ui -> ra_s -> setText( QString::number(0) ) ;

		} /////////////////////////////////////////////////////////////////////////////////

	space = 0 ;

	for (int i = pos; i < n ; i++) /////////////// change values of declination ////////////
		{

		if (star.at(i) == ' ')
			space++ ;

		}

	if (space == 2)
		{

		ui -> dec_deg -> setText( QString::fromStdString( star.substr(pos, 3) ) ) ;
		ui -> dec_min -> setText( QString::fromStdString( star.substr(pos+4, 3) ) ) ;
		ui -> dec_sec -> setText( QString::fromStdString( star.substr(pos+7, n-pos-7) ) ) ;

		}

	else if (space == 1)
		{

		ui -> dec_deg -> setText( QString::fromStdString( star.substr(pos, 3) ) ) ;
		ui -> dec_min -> setText( QString::fromStdString( star.substr(pos+4, n-pos-4) ) ) ;
		ui -> dec_sec -> setText( QString::number(0) ) ;

		}

	else
		{

		ui -> dec_deg -> setText( QString::fromStdString( star.substr(pos, n-pos) ) ) ;
		ui -> dec_min -> setText( QString::number(0) ) ;
		ui -> dec_sec -> setText( QString::number(0) ) ;

		} /////////////////////////////////////////////////////////////////////////////////

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




