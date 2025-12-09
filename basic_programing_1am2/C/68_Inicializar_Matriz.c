#include<stdio.h>
#include<stdlib.h>

void captura(int **m, int n){
    printf("\n\t Digita los elementos de tu matriz: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimir(int **m, int n){
    printf("\n\t Tu matriz es: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(" %d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    //Declaracion de matriz
    int **matriz = (int **)malloc(sizeof(int)*9);
    captura(matriz, 3);
    imprimir(matriz, 3);

}