
#include <iostream>
using namespace std;

/* Matriz: Arreglo de arreglos, dimension n, numeros hasta h, h= (n*n)-1, para hallar cero en if ( division entera entre dos la dimension(queda coordenada))
 para crear matrices: le meto a la fucion la dimension n y hago el calculo para ponerle 
 los numeros con el cero (con coordenada fila y coumna)
 para rotar cada 90 grados: convierto cada fila en columna (), para invertirlo uso ((n-1)-1) ver ejemplo de iknvertir
 en video---- recordar que ahora son las filas i las que recorro al reves
 
 
 funciones para rotar matriz
 1)crear la matriz neutra
 
 cada 90°
 -transponer esa matriz
 -recorrer al reves las filas actuales
 -actualizar contador (identificador de posicion)
 
 
 tener en cuenta
 -como rellenar la matriz apartir de la dimension n (h=(n*n)-1)
 -dejar un espacio en blanco en las coordenadas del cero (coor:division entera entre dos la dim +1(para i y j))
*/

int** matriz_neutra(int n){
    
    int** neutra = new int*[n]; //Para arreglos dinámicos,puntero que apunte a cada fila de mi matriz M.
    
    for (int i = 0; i < n; i++) {
        neutra[i] = new int[n]; //Memoria dinámica para cada fila.
    }
        
    int centro = n/2; //coordenada centro 0.
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

int main(){
    
    int dimension = 3; //Ejemplo (ya que es variable).
    int rotaciones = 1; //Contador en main (i guess) (90° por rotaciones++).
    rotar_noventa(dimension,rotaciones);
    
    return 0;
}

