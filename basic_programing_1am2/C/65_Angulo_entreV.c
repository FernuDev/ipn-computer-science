#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void captura(float v[]);
void datos();
float angulo(float v1[], float v2[]);
float producto_punto(float v1[], float v2[]);
float magnitud(float v[]);

int main(){
    datos();
    return 0;
}

void datos(){
    printf("\n\t Angulo entre dos vectores: ");
    float v1[3], v2[3];
    printf("\n\t Digita los valores del vector 1: ");
    captura(v1);
    printf("\n\t Digita los valores del vector 2: ");
    captura(v2);

    float angulo_1 = angulo(v1,v2);
    printf("\n\t El angulo entre tus dos vectores es: %.3f\n", angulo_1);
}

void captura(float v[]){
    for(int i=0;i<3;i++){
        scanf("%f", &v[i]);
    }
}

float producto_punto(float v1[], float v2[]){
    float producto = 0;
    for(int i=0;i<3;i++){
        producto+=v1[i]*v2[i];
    }

    return producto;
}

float magnitud(float v[]){
    float radicando = 0;
    for(int i=0;i<3;i++){
        radicando+=powf(v[i],2);
    }

    return sqrt(radicando);
}

float angulo(float v1[], float v2[]){
    float angulo=0,m1=0,m2=0;
    m1 = magnitud(v1);
    m2 = magnitud(v2);

    float coeficiente = producto_punto(v1,v2)/(m1*m2);
    return acos(coeficiente);

}
