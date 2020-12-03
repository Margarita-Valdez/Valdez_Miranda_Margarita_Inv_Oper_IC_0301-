/**
*@file  Camino.c
*@brief Apartado donde se encuentran las funciones del código.
*/
#include "Camino.h"
/**
*@brief    Se colocan las adyancecias que existen entre un nodo y otro.
*\details  Se va a colocar un 1 si existe una adyacencia.
*\details  Se va a colocar un 0 si no existe una adyacencia.
*@param    matriz    Variable para formar la matriz.
*@param    nodos     Variable para conocer el número de nodos para poder formar la matriz.
*@return   void.
*/
void adyacencias(int matriz[][t], int nodos){
	int i, j;
	for(i=0;i<nodos;i++){
		for(j=0;j<nodos;j++){
			printf("Colocar las adyacencias[%i][%i] -> ",i,j);
			scanf("%i",&matriz[i][j]);
			fflush(stdin);
		}
	}
}
/**
*@brief   Se imprime la matriz con los datos ingresados de las adyacencias.
*@param    matriz    Variable que forma la matriz con los datos.
*@param    nodos     Variable para conocer cuantos datos va a obtener la matriz.
*@return   void.
*/
void imprimirMatriz(int matriz[][t], int nodos){
	int i, j;
	printf("\n");
	for(i=0;i<nodos;i++){
		for(j=0;j<nodos;j++){
			printf("\t%i",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/**
*@brief   Va a buscar si existe un adyacencia entre los nodos.
*\details  Si dentro de la matriz tiene un uno significa que si hay camino por esa adyacencia.
*\details  Solo se van a ingresar el nodo origen y el destino, asi el programa nos va a decir si existe camino o no.
*@param    matriz      Variable donde se encuentra la matriz.
*@param    nodos       Variable para el número de nodos.
*@param    origen      Variable para conocer el inicio de la ruta.
*@param    destino     Variable para conocer el final de la ruta.
*@return   void.
*/
int buscarAdyacencia(int matriz[][t], int nodos, int origen, int destino){
	int i, j, unos = 0, origenTemp, destinoTemp;
	
	for(i=0; i<nodos; i++){
		for(j=0; j<nodos; j++){
			if(matriz[i][j] == 1){
				unos++;
			}
		}
	}
	int posibles[unos][2];
	int  aux = 0;
	for(i=0; i<nodos; i++){
		for(j=0; j<nodos; j++){
			if(matriz[i][j] == 1){
				posibles[aux][0] = i;
				posibles[aux][1] = j;
				aux++;
			}
		}
	}

	if(matriz[origen][destino] == 1){
		printf("Si existe un camino");
	} else{
		int encontrado = 0;
		int lim = 0;
		int coincidencia = 99;
		for(i=0; i<unos; i++){
			if(posibles[i][0] == origen){
				while(encontrado == 0 && lim < 10){
					origenTemp = posibles[i][1];
					for(i=0; i<unos; i++){
						if(posibles[i][0] == origenTemp){
							if (posibles[i][1] = destino){
								printf("\nSi existe camino\n");
								encontrado = 1;
								coincidencia = 1;
							} else{
								posibles[i][0] = 99;
								posibles[i][1] = 99;
							}
						}
					}
					if (coincidencia == 0){
						posibles[i][0] = 99;
						posibles[i][1] = 99;
					}
					lim++;
				}
			}	
		}
		if (encontrado==0) printf("No hay camino");
	}
}
