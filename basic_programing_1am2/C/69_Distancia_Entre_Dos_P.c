#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void datos();
float distancia_2P(float *v1, float *v2);
void captura(float *v);

int main(){
    datos();
    return 0;
}

void datos(){

    float *punto1 = (float *)malloc(sizeof(float)*2);
    float *punto2 = (float *)malloc(sizeof(float)*2);

    printf("\n\t Digita los elementos de tus puntos...\n\t ");
    captura(punto1);
    printf("\n\t ");
    captura(punto2);

    printf("\n\t La distancia entre tus puntos es: %.3f\n\t ", distancia_2P(punto1, punto2));
}

void captura(float *v){
    for(int i=0;i<2;i++){
        scanf("%f", &v[i]);
    }
}

float distancia_2P(float *v1, float *v2){
    float factor = 0;

    for(int i=0;i<2;i++){
        factor+=pow((v1[i]*v2[i]), 2);
    }

    return sqrt(factor);
}