/*
    Luis Fernando Nuñez Rangel
    Ing Aeronautica

    Realizar un programa que analice si un auto no circula 
    dependiendo del ultimo digito de su placa
*/

#include<stdlib.h>
#include<stdio.h>

void noCircula(char n){
    if(n=='5'||n=='6'){
        printf("\n\t No circiulas el Lunes");
    }else if(n=='7'||n=='8'){
        printf("\n\t No circulas el Martes");
    }else if(n=='3'||n=='4'){
        printf("\n\t No circulas el Miercoles");
    }else if(n=='1'||n=='2'){
        printf("\n\t No circulas el Jueves");
    }else if(n=='9'||n=='0'){
        printf("\n\t No circulas el Viernes");
    }
}

void datos(){
    char placa[7];
    printf("\n\t Digita tu placa: ");

    gets(placa);

    noCircula(placa[6]);
}

int main(){
    datos();

    return 0;
}