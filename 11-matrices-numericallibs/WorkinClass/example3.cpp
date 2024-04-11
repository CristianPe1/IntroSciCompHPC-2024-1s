#include <iostream>
#include <cstdlib>
#include <ctime>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{
    //----------------------Entrada de datos ----------------------
    //atoi convierte un string a un entero
    const int SEED = std::atoi(argv[1]);
    srand(SEED); // control seed
    std::cout<<"Valor introducido: "<<SEED<<std::endl;
    std::cout<<"Semilla establecida: "<<std::rand()<<std::endl;

    /**
     * @brief Esta line código establece la semilla utilizando std::time(nullptr), 
     * que devuelve la cantidad de segundos transcurridos desde el Epoch 
     * (00:00:00 Coordinated Universal Time (UTC), 1 de enero de 1970), lo 
     * que suele ser una semilla diferente cada vez que ejecutas el programa. 
     * Después, imprime el valor de std::rand() para mostrar la semilla que se 
     * está utilizando. 
    **/
    // std::srand(std::time(nullptr)); // Semilla basada en el tiempo actual
    // std::cout << "Semilla establecida: " << std::rand() << std::endl;

    Eigen::MatrixXd m = Eigen::MatrixXd::Random(5,5);
    std::cout << m << std::endl;

    return 0;
}

