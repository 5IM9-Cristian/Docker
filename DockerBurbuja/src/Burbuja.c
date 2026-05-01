#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define CantidadN 100 //Cantidad de numeros que seleccionara del archivo

void Burbuja(int *conjunto, int n);

int main(){
	FILE *archivo, *archivoEscritura;
	int n = CantidadN;
	int *conjunto;
	int i;
	conjunto = malloc(n*sizeof(int));
	clock_t t_inicio, t_final;
    double t_intervalo;
	
	archivo = fopen("data/Numeros.txt", "r");
	if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        free(conjunto);
        return 1; 
    }
	
	for (i = 0; i < n; i++) {
        // Intenta leer un número del archivo
        if (fscanf(archivo, "%d", &conjunto[i]) != 1) {
            printf("Error al leer el numero %d del archivo.\n", i + 1);
            break; // Sale del bucle si ocurre un error al leer el número
        }
    }
    fclose(archivo);
	
	t_inicio = clock();
	Burbuja(conjunto, n);
	t_final = clock();

	t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
	
    archivoEscritura = fopen("output/ordenados.txt", "w");
    if (archivoEscritura == NULL) {
        printf("Error al crear el archivo de salida.\n");
        free(conjunto);
        return 1;
    }

	for(i=0; i<n; i++){
		fprintf(archivoEscritura, "%d\n", conjunto[i]);
	}
	printf("\n");
	
	fprintf(archivoEscritura, "\nTiempo medido: %.10f segundos.", t_intervalo);
    fclose(archivoEscritura);

    free(conjunto);
	return 0;
}

void Burbuja(int *conjunto, int n){
	int i, j, tmp;
	for(i=0; i<=n-2; i++){
		for(j=0; j<=(n-2)-i; j++){
			if(conjunto[j]>conjunto[j+1]){
				tmp = conjunto[j];
				conjunto[j] = conjunto[j+1];
				conjunto[j+1] = tmp;
			}
		}
	}
}