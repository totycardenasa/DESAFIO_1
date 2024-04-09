#include "Parcial_1.h"
#include "Desafio_1.h"
#include <iostream>
using namespace std;
 //(4,3,1,-1,0,-100)


int main (){
        int condiciones = 2;
        int dim_M1;
        int* llamado = ingresar_numeros();
        int fila1=llamado[0];
        int columna1=llamado[1];
        int dato=0;
        int contador=0;
        while(dato!=-100){
            dato=llamado[contador]; // Se guarda cada elementos de "K" (contando el "-100")
            contador=contador+1; // el numero de elementos de K (contando el "-100")
        }
        int Tamanio_K = contador-1; // DIM del arreglo K, sin incluir el -100.
        int cantidad_condiciones = Tamanio_K-2; // cantidad de condiciones del arreglo k
        if (fila1>columna1){// fila es mayor que columna?
            if (fila1%2 == 0){ // verificar si es par ó impar
                dim_M1 = fila1+1;
            }
            else{
                dim_M1 = fila1;
            }

        }
        else if (columna1 > fila1){ // columna es mayor que fila?
            if (columna1%2 == 0){ // verifica si es par o impar
                dim_M1 = columna1+1;
            }
            else{
                dim_M1 = columna1;
            }
            cout<<"la dim de la cerradura es: "<<dim_M1<<endl;
        }

        else{ // si columna y fila son iguales
            if (fila1%2 == 0){ //verifica si es par o impar
                dim_M1 = fila1+1;
            }
            else{
                dim_M1 = fila1;
            }
            cout<<"la dim de la cerradura es: "<<dim_M1<<endl;
        }


        int fila2 = fila1;
        int columna2 = columna1;
        int dim_variable = dim_M1;
        int** primer_matriz = crear_matrices(dim_M1);
        int dim_variable1 = dim_M1;
        int cantidad_de_ArrdeX=cantidad_condiciones+1;
        int arreglo_X[cantidad_de_ArrdeX];
        int arreglo_rotaciones[cantidad_de_ArrdeX];
        int contador_posicion_x = 1;// contador para iterar
        int** segunda_matriz = crear_matrices(dim_variable);
        arreglo_X[0]=dim_M1;
        arreglo_rotaciones[0]=0;
        while(cantidad_condiciones >= 1){
            bool llamado_FUNcomprobador = false;
            while(llamado_FUNcomprobador == false){
                int rotaciones=0;
                while(rotaciones<=3){
                    llamado_FUNcomprobador =  comprobador(primer_matriz, segunda_matriz, fila1-1, columna1-1, fila2-1, columna2-1,llamado[condiciones]);
                    if(llamado_FUNcomprobador == false){ // toca rotar
                        rotar_noventa(segunda_matriz, dim_variable);
                        rotaciones=rotaciones+1;
                    }
                    else{
                        arreglo_X[contador_posicion_x]=dim_variable;
                        arreglo_rotaciones[contador_posicion_x]=rotaciones;
                        contador_posicion_x=contador_posicion_x+1;
                        liberar_mem_neutra(primer_matriz,dim_variable1);
                        cambiar_matriz(primer_matriz,segunda_matriz, dim_variable);
                        dim_variable1 = dim_variable;
                        liberar_mem_neutra(segunda_matriz,dim_variable);
                        dim_variable = dim_M1;
                        segunda_matriz = crear_matrices(dim_variable);
                        fila1 = fila2;
                        columna1 = columna2;
                        fila2= llamado[0];
                        columna2 = llamado[1];
                        rotaciones = 10;// para que se salga del while sin entrar al if
                    }
                    if(rotaciones==4){
                        liberar_mem_neutra(segunda_matriz, dim_variable);
                        dim_variable=dim_variable+2;
                        segunda_matriz = crear_matrices(dim_variable);
                            fila2=fila2+1;
                            columna2=columna2+1;


                    }
                }
            }
            cantidad_condiciones=cantidad_condiciones-1;
            condiciones=condiciones+1;
        }
        cout << "Con esta clave 'K' : (";
        for(int i = 0; i < Tamanio_K-1; i=i+1) {
            cout << llamado[i] << ", ";
        }
        cout << llamado[Tamanio_K-1] << ") se puede abrir esta cerradura:" << endl << "X(";
        for(int i = 0; i < cantidad_de_ArrdeX-1; i=i+1) {
            cout << arreglo_X[i] << ", ";
        }
        cout << arreglo_X[cantidad_de_ArrdeX-1] << ")" << endl << "La cerradura 'X' tiene las siguientes rotaciones:" << endl <<"R(";;
        for(int i = 0; i < cantidad_de_ArrdeX-1; i=i+1) {
            cout << arreglo_rotaciones[i] << ", ";
        }
        cout << arreglo_rotaciones[cantidad_de_ArrdeX-1] << ")" << endl;
        delete[] llamado;
        liberar_mem_neutra(primer_matriz, dim_variable1);
        liberar_mem_neutra(segunda_matriz, dim_variable);
        return 0;
    }





