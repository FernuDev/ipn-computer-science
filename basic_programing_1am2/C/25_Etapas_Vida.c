/*
    Clasificar las etapas de la vida de una persona

    Luis Fernando Nuñez Rangel
    Ing Aeronautica
*/

#include<stdlib.h>
#include<stdio.h>

void etapas(int age){
    if(age<0){
        printf("\n\t Prenatal");
    }else if(age>=1 && age<=3){
        printf("\n\t Primera infancia");
    }else if(age>=4 && age<=6){
        printf("\n\t Preescolar");
    }else if(age>=7 && age<=12){
        printf("\n\t Escolar");
    }else if(age>=13 && age<=18){
        printf("Adolescencia");
    }else if(age>=19 && age<=35){
        printf("\n\t Juventud");
    }else if(age>=36 && age<=50){
        printf("\n\t Madurez");
    }else if(age>=51 && age<=65){
        printf("\n\t Adultez");
    }else if(age>=66 && age<=120){
        printf("Tercera edad");
    }

}

void datos(){
    int age; 
    printf("\n\t Digita tu edad: ");
    scanf("%d", &age);

    etapas(age);
}

int main(){
    datos();

    return 0;
}