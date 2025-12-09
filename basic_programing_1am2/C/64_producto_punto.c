#include <stdlib.h>
#include <stdio.h>

void datos(void);
void captura(float v[]);
float producto_punto(float v1[], float v2[]);
void imprimir(float v1[], float v2[]);

int main(){
    datos();
    return 0;
}

void datos(void){
    printf("\n\t Producto punto de dos vectores: ");
    printf("\n\t Digita los datos de tu primer vector: ");
    float v1[3];
    captura(v1);
    printf("\n\t Digita los datos de tu segundo vector: ");
    float v2[3];
    captura(v2);

    float producto = producto_punto(v1, v2);
    printf("\n\t Tu producto punto es: %.2f", producto);
    imprimir(v1, v2);
}

void captura(float v[]){
    for(int i=0;i<3;i++){
        scanf("%f", &v[i]);
    }
}

float producto_punto(float v1[], float v2[]){
    float pX, pY, pZ;

    for(int i=0;i<3;i++){
        if(i==0){
            pX = v1[i]*v2[i];
        }else if(i==1){
            pY = v1[i]*v2[i];
        }else {
            pZ = v1[i]*v2[i];
        }
    }

    return pX+pY+pZ;
}

void imprimir(float v1[], float v2[]){
    char c;
    printf("\n\t Tu vector 1 es: ");
    for(int i=0, c='i';i<3;i++, c++){
        printf(" %.2f%c", v1[i], c);
    }

    printf("\n\t Tu vector 2 es: ");
    for(int i=0, c='i';i<3;i++, c++){
        printf(" %.2f%c",v2[i], c);
    }
}