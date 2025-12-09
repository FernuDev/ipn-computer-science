/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const float PI = 3.14159;

float Generatriz(float h, float r){
    return sqrt( (pow(h,2) + pow(r,2)) );
}

float area_Base(float r){
    return PI*pow(r,2);
}

float area_Lateral(float g, float r){
    return PI*g*r;
}

float area_Total(float a_B, float a_L){
    return a_B+a_L;
}

float volumen(float r, float h){
    return (PI * pow(r,2) * h)/3;
}

void imprimir(float r, float h, float aL, float aB, float aT, float g, float volumen){
    printf("\n\t Los datos de tu cono son: ");
    printf("\n\t Radio: %.2f", r);
    printf("\n\t Altura: %.2f", h);
    printf("\n\t Area lateral: %.2f", aL);
    printf("\n\t Area  base: %.2f", aB);
    printf("\n\t Area  total: %.2f", aT);
    printf("\n\t Volumen: %.2f", volumen);
    printf("\n\t Generatriz: %.2f \n", g);
}

void datos(){
    float r = 0, h=0, aL=0, aB=0, aT=0, g=0, V=0;

    printf("\n\t Digita la altura del cono: ");
    scanf("%f", &h);

    printf("\n\t Digita el radio del cono: ");
    scanf("%f", &r);
    
    g = Generatriz(h, r);
    aB = area_Base(r);
    aL = area_Lateral(g, r);
    aT = area_Total(aB, aL);
    V = volumen(r,h);

    imprimir(r,h,aL,aB, aT, g, V);
}

int main(){

    datos();
    system("pause");

    return 0;
}
