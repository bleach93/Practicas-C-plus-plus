#include <stdio.h>
int main(){
    int f1,c1,f2,c2,i,j,k,x;
    float A[100][100],B[100][100],C[100][100];
    printf("\nCaptura la fila y la columna de la primera matriz: \n");
    printf("\nFilas: ");
    scanf("%d",&f1);
    printf("\nColumnas: ");
    scanf("%d",&c1);
    printf("\nCaptura la fila y la columna de la segunda matriz: \n");
     printf("\nFilas: ");
    scanf("%d",&f2);
    printf("\nColumnas: ");
    scanf("%d",&c2);
    printf("\n");
    if (f1==f2){
       printf("Ingresa los valores de la primera matriz: \n\n");
       for (i=1;i<=f1;i++)
           for (j=1;j<=c1;j++){
               printf("A(%d,%d)= ",i,j);
               scanf ("%f",&A[i][j]);
           }
    printf("Ingresa los valores de la segunda matriz: \n\n");
    for (i=1;i<=f2;i++)
        for (j=1;j<=c2;j++){ 
            printf("B(%d,%d)= ",i,j);
            scanf ("%f",&B[i][j]);
        }
    for (i=1;i<=f1;i++){
        for (j=1;j<=c2;j++){
            C[i][j]=0;
            for (k=1;k<=c1;k++){
                C[i][j]=C[i][j]+A[i][k]*B[k][j];
            }
       }
    }
    printf("El resultado es: ");
    for (i=1;i<=f1;i++)
        for (j=1;j<=c2;j++){ 
            printf("%4.2f\n",i,j,C[i][j]);
         }
    }
    else{
         printf("Estas matrices no se pueden multiplicar");
    }
    getchar(); 
    getchar();
}

