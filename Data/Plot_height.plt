#!/usr/bin/gnuplot

set xdata time
set timefmt '%d/%m %H:%M'

set xtics format "%H:%M\n%d/%m"

set datafile separator ","

set ylabel "Height [°]"
set xlabel "Time"

plot 'Height.txt' using 1:2 with lines

pause -1
