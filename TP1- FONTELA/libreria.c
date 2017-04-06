#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

/**\brief Calculadora: muestra las opciones de calculos
 *
 * \param float x
 * \param float y
 * \return Retorna las opciones con los datos de x e y ya cargados
 *
 */
int calculadora (float x, float y)
{
        printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
		printf("\n         บ               :: C A L C U L A D O R A ::                 บ");
		printf("\n         ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
		printf("\n         บ                X = %.2f      Y = %.2f                     บ", x, y);
		printf("\n         บ                                                           บ");
		printf("\n         บ       1.- Suma                     4.- Division           บ");
		printf("\n         บ                                                           บ");
		printf("\n         บ       2.- Resta                    5.- Factorial          บ");
		printf("\n         บ                                                           บ");
		printf("\n         บ       3.- Multiplicacion           6.- Calcular todas     บ");
		printf("\n         บ                                                           บ");
		printf("\n         บ                        7.- Salir                          บ");
		printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
		printf("\n                                Elegir Operacion : ");
		return 0;
}


/**\brief Suma: toma los valores de x e y, realiza su suma
 *
 * \param float x
 * \param float y
 * \return Retorna la suma de los 2 operandos en un printf
 *
 */

float suma(float x, float y)
{
    printf("\n ----> La suma entre %.2f y %.2f es: %.2f \n\n",x,y,x+y);
    return 0;
}

/** \brief Resta: toma los valores de x e y, realiza la resta
 *
 * \param float x
 * \param float y
 * \return Retorna la resta de los 2 operandos en un printf
 *
 */

float resta(float x, float y)
{
    printf("\n ----> La diferencia entre %.2f y %.2f es: %.2f \n\n",x,y,x-y);
    return 0;
}

/** \brief Multiplicacion: toma los valores de x e y, realiza la multiplicacion
 *
 * \param float x
 * \param float y
 * \return Retorna la multiplicacion de los 2 operandos en un printf
 *
 */

float multiplicacion(float x, float y)
{
     printf("\n ----> La multiplicacion entre %.2f y %.2f es: %.2f \n\n",x,y,x*y);
     return 0;
}

/** \brief Division: toma los valores de x e y, realiza la division
 *
 * \param float x
 * \param float y
 * \return retorna la division de los 2 operandos en un printf
 *
 */

float division(float x, float y)
{
        if(y==0)
			{
				printf("\n >>>>> No se puede dividir por 0 <<<<<\n\n");
			}else
			{
				printf("\n ----> La division entre %.2f y %.2f es: %.2f \n\n", x,y, x/y);
			}
			return 0;
}

/** \brief Factorial: toma el valor de x y realiza la factorial
 *
 * \param float x
 * \return retorna el factorial del operando x en un printf
 *
 */

float factorial(float x)
{
    unsigned long long respuesta = 1;
    int i;
        if(x<0)
			{
				printf("\n >>>>> No existe el factorial de %.2f <<<<<\n\n", x);
			}
			else
			{
			    for(i=1; i<=x; ++i)
                {
                    respuesta *= i;
                }
			    printf("\n ----> El factorial de %.0f es: %llu \n\n",x, respuesta);
			}
			return 0;
}

/** \brief validarOpcion: valida que la opcion elegida sea entre 1 y 6
 *
 * \param opc
 * \return retorna mensaje de error
 *
 */

int validarOpcion(int opc)
{
     printf("\n>>>>> Ingrese opcion entre 1 y 6 <<<<<\n\n");
     return 0;
}
