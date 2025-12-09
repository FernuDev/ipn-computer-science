/*
    Programa que convierte longitudes

    Luis Fernando Nuñez Rangel

    Ing Aeronautica
*/

#include<stdlib.h>
#include<stdio.h>

float km_milla(float km){
    return km*062137;
}

float milla_km(float milla){
    return milla/0.62137;
}

float mts_ft(float metro){
    return metro*3.2808;
}

float ft_mts(float pies){
    return pies/3.2808;
}




int menu(){
    int option;

    printf("\n\t=== Programa de conversion de longitudes ===");
    printf("\n\t1. Km a millas\n\t2. Millas a km\n\t3. Metros a pies\n\t4. Pies a metros\n\t5. Salir\n\t ");
    scanf("%d", &option);

    float mts, fts, kms, millas;   

    switch(option){
        case 1:
            system("cls");
            printf("\n\t Digita los kilometros: ");
            scanf("%f", &kms);

            printf("\n\t En millas son: %.3f", km_milla(kms));
            break;
        case 2:
            system("cls");
            printf("\n\t Digita las millas: ");
            scanf("%f", &millas);

            printf("\n\t En millas son: %.3f", milla_km(millas));
            break;
        case 3:
            system("cls");
            printf("\n\t Digita los metros: ");
            scanf("%f", &mts);

            printf("\n\t En millas son: %.3f", mts_ft(mts));
            break;
        case 4:
            system("cls");
            printf("\n\t Digita los pies: ");
            scanf("%f", &fts);

            printf("\n\t En millas son: %.3f", ft_mts(fts));
            break;
        case 5:
            printf("\n\tGracias por usar el programa");
            return 1;
            break;
        default:
            printf("\n\t Numero fuera de rango!!");
            menu();
            break;
    }


    return 0;
}

void datos(){
    int n;
    do{
        n= menu();
    }while(n==0);
}

int main(){
    datos();
    return 0;
}

