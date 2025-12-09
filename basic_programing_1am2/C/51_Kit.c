#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

float calcularPagoMensual(float, int);

int main(){
	char opcion;
	do{
		printf("Bienvenido al kit de aeromodelismo\n");
		
		float precio;
		do {
			printf("Ingresa el precio del kit (entre 250 y 1200):\n");
			scanf("%f", &precio);
		} while (precio < 250 || precio > 1200);
		
		int meses;
		do {
			printf("Selecciona los meses a pagar:\n");
			printf("1. 3 meses sin intereses\n");
			printf("2. 6 meses sin intereses\n");
			printf("3. 9 meses sin intereses\n");
			scanf("%d", &meses);
		} while (meses < 1 || meses > 3);
		
		float pagoMensual = calcularPagoMensual(precio, meses);
		printf("El pago mensual es de: %.2f\n", pagoMensual);
		
		printf("Presiona enter para hacer otra compra, o cualquier otra tecla para salir\n");
		opcion = getch();
	} while(opcion == 13);
}

float calcularPagoMensual(float precio, int meses) {
	switch(meses) {
		case 1:
			return precio / 3;
		case 2:
			return precio / 6;
		case 3:
			return precio / 9;
		default:
			return 0;
	}
}
