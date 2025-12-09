#include <stdio.h>
#include <math.h>

double factorial(int x){
    double factorial=1;
    if(x<2){
        return 1; 
    }
    for(int i=x;i>0;i--){
        factorial*=i;
    }
    return factorial;
}

double seno(double x){

    double seno = 0;
    int signo = 1;
    for(int i=1;i<100;i+=2){
        seno+=signo*pow(x, i)/factorial(i); 
        signo*=-1;           
    }

    seno = round(seno);
    return seno;
}

double coseno(double x){
    double coseno = 0;
    int signo = 1;

    for(int i=0;i<100;i+=2){
        coseno+=signo*pow(x, i)/factorial(i);
        signo*=-1;
    }

    coseno = round(coseno);
    return coseno;
}

void datos(){
    int ch = 0;

    do{
        printf("\n\t ====== Calculadora trigonometrica ======");
        printf("\n\t 1. Seno x");
        printf("\n\t 2. Cos x");
        printf("\n\t 3. Tan x");
        printf("\n\t 4. Salir\n\t ");

        scanf("%d", &ch);

        float angle;
        switch (ch)
        {
        case 1:
            /* code */
            printf("\n\t Digita el angulo: ");

            scanf("%f", &angle);

            angle = (angle*3.14159)/180;


            printf("\n\t El seno de x es: %f\n\n", seno(angle));

            break;
        
        case 2:
            printf("\n\t Digita el angulo: ");
            scanf("%f", &angle);


            angle = (angle*3.14159)/180;

            printf("\n\t El cose de x es: %f\n\n", coseno(angle));

            break;

        case 3:
            printf("\n\t Digita el angulo: ");
            scanf("%f", &angle);

            angle = (angle*3.14159)/180;

            printf("\n\t La tan de x es: %f\n\n", sin(angle)/cos(angle));

            break;
        
        case 4:
            printf("\n\t Gracias por usar la App");
            break;
        
        default:
            printf("\n\t Digita un numero valido: ");
            scanf("%d", &ch);
            break;
        }

    }while(ch!=4);
}

int main(){
    datos();
    return 0;
}
