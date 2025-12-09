/*
    Programa de conversion de temperaturas

    Luis Fernando Nuñez Rangel

    Ing Aeronautica
*/

#include<stdlib.h>
#include<stdio.h>

float C_to_K(float celcius){
    return celcius+273.15;
}

float K_to_C(float kelvin){
    return kelvin-273.15;
}

float C_to_F(float celcius){
    return ((9/5)*celcius)+32;
}

float F_to_C(float fahrenheit){
    return (5/9)*(fahrenheit-32);
}

int menu(){
    int option;

    printf("\n\t=== Programa de conversion de temperaturas ===");
    printf("\n\t1. Celsius a Fahrenheit\n\t2. Celcius a Kelvin\n\t3. Fahrenheit a Celcius\n\t4. Kelvin a Celsius\n\t5. Salir\n\t ");
    scanf("%d", &option);

    float c, f, k;
    
    switch(option){
        case 1:
            system("cls");
            printf("\n\t Digita la temperatura en Celsius: ");
            scanf("%f", &c);
            printf("\n\t La temperatura en Fahrenheit es: %.2f %cF", C_to_F(c),167);

            break;
        case 2:
            system("cls");
            printf("\n\t Digita la temperatura en Celsius: ");
            scanf("%f", &c);
            printf("\n\t La temperatura en Kelvin es: %.2f %cK", C_to_K(c), 167);

            break;
        case 3:
            system("cls");
            printf("\n\t Digita la temperatura en Fahrenheit: ");
            scanf("%f", &f);
            printf("\n\t La temperatura en Celsius es: %.2f %cC", F_to_C(f),167);

            break;
        case 4:
            system("cls");
            printf("\n\t Digita la temperatura en Kelvin: ");
            scanf("%f", &k);
            printf("\n\t La temperatura en Celsius es: %.2f %cC", K_to_C(k),167);

            break;
        case 5:
            printf("\n\tGracias por usar el programa");
            return 1;
            break;
        default:
            system("cls");
            printf("\n\t Numero fuera de rango digita un numero valido");
            menu();
            break;
    }
    return 0;
}

void datos(){
    int n;
    do{
        n = menu();
    }while(n==0);
}


int main(){
    datos();

    return 0;
}