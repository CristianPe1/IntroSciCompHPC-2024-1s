/*En situaciones donde se necesita pasar punteros a funciones que requieren un
 tipo de puntero genérico (void*), como muchas funciones de la API de POSIX o 
 al trabajar con threads.*/

#include <pthread.h>
#include <iostream>

// Función que se ejecutará en el hilo
// Funcion tipo void* que recibe un argumento tipo void*
// Void* es un tipo de puntero genérico que puede apuntar a 
// cualquier tipo de dato
void* thread_function(void* arg) {
    int* ptr = static_cast<int*>(arg);
    *ptr = 10;
    return nullptr;
}

int main() {
    // Crear un thread 
    pthread_t thread;
    int value = 0;

    // Lanzar un thread pasando una dirección de memoria
    pthread_create(&thread, nullptr, thread_function, (void*)&value);
    pthread_join(thread, nullptr);

    std::cout << "Valor modificado por el thread: " << value << std::endl;
    return 0;
}
