#include <pthread.h>
#include <iostream>

// Función que se ejecutará en el hilo
void* threadFunction(void* arg) {
    // Hacer algo útil
    std::cout << "Hello from the thread!" << std::endl;
    return nullptr;
}

int main() {
    pthread_t thread; // Variable para almacenar el identificador del hilo

    // Crear un nuevo hilo
    int result = pthread_create(&thread, nullptr, threadFunction, nullptr);
    if (result != 0) {
        std::cerr << "Error creating thread" << std::endl;
        return 1;
    }

    // Esperar a que el hilo termine
    pthread_join(thread, nullptr);

    return 0;
}

// Compile command: g++ -pthread threads.cpp
/*
pthread_create: Esta función inicia un nuevo hilo. Toma como argumentos una 
referencia a una variable pthread_t, atributos opcionales para el hilo, la 
función que el hilo debe ejecutar y un argumento que se pasa a esa función. 
La función retorna 0 en caso de éxito.

pthread_join: Esta función bloquea el hilo llamante hasta que el hilo especificado
por el pthread_t termina. Se usa para sincronizar la terminación de los hilos.

pthread_equal: Compara dos identificadores de hilos para determinar si son el 
mismo hilo. Esto es útil porque pthread_t puede ser una estructura o un entero,
dependiendo de la implementación del sistema operativo.

pthread_self: Retorna el identificador pthread_t del hilo que invoca esta 
función, lo que es útil para que un hilo pueda referirse a sí mismo en 
contextos como la comprobación de igualdad o la auto-referencia.*/