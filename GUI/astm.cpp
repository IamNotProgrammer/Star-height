#include "astm.h"
#include <ctime>
#include <math.h>

double JDg(int y, int m, int d, int h, int mi, int s)
	{

	double JDN, JD ;

	JDN = ( 1461 * ( y + 4800 + (m-14) / 12 ) ) * 0.25 + ( 367 * ( m - 2
		- 12 * ( (m - 14) / 12 ) ) ) / 12 - ( 3 * ( ( y + 4900
		+ (m-14) / 12 ) * 0.01 ) ) * 0.25 + d - 32075 ;

	JD = JDN + (h - 12) / 24 + m / 1440 + s / 86400 ;

	if (h < 12)
		JD += 1 ;

	return JD ;

	}

double d_d(int y0, int m0, int d0, int h0, int mi0, int s0, int y, int m, int d, int h, int mi, int s)
	{

	struct std::tm a = { s0, mi0, h0, d0, m0 - 1, y0 - 1900 } ;

	struct std::tm b = { s, mi, h, d, m - 1, y - 1900 } ;

	std::time_t x = std::mktime(&a);

	std::time_t z = std::mktime(&b);

	long double difference = std::difftime(z, x) * 0.000011574074074074073 ;

	return difference ;

	}

double GMST(int y, int m, int d, int h, int mi, int s)
	{

	double d, T, gmst ;

	d = JDg(y, m, d, h, mi, s) - 2451545.0 ;
	T = d / 36525 ;

	gmst = 24110.54841 + 8640184.812866 * T + 0.093104 * T * T
		- 0.0000063 * T * T * T ;

	return gmst ;

	}

