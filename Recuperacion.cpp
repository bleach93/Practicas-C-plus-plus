/*
	Programa para implementar listas simple circular
	Eduardo Soto 4-3
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct nodo{
	char nombre[20];
	int clave;
	char domicilio[50];
	char fechaNac[10];
	struct nodo *next;
};

typedef struct nodo NODO;
typedef NODO *NODOPTR;
typedef int clave;
typedef char nom[20];
typedef char dom[50];
typedef char fechaNac[20];

void insertar(NODOPTR *,clave,nom,dom,fechaNac);
int borrar(NODOPTR *,int);
int esvacia (NODOPTR);
void imprime (NODOPTR);
void adelante(NODOPTR *);
void menu();

main(){
	NODOPTR lista = NULL, act = NULL;
	int op;
	int clave;
	char nom[20];
	char dom[50];
	char fechNac[10];
	do{
		system("cls");
		menu();
		scanf("%d",&op);
		fflush(stdin);
		switch(op){
			case 1:
				printf("Clave: ");
				scanf("%d",&clave);
				fflush(stdin);
				printf("Nombre: ");
				gets(nom);
				fflush(stdin);
				printf("Domicilio: ");
				gets(dom);
				printf("Fecha de Nacimiento(DD-MM-AAAA): ");
				gets(fechNac);
				fflush(stdin);
				insertar(&lista,clave,nom,dom,fechNac);
				act = lista;
				imprime(lista);
				getch();
				break;
			case 2:
				if(!esvacia(lista)){
					printf("\nCual clave sera borrada? ");
					scanf("%d",&clave);
					if(borrar(&lista,clave)>=0){
						printf("\n%d ha sido borrada",clave);
						imprime(lista);
					}
					else
						printf("\n%d no pudo ser borrada",clave);
						
				}
				else
					printf("\nLa lista esta vacia ");
					getch();
					break;
			case 3:
				adelante(&act);
				getch();
				break;
			case 4:
				imprime(lista);
				getch();
				break;
			case 5:
				break;
		}
	}while(op!=5);
}
void menu(){
	printf("Menu de Opciones: ");
	printf("\n1. Insertar ");
	printf("\n2. Borrar ");
	printf("\n3. Avanzar Siguiente ");
	printf("\n4. Mostrar todos");
	printf("\n5. Salir");
	printf("\nSelecciona una opcion: ");
}
void imprime (NODOPTR actualptr){
	NODOPTR cabecera = actualptr;
	if(esvacia(actualptr))
		printf("\nLa lista esta vacia");
	else{
		printf("\nLos elementos de la lista son: \n");
		while(actualptr->next != cabecera){
			printf("\nCLAVE: %d\nNOMBRE: %s\n DOMICILIO: %s \nFECHA DE NACIMIENTO: %s ---> \n",actualptr->clave,actualptr->nombre,actualptr->domicilio,actualptr->fechaNac);
			actualptr = actualptr->next;
		}
		if(actualptr->next == cabecera)
			printf("\nCLAVE: %d\nNOMBRE: %s\n DOMICILIO: %s \nFECHA DE NACIMIENTO: %s ---> \n",actualptr->clave,actualptr->nombre,actualptr->domicilio,actualptr->fechaNac);
			actualptr = actualptr->next;
	}
}
int esvacia(NODOPTR ptr){
	return ptr == NULL;
}
void insertar(NODOPTR *ptr, clave clave_t,nom nom_t,dom dom_t,fechaNac fechNac_t){
	NODOPTR nuevo, actual,antes;
	nuevo = (NODO *)malloc(sizeof(NODO));
	if(nuevo == NULL)
		printf("Los valores no pueden ser insertados");
	else{
		if(esvacia(*ptr)){
			nuevo->clave = clave_t;
			strcpy(nuevo->nombre,nom_t);
			strcpy(nuevo->domicilio,dom_t);
			strcpy(nuevo->fechaNac,fechNac_t);
			nuevo->next = nuevo;
			*ptr = nuevo;
		}
		else{
			nuevo->clave = clave_t;
			strcpy(nuevo->nombre,nom_t);
			strcpy(nuevo->domicilio,dom_t);
			strcpy(nuevo->fechaNac,fechNac_t);
			antes = NULL;
			actual = *ptr;
			while(actual->next != *ptr && clave_t >= actual->clave){
				antes = actual;
				actual = actual->next;
			}
			if(antes == NULL && clave_t < actual->clave){
				while(actual->next != *ptr){
					actual = actual->next;
				}
				nuevo->next = *ptr;
				*ptr = nuevo;
				actual->next = *ptr;
			}
			else if(actual->next == *ptr && clave_t >= actual->clave){
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
		printf("CLAVE: %d\tNOMBRE: %s\t DOMICILIO: %s\t FECHA DE NACIMIENTO: %s ---> \n",(*act)->clave,(*act)->nombre,(*act)->domicilio,(*act)->fechaNac);
	}
}
int borrar(NODOPTR *ptr, int valor)
{
	NODOPTR antesptr, actualptr,tempptr;
	int con=1;
	antesptr =*ptr;
	actualptr=(*ptr)->next;
	while(actualptr!= *ptr && actualptr->clave != valor)
	{
		antesptr =actualptr;
		actualptr =actualptr->next;
		if(actualptr ->clave ==valor)
			con=0;
	}
	if(actualptr->clave ==valor)
	{
		tempptr=actualptr;
		if(tempptr == *ptr)
		{
			*ptr =(*ptr)->next;
			if(actualptr->next == actualptr)
				*ptr=NULL;
		}
		antesptr->next= actualptr->next;
		free(tempptr);
		return valor;
	}
	return -1;
}

