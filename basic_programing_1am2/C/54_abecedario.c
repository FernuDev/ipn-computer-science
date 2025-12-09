#include<stdio.h>
#include<stdlib.h>

void app(){
    printf("\n\t====== Impresion del abecedario ======");
    char abecedario[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O', 'P', 'Q', 'R','S', 'T', 'U','V','W','X','Y','Z'};

    printf("\n\t");
    for(int i=0;i<26;i++){
        printf("%c",abecedario[i]);
    }


}

int main(){
    app();
    return 0;
}