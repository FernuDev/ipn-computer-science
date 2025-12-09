#include <stdlib.h>
#include <stdio.h>

void imprimir_Identidad(int n){
    double **identidad = (double **)malloc(sizeof(double *)*n);

    for(int i=0;i<n;i++){
        identidad[i] = (double *)malloc(sizeof(double)*n);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                identidad[i][j] = 1;
            }else{
                identidad[i][j] = 0;
            }
        }
    }

    printf("\n\t Tu matriz identidad es: \n\t ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%.f ", identidad[i][j]);
        }
        printf("\n\t ");
    }

    for(int i=0;i<n;i++){
        free(identidad[i]);
    }
    free(identidad);
}

int main(){
    int orden;
    printf("\n\t Digita el orden de tu matriz identidad: ");
    scanf("%d", &orden);

    imprimir_Identidad(orden);

    return 0;
}