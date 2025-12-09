/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float potencia (float n, float number);

int main(){

    float n = 0, number = 0, resultado = 0;

    printf("\n\t Digita que potencia quieres obtener: ");
    scanf("%f", &n);

    printf("\n\t A que numero quieres elevar: ");
    scanf("%f", &number);

    resultado = potencia(n, number);

    printf("\n\t La raiz es: %.2f", resultado); 

    return 0;
}

float potencia(float n, float number){
    return pow(number, n);
}

