#include<stdlib.h>
#include<stdio.h>

void datos(void);
void captura(float v[]);
void escalar_Vector(float v1[], float vR[], float e);
void print_Vector(float v1[],float vR[]);

int main(){

    datos();

    return 0;
}

void datos(void){
    float v1[3],vR[3];

    printf("\n\t Digita los valores de tus 2 vectores: ");

    printf("\n\t Digita los valores del vector 1: ");
    captura(v1);
    
    float e;
    printf("\t Digita el valor escalar: ");
    scanf("%f", &e);

    escalar_Vector(v1, vR, e);
}

void captura(float v[]){
    int i;
    for(i=0;i<3;i++){
        scanf("%f",&v[i]);
    }
}

void escalar_Vector(float v1[],float vR[], float e){
    int i;

    for(i=0;i<3;i++){
        vR[i] = v1[i]*e;
    }

    print_Vector(v1,vR);
}

void print_Vector(float v1[],float vR[]){
    int i;
    char c;

    printf("\n\t Vector 1: ");
    for(i=0,c='i'; i<3;i++, c++){
        printf("%.2f%c ", v1[i], c);
    }

    printf("\n\t Vector resultante: ");
    for(i=0,c='i'; i<3;i++, c++){
        printf("%.2f%c ", vR[i], c);
    }
}