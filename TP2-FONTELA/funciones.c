#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

#define TAM 3
#define LIBRE 0
#define ALTA 1


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(EPersona x[], int dni, int tam)
 {
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(x[i].dni==dni)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
 }

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */

int obtenerEspacioLibre(EPersona x[], int tam)
{
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(x[i].estado==LIBRE)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}


/**
 * Inicializa todos los estados de la estructura Persona en 0
 * @param lista el array se pasa como parametro.
 * @return el estado del indice en 0
 *
 */


void inicializarPersonas(EPersona x[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        x[i].estado=LIBRE;
    }
}


/**
 * busca si el estado se encuentra libre o no
 * @param lista el array se pasa como parametro.
 * @return el estado que se encuentra libre
 *
 */

int obtenerIndice(EPersona x[],int tam)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(x[i].estado==LIBRE)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


/**
 * Guarda en cada indice los datos de una persona, validandolos
 * @param lista el array se pasa como parametro.
 * @return guarda los datos de cada persona, llenando ese estado como alta
 *
 */

void agregarPersona(EPersona x[],int i)
{
    EPersona eAux;
    char aux[500];

    system("cls");
    printf("********** Agregar Persona **********");
    printf("\n\nIngrese Nombre: ");
    fflush(stdin);
    gets(aux);

    while(validarNombre(aux)==0 || strlen(aux)>49)
    {
        printf("\nError en Nombre. Reingrese: ");
        fflush(stdin);
        gets(aux);
    }
    strupr(aux);
    strcpy(eAux.nombre,aux);


    printf("\n\nIngrese Edad: ");
    scanf("%d",&eAux.edad);
    while(eAux.edad<0||eAux.edad>100)
    {
        printf("\nError Edad Invalida. Reingrese: ");
        fflush(stdin);
        scanf("%d",&eAux.edad);
    }

    printf("\n\nIngrese dni: ");
    scanf("%d",&eAux.dni);
    while(eAux.dni<0||eAux.dni>9999999)
    {
        printf("\nError en dni. Reingrese: ");
        fflush(stdin);
        scanf("%d",&eAux.dni);
    }

    eAux.estado=ALTA;

    if(buscarPorDni(x,eAux.dni,TAM)==0)
    {
        x[i]=eAux;

    }
    else
    {
        printf("\n\nDNI ya ingresado.");
        getche();
    }
}


/**
 * valida que el texto ingresado en nombre de agregar persona este dentro de los parametros correctos
 * @param caracteres ingresado como nombre en agregar persona
 * @return retorno 0 para nombre incorrecto, 1 para correcto
 *
 */

int validarNombre(char texto[])
{
    int i=0;
    int retorno=1;
    while(texto[i] != '\0')
    {
        if((texto[i] != ' ') && (texto[i] < 'a' || texto[i] > 'z') && (texto[i] < 'A' || texto[i] > 'Z'))
            retorno=0;
        i++;
    }
    return retorno;
}


/**
 * borra el array de la persona seg�n dni pedido, validando
 * @param lista el array se pasa como parametro.
 * @return limpia el array dejandolo libre
 *
 */

void borrarPersona(EPersona x[],int tam)
{
    int aux;
    char auxC;
    int indice;
    system("cls");
    printf("********** Borrar Persona **********\n\n");
    printf("Ingrese Dni de persona a eliminar: ");
    fflush(stdin);
    scanf("%d",&aux);

    if(buscarPorDni(x,aux,tam)==0)
    {
        printf("\nDni incorrecto.\n\n");
        fflush(stdin);
    }
    else
    {
        printf("\nDesea eliminar este registro? (s=si) : ");
        fflush(stdin);
        scanf("%c",&auxC);
        if(auxC=='s'||auxC=='S')
        {

            indice=obtenerIndiceDni(x,aux,tam);

            x[indice].estado=LIBRE;
            x[indice].dni=-1;
            printf("\nPersona eliminada\n\n");
        }
        else
        {
            printf("\nNo se elimina registro\n\n");
        }
    }
}


/**
 * busca el indice de lugar del dni buscado
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice donde se aloja el dni ingresado
 *
 */

int obtenerIndiceDni(EPersona x[],int dni,int tam)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(x[i].dni==dni )
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


/**
 * ordenar lista de nombres por orden alfab�tico, imprimirla
 * @param lista el array se pasa como parametro.
 * @return imprime una lista ordenada alfabeticamente por nombre
 *
 */

int ordenarLista(EPersona x[],int tam)
{
    EPersona aux;
    int i,j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            strupr(x[i].nombre);
            if(strcmp(x[i].nombre,x[j].nombre)>0)
            {
                aux=x[i];
                x[i]=x[j];
                x[j]=aux;
            }
            else
            {
                if(strcmp(x[i].nombre,x[j].nombre)==0&&x[i].dni>x[j].dni)
                {
                    aux=x[i];
                    x[i]=x[j];
                    x[j]=aux;
                }
            }
        }
    }

    for (i = 0; i < tam; i++)
    {
        if (x[i].estado==ALTA)
        {
            printf("\nNombre\tEdad\tDni\n");
            printf("%s\t%d\t%d\n", x[i].nombre, x[i].edad, x[i].dni);
        }
    }
    return 0;
}


/**
 * imprime un grafico con * sobre las edades de las personas ingresadas
 * @param lista el array se pasa como parametro.
 * @return imprime * por cada edad formando un grafico
 *
 */

int imprimirEdades(EPersona x[], int tam)
{
    int i;
    int flag=0;
    int a=0;//-18
    int b=0;//19 a 35
    int c=0;//+36

    for(i=0; i<tam; i++)
    {
        if(x[i].edad<=18)
        {
            a++;
        }
        else
        {
            if(x[i].edad>18 && x[i].edad<36)
            {
                b++;
            }
            else
            {
                c++;
            }
        }
    }

        for(i=tam; i>0; i--)
        {
            if (x[i].estado==ALTA)
            {
                if(i<= a)
                {
                    printf(" *");
                }
                if(i<= b)
                {
                    flag=1;
                    printf("\t*");
                }
                if(i<= c)
                {
                    if(flag==0)
                    printf("\t\t *");
                    if(flag==1)
                    printf("\t *");
                }
            printf("\n");
            }

        }

    printf("\n<18\t19-35\t>35\n\n");
    return 0;
}
