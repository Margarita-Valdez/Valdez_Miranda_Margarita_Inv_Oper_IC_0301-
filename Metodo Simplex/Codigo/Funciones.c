/**
*@file Funciones.c
*@brief Apartado donde de encuentran las funciones del código.
*/
#include "Funciones.h"
/**
*@brief    Llena de ceros la matriz.
*\details  En este caso la tablaVieja es la que se llena de ceros.
*@param    tablaVieja   Variable de la primer matriz.
*@param    noFilas      Variable para el número de filas.
*@param    noColumnas   Variable para el número de columnas.
*@return   void.
*/
void llenarCeros(float tablaVieja[][TAM], int noFilas, int noColumnas){
	int i, j;

	for (i=0; i<noFilas; i++){
        for (j=0; j<noColumnas; j++){
            tablaVieja[i][j]=0;
        }  
    }
}
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
void insertarDatos(float tablaVieja[][TAM], int noInecuaciones, int noVariables, int noFilas, int noColumnas){
    int i, j;

	for (i=0; i<noInecuaciones; i++){
        for (j=0; j<noVariables; j++){
			printf ("x%i, inecuacion %i: ", j+1, i+1);
            scanf("%f", &tablaVieja[i][j+1]);
        }
    	printf ("CR, inecuacion %i: ", i+1);
        scanf("%f", &tablaVieja[i][noColumnas-1]);
        printf("\n");
	}
    fflush(stdin);
    
	for (i=0; i<noVariables; i++){
    	printf ("x%i, ecuacion a maximizar: ", i+1);
        scanf("%f", &tablaVieja[noFilas-1][i+1]);
        tablaVieja[noFilas-1][i+1]=tablaVieja[noFilas-1][i+1]*-1;
    }
    fflush(stdin);
}
/**
*@brief      Se imprime la tabla con los datos ingresados anteriormente.
*@param   tabla       Variable para la matriz.
*@param   noFilas     Varianle para el número de filas.
*@param   noColumnas  Variable para el número de columnas.
*@return  void.
*/
void imprimirTabla(float tabla[][TAM], int noFilas, int noColumnas){
    int i, j;
    
	printf("\n");
    for (i=0; i< noFilas; i++){
        for (j=0; j<noColumnas; j++){
            printf ("\t %.2f", tabla[i][j]);
        }
        printf("\n");
    }
}
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
void obtenerColumnaPivote(float tablaVieja[][TAM], float *minimo1, int noFilas, int noColumnas, int *columnaPivote){
    int i, j;
		
	*minimo1=1000;
	for (i=0; i<noColumnas; i++){
        if (tablaVieja[noFilas-1][i]<*minimo1 && tablaVieja[noFilas-1][i]!=0){
            *minimo1=tablaVieja[noFilas-1][i];
		}
    }
	   
    for (i=0; i<noColumnas; i++){
        if (*minimo1==tablaVieja[noFilas-1][i]){
            *columnaPivote=i;
        }
    }
}
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
void obtenerFilaPivote(float tablaVieja[][TAM], float arregloAuxiliar[][TAM], float *minimo2, int noFilas, int noColumnas, int *filaPivote, int columnaPivote){
    int i, j;
    
	for (i=0; i<noFilas-1; i++){
        for (j=(noColumnas-1); j<noColumnas; j++){
            arregloAuxiliar[i][0] = tablaVieja[i][j];
        }
    }
        
    for (i=0; i<noFilas-1; i++){
        arregloAuxiliar[i][0] = arregloAuxiliar[i][0]/tablaVieja[i][columnaPivote];
    }
        
    *minimo2=1000;
    for (i=0; i<noFilas-1; i++){
        if (arregloAuxiliar[i][0] < *minimo2 && arregloAuxiliar[i][0]!=0){
            *minimo2=arregloAuxiliar[i][0];
        }
    }
      
    for (i=0; i<noFilas-1; i++){
        if (*minimo2==arregloAuxiliar[i][0]){
           *filaPivote=i;
        }
    }
}
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
void llenarTablaNueva(float tablaNueva[][TAM], float tablaVieja[][TAM], int noFilas, int noColumnas, int filaPivote, int columnaPivote, int elementoPivote){
	int i, j;
	
    for (i=0; i<noColumnas; i++){
        tablaNueva[filaPivote][i]=tablaVieja[filaPivote][i]/elementoPivote;
    }
                
    for (i=0; i<noFilas; i++){
        for (j=0; j<noColumnas; j++){
            if (i!=filaPivote){
                tablaNueva[i][j]=tablaVieja[i][j]-(tablaVieja[i][columnaPivote]*tablaNueva[filaPivote][j]);
            }
        }
    }
}
/**
*@brief   Comprueba que no existan números negativos en la nueva matriz.
*@param   tablaNueva       Variable para la nueva matriz.
*@param   noFilas          Variable para el número de filas.
*@param   noColumnas       Variable para el número de columnas.
*@param   comprobante      Variable para comprobar que no existan negativos 
*@return  void.
*/
void comprobarNumerosNegativos(float tablaNueva[][TAM], int noFilas, int noColumnas, float *comprobante){
    int i, j;
    
	*comprobante=1000;    
	for (i=0; i<noColumnas; i++){
        if (tablaNueva[noFilas-1][i] < *comprobante){
            *comprobante=tablaNueva[noFilas-1][i];
        }
    }
}
/**
*@brief    Se imprimen los resultados que lleva la tabla nueva.
*@param    tablaNueva   Variable para la nueva matriz.
*@param    noVariables  Variable para el número de variables.
*@param    noFilas      Variable para el número de filas.
*@param    noColumnas   Variable para el número de columnas.
*@return   void.
*/
void imprimirResultados(float tablaNueva[][TAM], int noVariables, int noFilas, int noColumnas){
    int i, j, aux = 0;
    
    for (i=noVariables-1; i>=0; i--){
    	aux++;
    	printf ("\nX%i", aux);
    	printf (" = %.0f", tablaNueva[i][noColumnas-1]);
    }
    printf ("\nZ = %.2f", tablaNueva[noFilas-1][noColumnas-1]);
}
/**
*@brief    Reemplaza los datos que existen en la tabla vieja y la  tabla nueva para poder crear la matriz con los datos definitivos.
*\details  Los datos de las dos matrices anteriores los va a guardar en la nueva matriz.
*@param    tablaVieja     Variable para la matriz de los primero datos.
*@param    tablaNueva     Variable para la matriz con los datos modificados.
*@param    noFilas        Variable para el número de filas.
*@param    noColumnas     Variable para el número de columnas.
*@return   void.
*/ 
void nuevaTablaVieja(float tablaVieja[][TAM], float tablaNueva[][TAM], int noFilas, int noColumnas){
	int i, j;
	
    for (i=0; i<noFilas; i++){
       	for (j=0; j<noColumnas; j++){
            tablaVieja[i][j]=tablaNueva[i][j];
        }
    }
}

