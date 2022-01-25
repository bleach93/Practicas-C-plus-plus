/* 
	Programa que controla los datos de los trabajadores con colas.
	Soto Tirado Jesús Eduardo 4-3
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct nodo{
	int ni;
	char nombre[30];
	char domicilio[30];
	int sf;
	int hrst;
	struct nodo *sig;
};

typedef struct nodo NODO;
typedef NODO *NODOPTR;
typedef int ni;
typedef char nomb[30];
typedef char domc[30];
typedef int sldo;
typedef int Ht;

void poner(NODOPTR *,ni,nomb,domc,sldo,Ht);
void quitar(NODOPTR *);
char esvacia(NODOPTR);
void mostrar(NODOPTR);
void menu();

main(){
	NODOPTR cima=NULL;
	int op;
	int ni;
	char nomb[30];
	char domc[30];
	int sldo;
	int Ht;
	do{
		menu();
		scanf("%d",&op);
		switch(op){
			case 1:
				system("cls");
				printf("Clave: ");
				scanf("%d",&ni); fflush(stdin);
				printf("Nombre: ");
				gets(nomb); fflush(stdin);
				printf("Domicilio: ");
				gets(domc); fflush(stdin);
				printf("Sueldo: ");
				scanf("%d",&sldo); fflush(stdin);
				printf("Horas trabajadas: ");
				scanf("%d",&Ht); fflush(stdin);
				poner(&cima,ni,nomb,domc,sldo,Ht);
				break;
			case 2:
				if(!esvacia(cima)){
					quitar(&cima);
				}
				else{
					printf("\nLa pila esta vacia\n");
				}
				break;
			case 3:
				mostrar(cima);
				break;
		}
	}while(op != 4);
}

void menu(){
	printf("Menu");
	printf("\n1.- Poner");
	printf("\n2.- Quitar");
	printf("\n3.- Mostrar");
	printf("\n4.- Salir");
	printf("\nSeleccione una opcion: ");
}

void mostrar(NODOPTR cima){
	if(cima==NULL){
		printf("\nLa cola esta vacia\n");
	}
	else{
		printf("Los elementos de la cola son: ");
		while(cima!=NULL){
			printf("\nClave: %d",cima->ni);
			printf("\nNombre: %s",cima->nombre);
			printf("\nDomicilio: %s",cima->domicilio);
			printf("\nSueldo: %d",cima->sf);
			printf("\nHoras: %d --> ",cima->hrst);
			cima=cima->sig;
		}
		printf("NULL\n");
	}
}

char esvacia(NODOPTR cima){
	return (cima==NULL);
}

void poner(NODOPTR *cima,ni ni1,nomb nom1,domc domc1,sldo suel1,Ht Ht1){
	NODOPTR nuevo,actual;
	nuevo=(NODO *)malloc(sizeof(NODO));
	if(nuevo==NULL)
		printf("\n %d %s %s %d %d no puede ser insertado",ni1,nom1,domc1,suel1,Ht1);
	else
	{
		if(esvacia(*cima)){
			nuevo->ni=ni1;
			strcpy(nuevo->nombre,nom1);
			strcpy(nuevo->domicilio,domc1);
			nuevo->sf=suel1;
			nuevo->hrst=Ht1;
			nuevo->sig=NULL;
			*cima=nuevo;
		}
		else{
			nuevo->ni=ni1;
			strcpy(nuevo->nombre,nom1);
			strcpy(nuevo->domicilio,domc1);
			nuevo->sf=suel1;
			nuevo->hrst=Ht1;
			nuevo->sig=NULL;
			actual=*cima;
			while(actual->sig!=NULL){
				actual=actual->sig;
			}
			actual->sig=nuevo;
		}
	}
}

void quitar(NODOPTR *cima){
	NODOPTR temptr;
	temptr=*cima;
	*cima=(*cima)->sig;
	free(temptr);
}
