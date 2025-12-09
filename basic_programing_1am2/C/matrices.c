#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void diagonal_Principal(float **v, int height, int width){

    printf("\n\t The principal diagonal is: ");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i==j){
                printf("%.2f ", v[i][j]);
            }
        }
    }
}

void diagonal_Secundaria(float **v, int height, int width){
    printf("\n\t The secondary diagonal is: ");
    for(int i=0;i<height;i++){
        for(int j=width;j>=0;j--){
            if((i+j)==height-1){
                printf("%.2f ", v[i][j]);
            }
        }
    }
}

void captura(float **v, int height, int width){
    printf("\n\t Type the elements for your matrix: \n\t ");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            scanf("%f", &v[i][j]);
        }
        printf("\t ");
    }
}

double get_Determinate(float **v, int n){
    double det = 0, aux = 0;
    int c;
    if(n==2){
        return v[0][0]*v[1][1]-v[0][1]*v[1][0];
    }else{
        
        for(int i=0;i<n;i++){
            float **menor = (float **)malloc(sizeof(float)*(n-1));
            for(int h=0;h<(n-1);h++){
                menor[h] = (float *)malloc(sizeof(float)*(n-1));
            }

            for(int k=1;k<n;k++){
                c = 0;

                for(int l=0;l<n;l++){
                    if(l!=i){
                        menor[k-1][c] = v[k][l];
                        c++;
                    }
                }
            }

            aux = pow(-1, 2+i)*v[0][i]*get_Determinate(menor, n-1);

            det+= aux;

            for(int q=0;q<n-1;q++){
                free(menor[q]);
            }

            free(menor);
        }
    }

    return det;

}

void get_Inver_Matrix(float **v, int n){
    printf("\n\t La matriz inversa es: ");
}

void get_Matrix(float **v, int height, int width){
    printf("\n\t Your matrix is: \n");
    for(int i=0;i<width;i++){
        printf("\t ");
        for(int j=0;j<height;j++){
            printf("%.f ", v[i][j]);
        }
        printf("\n");
    }

}

void get_Transpuesta(float **v, int heiht, int width){
    printf("\n\t The transposed matrix is: \n");
    for(int i=0;i<heiht;i++){
        printf("\t ");
        for(int j=0;j<width;j++){
            printf("%.f ", v[j][i]);
        }
        printf("\n");
    }
}


int main(){

    int width, height;

    printf("\n\t Type the dimenssions for your matrix: ");
    scanf("%d",&width);
    scanf("%d",&height);
    printf("\n\t The dimenssions of your matrix are: %d, %d", width, height);

    float **array2d = malloc(sizeof(*array2d) * height);
    float  *array1d = malloc(sizeof(*array1d) * width* height);

    for (int i = 0; i < height; ++i){
        array2d[i] = &array1d[i * width];
    }

    captura(array2d, height, width);
    get_Matrix(array2d, height, width);
    diagonal_Principal(array2d, height, width);
    diagonal_Secundaria(array2d, height, width);
    get_Transpuesta(array2d, height, width);
    printf("\n\t The determinant of your matrix is: %f", get_Determinate(array2d, height));

    printf("\n");

    return 0;
}


