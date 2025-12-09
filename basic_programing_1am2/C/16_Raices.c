/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float raiz (float n, float number);

int main(){

    float n = 0, number = 0, resultado = 0;

    printf("\n\t Digita que raiz quieres obtener: ");
    scanf("%f", &n);

    printf("\n\t A que numero le quieres sacar esa raiz: ");
    scanf("%f", &number);

    resultado = raiz(n, number);

    printf("\n\t La raiz es: %.2f  \n", resultado); 

    system("pause");

    return 0;
}

float raiz(float n, float number){
    return pow(number, 1/n);
}

