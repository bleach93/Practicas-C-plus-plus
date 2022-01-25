/*
	Programa que utiliza pilas para capturar la clave, nombre, domicilio, suelto y horas trabajadas de un empleado.
	Soto Tirado Jesús Eduardo 4-3 
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct nodo{
	int clave;
	char nombre[50];
	char dom[50];
	float sueldo;
	int hrstrab;
	struct nodo *sig;//este es el campo siguiente
};

typedef struct nodo NODO;//typedef sirve para definir un tipo de dato en el codigo, da lo mismo usar NODO o nodo.
typedef NODO *NODOPTR;
typedef char cadena[50];

void poner (NODOPTR *,int key,cadena nom0,cadena dom0, float sueldo, int hrstra);
void quitar (NODOPTR *);
int esvaciar(NODOPTR);
void mostrar(NODOPTR);
void menu();//funcion para desplegar el menu

main(){
	NODOPTR cima = NULL;
	int op,cl,hrst;
	float sueld0;
	char nom0[50],dom0[50];
	do{
		menu();
		scanf("%d",&op); 
		fflush(stdin);
		switch(op){
			case 1:
				printf("\nNombre: ");
				gets(nom0);
				printf("\nDomicilio: ");
				gets(dom0);
				printf("\nClave: ");
				scanf("%d",&cl);
				printf("\nHoras: ");
				scanf("%d",&hrst);
				printf("\nSueldo: ");
				scanf("%f",&sueld0);
				fflush(stdin);
				poner(&cima,cl,nom0,dom0,sueld0,hrst);
				break;
				
			case 2:	
				if(!esvaciar(cima)){
					quitar(&cima);
				}
				else{
					printf("\nLa pila esta vacia ");
				}
				getch();
				break;
			case 3:
				mostrar(cima);
				break;			
		}
	}while(op != 4);	
}

void menu(){
	system("cls");
	printf("\n\tMENU DE OPCIONES: \n");
	printf("\n1.- Poner");
	printf("\n2.- Quitar");
	printf("\n3.- Mostrar");
	printf("\n4.- Salir");
	printf("\n\nSelecciona una opcion: ");
}

void mostrar (NODOPTR cima){//nodo ptr es un puntero
	system("cls");

	if(cima == NULL)
		printf("\nLa pila esta vacia");
	else{
		printf("\nLos elementos de la pila son: \n");
		while(cima != NULL){
			printf("\nClave\tnombre\tdomicilio\tsueldo\thoras");
			printf("\n%d|",cima->clave);
			printf("\t%s|",cima->nombre);
			printf("\t%s|",cima->dom);
			printf("\t%.2f|",cima->sueldo);
			printf("\t%d--->",cima->hrstrab);//imprime la informacion
			cima = cima->sig;//esto es igual a esto 1++
		}
		printf("NULL \n\n");
	}
	getch();
}

int esvaciar(NODOPTR cima){
	system("cls");
	return (cima == NULL);
}

void poner(NODOPTR *cima, int key,cadena nom0,cadena dom0, float sueldo, int hrstra){
	system("cls");
	
	NODOPTR nuevo;
	nuevo = (NODO *)malloc(sizeof(NODO));
		printf("\n Los no pueden ser insertado");
		if(esvaciar(*cima)){
			nuevo->clave = key;
			strcpy(nuevo->nombre,nom0);
			strcpy(nuevo->dom,dom0);
			nuevo->sueldo = sueldo;
			nuevo->hrstrab = hrstra;
			nuevo->sig = NULL;
			*cima = nuevo;//establecer la cima como el apuntador de nuevo
		}
		else{
			nuevo->clave = key;
			strcpy(nuevo->nombre,nom0);
			strcpy(nuevo->dom,dom0);
			nuevo->sueldo = sueldo;
			nuevo->hrstrab = hrstra;
			nuevo->sig=*cima;
			*cima=nuevo;//porque este es el ultimo que se inserto y queda en la cima. La variable nuevo se pierde despues de esto.
		}
}

void quitar(NODOPTR *cima){
	system("cls");
	NODOPTR tempptr;//esta es una variable auxiliar...
	tempptr = *cima;
	*cima = (*cima)->sig;//lo queeste en cima en su campo siguiente
	free(tempptr);// la funcion free libera la memoria
	printf("Eliminado");
}

