#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int obtenerEspacioLibre(EPersona x[], int tam);

int buscarPorDni(EPersona x[], int dni, int tam);

void inicializarPersonas(EPersona x[],int tam);

int obtenerIndice(EPersona x[],int tam);

void agregarPersona(EPersona x[],int i);

int validarNombre(char texto[]);

void borrarPersona(EPersona x[],int tam);

int obtenerIndiceDni(EPersona x[],int dni,int tam);

int ordenarLista(EPersona x[],int tam);

int imprimirEdades(EPersona x[], int tam);

#endif // FUNCIONES_H_INCLUDED

