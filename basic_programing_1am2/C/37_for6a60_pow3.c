#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void datos(){
    for(int i=6;i<=60;i+=6){
        printf("\n%.f", pow(i, 3));
    }
}

int main(){

    datos();
    return 0;
}