#!/usr/bin/gnuplot

set xdata time
set timefmt '%d/%m %H:%M'

set datafile separator ","

plot 'Height.txt' using 1:2 with lines

pause -1
