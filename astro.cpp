#include <iostream>
#include <cmath>

#define PI 3.1415926536  
#define k 1.002737909

/*////////////////////////////////////////////////////////////////////////
//									//
//      d       - declination						//
//      a       - rectascence                   			//
//      t       - star's hour angle					//
//      phi     - latitiude						//
//      l       - longitude               				//
//      h       - horizontal height					//
//      A       - Azumuth						//
//      UT      - Universal time                			//
//      LST 	- Local siderial time					//
//      k       - kappa                         			//
//									//
*/////////////////////////////////////////////////////////////////////////

using namespace std ;

float date2LST(float l) ;
double dec2height (double dec, double t, double phi) ;
double hour2azm (double dec, double h, double phi, double t) ;

int main()
	{

	double d, t, phi, h, A, UT, LST, l, a ;

	cout << "\nInput declination in °: " ;
	cin >> d ;	

	cout << "Input rectastence in h: " ;
	cin >> a ;
	
	cout << "Input latitude in °: " ;
	cin >> phi ;
	
	cout << "longitude in °:" ;
	cin >> l ;

	l /= 15 ;
	LST = date2LST(l) ;
	t = LST - a ;

	h = dec2height(d, t, phi) ;
	A = hour2azm (d, h, phi, t) ;

	cout <<	"\nSMART's Azimuth\n" ;
	cout <<	"                 N\n\n" ;                 
                 
	cout <<	"              #######\n" ;
	cout <<	"           #\\    |     #\n" ;
	cout <<	"        #    \\   |        #\n" ;
	cout << "       #      \\ A|         #\n" ;
	cout << "      #        \\ |          #\n" ;
	cout << " W   #          \\|           #  E\n" ;
	cout << "      #                     #\n" ;
	cout << "       #                   #\n" ;
	cout << "         #               #\n" ;
	cout << "           #          #\n" ;
	cout << "              #######\n\n" ;
		
	cout << "                 S\n" ;
	cout << "A - Azimuth\n" ;
	cout << "N - North\n" ;
	cout << "E - East etc.\n" ;

        cout << "\nHeight: " << h << "°\n" ;
        cout << "SMART's Azimuth: " << A << "°\n\n" ;

	return 0 ;

	}




double dec2height (double dec, double t, double phi)
	{
	
	double h ; 	// height
	double S_h ; 	// sin h

	t = t * PI / 12 ;
	dec = dec * PI / 180 ;
	phi = phi * PI / 180 ;	

	S_h = sin(phi) * sin(dec) + cos(phi) * cos(dec) * cos(t) ;
	h = asin(S_h) * 180 / PI ;
	h = int(h * 1e4) / 1e4 ;

	return h ;

	}




double hour2azm (double dec, double h, double phi, double t)
	{
	
	double A ;	// azimuth
	double C_A ;	// cos A

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




float date2LST(float l)
	{
	
	int month[12] ;
	int mon1, day1, mon2, day2, dd, year ;
	float hour_S, hour, a_a, LST ;	// hour_S equinox time, a_a is average alpha
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

	cout << "input year: " ;
	cin >> year ;

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

        cout << "Input month: " ;
        cin >> mon2 ;

        cout << "Input day: " ;
        cin >> day2 ;

	cout << "Input hour in UT: " ;
	cin >> hour ;

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
