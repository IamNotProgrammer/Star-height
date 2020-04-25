#!/usr/bin/gnuplot

set term pngcairo size 960, 720 font ",14"
set output "/usr/local/Data/Images/area.png"
unset key

set border linecolor "#5E610B"
set style line 12 lc rgb "#2E2E2E"

file = '/usr/local/Data/area.txt'

set datafile separator "|"

stats file every ::::1 nooutput
a = STATS_min_x
b = STATS_min_y

set yrange [a - 0.5:a + 0.5]
set xrange [b - 0.033333333: b + 0.033333333]

set ylabel "dec [°]" tc rgb "red"
set xlabel "ra [h]" tc rgb "red"

plot file every ::1 using ($3 * 0.066666666666):2:(5 - $4 * 0.4) \
w points pt 7 ps variable
