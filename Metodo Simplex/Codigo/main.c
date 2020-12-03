/**
*@file main.c
*@brief Parte principal del código.
*@author Margarita Valdez Miranda.
*@todo Implementar los gráficos.
*
*@param   i                  Variable auxiliar que nos ayuda para la estructura "for", "if" y "while".
*@param   j                  Variable auxiliar que nos ayuda para la estructura "for", "if" y "while".
*@param  noInecuaciones      Variable de tipo entero que va a guardar el número de inecuaciones.
*@param  noVariables         Variable de tipo entero que va a guardar el número de variables.
*@param  noFilas             Variable de tipo entero que va a guardar el número de Filas.
*@param  noColumnas          Variable de tipo entero que va a guardar el número de Columnas.
*@param  contador            Variable de tipo entero que va a guardar los datos que se se van ingresando.
*@param  minimo1             Variable de tipo flotante que almacena datos para la columna pivote.
*@param  minimo2             Variable de tipo flotante que almacena datos para la fila pivote.
*@param  comprobante         Variable de tipo flotante que va a comprobar que no existan números negativos en la tabla.
*@param  tablaVieja          Matriz donde se van almecenar los primero datos que se obtienen.
*@param  arregloAuxiliar     Matriz auxiliar que nos ayuda a ir modificando los datos.
*@param  tablaNueva          Matriz donde se guardan todos los datos ya modificados.
*@return  0.
*/

#include<stdio.h>
#include<stdlib.h>
#include "Funciones.h"

int main (){
	int i=0, j=0, noInecuaciones, noVariables, noFilas, noColumnas, contador=0;
    float minimo1, minimo2, comprobante;
    int columnaPivote=0, filaPivote=0;
    double elementoPivote;
    int repeticion=1;        
    
    printf("- PROGRAMA DISEÑADO PARA LA REALIZACION DEL METODO SIMPLEX-\n");
    
    noInecuaciones = 3;
    noVariables = 2;
       
    noFilas = noInecuaciones+1;
    noColumnas = noVariables+noInecuaciones+2;
    
	float tablaVieja[TAM][TAM];
    float arregloAuxiliar[TAM][TAM];
    float tablaNueva[TAM][TAM];
    
    llenarCeros(tablaVieja, noFilas, noColumnas);//Llena la tabla de ceros
	insertarDatos(tablaVieja, noInecuaciones, noVariables, noFilas, noColumnas);//Llena tabla con restricciones y ecuacion a maximizar

    tablaVieja[noFilas-1][0]=1;
        
    for (i=0; i<noInecuaciones; i++){
        for (j=0; j<noInecuaciones; j++){
	        tablaVieja[i][j+noVariables+(i+1)]=1;
            break;
        }
    }     
    
	imprimirTabla(tablaVieja, noFilas, noColumnas);
        
	while (repeticion==1){            
        repeticion=0;
        
		obtenerColumnaPivote(tablaVieja, &minimo1, noFilas, noColumnas, &columnaPivote);//Obtiene la columna pivote de la tabla
		obtenerFilaPivote(tablaVieja, arregloAuxiliar, &minimo2, noFilas, noColumnas, &filaPivote, columnaPivote);//Obtiene la fila pivote de la tabla
        elementoPivote=tablaVieja[filaPivote][columnaPivote];//Elemento pivote de la tabla
        llenarTablaNueva(tablaNueva, tablaVieja, noFilas, noColumnas, filaPivote, columnaPivote, elementoPivote);//Llena la tabla nueva
        imprimirTabla(tablaNueva, noFilas, noColumnas);//Imprime la tabla nueva
    	comprobarNumerosNegativos(tablaNueva, noFilas, noColumnas, &comprobante);//Comprueba que no haya números negativos en la tabla

        
        if (comprobante>=0){
            imprimirResultados(tablaNueva, noVariables, noFilas, noColumnas);//Muestra los resultados
        } else{
			nuevaTablaVieja(tablaVieja, tablaNueva, noFilas, noColumnas);//La tabla nueva pasa a ser la tabla vieja
        	repeticion=1;//y se repite el proceso
    	}
	}
	return 0;
}
