// Genera un programa que solicite al usuario un numero de materias y la calificacion de las mismas para calcular el promedio

/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

float Promedio(float calificaciones[]);
void Datos_Clase();
void Imprimir_Datos(float promedio, float calificaciones[]);

int main(){
    Datos_Clase();
    return 0;
}

float Promedio (float calificaciones[] ){
    float promedio = 0;
    for(int i=0;i<6;i++){
        promedio+=calificaciones[i];
    }
    return promedio / 6;
}


void Imprimir_Datos(float promedio, float calificaciones[]){
    printf("\n\t Aqui tienes tu reporte academico: ");
    printf("\n\t Fisica:  %.2f", calificaciones[0]);
    printf("\n\t Calculo:  %.2f", calificaciones[1]);
    printf("\n\t Quimica:  %.2f", calificaciones[2]);
    printf("\n\t Algebra Lineal:  %.2f", calificaciones[3]);
    printf("\n\t Programacion:  %.2f", calificaciones[4]);
    printf("\n\t Humanidades:  %.2f", calificaciones[5]);

    printf("\n\t Tu promedio es: %.2f\n\n", promedio);
};

void Datos_Clase(){

    float calificaciones[6];

    float promedio = 0;

    printf("\n\t Bienvenido a tu programa de administracion escolar");
    printf("\n\t Digita por favor en orden la calificacion de las siguientes materias: \n");

    printf("\n\t Fisica: ");
    scanf("%f", &calificaciones[0]);

    printf("\n\t Calculo: ");
    scanf("%f", &calificaciones[1]);

    printf("\n\t Quimica: ");
    scanf("%f", &calificaciones[2]);

    printf("\n\t Algebra Lineal: ");
    scanf("%f", &calificaciones[3]);

    printf("\n\t Programacion I: ");
    scanf("%f", &calificaciones[4]);

    printf("\n\t Humanidades: ");
    scanf("%f", &calificaciones[5]);

    promedio = Promedio(calificaciones);

    Imprimir_Datos(promedio, calificaciones);

}