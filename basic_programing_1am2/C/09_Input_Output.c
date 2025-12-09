/*
    Solicita al usuario tres datos mediante una función
    para posteriormente imprimirlo en pantalla 
*/

/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

void Datos();
void imprimir_Datos(int sala, int vuelo, float hora);

int main(){

    Datos();
    return 0;
}

void Datos(){
    int sala, vuelo;
    float hora;

    printf("\n\t Bienvenido al sistera del AICM, ingresa los datos que se te piden a continuación: ");
    printf("\n\t Sala: ");
    scanf("%d", &sala);
    printf("\n\t Vuelo: ");
    scanf("%d", &vuelo);
    
    printf("\n\t Hora de vuelo: ");
    scanf("%f", &hora);

    imprimir_Datos(sala, vuelo, hora);
}

void imprimir_Datos(int sala, int vuelo, float hora){
    system("cls");

    printf("\n\t Los datos de tu vuelo son: \n\n");
    printf("\n\t La sala es: %d", sala);
    printf("\n\t El vuelo es: %d", vuelo);
    printf("\n\t La hora es: %.2f\n\n", hora);

}