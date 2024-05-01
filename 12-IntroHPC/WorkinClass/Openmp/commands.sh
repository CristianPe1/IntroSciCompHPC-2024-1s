for nth in {1..8}; do echo -n "$nth  "; OMP_NUM_THREADS=$nth ./a.out 2000 8 2> /dev/null; done | tee times.txt

# Sacamos los datos de la ejecución de los tiempos y los guardamos en un archivo
#Imprimimos el número de hilos, el speedup (S = T(s,1)/ T(s,N)) y la eficiencia (E=S/N)
#Con T(s,1) = 1.39682: Tiempo de ejecución con un solo hilo y T(s,N) el tiempo de ejecución con N hilos
awk '{print $1, 1.39682/$3, 1.39682/$3/$1}' times.txt > metrics.txt

gnuplot plot.gp

