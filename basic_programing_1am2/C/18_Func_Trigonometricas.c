/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void imprimir(float angulo);

double const Pi = 3.14159;


int main(){

    float angulo = 0;
    printf("\n\t Digitame el angulo: ");
    scanf("%f", &angulo);

    angulo = (angulo/180)*Pi;

    imprimir(angulo);
    system("pause");
    return 0;
}

void imprimir(float angulo){
        
    printf("\n\t Las funciones trigonometricas del angulo %.2f rad son: \n seno: %f \n coseno: %f \n tangente: %f\n\n",angulo, sin(angulo), cos(angulo), tan(angulo));
};

