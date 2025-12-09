/*
    Luis Fernando Nuñez Rangel
    Ingenieria Aeronautica
    1AM2
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float formula_General1(float a, float b, float c){
    return ( -b + (sqrt( pow(b,2) - (4*a*c))) )/(2*a);
}

float formula_General2(float a, float b, float c){
    return ( -b - (sqrt( pow(b,2) - (4*a*c))) )/(2*a);
}

void imprimir(float x1, float x2){
    printf("\n\t La primera raiz es: %.3f", x1);
    printf("\n\t La segunda raiz es: %.3f\n\n", x2);
}

void datos(){
    float a, b, c, x1=0, x2=0;

    printf("\n\t Digita el coeficiente de x2: ");
    scanf("%f", &a);

    printf("\n\t Digita el coeficiente de x: ");
    scanf("%f", &b);

    printf("\n\t Digita el coeficiente lineal: ");
    scanf("%f", &c);

    x1 = formula_General1(a,b,c);
    x2 = formula_General2(a,b,c);

    imprimir(x1,x2);
}

int main(){
    datos();
    system("pause");

    return 0;
}
