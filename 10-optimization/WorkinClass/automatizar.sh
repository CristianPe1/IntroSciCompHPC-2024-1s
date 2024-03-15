
# Leer el número de potencias de 2 a calcular
read -p "Ingrese el numero de potencias de 2 a imprimir: " n

gcc -O3 flags.c -o flags.out

# # Inicializar la potencia de 2 en 1 (2^0)
# potencia=1

for ((i = 0; i < n; i++))
do
    echo "2^$i = $potencia"
    # Calcular la siguiente potencia de 2 multiplicando por 2
    potencia=$((potencia * 2))
    echo $potencia | ./flags.out
    # make run nsize
done
