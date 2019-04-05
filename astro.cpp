#include <iostream>
#include <cmath>

#define PI 3.1415926536  
#define k 1.002737909

/*////////////////////////////////////////////////////////////////////////
//									//
//      d       - declination						//
//      t       - star's hour angle					//
//      phi     - latitiude						//
//      h       - horizontal height					//
//      A       - Azumuth						//
//      a       - rectascence                   For now does nothing	//
//      GST     - Greenwich siderial time       For now does nothing	//
//	GMST    - Geenwhich midnight si time    -||-			//
//      l       - LST = GST + l                 -||-			//
//      UT      - Universal time                -||-			//
//      k       - kappa                         -||-			//
//									//
//      year:								//
//      month:								//
//      day:								//
//      ^based on these we can calculate 				//
//									//
//      LST = GST + l ;							//
//      t = LST - a ;							//
//									//
//	because								//
//									//
//      n_o = 24 / 365.242189						//
//      GST = n_o * dt							//
//									//
//      dt must be in days						//
//									//
//      where								//
//									//
//      dt = T - T_0            T_0 is equinox day in scale		//
//      GST = UT                then					//
//									//
//      now implement this shit						//
//									//
*/////////////////////////////////////////////////////////////////////////

using namespace std ;



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



int main()
	{

	double d, t, phi, h, A, GMST, UT, GST, LST, l, a ;

	cout << "\nInput declination in °: " ;
	cin >> d ;	

	cout << "Input rectastence in h: "
	cin >> a ;

        cout << "Input GMT in h: " ;
        cin >> GMST ;			// I could use GST BUT it will be usefull later

	cout << "Input time of observation UT in h: " ;
	cin >> UT ; 

	cout << "longitude in °:" ;
	cin >> l ;

	cout << "Input latitude in °: " ;
	cin >> phi ;

	l = l / 15 ;
	LST = GMST + UT * k + l ;
	t = LST - a ;

	h = dec2height(d, t, phi) ;
	A = hour2azm (d, h, phi, t) ;

	cout << "\nHeight: " << h << "°\n" ;
	cout << "SMART's Azimuth: " << A << "°\n\n" ;

	return 0 ;

	}
