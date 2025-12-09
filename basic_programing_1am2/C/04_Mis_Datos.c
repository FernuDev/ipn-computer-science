// Imprimir en pantalla mis datos personales haciendo uso de una funcion void

/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

void misDatos(void);

int main(){

    misDatos();
    system("pause");
    return 0;
}

void misDatos(){
    int edad = 20, n_Hernamos = 1;
    float estatura = 1.75, peso = 62.2;
    char nombre[] = "Luis Fernando";
    char carrera[] = "Ingenieria Aeronautica";

    system("Color 0A"); 
    printf("\n\t ==================================");
    printf("\n\t Hola, mi nombre es %s", nombre);
    printf("\n\t Mido %0.2f m y peso %0.2f Kg", estatura, peso);
    printf("\n\t Estudio %s", carrera);
    printf("\n\t estoy cursando el primer semestre de %s", carrera);
    printf("\n\t ==================================\n");

}