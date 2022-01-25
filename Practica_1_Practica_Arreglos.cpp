#include<stdio.h>
#include<stdlib.h>
main(void) {
	int filas, columnas;
	printf("Capture el numero de filas: ");
	scanf("%d", &filas);
	printf("Capture el numero de columnas: ");
	scanf("%d", &columnas);
	int datos[filas][columnas], sumaFilas[filas], sumaColumnas[columnas];
	for(int x = 0; x < filas; x++) {
		for(int i = 0; i < columnas; i++) {
			printf("Matriz[%d][%d]= ", x, i);
			scanf("%d", &datos[x][i]);
		}
	}
	system("cls");
	for(int j = 0; j < filas; j++) {
		sumaFilas[j] = 0;
		for(int y = 0; y < columnas; y++) {
			sumaFilas[j] += datos[j][y];
		}
	}
	for(int z = 0; z < columnas; z++) {
		sumaColumnas[z] = 0;
		for(int k = 0; k < filas; k++) {
			sumaColumnas[z] += datos[k][z];
		}
	}
	for(int x = 0; x < filas; x++) {
		for(int i = 0; i < columnas; i++) {
			printf("\t%d", datos[x][i]);
		}
		printf("\n");
	}
	for(int x = 0; x < filas; x++) {
		printf("\n\t\t\t%d", sumaFilas[x]);
	}
	printf("\n\n");
	for(int x = 0; x < columnas; x++) {
		printf("\t%d", sumaColumnas[x]);
	}
}
