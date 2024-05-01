# # Archivo gp para graficar los resultados de la estimación de 
# # tiempo de compilación vs. número de procesadores (escalamiento debil)
# set terminal pngcairo enhanced font 'Verdana,10'
# set output 'Metrics Weak Scaling.pdf'

# # Etiquetas y título del gráfico
# set title "Tiempo de compilación vs. Numero de procesadores"
# set xlabel "Numero de procesadores"
# set ylabel "Tiempo de compilación (s)"

# # Rango para el eje Y si es necesario ajustar manualmente
# set yrange [-3:3]

# # Leyendas
# set key outside

# # Plotea las curvas con barras de error y puntos
# plot "matmul_weak.txt" using 1:2:3 title "Tiempo de reloj" with yerrorlines lw 2 lc 'red' pt 7 ps 0.5, \
#      # "matmul_weak.txt" using 1:4:5 title "Tiempo de cpu" with yerrorlines lw 2 lc 'blue' pt 7 ps 0.5

# # Cierra el archivo de salida
# set output


set term pdf size 3in,3in font "Times New Roman,10"
set out "Metrics Weak Scaling.pdf"

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