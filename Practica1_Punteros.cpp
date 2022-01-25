/*
    Programa que utiliza punteros y memoria dinamica.
    Soto Tirado Jesús Eduardo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct data  // Declarar la estructura
{   int code;
    char descript[50];
    float precio;
    int cantidad;
};

main(){
    struct data *ptr; // Declarar el puntero
    ptr = (struct data *) malloc(sizeof(struct data)); //Determina el espacio en memoria.
    printf("Codigo: "); 
	scanf("%d",&ptr -> code);
	fflush(stdin);	// Se utiliza para vaciar el buffer.
    printf("Descripcion: ");
	gets(ptr -> descript);
    printf("Precio: ");
	scanf("%f",&ptr -> precio);
	fflush(stdin);
    printf("Cantidad: ");
	scanf("%d",&ptr -> cantidad);
	fflush(stdin);
    printf("\n\nCodigo: %d \nDescripcion: %s \nPrecio: %.2f \nCantidad: %d", ptr -> code, ptr -> descript, ptr -> precio, ptr -> cantidad);
}
