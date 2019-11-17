#!/usr/bin/gnuplot

set grid
set xdata time
set timefmt '%d/%m %H:%M'

set xtics format "%H:%M\n%d/%m"
set xrange []

set datafile separator ","

set xlabel "Local Time\nDay/Month"

set yrange [*<-10 : 10<*]

set object 1 rectangle from graph 0, first 0 to graph 1, 0 fs solid 0.1 fc rgb "green" behind

plot '~/Star-height/Data/Height.txt' using 1:2 with lines title "Elevation", 0 notitle

pause -1
