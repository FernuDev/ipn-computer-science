#include <stdio.h>
#include <stdlib.h>

int main(){

    //Inizializacion de un vector con 10 elementos y llenarlo con numeros del 1 al 10
    int numeros[10];

    for(int i=0;i<10;i++){
        numeros[i] = i+1;
    }

    //Imprimir los datos del vector
    printf("\n\t");

    for(int i=0;i<10;i++){
        printf("%d ", numeros[i]);
    }
    return 0;

}