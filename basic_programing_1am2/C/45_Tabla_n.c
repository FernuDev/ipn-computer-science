#include<stdlib.h>
#include<stdio.h>

int main(){

    int n;

    printf("\n\t Digita un numero: ");
    scanf("%d", &n);

    for(int i=1;i<11;i++){
        printf("\n\t %d x %d = %d",n,i,n*i );
    }
    


    return 0;
}