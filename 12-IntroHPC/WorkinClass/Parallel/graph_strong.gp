# Archivo gp para graficar los resultados de la estimación de 
# tiempo de compilación vs. tamaño del sistema (escalamiento fuerte)
set terminal pngcairo enhanced font 'Verdana,10'
set output 'Metrics Strong Scaling.pdf'

# Etiquetas y título del gráfico
set title "Tiempo de compilación vs. Tamaño del sistema"
set xlabel "Tamaño del sistema"
set ylabel "Tiempo de compilación (s)"

# Rango para el eje Y si es necesario ajustar manualmente
set yrange [-3:3]

# Leyendas
set key outside

# Plotea las curvas con barras de error y puntos
plot "matmul_strong.txt" using 1:2:3 title "Tiempo de reloj" with yerrorlines lw 2 lc 'red' pt 7 ps 0.5, \
     # "matmul_strong.txt" using 1:4:5 title "Tiempo de cpu" with yerrorlines lw 2 lc 'blue' pt 7 ps 0.5

# Cierra el archivo de salida
set output
