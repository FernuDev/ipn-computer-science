/*
    Luis Fernando Nuñez Rangel
    Ingenieria Aeronautica
    1AM2
*/

#include<stdlib.h>
#include<stdio.h>

void impimir(int year, char locate[], int n_passagers, int i_passagers, float ton_weigth, int operation_a){
    printf("\n\t Estadistica %d AIFA \n\t Ubicacion: %s \n\t Movimiento de pasajeros: %d \n\t Pasajeros Internacionales: %d \n\t Toneladas de carga: %.3f \n\t Areas de Operaciones: %d\n\n", year, locate, n_passagers, i_passagers, ton_weigth, operation_a);
}

void datos(){
    int year = 2023, n_passagers = 912415, i_passagers = 36368, operation = 8992;
    float ton_weigth = 34.1;
    char locate[] = "Santa Lucia, Estado de Mexico";
    impimir(year, locate, n_passagers, i_passagers,ton_weigth, operation);
}

int main(){
    datos();

    system("pause");

    return 0;
}