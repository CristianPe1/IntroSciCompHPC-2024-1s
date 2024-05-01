GCC = g++ 
#FLAGS = -O3 -std=c++17 -Wall -Wextra -Wpedantic -Werror
# -O3: Activa todas las optimizaciones que no interfieren con la norma ISO C++.

#-std=c++17: Establece la versión del estándar de C++ que se utilizará para la compilación.

# -Wall: Activa los avisos más comunes que pueden indicar errores en el código. Estos avisos

# - Wextra: Activa avisos adicionales que no están cubiertos por -Wall. Estos avisos suelen referirse a 
# casos que no necesariamente son errores, pero que pueden haber surgido de errores de codificación.

# -Wpedantic: Esta opción hace que el compilador genere advertencias para el código que no sigue  
# estrictamente los estándares de C++ y las extensiones GNU. Es útil para asegurarse de que el código 
#sea portable entre diferentes compiladores que siguen el estándar.

# -Werror: Convierte todos los avisos en errores. Si se genera cualquier advertencia, el compilador 
#tratará esa advertencia como un error y detendrá el proceso de compilación. Esta es una forma de 
#asegurarse de que el código no contenga construcciones que el compilador considere potencialmente 
#problemáticas.
FLAGS = -O3 -std=c++17

TARGET = $(patsubst %.cpp, %, $(wildcard *.cpp))

PARAMS = 100 500 1000
# PARAMS = 100 500 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000 
NREPS = 2
TREADHS = 1 2 4 8 

FORMAT = 'Real Time: %e\nUser Time: %U\nSystem Time: %S\nCPU usage: %P\nMax memory: %MkB\n'


# WEAK_SCALING = ./$(TARGET).x {} $(NREPS) 1>> $(TARGET)_weak.txt 2>> /dev/null
WEAK_SCALING = ./matmul.x {} $(NREPS) 1
STRONG_SCALING = ./matmul.x {} $(NREPS) 1>> $(TARGET)_strong.txt 2>> /dev/null
#Cambiar el nombre de matmul por el nombre del archivo que se quiera ejecutar
#de manera que se pueda ejecutar cualquier archivo de la carpeta con el makefile


COMMAND_PARALLEL_STRONG = /usr/bin/time --format=$(FORMAT) parallel -j 8 '$(STRONG_SCALING)' ::: $(PARAMS)
# Solo es posible usar /usr/bin/time una vez en el comando, si se quiere usar más de una vez
# es necesario usar el comando time de bash, pero no se puede usar en paralelo
# por lo que no se puede usar en el comando de parallel
# Se puede usar el comando time de bash para medir el tiempo de ejecución de parallel
# pero no se puede usar para medir el tiempo de ejecución de cada uno de los comandos
# que se ejecutan en paralelo
#Es necesario usar la bandera --line-bufer???



all: $(TARGET:=.txt) graph_strong 

$(TARGET).x: $(TARGET).cpp
	$(GCC) $(FLAGS) $< -o $@

$(TARGET).txt: $(TARGET).x
	$(COMMAND_PARALLEL_STRONG)
#$(STRONG_SCALING)
#$(COMMAND)
#$(COMMAND_PARALLEL)
#Como hacer para que se ejecute el comando en paralelo y se guarde el tiempo de compilacion
#por ejecucion de una simulación y el timpo total de las ejecuciones de todas las 
#simulaciones en un archivo de texto, sin tener que hacerlo a mano ni usar la saida 
#standard ni el error standard




#($(COMMAND_PARALLEL)) >> total_time.txt
#/usr/bin/time --format='Total Time: %E\nCPU usage: %P\nMax memory: %MkB' parallel -j 8 '(/usr/bin/time --format="Real Time: %e\nUser Time: %U\nSystem Time: %S" ./matmul.x {} 1 1>>matmul.txt 2>>trash.txt) 2>> time_{}_output.txt' ::: 100 500 1000


weak_scaling: 
	for treadh in $(TREADHS); do echo -n "$$treadh  ";/usr/bin/time --format=$(FORMAT) parallel -j $$treadh '$(WEAK_SCALING)' ::: {1..10}; done
#Ejecutar el comando de weak scaling para cada uno de los hilos ejecutando el mismo archivo
# un cierto número de veces y hacer la estadistica para cada uno de los hilos (mean, std, etc)
# y guardarla en un archivo de texto

graph_weak: weak_scaling
	gnuplot graph_weak.gp

graph_strong: graph_strong.gp
	gnuplot graph_strong.gp

PHONY: clean
clean:
	rm -f *.x *.txt *.out *.png *.pdf
