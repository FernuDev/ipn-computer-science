/*
    Luis Fernando Nuñez Rangel 
    1AM2 Ingeniería Aeronautica
    Programación 1
*/

#include<stdio.h>
#include<stdlib.h>

void personaje(void);

int main(){

    personaje();

    system("pause");
    return 0;
}

void personaje (void)  { 
    system ("color 0A") ;
    printf("\n\t NOMBRE:Stephen Hawking") ;
    printf("\n\t Naci%c el 8 de enero de 1942 \t", 162) ;
    printf("\n\t hechos relevantes: fue un f%csico te%crico, astrof%csico, cosm%clogo y divulgador cient%cfico brit%cnico",161,162,161,162,161,160) ;
    printf("\n\t Muri%c el d%ca 14 de Marzo de 2018",162,161 );
    printf("\n\t Me agrada ya que gracias a %cl el humano podr%c descubrir la m%cquina del tiempo \t\n",130,160,160 );
}