/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

void imprimir(float area, float perimetro);
float area_Rectangulo(float b, float h);
float perimetro_Rectangulo(float b, float h);

int main(){
    float b = 0, h = 0, area = 0, perimetro = 0;

    printf("\n\t Digita la base de tu rectangulo: ");
    scanf("%f", &b);

    printf("\n\t Digita la altura de tu rectangulo: ");
    scanf("%f", &h);

    area = area_Rectangulo(b,h);
    perimetro = perimetro_Rectangulo(b,h);

    imprimir(area, perimetro);

    return 0;
}

void imprimir(float area, float perimetro){
    printf("\n\t Tu perimetro es: %.2f cm", perimetro);
    printf("\n\t Tu area es: %.2f cm2", area);
}

float area_Rectangulo(float b, float h){
    return b*h;
};

float perimetro_Rectangulo(float b, float h){
    return (b*2)+(h*2);
};
