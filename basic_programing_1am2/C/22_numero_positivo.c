/*
    Luis Fernando Nuñez Rangel
    Ing Aeronautica 
    Fundamentos de programación

    Programa que verifica si un numero es positivo
*/

#include<stdlib.h>
#include<stdio.h>

void isPositive(float n){
    if(n==0){
        printf("\n\t Tu numero es cero");
    }else{
        (n>0) ? printf("\n\t Es positivo") : printf("\n\t Es negativo");
    }
}

int main(){
    float n;

    printf("\n\t Digita un numero: ");
    scanf("%f", &n);

    isPositive(n);

    return 0;
}