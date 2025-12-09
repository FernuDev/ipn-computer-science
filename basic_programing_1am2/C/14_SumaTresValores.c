/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdlib.h>
#include<stdio.h>

float suma_3Valores(float datos[]);


int main(){
    float datos[3],  respuesta = 0;
    
    for (int i=0;i<3;i++){
        printf("\n\t Digita tu %d termino: ", i);
        scanf("%f", &datos[i]);
    }

    respuesta = suma_3Valores(datos);

    printf("\n\t Tu resultado es: %.3f", respuesta);

    return 0;
}

float suma_3Valores(float datos[]){

    float suma = 0;

    for(int i=0;i<3;i++){
        suma+=datos[i];
    }

    return suma;
};