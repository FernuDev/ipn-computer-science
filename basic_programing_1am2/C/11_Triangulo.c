
/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

float area_Triangulo(float b, float h){
    return (b*h)/2;
}

void imprime(float area){
    printf("\n\t El area de tu triangulo es: %.2f", area);
}

void datos(void){
    float b = 0, h = 0, area = 0;

    printf("\n\t Digita la base del triangulo: ");
    scanf("%f", &b);

    printf("\n\t Digita la altura del triangulo: ");
    scanf("%f", &h);

    area = area_Triangulo(b,h);

    imprime(area);
}

int main(){
    datos();
    return 0;
}