/*
	Ejemplo Arbol binario con datos 
	Soto Tirado Jesús Eduardo
	31 de Octubre de 2019.
	Feliz Halloween Maestra!
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct nodo
{
	char palabra[15];
	struct nodo *izq, *der;
};

typedef struct nodo ARBOL;
typedef ARBOL *TREE;

void menu();
bool vacio(TREE A);
void agregar(TREE *A, char *n);
void pre_izq(TREE A);
void in_izq(TREE A);
void post_izq(TREE A);
void pre_der(TREE A);
void in_der(TREE A);
void post_der(TREE A);
bool borrar(TREE *A,char *n);

main()
{
	int op;
	char word[15];
	TREE raiz = NULL;
	do
	{
		system("cls");
		menu();
		scanf("%d",&op); fflush(stdin);
		switch(op)
		{
			case 1: 
				printf("Introduzca una palabra: ");
				gets(word); strupr(word);
				agregar(&raiz, word);
				break;
			case 2:
				pre_izq(raiz); printf("\n");
				system("pause");
				system("cls");
				break;
			case 3:
				in_izq(raiz); printf("\n");
				system("pause");
				system("cls");
				break;
			case 4:
				post_izq(raiz); printf("\n");
				system("pause");
				system("cls");
				break;
			case 5:
				pre_der(raiz); printf("\n");
				system("pause");
				system("cls");
				break;
			case 6:
				in_der(raiz); printf("\n");
				system("pause");
				system("cls");
				break;
			case 7:
				post_der(raiz); printf("\n");
				system("pause");
				system("cls");
				break;
			case 8:
				if(vacio(raiz)){
					printf("\n Arbol Vacio");
				}
				else{
					printf("Dato que desea borrar: ");
					gets(word); strupr(word);
					if(borrar(&raiz,word)){
						printf("\n Elemento %s borrado", word);
					}else{
						printf("\n Elemento %s no pudo ser borrado", word);
					}
				}
				getch();
				break;
			
					
		}	
	}while(op != 9);	
}

void menu()
{
	printf("\n\tMENU DE OPCIONES\n");
	printf("\n 1. Insertar");
	printf("\n 2. Recorrido Pre-Orden Izq-Der");
	printf("\n 3. Recorrido In-Orden Izq-Der");
	printf("\n 4. Recorrido Post-Orden Izq-Der");
	printf("\n 5. Recorrido Pre-Orden Der-Izq");
	printf("\n 6. Recorrido In-Orden Der-Izq");
	printf("\n 7. Recorrido Post-Orden Der-Izq");
	printf("\n 8. Borrar");
	printf("\n 9. Salir");
	printf("\n\n Selecciona una opcion: ");
}

bool vacio(TREE A)
{
	return A == NULL;
}
void agregar(TREE *A, char *n)
{
	if(vacio(*A))
	{
		*A=(TREE)malloc(sizeof(nodo));
		if(*A==NULL)
		{
			printf("No hay memoria disponible");
		}
		else
		{	
			strcpy((*A)->palabra,n);
			(*A)->izq = NULL;
			(*A)->der = NULL;
		}	
	}
	else
	{
		if(0 >strcmp(n,(*A)->palabra))
			agregar(&((*A)->izq),n);
		else if(0 < strcmp(n,(*A)->palabra))
			agregar(&((*A)->der),n);
		else
			printf("Duplicado");
	}	
}
void pre_izq(TREE A)
	if(!vacio(A))
	{
		printf("\t%s",A->palabra);
		pre_izq(A->izq);
		pre_izq(A->der);
	}
}
void in_izq(TREE A)
{
	if(!vacio(A))
	{
		in_izq(A->izq);
		printf("\t%s",A->palabra);
		in_izq(A->der);
		
	}
}
void post_izq(TREE A)
{
	if(!vacio(A))
	{
		post_izq(A->izq);
		post_izq(A->der);
		printf("\t%s",A->palabra);
		
	}
}
void pre_der(TREE A)
{
	if(!vacio(A))
	{
		printf("\t%s",A->palabra);
		pre_der(A->der);
		pre_izq(A->izq);
	}
}
void in_der(TREE A)
{
	if(!vacio(A))
	{
		in_der(A->der);
		printf("\t%s",A->palabra);
		in_der(A->izq);
	}
}
void post_der(TREE A)
{
	if(!vacio(A))
	{
		post_der(A->der);
		post_der(A->izq);
		printf("\t%s",A->palabra);
		
	}
}
bool borrar(TREE *A, char *n){
	if(vacio((*A))){
		printf("\n El elemento %s no se encuentra",n);
		return false;
	}
	if(strcmp((*A)->palabra,n)==0){
		if(vacio((*A)->izq) && vacio((*A)->der)){
			(*A) = NULL;
			return true;
		}
	}else if(strcmp((*A)->palabra,n)>0){
		borrar(&(*A)->izq,n);
	}else if(strcmp((*A)->palabra,n)<0){
		borrar(&(*A)->der,n);
	}else{
		printf("\n El elemento %s no se encuentra",n);
		return false;
	}
}

