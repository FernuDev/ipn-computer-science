#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void datos(void);
void captura(float v[]);
float magnitud(float v[]);

int main(){
    datos();
    return 0;
}

void datos(){
    float v[3];

    captura(v);
    printf("\n\t La magnitud del vector es: %f", magnitud(v));
}

void captura(float v[]){
    printf("\n\t Digita los valores de tu vector (i,j,k): ");
    int i;

    for(i=0;i<3;i++){
        scanf("%f", &v[i]);
    }
}

float magnitud(float v[]){
    return sqrt(pow(v[0], 2)+pow(v[1], 2)+pow(v[2], 2));
}
