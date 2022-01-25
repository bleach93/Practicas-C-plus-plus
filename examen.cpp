#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Codigo para capturar n cadenas, y indicar cuantos espacios hay en cada cadena. Soto Tirado 4-3.
main(void) {
	typedef char String[100]; //Se declara la string y la longitud de la misma.
	String temp; // Variable temporal para copiar y guardar la cadena.
	int Strings; // Se declara la variable donde se guardarán el  número de cadenas.
	printf("Captura el numero de cadenas que deseas capturar: "); // Se le pide al usuario que capture el número de cadenas que desea.
	scanf("%d", &Strings); // El usuario captura las cadenas.
	String cadena[Strings]; 
	int space[Strings]; // Se utiliza para contar el número de espacios en la cadena.
	for(int i = 0; i < Strings; i++) { // Ciclo que recorre el arreglo.
		fflush(stdin); 
		printf("\nCadena %d: ", i + 1); // Se captura la n cadena.
		gets(cadena[i]);// Se obtiene la n cadena.
		strcpy(temp, cadena[i]); // se copia la cadena a temp
		strupr(temp); // se utiliza para convertir las letras en solo minusculas. 
	}
	system("cls");
	printf("Numero de espacios en la cadena."); // se muestra el número de espacios.
	for(int i = 0; i < Strings; i++) { // Se recorre la cadena.
		space[i] = 0; // Número de espacios.
		for(int j = 0; j < strlen(cadena[i]); j++) { // Se recorre la cadena en busqueda de espacios.
			switch(temp[j]) {
				case ' ': 
					space[i] = space[i] + 1;
					break;
			}
		}
		printf("\nCadena %d: '%s' tiene %d espacios", i + 1, cadena[i], space[i]); // Se muestra el número de espacios que existen en las cadenas antes mencionadas.
	} // Fin de For que recorre la cadena.
} //Fin del programa.
