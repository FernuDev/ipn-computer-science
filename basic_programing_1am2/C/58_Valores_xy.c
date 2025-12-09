#include <stdio.h>
#include <stdlib.h>

void datos(void);
void captura(int  vector[]);
void imprimir(int vector[]);

int main(){
    datos();
    return 0;
}

void datos(){

    printf("\n\t Iniciar un vector (x,y)");

    int vector[2];

    captura(vector);
    imprimir(vector);
}

void captura(int vector[]){
    printf("\n\t Digita los elementos de tu vector (x,y): ");

    for(int i=0;i<2;i++){
        scanf("%d",&vector[i]);
    }
}

void imprimir(int vector[]){
    printf("\n\t Tu vector es: (");
    for(int i=0;i<2;i++){
        printf("%d", vector[i]);
        if(i<=2-2){
            printf(", ");
        }
    }
    printf(")\n");
}