/*
    Calcular el IMC

    Ing Aeronautica
    Luis Fernando Nuñez Rangel
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float IMC(float h, float w){
    return w/pow(h,2);
}

void IMC_estatus(float IMC){
    if (IMC<18){
        printf("\n\tTienes bajo peso");
    }else if(IMC>=18 && IMC<=24.9){
        printf("\n\t Tienes un peso normal");
    }else if(IMC>=25 && IMC<=26.9){
        printf("\n\t Tienes sobrepeso");
    }else if(IMC>=27 && IMC<=29.9){
        printf("\n\t Tienes obesidad Grado I");
    }else if(IMC>=30 && IMC <=39.9){
        printf("\n\t Obesidad Grado II, Muy alto");
    }else if(IMC>=40){
        printf("\n\t Obesidad morbida");
    }
}

int main(){
    float h, w, imc;
    printf("\n\t Digita tu estatura y tu peso: ");
    scanf("%f %f", &h, &w);

    imc = IMC(h,w);
    printf("\n\t Tienes in IMC de: %.2f", imc);
    IMC_estatus(imc);

    return 0;
}
