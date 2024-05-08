
#!/bin/bash 
TARGET=matmul
PARAMS=2000
NREPS=8
TREADHS="1 2 3 4 5 6 7 8"

FORMAT='Real Time: %e\nUser Time: %U\nSystem Time: %S\nCPU usage: %P\nMax memory: %MkB\n'

# Asegúrate de que la variable TARGET está definida
TARGET="matmul" # Asumiendo que el nombre del target es 'matmul'

# Definir correctamente el comando usando variables
WEAK_SCALING="./${TARGET}.x {} ${NREPS} 2> /dev/null"
# Aquí, utiliza comillas dobles para que las variables se expandan correctamente

# Loop para ejecutar comandos
for treadh in $TREADHS; do
    echo -n "$treadh  ";
    parallel -j $treadh $WEAK_SCALING ::: $PARAMS;
done | tee matmul_weak.txt


awk '{print $1, 1.39682/$3, 1.39682/$3/$1}' matmul_weak.txt > metrics.txt

gnuplot graph_weak.gp
