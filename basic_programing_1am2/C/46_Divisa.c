/*
    Programa que hace conversion de divisas

    Luis Fernando Nuñez Rangel 

    Ing Aeronautica
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

float mxn_to_usd(float pesos){
    return pesos*0.055;
}

float usd_to_mxn(float dollars){
    return dollars*18.1;
}

float mxn_to_eur(float pesos){
    return pesos*0.05;
}

float eur_to_mxn(float euro){
    return euro*19.83;
}

void menu(){
    int option;
    printf("\n\t Selecciona una opcion: ");
    printf("\n\t1. Pesos a dolares \n\t2.Dolares a pesos \n\t3.Pesos a euros \n\t4.Euros a pesos\n\t");

    scanf("%d", &option);

    float pesos;
    float euros;
    float dolares;

    switch (option)
    {
    case 1:
        system("cls");
        printf("\n\t Pesos a Dolares");
        printf("\n\t Digita la cantidad a convertir: ");
        scanf("%f", &pesos);

        printf("\n\t La cantidad es: %.2f usd", mxn_to_usd(pesos));
        break;
    case 2:
        system("cls");
        printf("\n\t Dolares a Pesos");
        printf("\n\t Digita la cantidad a convertir: ");
        scanf("%f", &dolares);

        printf("\n\t La cantidad es: %.2f mxn", usd_to_mxn(dolares));
        break;
    case 3:
        system("cls");
        printf("\n\t Pesos a Euros");
        printf("\n\t Digita la cantidad a convertir: ");
        scanf("%f", &pesos);

        printf("\n\t La cantidad es: %.2f eur", mxn_to_eur(pesos));
        break;
    case 4:
        system("cls");
        printf("\n\t Euros a Pesos");
        printf("\n\t Digita la cantidad a convertir: ");
        scanf("%f", &euros);

        printf("\n\t La cantidad es: %.2f mxn", eur_to_mxn(euros));
        break;
    default:
        printf("\n\t Digita un numero valido");
        menu();
        break;
    }

}

void datos(){
    int otro;
    printf("\n\n === Programa que convierte divisas ===");

    do{
        menu();
        printf("\n\n\t Digita 1 si quieres realizar otra operacion\n\t Digita 2 si quieres salir\n\t ");
        scanf("%d", &otro);
    }while(otro==1);

    printf("\n\tGracias por usar el programa!!");
}

int main(){
    datos();

    return 0;
}