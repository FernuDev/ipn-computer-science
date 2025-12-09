/*
    Luis Fernando Nuñez Rangel
    Ingenieria Aeronautica

    Fundamentos de programacion 1AM2

*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

float promedio(float calificaciones[]){
    float sum = 0;
    for(int i=0;i<6;i++){
        sum+=calificaciones[i];
    }

    return sum/6;
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

void datos(){

    char Materias[6][20] = {"Fisica", "Calculo", "Quimica", "Algebra Lineal", "Programacion", "Humanidades"};
    float prom = 0;
    float calificaciones[6];

    printf("\n\tDigita tus calificaciones: \n");
    for(int i=0;i<6;i++){
        printf("\t %s: ", Materias[i]);
        scanf("%f", &calificaciones[i]);

        if(calificaciones[i]<0||calificaciones[i]>10){
            do{
                printf("\n\tNumero fuera de rango, digita un valor valido entre 0 y 10:");
                printf("\n\t%s: ",Materias[i]);
                scanf("%f", &calificaciones[i]);
            }while(calificaciones[i]<0||calificaciones[i]>10); 
        }
    }
    prom = promedio(calificaciones);
    Imprimir_Datos(prom,calificaciones);
    printf("\n\tPulsa 1 si quieres salir y 0 para reiniciar: ");

}

void app(){
    int n=0;
    do{
        datos();
        scanf("%d",&n);
    }while(n==0);
}

int main(){

    app();

    return 0;
}