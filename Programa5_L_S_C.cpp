/*
Realizar un programa en lenguaje C que utilicen lista simple circular.
Soto Tirado Jesús Eduardo TCI 4-3 08 de Octubre de 2019
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct nodo{
	char nombre[20];
	int codigo;
	int existencia;
	float costo;
	struct nodo *next;
};

typedef struct nodo NODO;
typedef NODO *NODOPTR;
typedef int cod;
typedef char nom[20];
typedef float costo;
typedef int existencia;

void insertar(NODOPTR *,cod,nom,costo,existencia);
int borrar(NODOPTR *,int);
int esvacia (NODOPTR);
void imprime (NODOPTR);
void adelante(NODOPTR *);
void menu();

main(){
	NODOPTR lista = NULL, act = NULL;
	int op;
	int cod;
	char nom[20];
	float costo;
	int existencia;
	do{
		system("cls");
		menu();
		scanf("%d",&op);
		fflush(stdin);
		switch(op){
			case 1:
				printf("Codigo: ");
				scanf("%d",&cod);
				fflush(stdin);
				printf("Nombre: ");
				gets(nom);
				fflush(stdin);
				printf("Costo: ");
				scanf("%f",&costo);
				printf("Existencia: ");
				scanf("%d",&existencia);
				fflush(stdin);
				insertar(&lista,cod,nom,costo,existencia);
				act = lista;
				imprime(lista);
				getch();
				break;
			case 2:
				if(!esvacia(lista)){
					printf("\nCual codigo sera borrado? ");
					scanf("%d",&cod);
					if(borrar(&lista,cod)>=0){
						printf("\n%d ha sido borrado",cod);
						imprime(lista);
					}
					else
						printf("\n%d no pudo ser borrado",cod);
						
				}
				else
					printf("\nLa lista esta vacia ");
					getch();
					break;
		}
	}while(op!=3);
}
void menu(){
	printf("Menu de Opciones: ");
	printf("\n1. Insertar ");
	printf("\n2. Borrar ");
	printf("\n3. Salir");
	printf("\nSelecciona una opcion: ");
}
void imprime (NODOPTR actualptr){
	NODOPTR cabecera = actualptr;
	if(esvacia(actualptr))
		printf("\nLa lista esta vacia");
	else{
		printf("\nLos elementos de la lista son: \n");
		while(actualptr->next != cabecera){
			printf("CODIGO: %d\tNOMBRE: %s\t COSTO: %.2f EXISTENCIA: %d ---> \n",actualptr->codigo,actualptr->nombre,actualptr->costo,actualptr->existencia);
			actualptr = actualptr->next;
		}
		if(actualptr->next == cabecera)
			printf("CODIGO: %d\tNOMBRE: %s\t COSTO: %.2f EXISTENCIA: %d ---> \n",actualptr->codigo,actualptr->nombre,actualptr->costo,actualptr->existencia);
	}
}
int esvacia(NODOPTR ptr){
	return ptr == NULL;
}
void insertar(NODOPTR *ptr, cod cod_t,nom nom_t,costo cost_t,existencia exist_t){
	NODOPTR nuevo, actual,antes;
	nuevo = (NODO *)malloc(sizeof(NODO));
	if(nuevo == NULL)
		printf("Los valores no pueden ser insertados");
	else{
		if(esvacia(*ptr)){
			nuevo->codigo = cod_t;
			strcpy(nuevo->nombre,nom_t);
			nuevo->costo = cost_t;
			nuevo->existencia = exist_t;
			nuevo->next = nuevo;
			*ptr = nuevo;
		}
		else{
			nuevo->codigo = cod_t;
			strcpy(nuevo->nombre,nom_t);
			nuevo->costo = cost_t;
			nuevo->existencia = exist_t;
			antes = NULL;
			actual = *ptr;
			while(actual->next != *ptr && cod_t >= actual->codigo){
				antes = actual;
				actual = actual->next;
			}
			if(antes == NULL && cod_t < actual->codigo){
				while(actual->next != *ptr){
					actual = actual->next;
				}
				nuevo->next = *ptr;
				*ptr = nuevo;
				actual->next = *ptr;
			}
			else if(actual->next == *ptr && cod_t >= actual->codigo){
					actual->next = nuevo;
					nuevo->next = *ptr;
			}
			else{
				antes->next = nuevo;
				nuevo->next = actual;
			}
		}
	}
}
void adelante(NODOPTR *act){
	if(act != NULL)
	{
		*act = (*act)->next;
		printf("CODIGO: %d\tNOMBRE: %s\t COSTO: %.2f EXISTENCIA: %d ---> \n",(*act)->codigo,(*act)->nombre,(*act)->costo,(*act)->existencia);
	}
}
int borrar(NODOPTR *ptr,int valor){
		NODOPTR antesptr,actualptr,tempptr;
		if(valor == (*ptr)->codigo){
			tempptr = *ptr;
			*ptr = (*ptr)->next;
			free(tempptr);
			return valor;
		}
		else{
			antesptr = *ptr;
			actualptr=(*ptr)->next;
			while(actualptr != NULL && actualptr->codigo != valor){
				antesptr = actualptr;
				actualptr = actualptr->next;
			}
			if(actualptr != NULL){
				tempptr = actualptr;
				antesptr->next = actualptr->next;
				free(tempptr);
				return valor;
			}
		}
		return -1;
	}
