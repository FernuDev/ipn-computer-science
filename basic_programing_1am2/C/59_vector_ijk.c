#include<stdlib.h>
#include<stdio.h>

void datos(void);
void captura(float v[]);
void printVector(float v[]);

int main(){

    datos();

    return 0;
}


void datos(void){
    float v[3];
    int i;

    printf("\n\t Digita los elementos de tu vector: ");
    captura(v);
    printVector(v);
}

void captura(float v[]){

    int i;
    for(i=0;i<3;i++){
        scanf("%f",&v[i]);
    }
}

void printVector(float v[]){
    int i;
    char c;
    printf("\n\t");
    for(i=0, c='i';i<3;i++, c++){
        printf("%.1f%c ", v[i], c);
    }
}

