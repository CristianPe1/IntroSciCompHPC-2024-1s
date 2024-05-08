/*
memset se utiliza para establecer los bytes en un bloque específico de memoria
a un valor determinado. El uso de (void*) garantiza que la dirección de memoria
se trate de forma genérica.
*/
#include <iostream>
#include <cstring> // Para memset

int main() {
    int arr[5];

    // Establecer todos los elementos de arr a -1
    memset((void*)arr, -1, sizeof(arr));

    // Verificación
    for (int i = 0; i < 5; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
    return 0;
}
