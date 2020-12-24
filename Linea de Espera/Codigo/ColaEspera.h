/**
*@file   ColaEspera.h
*@brief   Apartado donde se mandan a llamar las funciones.
*/
#ifndef _ColaEspera_h
#define _ColaEspera_h
#include <stdio.h>
#define max 24
/**
*@brief    Se llenan la llegada de lo clientes que van llegando por hora.
*@param    llegadaClientes   Arreglo unidimensional para obtener la llegada de los clientes.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@param    horA              Variable de tipo entero para determinar la hora de apertura.
*@return   void.
*/
void setLlegadasClientes(int llegadasClientes[max], int hrs, int horA);
/**
*@brief    Se llenan el numero de cajas abiertas por hora.
*@param    cajasAbiertas     Arreglo unidimensional para obtener el numero de cajas abiertas.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@param    horA              Variable de tipo entero para determinar la hora de apertura.
*@return   void.
*/
void setCajasAbiertas(int cajasAbiertas[max], int hrs, int horA);
/**
*@brief    Se obtiene la capacidad de salidas por hora.
*@param    capacidadSalidas  Arreglo unidimensional para obtener la capacidad de salidas por hora.
*@param    cajasAbiertas     Arreglo unidimensional para obtener el numero de cajas abiertas.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@param    capUnit           Variable de tipo entero para determinar la capacidad unitaria por hora.
*@return   void.
*/
void getCapacidadesSalidas(int capacidadSalidas[max], int cajasAbiertas[max], int hrs, int capUnit);
/**
*@brief    Se obtiene la salida de cada uno de los clientes por hora.
*@param    salidasClientes   Arreglo unidimensional para obtener el numero de salidas de los clientes.
*@param    capacidadSalidas  Arreglo unidimensional para obtener la capacidad de salidas por hora.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@return   void.
*/
void getSalidasClientes(int salidasClientes[max], int capacidadSalidas[max], int hrs);
/**
*@brief    Se obtiene la cola de espera.
*\details  La cola de espera se obtiene restando la salidas de lo clientes a la llegada de los clientes.
*\details  Cada que se avanza una hora se le suma el resultado de la cola de espera a la llegada de los clientes de la hora que este enseguida,
y se realiza el mismo procedimiento.
*@param    colaEspera        Arreglo unidimensional para obtener la cola de espera que se va obteniendo por hora.
*@param    llegadaClientes   Arreglo unidimensional para obtener la llegada de los clientes.
*@param    salidasClientes   Arreglo unidimensional para obtener el numero de salidas de los clientes.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@return   void.
*/
void getColaEspera(int colaEspera[max], int llegadasClientes[max], int salidasClientes[max], int hrs);
/**
*@brief    Se obtiene el input de la tabla.
*\details  El input para el primer dato se obtiene con la llegada de los clientes.
*\details  Para los otros datos se va a sumar el resultado que esta en el input mas la llegada de los clientes de esa hora.
*@param    input             Arreglo unidimensional para obtener el input.
*@param    llegadaClientes   Arreglo unidimensional para obtener la llegada de los clientes.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@return   void.
*/
void getInput(int input[max], int llegadasClientes[max], int hrs);
/**
*@brief    Se obtiene el output de cada uno de los datos.
*\details  El primer dato se obtiene con la salida de lo clientes.
*\details  Para los otros datos se suma lo que se tiene en el output mas la salida de los clientes de esa hora.
*@param    output            Arreglo unidimensional para obtener el output.
*@param    salidasClientes   Arreglo unidimensional para obtener el numero de salidas de los clientes.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@return   void.
*/
void getOutput(int output[max], int salidasClientes[max], int hrs);
/**
*@brief    Se llena todo el esquema con los datos obtenidos.
*\details  Una vez que los datos ya son solicitados y guardados ya se puede imprimir la tabla.
*@param    llegadaClientes   Arreglo unidimensional para obtener la llegada de los clientes.
*@param    cajasAbiertas     Arreglo unidimensional para obtener el numero de cajas abiertas.
*@param    capacidadSalidas  Arreglo unidimensional para obtener la capacidad de salidas por hora.
*@param    salidasClientes   Arreglo unidimensional para obtener el numero de salidas de los clientes.
*@param    colaEspera        Arreglo unidimensional para obtener la cola de espera que se va obteniendo por hora.
*@param    input             Arreglo unidimensional para obtener el input.
*@param    output            Arreglo unidimensional para obtener el output.
*@param    hrs               Variable de tipo entero para obtener cada una de las horas.
*@param    horA              Variable de tipo entero para determinar la hora de apertura.
*@return   void.
*/
void imprimirEsquema(int llegadasClientes[max], int cajasAbiertas[max], int capacidadSalidas[max], int salidasClientes[max], int colaEspera[max], int input[max], int output[max], int hrs, int horA);

#endif

