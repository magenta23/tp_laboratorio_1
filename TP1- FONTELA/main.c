#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include"libreria.h"
int main()
{
	float x,y;
	int opc;
	system("cls");
	printf("Ingrese 1er nro:\n");
	scanf("%f",&x);
	printf("Ingrese 2do nro:\n");
	scanf("%f",&y);
	for(;;)
	{
		calculadora(x,y);
		scanf("%d",&opc);
		switch(opc)
		{
			case 1: suma(x,y);
			break;
			case 2: resta(x,y);
			break;
			case 3: multiplicacion(x,y);
			break;
			case 4: division(x,y);
			break;
			case 5: factorial(x);
			break;
			case 6: suma(x,y); resta(x,y); multiplicacion(x,y); division(x,y); factorial(x);
			break;
			case 7: return 0;
			break;
			default: validarOpcion(opc);
			break;
		}
	}
	getch();
}
