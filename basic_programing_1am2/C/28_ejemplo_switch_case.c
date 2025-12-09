#include<stdlib.h>
#include<stdio.h>

void datos(){

    int n;
    printf("\n\t Elige un numero 1 o 2 ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("\n\t Elegiste el 1");
        break;
    case 2:
        printf("\n\t Elegiste el 2");
        break;
    
    default:
        printf("\n\t Numero fuera de rango");
        break;
    }

}

int main(){

    datos();
    return 0;
}