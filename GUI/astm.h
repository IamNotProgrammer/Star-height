#ifndef ASTM_H
#define ASTM_H

double JDg(int, int, int, int, int, int) ; // Julian day for gregorian callendar. Fuck people who don't use it

double d_d(int, int, int, int, int, int, int, int, int, int, int, int) ; // difference between 2 dates (initial: year, month,
									// day, hour, minute, second
									// final: year, month etc.)
									// Also works backwards i.e. first year 2000 final year 1840

double GMST(int, int, int, int, int, int) ; 				// Greenwich medium siderial time. Input current year, month,
									// day, hour, minute, second 


#endif /* ASTM_H */
