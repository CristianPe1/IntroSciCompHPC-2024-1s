#include <iostream>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

int main() {
    gsl_matrix* A = gsl_matrix_alloc(3, 3);  // Crear una matriz 3x3
    gsl_vector* x = gsl_vector_alloc(3);    // Crear un vector de 3 elementos
    gsl_vector* y = gsl_vector_alloc(3);    // Crear un vector de 3 elementos

    // Rellenar la matriz A y los vectores x e y con valores apropiados

    // Realizar la multiplicación de matriz-vector A * x y almacenar el resultado en y
    gsl_blas_dgemv(CblasNoTrans, 1.0, A, x, 0.0, y);

    // Imprimir el resultado
    for (size_t i = 0; i < 3; i++) {
        std::cout << "y[" << i << "] = " << gsl_vector_get(y, i) << std::endl;
    }

    // Liberar memoria
    gsl_matrix_free(A);
    gsl_vector_free(x);
    gsl_vector_free(y);

    return 0;
}
