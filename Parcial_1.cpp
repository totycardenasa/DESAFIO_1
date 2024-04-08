
#include "Parcial_1.h"
#include <iostream>
using namespace std;



void liberar_mem_neutra(int**matriz,int n){  //Liberar el espacio de memoria de la anterior matriz.
    
    for (int i= 0; i<n;++i){
        delete[]matriz[i];
    }
    delete[] matriz;
}

void transponer(int**matriz, int n){
    
    for(int i= 0; i<n; ++i){
        for (int j= i + 1; j<n; ++j){ // Con la j de esa forma aseguramos no repetir intercambios(diagonal principal única que cambia).
            int temporal_aux = matriz[i][j];
            matriz[i][j] = matriz[j][i]; // Intercambio filas por columnas una a una.
            matriz[j][i] = temporal_aux;
        }
        
    }
}

void invertir_filas(int**matriz,int n) {
    
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            int temporal_aux = matriz[i][j];
            matriz[i][j] = matriz[n - 1 - i][j]; //Tener en cuenta la indexación, por eso da.
            matriz[n - 1 - i][j] = temporal_aux;
        }
    }
}

void rotar_noventa(int** matriz, int n){
    transponer(matriz,n);
    invertir_filas(matriz,n);
}
