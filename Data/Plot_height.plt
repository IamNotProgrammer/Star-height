#!/usr/bin/gnuplot

set grid
set xdata time
set timefmt '%d/%m %H:%M'

set xtics format "%H:%M\n%d/%m"

set datafile separator ","

set ylabel "Height °"
set xlabel "Local Time\nDay/Month"

set arrow from graph 0.5, graph 0 to graph 0.5, graph 1 nohead
set yrange [*<-10 : 10<*]

plot '/usr/local/Data/Height.txt' using 1:2 with lines title "Height in °", 0 title "Horizon"

pause -1
