#include<stdio.h>
#include<stdlib.h>

void datos(){
    for(int i=300;i>=270;i-=3){
        printf("\n%d", i);
    }
}

int main(){

    datos();
    return 0;
}