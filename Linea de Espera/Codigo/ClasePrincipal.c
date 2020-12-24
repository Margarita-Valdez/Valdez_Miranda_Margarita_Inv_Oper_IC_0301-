/**
*@file     ClasePrincipal.c
*@brief    La clase principal del código.
*@author   Margarita Valdez Miranda
*
*@param    horA              Variable de tipo entero para determinar la hora de apertura.
*@param    horC              Variable de tipo entero para determinar la hora de cierre.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@param    capUnit           Variable de tipo entero para determinar la capacidad unitaria por hora.
*@param    llegadaClientes   Arreglo unidimensional para obtener la llegada de los clientes.
*@param    cajasAbiertas     Arreglo unidimensional para obtener el numero de cajas abiertas.
*@param    capacidadSalidas  Arreglo unidimensional para obtener la capacidad de salidas por hora.
*@param    salidasClientes   Arreglo unidimensional para obtener el numero de salidas de los clientes.
*@param    colaEspera        Arreglo unidimensional para obtener la cola de espera que se va obteniendo por hora.
*@param    input             Arreglo unidimensional para obtener el input.
*@param    output            Arreglo unidimensional para obtener el output.
*/
#include <stdio.h>
#include <stdlib.h>
#include "ColaEspera.h"
int main (){
	int llegadasClientes[max], cajasAbiertas[max], capacidadSalidas[max], salidasClientes[max], colaEspera[max], input[max], output[max];
	int horA, horC, hrs, capUnit;
	printf("Hora de apertura: ");
	scanf("%i", &horA);
	printf("Hora de cierre: ");
	scanf("%i", &horC);
	hrs = horC - horA;
	setLlegadasClientes(llegadasClientes, hrs, horA);
	setCajasAbiertas(cajasAbiertas, hrs, horA);
	printf("Capacidad unitaria de caja por hora: ");
	scanf("%i", &capUnit);
	fflush(stdin);
	getCapacidadSalidas(capacidadSalidas, cajasAbiertas, hrs, capUnit);
	getSalidasClientes(salidasClientes, capacidadSalidas, hrs);
	getColaEspera(colaEspera, llegadasClientes, salidasClientes, hrs);
	getInput(input, llegadasClientes, hrs);
	getOutput(output, salidasClientes, hrs);
	imprimirEsquema(llegadasClientes, cajasAbiertas, capacidadSalidas, salidasClientes, colaEspera, input, output, hrs, horA);
	return 0;
}
