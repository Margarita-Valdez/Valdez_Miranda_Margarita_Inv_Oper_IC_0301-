/**
*@file     Funciones.h
*@brief    Apartado donde se hacen llamar las funciones.
*/
#ifndef _Funciones_h
#define _Funciones_h
#include <stdio.h>
#define TAM 7
/**
*@brief    Llena de ceros la matriz.
*\details  En este caso la tablaVieja es la que se llena de ceros.
*@param    tablaVieja   Variable de la primer matriz.
*@param    noFilas      Variable para el número de filas.
*@param    noColumnas   Variable para el número de columnas.
*@return   void.
*/
void llenarCeros(float tablaVieja[][TAM], int noFilas, int noColumnas);
/**
*@brief  Se le pide al usuario que ingrese los datos.
*\details  Todos los datos ingresados se van almacenar en la matriz de la tablaVieja.
*@param  tablaVieja        Variable de la primer matriz.
*@param  noInecuaciones    Variable para el número de inecuaciones.
*@param  noVariables       Variable para el número de variables.
*@param  noFilas           Variable para el número de filas.
*@param  noColumnas        Variable para el número de columnas. 
*@return void
*/
void insertarDatos(float tablaVieja[][TAM], int noInecuaciones, int noVariables, int noFilas, int noColumnas);
/**
*@brief      Se imprime la tabla con los datos ingresados anteriormente.
*@param   tabla       Variable para la matriz.
*@param   noFilas     Varianle para el número de filas.
*@param   noColumnas  Variable para el número de columnas.
*@return  void.
*/
void imprimirTabla(float tablaVieja[][TAM], int noFilas, int noColumnas);
/**
*@brief     Se obtiene la columna pivote de la matriz.
*\details   La columna pivote se va a ir guardando en la matriz de la tabla vieja.
*@param   tablaVieja    Variable para la matriz.
*@param   minimo1       Variable para agregar un dato.
*@param   noFilas       Variable para el número de filas.
*@param   noColumna     Variable para el número de columnas.
*@param   columnaPivote Variable para los datos que se encuentran en la columna pivote.
*@return  void.
*/
void obtenerColumnaPivote(float tablaVieja[][TAM], float *minimo1, int noFilas, int noColumnas, int *columnaPivote);
/**
*@brief      Se obtiene la fila pivote.
*\details    Al igual que la columna pivote, la fila pivote se guarda en la matriz de la tabla vieja.
*@param     tablaVieja         Variable para la matriz.
*@param     arregloAuxiliar    Variable para la matriz donde de encuentra el arreglo.
*@param     minimo2            Variable para obtener el segundo dato.
*@param     noFilas            Variable para el número de filas.
*@param     noColumnas         Variable para el número de columnas.
*@param     filaPivote         Variable para los datos de forma vertical que conforman la fila pivote.
*@param     columnaPivote      Variable para los datos de forma horizontal de la columna pivote.
*@return    void.
*/
void obtenerFilaPivote(float tablaVieja[][TAM], float arregloAuxiliar[][TAM], float *minimo2, int noFilas, int noColumnas, int *filaPivote, int columnaPivote);
/**
*@brief    Se empieza a llenar la tabla nueva.
*@param    tablaNueva     Variable para la matriz que contiene los nuevos datos.
*@param    tablaVieja     Variable para la matriz que contiene los datos principales.
*@param    noFilas        Variable para el número de filas.
*@param    noColumnas     Variable para el número de columnas.
*@param    filaPivote     Variable para los datos de la fila pivote.
*@param    columnaPivote  Variable para los datos de la columna pivote.
*@param    elementoPivote Variable para el elemento pivote.
*@return   void.
*/
void llenarTablaNueva(float tablaNueva[][TAM], float tablaVieja[][TAM], int noFilas, int noColumnas, int filaPivote, int columnaPivote, int elementoPivote);
/**
*@brief   Comprueba que no existan números negativos en la nueva matriz.
*@param   tablaNueva       Variable para la nueva matriz.
*@param   noFilas          Variable para el número de filas.
*@param   noColumnas       Variable para el número de columnas.
*@param   comprobante      Variable para comprobar que no existan negativos 
*@return  void.
*/
void comprobarNumerosNegativos(float tablaNueva[][TAM], int noFilas, int noColumnas, float *comprobante);
/**
*@brief    Se imprimen los resultados que lleva la tabla nueva.
*@param    tablaNueva   Variable para la nueva matriz.
*@param    noVariables  Variable para el número de variables.
*@param    noFilas      Variable para el número de filas.
*@param    noColumnas   Variable para el número de columnas.
*@return   void.
*/
void imprimirResultados(float tablaNueva[][TAM], int noVariables, int noFilas, int noColumnas);
/**
*@brief    Reemplaza los datos que existen en la tabla vieja y la  tabla nueva para poder crear la matriz con los datos definitivos.
*\details  Los datos de las dos matrices anteriores los va a guardar en la nueva matriz.
*@param    tablaVieja     Variable para la matriz de los primero datos.
*@param    tablaNueva     Variable para la matriz con los datos modificados.
*@param    noFilas        Variable para el número de filas.
*@param    noColumnas     Variable para el número de columnas.
*@return   void.
*/ 
void nuevaTablaVieja(float tablaVieja[][TAM], float tablaNueva[][TAM], int noFilas, int noColumnas);

#endif
