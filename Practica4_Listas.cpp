#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct nodo{
	int codigo;
	char nombre[40];
	float costo;
	int existencia;
	struct nodo *next;	
};
typedef struct nodo NODO;
typedef NODO *NODOPTR;
void insertar (NODOPTR *, int, char *, float, int);
int borrar(NODOPTR *, int);
int esvacia(NODOPTR);
void imprime(NODOPTR);
void menu();
main() { 
	NODOPTR inicio = NULL;
	int op;
	int codigo, existencia;
	char nombre[40];
	float costo;
	do {
		system("cls");
		menu();
		scanf("%d", &op);
		switch(op) { 
			case 1:	
				puts("\nCodigo: ");
				scanf("%d", &codigo);
				fflush(stdin);
				puts("\nNombre: ");
				gets(nombre);
				puts("\nCosto: ");
				scanf("%f", &costo);
				puts("\nExistencia: ");
				scanf("%d", &existencia);
				insertar(&inicio, codigo, nombre, costo, existencia);
				imprime(inicio);
				getch();
				break;
			case 2: 
				if(!esvacia(inicio)) {
					puts("\nCual id sera borrado? ");
					scanf("%d",&codigo);
					if(borrar(&inicio, codigo) >= 0) {
						printf("\n%d ha sido borrado", codigo);
						imprime(inicio);
						getch();
					}
				}
				else {
				 	printf("\n%d no pudo ser borrado porque no hay elementos en la lista", codigo);
					getch();
				}	
		}
	}while(op!=3);
}
void menu() {
	puts("MENU\n1.-Insertar\n2.-Borrar\n3.-Salir\n\n\nSelecciona una opcion: ");
}
void imprime(NODOPTR actualptr) {
	if(actualptr == NULL) {
		puts("La lista esta vacia");
	}
	else {
		puts("\n Los elementos de la lista son: \n");
		while(actualptr != NULL) {
			printf("\n");
			printf("%d \t %s \t %f \t %d ", actualptr->codigo, actualptr->nombre, actualptr->costo, actualptr->existencia);
			actualptr = actualptr->next;
		}
		puts("--> NULL \n\n");
	}
	getch();
}
int esvacia(NODOPTR ptr) {
	return ptr == NULL;
}
void insertar(NODOPTR *ptr, int valor, char *N, float costo, int existencia) {
	NODOPTR nuevo, actual, antes;
	nuevo = (NODO *) malloc (sizeof(NODO));
	if(nuevo == NULL) {
		printf("\n %d no puede ser insertado", valor);
	}
	else {
		if(esvacia(*ptr)) {
			nuevo->codigo = valor;
			strcpy(nuevo->nombre, N);
			nuevo->costo = costo;
			nuevo->existencia = existencia;
			nuevo->next = NULL;
			//Redireccionamiento del apuntador
			*ptr = nuevo;
		}
		else { 
			nuevo->codigo = valor;
			strcpy(nuevo->nombre, N);
			nuevo->costo = costo;
			nuevo->existencia = existencia;
			nuevo->next = NULL;
			actual = *ptr;
			while(actual != NULL && valor > actual->codigo) {
				antes = actual;
				actual = actual->next;
			}
			if(antes == NULL){
				nuevo->next = *ptr;
				*ptr = nuevo;
			}
			else {
				antes->next = nuevo;
				nuevo->next = actual;
			}
		}
	}
}
int borrar(NODOPTR *ptr, int valor) {
	NODOPTR antesptr, actualptr, tempptr;
	if(valor == (*ptr)->codigo) {
		tempptr = *ptr;
		*ptr = (*ptr)->next;
		free(tempptr);
		return valor;
	}
	else {
		antesptr = *ptr;
		actualptr = (*ptr)->next;
		while(actualptr != NULL && actualptr->codigo != valor) {
			antesptr = actualptr;
			actualptr = actualptr->next;
		}
		if(actualptr != NULL && actualptr->codigo == valor) {
			tempptr = actualptr;
			antesptr->next = actualptr->next;
			free(tempptr);
			return valor;
		}
		else {
			printf("\n%d no se encuentra en la lista", valor);
			getch();
			return -1;
		}
	}
}
