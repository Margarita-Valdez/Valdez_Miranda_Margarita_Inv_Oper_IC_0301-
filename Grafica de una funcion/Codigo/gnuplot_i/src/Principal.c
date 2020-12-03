/**
*@file      Principal.c
*@author    Margarita Valdez Miranda
*
*@brief     Apartado principal del código.
*@param     valorm    Variable para guardar el dato "m" de la funcion.
*@param     valorb    Variable para guardar el dato "b" que tiene la funcion.
*@param     rango1    Variable para guardar el rango inferior izquierdo. 
*@param     rango2    Variable para guardar el rango superior  derecho.
*@return    0.
*/
#include "gnuplot_i.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int valorm, valorb, rango1, rango2;
	gnuplot_ctrl * inicioS;
	inicioS = gnuplot_init();
	printf("Coloca el valor de m: ");
	scanf("%d",&valorm);
	printf("Coloca el valor de b: ");
	scanf("%d",&valorb);
	printf("Agrega el rango inicial: ");
	scanf("%d",&rango1);
	printf("Agrega el rango final: ");
	scanf("%d",&rango2);
	
	gnuplot_setstyle(inicioS, "Lineas");
	gnuplot_set_xlabel(inicioS, "Eje X");
	gnuplot_set_ylabel(inicioS, "Eje Y");
	gnuplot_cmd(inicioS,"set xzeroaxis It-1");
	gnuplot_cmd(inicioS,"set yzeroaxis It-1");
	gnuplot_cmd(inicioS,"set xrange [%d:%d]",rango1,rango2);
	gnuplot_cmd(inicioS,"set yrange [%d:%d]",rango1,rango2);
	gnuplot_plot_slope(inicioS,valorm,valorb,"Funcion de la forma y = mx + b");
	sleep(10);
	gnuplot_close(inicioS);
	
	return 0;
}
