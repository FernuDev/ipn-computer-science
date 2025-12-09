
/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdlib.h>
#include<stdio.h>

void edad(void);

int main(){
    edad();
    system("pause");
    return 0;
}

void edad(void){
    int edad = 20;
    float altura = 1.75, peso = 63.5;
    char nombre[] = "Luis Fernando Nunez Rangel";

    printf("\n\t Hola que tal mi nombre es: %s", nombre);
    printf("\n\t Tengo %d a%cos", edad, 164);
    printf("\n\t Mido %.2fm y peso %.2fKg\n", altura, peso);
}