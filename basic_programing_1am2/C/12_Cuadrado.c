
/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

float area_Cuadrado(float lado);

void datos(void);
float perimetro_Cuadrado(float lado);
void imprimir(float area);

int main(){

    datos();
    return 0;
}

float area_Cuadrado(float lado){
    return lado*lado;
}

void imprimir(float area){
    printf("\n\t El area de tu cuadrado es: %.2f", area);
}

float perimetro_Cuadrado(float lado){
    return (lado*4);
}

void datos(){

    float lado = 0, area = 0;
    printf("\n\t Digita el lado de tu cuadrado: ");
    scanf("%f", &lado);

    area = area_Cuadrado(lado);

    imprimir(area);
}