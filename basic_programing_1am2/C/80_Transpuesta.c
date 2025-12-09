#include<stdlib.h>
#include<stdio.h>

void transpuesta(float **m, int h, int w){
    printf("\n\t Tu matriz transpuesta es:\n\t ");
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            printf("%.1f ", m[j][i]);
        }
        printf("\n\t ");
    }
}

void imprimir(float **m, int h, int w){
    printf("\n\t Tu matriz normal es: \n\t");
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            printf("%.1f ", m[i][j]);
        }
        printf("\n\t");
    }
}

void captura(float **m, int h, int w){
    printf("\n\t Digita los elementos de tu matriz: \n\t ");
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%f", &m[i][j]);
        }
        printf("\t ");
    }
}

int main(){

    int n, m;
    printf("\n\t Digita el orden de tu matriz: ");
    scanf("%d", &n);
    scanf("%d", &m);
    float **matriz = (float **)malloc(sizeof(float)*n);
    for(int i=0;i<n;i++){
        matriz[i] = (float *)malloc(sizeof(float)*m);
    }

    captura(matriz, n, m);
    imprimir(matriz, n, m);
    transpuesta(matriz, n, m);

    return 0;
}