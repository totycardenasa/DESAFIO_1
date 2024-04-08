#ifndef DESAFIO_1_H
#define DESAFIO_1_H

#include <iostream>
using namespace std;

int** crear_matrices( int n);
int* ingresar_numeros();
bool comprobador(int** matriz_1,int** matriz_2, int fila1, int columna1, int fila2, int columna2,int condicion);
void cambiar_matriz(int**& matriz1,int** matriz2, unsigned int dimension);

#endif // DESAFIO_1_H
