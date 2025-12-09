#include <stdlib.h>
#include <stdio.h>

void isSimetrica(float **m, int n);
void captura(float **m, int n);

int main(){

    int n;
    printf("\n\t Digita el orden de tu matriz: ");
    scanf("%d", &n);

    float **matriz = (float **)malloc(sizeof(float)*n);

    for(int i=0;i<n;i++){
        matriz[i] = (float *)malloc(sizeof(float)*n);
    }

    captura(matriz, n);
    isSimetrica(matriz, n);

    return 0;
}

void captura(float **m, int n){
    printf("\n\t Digita los elementos de tu matriz: \n\t ");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%f", &m[i][j]);
        }

        printf("\t ");
    }
}

void isSimetrica(float **m,int n){
    int isSimetric = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]!=m[j][i]){
                isSimetric = 0;
            }else{
                isSimetric = 1;
            }
        }
    }

    if(isSimetric==0){
        printf("\n\t Tu matriz es simetrica");
    }else if(isSimetric==1){
        printf("\n\t Tu matriz no es simetrica");
    }
}