/*
    Luis Fernando Nuñez Rangel

    Ing Aeronautica

    Desarrollar un program que verifique si un numero es multiplo de 5
*/

#include<stdlib.h>
#include<stdio.h>

void multiplo(int n){
    if(n%5==0){
        printf("\n\t Tu numero %d es multiplo de 5", n);
    }else{
        printf("\n\t No es multiplo de 5");
    }
}

void datos(){
    int n;
    printf("\n\t Digita un numero: ");
    scanf("%d", &n);

    multiplo(n);
}

int main(){
    datos();

    return 0;
}

