/*memcpy es una función que copia una cantidad específica de bytes de una 
dirección de memoria a otra. Usar (void*) es útil para asegurarte de que 
las direcciones pasadas a memcpy son tratadas como direcciones genéricas, 
sin preocuparse por el tipo de datos.*/

#include <iostream>
#include <cstring> // Para memcpy

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5];

    // Copiar datos de arr1 a arr2
    memcpy((void*)arr2, (void*)arr1, sizeof(arr1));

    // Verificación de la copia
    for (int i = 0; i < 5; i++) {
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }
    return 0;
}
