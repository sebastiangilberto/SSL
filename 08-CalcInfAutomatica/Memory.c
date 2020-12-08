#include "Memory.h"

/* DEFINICION DE VARIABLES */

int ID_ACTUAL = 0;
RegEx MEMORIA[TAMMEM];

/* DECLARACION DE FUNCIONES PRIVADAS */

static int Buscar(char nombre[TAMNOM]);

/* FUNCIONES PUBLICAS */

void Agregar(char nombre[TAMNOM], int valor)
{
    int pos = Buscar(nombre);

    if (pos == -1)
    {
        strcpy(MEMORIA[ID_ACTUAL].identificador, nombre);
        MEMORIA[ID_ACTUAL].valor = valor;
        ID_ACTUAL++;
    }
    else
    {
        MEMORIA[pos].valor = valor;
    }
}

int Obtener(char nombre[TAMNOM])
{
    int pos = Buscar(nombre);

    if (pos == -1)
    {
        Error("[Memoria] Identificador no declarado: %s\n", nombre);
        exit(EXIT_FAILURE);
    }

    return MEMORIA[pos].valor;
}

/* FUNCIONES PRIVADAS */

static int Buscar(char nombre[TAMNOM])
{
    for (int i = 0; i < ID_ACTUAL; i++)
    {
        if (strcmp(MEMORIA[i].identificador, nombre) == 0)
        {
            return i;
        }
    }

    return -1;
}