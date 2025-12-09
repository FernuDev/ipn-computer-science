/*
    Desarrolla la ecuacion de la pendiente y el 
    punto medio entre dos puntos 

    Luis Fernando Nuñez Rangel
    Ing Aeronautica 1AM2

*/

#include<stdlib.h>
#include<stdio.h>

//Envolvemos los multiples valores en un struct

struct P_medio
{
    /* data */
    float m_x;
    float m_y;
};


float pendiente(float x1, float x2, float y1, float y2){
    return (y2-y1)/(x2-x1);
}

struct P_medio punto_Medio(float x1, float x2, float y1, float y2){
    struct P_medio punto_M= { (x1+x2)/2 , (y1+y2)/2 };
    return punto_M;
}

void datos(){
    float x1, x2, y1, y2, m;
    struct P_medio puntos;

    printf("\n\t Digita las coordenadas de los dos puntos: ");
    
    printf("\n\t X1: ");
    scanf("%f", &x1);

        
    printf("\n\t Y1: ");
    scanf("%f", &y1);

        
    printf("\n\t X2: ");
    scanf("%f", &x2);

        
    printf("\n\t Y2: ");
    scanf("%f", &y2);

    m = pendiente(x1,x2,y1,y2);

    puntos = punto_Medio(x1,x2,y1,y2);

    printf("\n\t La pendiente de tu recta es: %.3f", m);
    printf("\n\t El punto medio entre (%.f, %.f) y (%.f, %.f) es: (%.3f, %.3f)", x1,y1,x2,y2, puntos.m_x, puntos.m_y);
    
    
}

int main(){

    datos();
    system("pause");


    return 0;
}