/**
*@file   Camino.h
*@brief   Apartado donde se mandan a llamar las funciones.
*/
#ifndef _Camino_h
#define _Camino_h
#include <stdio.h>
#define t 50
/**
*@brief    Se colocan las adyancecias que existen entre un nodo y otro.
*\details  Se va a colocar un 1 si existe una adyacencia.
*\details  Se va a colocar un 0 si no existe una adyacencia.
*@param    matriz    Variable para formar la matriz.
*@param    nodos     Variable para conocer el número de nodos para poder formar la matriz.
*@return   void.
*/
void adyacencias(int matriz[][t], int nodos);
/**
*@brief   Se imprime la matriz con los datos ingresados de las adyacencias.
*@param    matriz    Variable que forma la matriz con los datos.
*@param    nodos     Variable para conocer cuantos datos va a obtener la matriz.
*@return   void.
*/
void imprimirMatriz(int matriz[][t], int nodos);
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
int buscarAdyacencia(int matriz[][t], int nodos,int origen, int destino);

#endif
