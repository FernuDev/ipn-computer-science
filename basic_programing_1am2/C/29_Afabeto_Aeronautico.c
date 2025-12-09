
/*

    Luis Fernando Nuñez Rangel
    Ing Aeronaitica 

    Fundamentos de programacion
*/

#include<stdlib.h>
#include<stdio.h>

void alfabeto(char letra){
    switch(letra)
	{
		case 'a':
		case 'A':
			printf("\n\t Alfa");
			break;
		case 'b':
		case 'B':
			printf("\n\t Bravo");
			break;
		case 'c':
		case 'C':
			printf("\n\t Charly");
			break;
		case 'd':
		case 'D':
			printf("\n\t Delta");
			break;
		case 'e':
		case 'E':
			printf("\n\t Eco");
			break;
		case 'f':
		case 'F':
			printf("\n\t Foxtrot");
			break;
		case 'g':
		case 'G':
			printf("\n\t Golf");
			break;
		case 'h':
		case 'H':
			printf("\n\t Hotel");
			break;
		case 'i':
		case 'I':
			printf("\n\t India");
			break;
		case 'j':
		case 'J':
			printf("\n\t Juliett");
			break;
		case 'k':
		case 'K':
			printf("\n\t Kilo");
			break;
		case 'l':
		case 'L':
			printf("\n\t Lima");
			break;
		case 'm':
		case 'M':
			printf("\n\t Metro");
			break;
		case 'n':
		case 'N':
			printf("\n\t Nectar");
			break;
		case 'o':
		case 'O':
			printf("\n\t Oscar");
			break;
		case 'p':
		case 'P':
			printf("\n\t Papa");
			break;
		case 'q':
		case 'Q':
			printf("\n\t Quebec");
			break;
		case 'r':
		case 'R':
			printf("\n\t Romeo");
			break;
		case 's':
		case 'S':
			printf("\n\t Sierra");
			break;
		case 't':
		case 'T':
			printf("\n\t Tango");
			break;
		case 'u':
		case 'U':
			printf("\n\t Union");
			break;
		case 'v':
		case 'V':
			printf("\n\t Victor");
			break;
		case 'w':
		case 'W':
			printf("\n\t Whiskey");
			break;
		case 'x':
		case 'X':
			printf("\n\t x-ray");
			break;
		case 'y':
		case 'Y':
			printf("\n\t Yankee");
			break;
		case 'z':
		case 'Z':
			printf("\n\t Zuluu");
			break;	
	}
}

void datos(){
    char letra;

    printf("\n\t Digita una letra: ");
    scanf("%c", &letra);

    alfabeto(letra);
}

int main(){

    datos();
    printf("\n");
    system("pause");

    return 0;
}