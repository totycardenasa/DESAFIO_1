
#include "Parcial_1.h"
#include <iostream>
using namespace std;

int** matriz_neutra(int n){
    
    int** neutra = new int*[n]; //Para arreglos dinámicos,puntero que apunte a cada fila de mi matriz M.
    
    for (int i = 0; i < n; i++) {
        neutra[i] = new int[n]; //Memoria dinámica para cada fila.
    }
        
    int centro = n/2; //Coordenada centro 0.
    int elemento = 1; //Empieza a contar de 1 hasta (n*n)-1.
    
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (i != centro or j != centro) {
                neutra[i][j] = elemento++;
            } 
            else{
                neutra[i][j]= 0; //Colocar elemento 0.
            }
        }
    }
    return neutra; //Devolver la matriz que se creó.
}

void liberar_mem_neutra(int**matriz,int n){ //Liberar el espacio de memoria de la anterior matriz.
    
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

void rotar_noventa(int n, int rotaciones){
    
    int** cajita = matriz_neutra(n); //Invoco mi matriz inicial.
    
    for (int i= 0; i<rotaciones; ++i){
        transponer(cajita,n);
        invertir_filas(cajita,n);
    }
    
    for (int i= 0; i<n; ++i){
        for (int j= 0; j<n; ++j){
            cout << cajita[i][j] << " ";
        }
        cout << endl;
    }
    liberar_mem_neutra(cajita,n);
}