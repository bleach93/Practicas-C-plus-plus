/* 
	Recorrido de Arbol Binario.
	Soto Tirado Jesús Eduardo
	4-3
	31 de Octubre de 2019.
	Feliz Halloween Maestra!
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct nodo{
	int operacion;
	struct nodo*izq,*der;
};

typedef struct nodo ARBOL;
typedef ARBOL *TREE;

void menu();
bool vacio(TREE A);
void agregar(TREE *A,int n);
void pre_izq(TREE A);
void in_izq(TREE A);
void post_izq(TREE A);
void pre_der(TREE A);
void in_der(TREE A);
void post_der(TREE A);

main(){
	int op,num;
	TREE raiz=NULL;
	do{
		system("cls"); 
		menu();
		scanf("%d",&op); 
		fflush(stdin);
		switch(op){
			case 1: printf("Dame un numero:");
			        scanf("%d",&num);
			        fflush(stdin);
			        agregar(&raiz,num);
			        break;
			case 2: pre_izq(raiz);
			        getch();
			        break;
			case 3: in_izq(raiz);       
			         getch();
			         break;
		   case 4: post_izq(raiz);
		           getch();
		           break;
		    case 5:pre_der(raiz);
		           getch();
		           break;
		    case 6:in_der(raiz);
		           getch();
		           break;   
		   case 7:post_der(raiz);
		           getch();
		           break;     
		}
			
	}while(op!=8);
}

void menu(){
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

bool vacio(TREE A ){
	return A==NULL;
}
void agregar(TREE *A,int n){
	if(vacio(*A)){
		*A=(TREE)malloc(sizeof(nodo));
	if(*A==NULL){
		printf("no hay memoria disponible");
	}else{
		    (*A)->operacion=n;
		    (*A)->izq=NULL;
		    (*A)->der=NULL;
	}
	}else{
		if(n<(*A)->operacion)
		  agregar(&((*A)->izq),n);
		else if(n>(*A)->operacion)
		   agregar(&((*A)->der),n);
		else
		    printf("Duplicado");
	}
	
}

void pre_izq(TREE A){
	if(!vacio(A)){
		printf("\t%d",A->operacion);
		pre_izq(A->izq);
		pre_izq(A->der);
	}
}
void in_izq(TREE A){
	if(!vacio(A)){
		in_izq(A->izq);
		printf("\t%d",A->operacion);
		in_izq(A->der);
	}
}
void post_izq(TREE A){
	if(!vacio(A)){
		post_izq(A->izq);
		post_izq(A->der);
		printf("\t%d",A->operacion);
	}
}

void pre_der(TREE A){
	if(!vacio(A)){
		printf("\t%d",A->operacion);
		pre_der(A->der);
		pre_der(A->izq);
	}
}
void in_der(TREE A){
	if(!vacio(A)){
		in_der(A->der);
		printf("\t%d",A->operacion);
		in_der(A->izq); 
	}
}
void post_der(TREE A){
	if(!vacio(A)){
		post_der(A->der);
		post_der(A->izq);
		printf("\t%d",A->operacion);
	}
}
	

