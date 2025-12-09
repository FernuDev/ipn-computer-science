/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

void capturar_datos(void);

int main(){
    return 0;
}

void capturar_datos(void){
    int edad, numero_hermanos;
    char nombre[20];
    float gasto, promedio;

    printf("\n\t Digita tu edad: ");
    scanf("%d", &edad);

    printf("\n\t Cuantos hermanos tienes?");
    scanf("%d", &numero_hermanos);

    printf("\n\t Digita tu nombre: ");
    gets(nombre);

    printf("Digita tu gasto: ");
    scanf("%f", &gasto);

    printf("\n\t Digita tu promedio: ");
    scanf("%f", &promedio);

}