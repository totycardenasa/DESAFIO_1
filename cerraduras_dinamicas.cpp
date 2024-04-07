#include "Parcial_1.h"
#include <iostream>
using namespace std;

//como le asigno mi dim_m1 a la cantidad de arreglos que debo tener en mi cerradura x

int*** crear_cerraduras_dinamicas(int dim, int cantidad_M) {
    int*** cerraduras = new int**[cantidad_M]; // Crear un arreglo de punteros a arreglos
    
    for (int i = 0; i < cantidad_M; ++i) {
        cerraduras[i] = matriz_neutra(dim); // Asignar a cada elemento del arreglo una matriz neutra
    }
    
    return cerraduras;
}

void liberar_memoria_cerraduras(int*** cerraduras, int cantidad_M, int dim) {
    for (int i = 0; i < cantidad_M; ++i) {
        liberar_mem_neutra(cerraduras[i], dim); // Liberar memoria de cada matriz
    }
    delete[] cerraduras; // Liberar memoria del arreglo de punteros
}

int main() {
    int dim = 5;
    int cantidad_M = 3;

    int*** cerraduras = crear_cerraduras_dinamicas(dim, cantidad_M);

    // Hacer lo que necesites con las cerraduras aquí...

    liberar_memoria_cerraduras(cerraduras, cantidad_M, dim);

    return 0;
}