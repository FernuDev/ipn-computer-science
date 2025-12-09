
/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/
#include<stdio.h>
#include<stdlib.h>

void datos_Clase();
void imprime(char clave[], int folio, int web_ID, float precio, float monto);

int main (){

    datos_Clase();

    return 0;
}

void datos_Clase(){
    char clave[4] = "E012";
    int folio = 967, web_ID = 7238;
    float precio = 22.189, monto = 1107.5;

    imprime(clave, folio, web_ID, precio, monto);
}

void imprime(char clave[], int folio, int web_ID, float precio, float monto){
    printf("\n\t Clave de estacion: %s", clave);
    printf("\n\t Folio: %d", folio);
    printf("\n\t WEB_ID: %d", web_ID);
    printf("\n\t Precio: %.2f", precio);
    printf("\n\t Monto total: %.2f", monto);
    
};