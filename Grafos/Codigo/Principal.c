/**
*@file     Principal.c
*@brief    La clase principal del código.
*@author   Margarita Valdez Miranda
*
*@param    nodos     Variable que va a guardar el número de nodos del grafo.
*@param    aristas   Variable que guarda el número de aristas del grafo.
*@param    origen    Variable que va a indicar donde se inicia la ruta.
*@param    destino   Variable que indica donde termina la ruta.
*@param    nuevo     Variable que se ocupa para el ciclo "while".    
*@param    matriz    En ella se va a representar como se van llenado los datos de la matriz.
*/
#include <stdio.h>
#include <stdlib.h>
#include "Camino.h"
int main (){
	int nodos, aristas, origen, destino;
	int i, j;
	char nuevo = 'S';
	
	printf("Ingresa el numero de nodos que tiene el grafo: ");
	scanf("%i",&nodos);
	printf("Ingresa el numero de aristas: ");
	scanf("%i",&aristas);
	
	int matriz[t][t];
	printf("\t0 -> Falso \t1 -> Verdadero\n");
	adyacencias(matriz, nodos);
	imprimirMatriz(matriz, nodos);
	
	while(nuevo == 'S'){
		printf("Coloca el nodo origen: ");
		scanf("%i",&origen);
		printf("Coloca el nodo destino: ");
		scanf("%i",&destino);
		
		buscarAdyacencia(matriz, nodos, origen, destino);
		
		fflush(stdin);
		printf("\nDesea cambiar cambiar los nodos origen y destino? [S/N] -> ");
		scanf("%c",&nuevo);
	}
}
