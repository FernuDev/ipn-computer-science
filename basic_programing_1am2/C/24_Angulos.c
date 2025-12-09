/*
    Generar un programa que clasifique los angulos 

    Luis Fernando Nuñez Rangel
    Ing Aeronautica 1AM2

*/
#include<stdlib.h>
#include<stdio.h>

void angulos(float a){
    if(a<90 && a>0){
        printf("\n\t Es un angulo agudo ");
    }else if(a==90){
        printf("\n\t Es un angulo recto ");
    }else if(a<180 && a>90){
        printf("\n\t Es un angulo obtuso ");
    }else if(a==180){
        printf("\n\t Es un angulo llano");
    }else if(a>180 && a<360){
        printf("\n\t Es un angulo concavo");
    }else if(a==360){
        printf("\n\t Es un angulo completo");
    }
}

void datos(){
    float a;
    printf("\n\t Digita un angulo: ");
    scanf("%f", &a);

    angulos(a);
}

int main(){
    datos();

    return 0;
}