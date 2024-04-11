#include <iostream> // Libreria para entrada y salida de datos
#include <eigen3/Eigen/Dense> // Libreria para algebra lineal

using namespace Eigen; // Espacio de nombres para algebra lineal

int main(){

    MatrixXd A = MatrixXd::Random(5,5); // Matriz de 5x5 con valores aleatorios
    MatrixXd B = MatrixXd::Random(5,5); // Matriz de 5x5 con valores aleatorios
    MatrixXd x = A.fullPivLu().solve(B); // Resolviendo el sistema de ecuaciones
    double relative_error = (A*x - B).norm() / B.norm(); // Calculando el error relativo
    std::cout << "The relative error is:\n" << relative_error << std::endl; // Imprimiendo el error relativo

}