#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

#define TAM 3
#define LIBRE 0
#define ALTA 1

int main()
{
    char seguir='s';
    int opcion=0;
    int indice;
    EPersona unaPersona[TAM];

    inicializarPersonas(unaPersona,TAM);

    while(seguir=='s')
    {
        printf("\n************ ALTAS/BAJAS ************\n");
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");
        printf("*************************************\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(obtenerEspacioLibre(unaPersona,TAM)==1)
                {
                    indice=obtenerIndice(unaPersona,TAM);
                    agregarPersona(unaPersona,indice);
                }
                else
                {
                    printf("\n\nCapacidad Agotada!");
                }
                break;
            case 2:
                borrarPersona(unaPersona,TAM);
                break;
            case 3:
                ordenarLista(unaPersona,TAM);
                break;
            case 4:
                imprimirEdades(unaPersona,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion invalida, elija de 1 a 5\n");
                break;
        }
    }

    return 0;
}
