
#ifndef PARCIAL_1_H
#define PARCIAL_1_H

#include <iostream>
using namespace std;

int** matriz_neutra(int n);
void liberar_mem_neutra(int**matriz,int n);
void transponer(int**matriz, int n);
void invertir_filas(int**matriz,int n);
void rotar_noventa(int n, int rotaciones);


#endif // PARCIAL_1_H