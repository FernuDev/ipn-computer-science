// Diseñar la ficha tecnica de un avion

/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdlib.h>
#include<stdio.h>

void ficha_Tecnica();

int main(){
    ficha_Tecnica();
    system("pause");
    return 0;
}

void ficha_Tecnica(){
    system("Color 0A");

    char model[] = "Boeing 747SP";
    int tripulacion = 3, c_pasajeros = 331, area_Ala = 511,peso_m = 317500;
    float longitud = 56.31, envergadura = 59.64, altura = 20.07;
    float peso_v = 147.54, vel_max = 1004;


    
    printf("\n\t Ficha tecnica de el avi%cn %s",162, model);
    printf("\n\n\t Capacidad: ");
    printf("\n\t Numero de pasajeros: %d", c_pasajeros);
    printf("\n\t Tripulaci%cn: %d", 162, tripulacion);
    printf("\n\t Peso maximo al despegue: %dKg",peso_m);
    printf("\n\t Valocidad maxima: %.2fkm/h", vel_max);
    printf("\n\t Tripulaci%cn: %d", 162, tripulacion);

    printf("\n\n\t Dimensiones:  ");
    printf("\n\t Longitud: %.2fm", longitud);
    printf("\n\t Envergadura: %.2fm", envergadura);
    printf("\n\t Altura: %.2fm", altura);
    printf("\n\t Area alar: %dm2\n\n", area_Ala);
}