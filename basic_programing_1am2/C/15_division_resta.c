/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

float division(float a, float b);
float resta(float a, float b);
void imprimir(float div, float res);

int main(){
    float a, b;
    float Resta = 0, Division = 0;

    printf("\n\t Digita tu primer valor: ");
    scanf("%f", &a);

    printf("\n\t Digita tu segundo valor: ");
    scanf("%f", &b);

    Resta = resta(a,b);
    Division = division(a,b);

    imprimir(Division, Resta);

    return 0;
}

void imprimir(float div, float res){
    printf("\n\t El resultado de la division fue: %.2f", div);
    printf("\n\t El resultado de la resta fue: %.2f", res);
}

float division(float a, float b){
    return a/b;
}

float resta(float a, float b){
    return a-b;
}