#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void datos(){
    for(int i=20;i<=400;i+=2){
        printf("\n%f", sqrt(i));
    }
}

int main(){
    
    datos();

    return 0;
}