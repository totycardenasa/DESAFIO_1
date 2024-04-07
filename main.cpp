#include "Desafio_1.h"
#include "Parcial_1.h"
#include <iostream>
using namespace std;


int main (){

    int elementos_de_k;
    int contador=0;
    int dato;
    int* llamado=ingresar_numeros();
    while(dato!=-100){
        dato=llamado[contador]; // Se guardan cada elementos de K (contando el "-100")
        contador=contador+1; // el numero de elementos de K (contando el "-100")
        //cout << dato<<endl;
    }

    int cantidad_de_ArrdeX;
    cantidad_de_ArrdeX=contador-2;//cantidad de arreglos que tendra mi cerradura "X".
    //cout << cantidad_de_ArrdeX<<endl;


    //delete[] llamado;

    int num1_K = llamado[0]; //fila
    int num2_k = llamado[1]; //columna
    int dim_M1;

    if (num1_K>num2_k){// numero 1 de la clave k mayor
        if (num1_K%2 == 0){ // verificar si es par o impar
            dim_M1 = num1_K+1;
        }
        else{
            dim_M1 = num1_K;
        }
    
    }
    else if (num2_k > num1_K){ //numero 2 de la clave k mayor
        if (num2_k%2 == 0){ // same
            dim_M1 = num2_k+1;
        }
        else{
            dim_M1 = num2_k;
        }
    }
    else{ // num 1 y 2 de la clave k iguales 
        if (num1_K%2 == 0){ //same
            dim_M1 = num1_K+1;
        }
        else{
            dim_M1 = num1_K;
        }
    }
    return 0;

    //COMPROBAR ARREGLOS DE X(int dim, int cantidad_M,int fila, int columna){ 

    int rotaciones = 3; 
    int Cm1;   
    int* arreglos_X_final = new int[m]; //ir almacenando las dimensiones ya verificadas
    int** matriz_inicial = matriz_neutra(dim_M1); 

    for (int i = 0; i<dim_M1; i++){    //Recorro mi matriz m1 para hallar el valor de las cooordenadas inicales
        for (int j = 0; j<dim_M1; j++){ 
        if (matriz_inicial[i][j] == matriz_inicial[num1_K-1][num2_k-1]){ 
            Cm1 = matriz_inicial[i][j]; //Cm1 va a ser mi valor
             } 
        } 
    } 
    //ALMACENAR DIM_M1 EN arreglos_X_final

    for (int r = 1; r <= rotaciones; r++){ 
        
        int** rotar_m2 = rotar_noventa(dim,r); 
        
        if (Cm1>rotar_m2[fila][columna]){  //y como se si es -1 1 o 0?
            int* comprobante = comprobador(int** matriz_1,int** matriz_2,int fila1,int fila2, int columna1,int columna2,int condicion)
            if (comprobante == true){ //osea si cumple con la condicion
                //ALAMCENAR LA MISMA 


                
            break;
            } 

        else if (Cm1<rotar_m2[fila][columna]){ 
            
            
            break; 
            } 
        
        else{
            if (Cm1 == rotar_m2[fila][columna]) = rotaciones +1;
        } 
    }  
    }
}