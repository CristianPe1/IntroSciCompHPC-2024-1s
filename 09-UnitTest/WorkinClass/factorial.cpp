#include "factorial.h"

int factorial(int number){
    //Funcion recorsiva para calcular el factorial de un numero
    return number <= 1 ? 1 : number * factorial(number - 1)
}