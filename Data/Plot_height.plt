#!/usr/bin/gnuplot

set grid
set xdata time
set timefmt '%d/%m %H:%M'

set xtics format "%H:%M\n%d/%m"

set datafile separator ","

set ylabel "Height °"
set xlabel "Time UT\nDay/Month"

plot './Data/Height.txt' using 1:2 with lines title "Height in °", 0 title "Horizon"

pause -1
