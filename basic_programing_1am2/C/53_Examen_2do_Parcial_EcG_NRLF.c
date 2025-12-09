#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>


struct raices{
    double x1;
    double x2;
    bool isC;
};

struct raices ec_Coeficientes(float a, float b, float c){
    double det = pow(b,2)-(4*a*c);


    struct raices res;

    if(det<0){
        det*=-1;

        res.x1 = (-b)/(2*a);
        res.x2 = (sqrt(det))/(2*a);
        res.isC = true;
    }else if(det>=0){
        res.x1 = (-b+sqrt(det))/(2*a);
        res.x2 = (-b-sqrt(det))/(2*a);
        res.isC = false;
    }

    return res;

}

int app(){

    system("Color 0A");
    printf("\n\n\t Menu de formula general");
    printf("\n\t 1.- Ingresar coeficientes");
    printf("\n\t 2.- Salir\n\t");

    int option = 0;
    scanf("  %d", &option);

    float a = 0;
    float b = 0;
    float c = 0;

    char ecuation[100];

    switch (option)
    {
    case 1:
        

        printf("\n\t Digita los coeficientes: ");
        printf("\n\t A: ");
        scanf("%f", &a);

        if(a==0){
            do{
                printf("\n\t El coeficiente cuadratico no puede ser 0");
                printf("\n\t Digita un numero valido: ");
                scanf("%f", &a);
            }while(a==0);
        }

        printf("\n\t B: ");
        scanf("%f", &b);
        printf("\n\t C: ");
        scanf("%f",&c);

        struct raices res = ec_Coeficientes(a,b,c);

        if(res.isC){
            printf("\n\tLas raices son: ");
            printf("\n\t %f + %fi", res.x1, res.x2);
            printf("\n\t %f - %fi", res.x1, res.x2);
        }else {
            printf("\n\t Las raices son: ");
            printf("\n\t %f, %f", res.x1, res.x2);
        }


        return 1;
        break;
   
    case 2:
        printf("\n\t Gracias por usar el programa");
        return 0;
        break;
    
    default:
        system("cls");
        printf("\n\t Numero fuera de rango, ingresa una opcion correcta: ");
        break;
    }


}


int main(){
    int n;
    do{
        n=app();
    }while(n!=0);

    return 0;
}