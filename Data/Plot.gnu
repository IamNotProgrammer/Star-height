#!/usr/bin/gnuplot

set term pngcairo size 960, 720 font ",14"
set output "/usr/local/Data/Images/elevation.png"

unset key
set datafile separator ","

fmt = "%d-%m-%Y %H:%M"
stats '/usr/local/Data/Height.txt' u (strptime(fmt,strcol(1))):2 nooutput

set timefmt "%d-%m-%Y %H:%M"
set xdata time

a = STATS_min_y - 10
b = STATS_max_y + 10

set xrange [STATS_min_x:STATS_max_x]
set yrange [a:b]

set border linecolor "#5E610B"
set object 1 rect from screen 0, 0 to screen 1, 1 fc rgb "#0B0B3B" behind
set object 2 rect from graph 0, first 0 to graph 1, 0 fc rgb "#006E00" behind

set format x "%H:%M\n%d/%m"

set style line 12 lc rgb "#2E2E2E"
set grid ls 12

set ylabel "Elevation [°]" tc rgb "red"
set xlabel "Date and time" tc rgb "red"

plot "/usr/local/Data/Height.txt" every ::0::61 using 1:2 with lines lc rgb "red", \
"/usr/local/Data/Height.txt" every ::30::30 using 1:2 with points pt 3 ps 2.5 lc rgb "yellow"

reset

set term pngcairo size 800, 800 font ",14"
set output "/usr/local/Data/Images/azimuth.png"

unset key
unset border

set tmargin 4
set bmargin 4
set rmargin 4
set lmargin 4

stats "/usr/local/Data/Height.txt" every ::61::61 using 1:2 nooutput

set polar
set size square
set angles degrees
set style line 12 lc rgb "#2E2E2E"
set grid polar 20 ls 12
set border polar linecolor "#5E610B"
set ttics 0, 20 format "%g".GPVAL_DEGREE_SIGN
set mttics 4
set theta top
set rrange [0:2]
set object rect from screen 0, 0 to screen 1, 1 fc rgb "#0B0B3B" behind

unset xtics
unset ytics
unset rtics
unset raxis

set arrow from 0, 0 to polar STATS_min_x, 2 lc rgb "red" nohead

set label "N" at screen 0.5, 0.96 center tc rgb "red" font ", 20"
set label "E" at screen 0.96, 0.5 center tc rgb "red" font ", 20"
set label "S" at screen 0.5, 0.04 center tc rgb "red" font ", 20"
set label "W" at screen 0.04, 0.5 center tc rgb "red" font ", 20"

plot 0.6666666 ls 12, 1.33333333 ls 12, \
"/usr/local/Data/Height.txt" every ::61::61 using 1:2 with points pt 3 ps 2.5 lc rgb "yellow"







