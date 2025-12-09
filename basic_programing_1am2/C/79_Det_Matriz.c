#include<stdlib.h>
#include<stdio.h>

void captura(int **m){
    printf("\n\t Captura los elementos de tu matriz: \n\t ");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d", &m[i][j]);
        }
        printf("\t ");
    }
}

int det(int **m){
    return (m[0][0]*m[1][1])-(m[0][1]*m[1][0]);
}

int main(){
    int **matriz = (int **)malloc(sizeof(int)*2);
    for(int i=0;i<2;i++){
        matriz[i] = (int *)malloc(sizeof(int)*2);
    }
    captura(matriz);

    printf("\n\t La determinante de tu matriz es: %d\n", det(matriz));

    return 0;
}