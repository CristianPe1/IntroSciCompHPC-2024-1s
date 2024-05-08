set term pdf size 3in,3in font "Times New Roman,10"
set out "Weak Scaling with OpenMP.pdf"
set title "Weak Scaling with OpenMP"

set xlabel "nThreads"
set ylabel "SpeedUp"
set title "SpeedUp"

set xrange [0:8];
set yrange [0:8];

plot x lc "black" notitle, \
	 "metrics.txt" using 1:2 pt 5 ps 0.5 dt 2 lc "green" title 'SpeedUp'

set xlabel "nThreads"
set ylabel "Eficiencia"
set title "Efficiency"

set xrange [0:8];
set yrange [0:1.01];

plot 1 lc "red" notitle, \
	 0.6 lc "blue" notitle, \
	 "metrics.txt" using 1:3 pt 5 ps 0.5 dt 2 lc "green" title 'Efficiency'

unset output