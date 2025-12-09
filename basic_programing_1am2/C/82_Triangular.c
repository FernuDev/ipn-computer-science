#include <stdlib.h>
#include <stdio.h>

void triangular_Superior(int n);
void triangular_Inferior(int n);

int main(){
    int n;
    printf("\n\t Digita el orden de tu matriz: ");
    scanf("%d", &n);

    triangular_Superior(n);
    triangular_Inferior(n);

    return 0;
}

void triangular_Superior(int n){
    double **identidad = (double **)malloc(sizeof(double)*n);

    for(int i=0;i<n;i++){
        identidad[i] = (double *)malloc(sizeof(double)*n);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||i<j){
                identidad[i][j] = 1;
            }else{
                identidad[i][j] = 0;
            }
        }
    }

    printf("\n\t Tu triangular superior es: \n\t ");
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

void triangular_Inferior(int n){
    double **identidad = (double **)malloc(sizeof(double)*n);

    for(int i=0;i<n;i++){
        identidad[i] = (double *)malloc(sizeof(double)*n);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||j<i){
                identidad[i][j] = 1;
            }else{
                identidad[i][j] = 0;
            }
        }
    }

    printf("\n\t Tu triangular inferior es: \n\t ");
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