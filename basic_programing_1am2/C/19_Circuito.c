/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float I_Corriente1(float E1, float E2, float R1, float R2, float R3){
    return (E2*R3 + E1*(R1+R3))/((R1+R3)*(R2+R3)-pow(R3,2));
}

float I_Corriente2(float E1, float E2, float R1, float R2, float R3){
    return (E1*R3 + E2*(R1+R3))/((R1+R3)*(R2+R3)-pow(R3,2));
}

float I3(float i1, float i2){
    return i1-i2;
}

void imprimir(float i1, float i2, float i3){
    printf("\n\t Los resultados de tu circuito son: ");
    printf("\n\t I1 = %.2f A", i1);
    printf("\n\t I2 = %.2f A", i2);
    printf("\n\t I3 = %.2f A", i3);

}

void datos(){
    //Variables
    float E1 = 12, E2 = 9, R1 = 10, R2 = 4, R3 = 6;

    //Resultados
    float i1 = I_Corriente1(E1, E2, R1, R2, R3);
    float i2 = I_Corriente2(E1, E2, R1, R2, R3);

    float i3 = I3(i1, i2);

    //Imprimir resultados
    imprimir(i1, i2, i3);
}

int main(){
    datos();
    system("pause");

    return 0;
}