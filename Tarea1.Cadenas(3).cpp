#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(void) {
	typedef char String[100];
	String temp;
	int totStrings;
	printf("Captura el numero de cadenas que deseas capturar: ");
	scanf("%d", &totStrings);
	String cadena[totStrings];
	int aeiou[totStrings];
	
	for(int i = 0; i < totStrings; i++) {
		fflush(stdin);
		printf("\nCadena %d: ", i + 1);
		gets(cadena[i]);
		strcpy(temp, cadena[i]);
		strupr(temp);
	}
	system("cls");
	printf("Numero de vocales por cadena");
	for(int i = 0; i < totStrings; i++) {
		aeiou[i] = 0;
		for(int j = 0; j < strlen(cadena[i]); j++) {
			switch(temp[j]) {
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					aeiou[i] = aeiou[i] + 1;
					break;
			}
		}
		printf("\nCadena %d: '%s' tiene %d vocales", i + 1, cadena[i], aeiou[i]);
	}
}
