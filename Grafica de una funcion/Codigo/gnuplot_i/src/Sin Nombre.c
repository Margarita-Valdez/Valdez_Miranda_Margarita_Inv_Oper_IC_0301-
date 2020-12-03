#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int h;
	double x1, x2, y1, y2;
	printf ("Ingrese la coordenada en x1:  ");
	scanf("%d", x1);
	printf ("Ingrese la coordenada en x2:  ");
	scanf("%d", x2);
	printf ("Ingrese la coordenada en y1:  ");
	scanf("%d", y1);
	printf ("Ingrese la coordenada en y2:  ");
	scanf("%d", y2);
	
	if (x1 == x2){
		printf("No existe la ecuacion lineal para las coordenadas sumatorias");	
	}else{
		printf("la ecuacion de la recta es y= ",(-y2-y1)*x1/(x2-x1)+y1);
		
	}
	


	return 0;
}
