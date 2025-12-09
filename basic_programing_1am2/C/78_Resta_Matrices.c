#include <stdlib.h>
#include <stdio.h>

void datos();
void captura(float **ma, int n, int m);
void resta(float **m1, float **m2, int n, int m);
void imprimir(float **ma, int n, int m);

int main(){

    datos();

    return 0;
}

void datos(){
    int n,m;
    printf("\n\t Digita el orden de tu matriz: ");
    scanf("%d", &n);
    scanf("%d", &m);

    float **matriz = (float **)malloc(sizeof(float*)*n);
    float **matriz2 = (float **)malloc(sizeof(float*)*n);
    for(int i=0;i<n;i++){
        matriz[i] = (float *)malloc(sizeof(float)*m);
        matriz2[i] = (float *)malloc(sizeof(float)*m);
    }


    printf("\n\t Captura tu primera matriz: ");
    captura(matriz, n, m);
    printf("\n\t Captura tu segunda matriz: ");
    captura(matriz2, n, m);

    suma(matriz, matriz2, n, m);

    printf("\n\t Tu primera matriz fue: ");
    imprimir(matriz, n ,m);
    printf("\n\t Tu segunda matriz es: ");
    imprimir(matriz2, n, m);
}

void captura(float **ma, int n, int m){
    printf("\n\t Digita los datos de tu matriz %dx%d:\n\t ", n, m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%f", &ma[i][j]);
        }
        printf("\t ");
    }
}

void resta(float **m1, float **m2, int n, int m){
    float **mR = (float **)malloc(sizeof(float *)*n);
     for(int i=0;i<n;i++){
        mR[i] = (float *)malloc(sizeof(float)*m);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mR[i][j] = m1[i][j]-m2[i][j];
        }
    }

    printf("\n\t Resta de matrices: ");
    imprimir(mR, n, m);
}

void imprimir(float **ma, int n, int m){
    printf("\n\t Digita los datos de tu matriz %dx%d:\n\t ", n, m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%.1f ", ma[i][j]);
        }
        printf("\n\t ");
    }

    for(int i=0;i<n;i++){
        free(ma[i]);
    }

    free(ma);
}