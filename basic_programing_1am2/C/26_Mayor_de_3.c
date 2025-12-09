/*
    Desarrollar un programa que verifique que numero
    de 3 es mayor

    Ing Aeronautica 
    Luis Fernando Nuñez Rangel

*/

#include<stdlib.h>
#include<stdio.h>

float mayor(float a, float b, float c){
    if(a>b && a>c){
        return a;
    }else if(b>a && b>c){
        return b;
    }else if(c>b && c>a){
        return c;
    }
}

void datos(){
    float a,b,c;

    printf("\n\t Digita tres numeros: ");
    scanf("%f %f %f", &a,&b,&c);

    printf("\n\t a: %.2f b: %.2f c: %.2f", a,b,c);
    printf("\n\t El mayor de ellos es: %.2f", mayor(a,b,c));
}

int main(){

    datos();

    return 0;
}