#include <Desafio_1.h>

#include <iostream>
using namespace std;


int main (){
    int* llamado=ingresar_numeros();
    cout << "Primera posicion de K: " << llamado[0] << endl;
    delete[] llamado;
    return 0;
}
