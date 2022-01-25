/*	
	Realizar un programa que implemente una lista enlazada doble circular.
	Soto Tirado Jesús Eduardo TCI 4-3	
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 

struct nodo
{
  int codigo;
  char nombre[20];
  float costo;
  int existencia;
  struct nodo *ant, *sig;
};

typedef struct nodo NODO;
typedef NODO *NODOPTR;
typedef int cod;
typedef char nom[20];
typedef float cost;
typedef int exist;

void menu();
void inserta(NODOPTR *,cod,nom,cost,exist);
bool elimina(NODOPTR *,int);
int esvacia(NODOPTR);
void imprime(NODOPTR);
void adelante(NODOPTR *);
void atras(NODOPTR *);

main()
{ 
	NODOPTR lista = NULL, actual = NULL;
	int op;
	int cod;
	char nom[20];
	float cost;
	int exist;
	do{
		system("cls");
		menu();
		scanf("%d",&op);
		switch(op)
	{
			case 1: 	printf("CODIGO: ");//se piden los datos al usuario
						scanf("%d",&cod);
						fflush(stdin);
						printf("NOMBRE: ");
						gets(nom);
						fflush(stdin);
						printf("COSTO: ");
						scanf("%f",&cost);
						fflush(stdin);
						printf("EXISTENCIA: ");
						scanf("%d",&exist);
						fflush(stdin);
						inserta(&lista,cod,nom,cost,exist);
						actual = lista;
						imprime(lista);
						getch();
						break;
			case 2:	if(!esvacia(lista))
						{
							printf("\n Cual codigo sera borrado ?");
							scanf("%d",&cod);
							if(elimina(&lista,cod))
						{
							printf("\n %d ha sido borrado",cod);
							actual = lista;
							imprime(lista);
						}
						else
							printf("\n %d no pudo ser borrado",cod);
						}
						else
						printf("\n La lista esta vacia ");
						getch();
						break;
			case 3: imprime(lista);
					getch();
					break;
			case 4: adelante(&actual);
					getch();
					break;
			case 5: atras(&actual);
					getch();
					break;
	}

	}while(op != 6);
}
void menu()
{
	printf(" MENU DE OPCIONES \n");
	printf("\n 1. Insertar");
	printf("\n 2. Borrar ");
	printf("\n 3. Imprime");
	printf("\n 4. Mover hacia adelante ");
	printf("\n 5. Mover hacia atras ");
	printf("\n 6. Salir ");
	printf("\n\n Selecciona una opcion: ");
}
void inserta(NODOPTR *ptr,cod cod_t,nom nom_t,cost cost_t,exist exist_t){
{
	NODOPTR nuevo, actual, antes;
	nuevo = (NODO *) malloc(sizeof(NODO));
	if(nuevo == NULL)
		printf("\n Los valores no pueden ser insertados");
	else
	{
		if(esvacia(*ptr))
		{
			nuevo->codigo = cod_t;
			strcpy(nuevo->nombre,nom_t);
			nuevo->costo = cost_t;
			nuevo->existencia = exist_t;
			nuevo->ant = nuevo;
			nuevo->sig = nuevo;
			*ptr = nuevo;
		}
		else{
			nuevo->codigo = cod_t;
			strcpy(nuevo->nombre,nom_t);
			nuevo->costo = cost_t;
			nuevo->existencia = exist_t;
			antes = NULL;
			actual = *ptr;
			while(actual->sig != *ptr && cod_t >= actual->codigo )
			{
				antes = actual;
				actual = actual->sig;
			}
			if(antes == NULL && cod_t < actual->codigo)
			{
				while(actual->sig != *ptr)
				{
					actual = actual->sig;
				}
				nuevo->sig = *ptr;
				nuevo->ant = actual;
				actual->sig = nuevo;
				*ptr = nuevo;				
			}
			else if(actual->sig == *ptr && cod_t >= actual->codigo)
			{
				actual->sig = nuevo;
				nuevo->ant = actual;
				nuevo->sig = *ptr;
				(*ptr)->ant = nuevo;
			}
			else 
			{
				antes->sig = nuevo;
				nuevo->ant = antes;
				nuevo->sig = actual;
				actual->ant = nuevo;
			}			
		}
	}

}
}
bool elimina(NODOPTR *ptr,int valor){
	 NODOPTR antesptr, actualptr, tempptr;
	 actualptr = *ptr;
	 if(actualptr == actualptr->sig) {
		if(valor == actualptr->codigo){
			*ptr = NULL;
			free(actualptr);
			return true;	
		}else{
			return false;
		}		
	 }else{
		antesptr = *ptr;
		actualptr = (*ptr)->sig;
		while(actualptr != *ptr && actualptr->codigo != valor){
			antesptr = actualptr;
			actualptr = actualptr->sig;
		}
		if(actualptr != *ptr && actualptr->codigo == valor){
			tempptr = actualptr;
			antesptr->sig = actualptr->sig;
			actualptr = actualptr->sig;
			actualptr->ant = antesptr;
			free(tempptr);
			return true;
		}else if(actualptr == *ptr && actualptr->codigo == valor){
			tempptr = actualptr;
			antesptr->ant = actualptr->ant;
			antesptr->sig = actualptr->sig;
			*ptr = antesptr;
			free(tempptr);
			return true;
		}else{
			return false;
		}			
	 }
	 return false;
}
void adelante(NODOPTR *act){
	if (act != NULL){
		*act = (*act)->sig;
		printf("\n CODIGO: %d NOMBRE: %s COSTO: %.2f EXISTENCIA: %d ---> \n",(*act)->codigo,(*act)->nombre,(*act)->costo,(*act)->existencia);
	}
}
void atras(NODOPTR *act){
	if (act != NULL){
		*act = (*act)->ant;
		printf("\n <-- CODIGO: %d NOMBRE: %s COSTO: %.2f EXISTENCIA: %d \n",(*act)->codigo,(*act)->nombre,(*act)->costo,(*act)->existencia);
	}
}
int esvacia(NODOPTR ptr){
	return ptr == NULL;
}
void imprime(NODOPTR actualptr){
	NODOPTR cabecera = actualptr;
	if(esvacia(actualptr))
		printf("\n La lista esta vacia ");
	else
	{
		printf("\n Los elementos de la lista son: \n -->");
		while(actualptr->sig != cabecera)
		{
			printf("CODIGO: %d\tNOMBRE: %s\tCOSTO: %.2f\tEXISTENCIA: %d--> ",actualptr->codigo,actualptr->nombre,actualptr->costo,actualptr->existencia);
			actualptr = actualptr->sig;
		}
		if(actualptr->sig == cabecera)
			printf("CODIGO: %d\tNOMBRE: %s\tCOSTO: %.2f\tEXISTENCIA: %d--> ",actualptr->codigo,actualptr->nombre,actualptr->costo,actualptr->existencia);
	}
}
