#!/usr/bin/gnuplot

set term x11
#set output "./Images/elevation.png"

unset key
set datafile separator ","

fmt = "%d/%m %H:%M"
stats 'Height.txt' u (strptime(fmt,strcol(1)))

set timefmt "%d/%m %H:%M"
set xdata time

set xrange [STATS_min:STATS_max]

set format x "%H:%M\n%d/%m"
set grid

plot "Height.txt" using 1:2

pause -1
