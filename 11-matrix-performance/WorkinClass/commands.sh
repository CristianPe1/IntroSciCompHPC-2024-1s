for nth in {1..8}; do echo -n "$nth  "; OMP_NUM_THREADS=$nth ./a.out 2000 8 2> /dev/null; done | tee times.txt

awk '{print $1, 1.39682/$3 1.39682/$3$1}' times.txt > metrics.txt

gnuplot plot.gp

