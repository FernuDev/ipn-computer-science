#include <stdlib.h>
#include <stdio.h>

int main(){

    int *ptr;
    int n;

    printf("\n\t Digita los elementos de tu arreglo: ");
    scanf("%d", &n);
    printf("\n\t El numero de elementos de tu vecotor es: %d", n);

    ptr = (int*)malloc(n*sizeof(int));

    if(ptr == NULL){
        printf("\n\t No allocated memory\n");
    }else {
        printf("\t Memory successfully allocated using malloc\n");

        for(int i=0;i<n;i++){
            ptr[i] = i+1;
        }

        printf("\n\t Los elementos de tu array son: ");

        for(int i=0;i<n;i++){
            printf("%d, ", ptr[i]);
        }
    }

    return 0;
}