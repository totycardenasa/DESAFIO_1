#include <iostream>
using namespace std;

#include "Desafio_1.h"


int** crear_matrices(unsigned int n){
        int** arreglo = new int*[n];
        int variable=0;
        for (unsigned int i = 0; i < n; i=i+1) {
            arreglo[i] = new int[n];
        }


    for (int i = 0; i < n; i=i+1) {
        for (int j = 0; j < n; j=j+1) {
            if (i==n/2 && j==n/2){
                arreglo[i][j]=0;
            }

            else{
                arreglo[i][j] = variable;
                variable=variable+1;
            }

        }
    }


    for (int i = 0; i < n; i=i+1) {
        for (int j = 0; j < n; j=j+1) {
            cout << arreglo[i][j]<< " ";
        }
        cout << endl;
    }

    return arreglo;

}

//recordar que en el main debo de borrar la memoria dinamica con "delete"


int* ingresar_numeros(){
    int* key=nullptr; // Inicializa el puntero
    int numero;
    const int alto = -100;
    int contador = 0;
    int fila;
    int columna;
    int* arreglo_K;
    cout<<"Ingrese dos numeros (filas - columnas)."<<endl;
    cin>>fila;
    cin>>columna;

    while(fila<1 || columna <1){
        cout<<"ERROR"<<endl;
        cout<<"Ingrese un numero valido, es decir, un numero positivo."<<endl;
        cin>>fila;
        cin>>columna;
    }


    while (true) {
        cout << "Ingrese las comparaciones que desee ('-1','1','0'); para parar, ingrese un '" << alto << "': "<<endl;
        cin >> numero;
        while((numero<-1) || (numero > 1)){
            if(numero==alto){
                break;
            }
            cout<<"ERROR"<<endl<<"Ingrese un numero valido ('-1','1','0')"<<endl;
            cin>>numero;
        }


        int* arreglo_temporal = new int[contador + 1];
        for (int i = 0; i < contador; i=i+1) {
            arreglo_temporal[i] = key[i];
        }

        arreglo_temporal[contador] = numero;
        delete[] key;
        key = arreglo_temporal; // Actualizar el puntero
        contador=contador+1;// numero de comparaciones
        if (numero == alto) {
            break; // Salir del bucle cuando se ingrese el "-100"
        }

    }
    int elementos_k=contador+2;
    arreglo_K=new int [elementos_k];
    arreglo_K[0]=fila;
    arreglo_K[1]=columna;
    for(int i=2; i<elementos_k;i=i+1){
        arreglo_K[i]=key[i-2];

    }


    delete[] key;

    return arreglo_K;
}


bool comprobador(int** matriz_1,int** matriz_2,int fila1,int fila2, int columna1,int columna2,int condicion){
    bool variable=false;
    if(condicion==1){
        if((matriz_1[fila1][columna1])>matriz_2[fila2][columna2]){
            variable= true;
        }

    }
    else if(condicion==-1){
        if((matriz_1[fila1][columna1])<matriz_2[fila2][columna2]){
            variable= true;
        }

    }
    else if(condicion==0){
        if((matriz_1[fila1][columna1])==matriz_2[fila2][columna2]){
            variable= true;
        }

    }
    return variable;

}







