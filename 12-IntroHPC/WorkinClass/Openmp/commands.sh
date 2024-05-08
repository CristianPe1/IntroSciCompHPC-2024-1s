#!/bin/bash 
#El comando !/bin/bash indica que el script se ejecutará en bash
#Esto es esencial para scripts que utilizan características 
#específicas de Bash que no están disponibles en otros shells 
#como sh (Shell estándar de UNIX). 
TARGET=matmul
PARAM=2000
NREPS=8
TREADHS="1 2 3 4 5 6 7 8"

FORMAT='Real Time: %e\nUser Time: %U\nSystem Time: %S\nCPU usage: %P\nMax memory: %MkB\n'

# Asegúrate de que la variable TARGET está definida
TARGET="matmul" # Asumiendo que el nombre del target es 'matmul'

# Definir correctamente el comando usando variables
WEAK_SCALING="./${TARGET}.x ${PARAMS} ${NREPS} 2> /dev/null"
# Aquí, utiliza comillas dobles para que las variables se expandan correctamente

# echo "Mean wall time   sigma wall time   Mean CPU time   sigma CPU time "
# Loop para ejecutar comandos
for treadh in $TREADHS; do
    echo -n "$treadh  ";
    OMP_NUM_THREADS=$treadh $WEAK_SCALING;
done | tee matmul_weak.txt

# for nth in {1..8}; do
#      echo -n "$nth  "; 
#      OMP_NUM_THREADS=$nth ./a.out 2000 8 2> /dev/null; 
# done | tee times.txt

# Sacamos los datos de la ejecución de los tiempos y los guardamos en un archivo
#Imprimimos el número de hilos, el speedup (S = T(s,1)/ T(s,N)) y la eficiencia (E=S/N)
#Con T(s,1) = 1.39682: Tiempo de ejecución con un solo hilo y T(s,N) el tiempo de ejecución con N hilos
awk '{print $1, 1.39682/$3, 1.39682/$3/$1}' matmul_weak.txt > metrics.txt

gnuplot plot.gp

