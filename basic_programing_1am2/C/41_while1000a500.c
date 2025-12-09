/*
    Decrementos de 10 en 10
*/

#include<stdlib.h>
#include<stdio.h>

int main(){
    int i=1000;

    while(i>=500){
        printf("%d\n",i);
        i-=10;
    }

    return 0;
}