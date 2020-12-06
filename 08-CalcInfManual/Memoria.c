#include "Memoria.h"

/* DEFINICION DE VARIABLES */

RegEx MEMORIA[MAXVAL];
int ID = 0;

/* FUNCIONES PUBLICAS */

void Agregar(char nombre[MAXVAL], int valor)
{
    for (int i = 0; i < ID; i++)
    {
        if (strcmp(MEMORIA[i].identificador, nombre) == 0)
        {
            MEMORIA[i].valor = valor;
            return;
        }
    }
    strcpy(MEMORIA[ID].identificador, nombre);
    MEMORIA[ID].valor = valor;
    ID++;
}

int Obtener(char nombre[MAXVAL])
{
    for (int i = 0; i < ID; i++)
    {
        if (strcmp(MEMORIA[i].identificador, nombre) == 0)
        {
            return MEMORIA[i].valor;
        }
    }
    return 0;
}