#include "Memory.h"

/* DEFINICION DE VARIABLES */

int ID_ACTUAL = 0;
RegEx MEMORIA[TAMMEM];

/* FUNCIONES PUBLICAS */

void Agregar(char nombre[TAMNOM], int valor)
{
    for (int i = 0; i < ID_ACTUAL; i++)
    {
        if (strcmp(MEMORIA[i].identificador, nombre) == 0)
        {
            MEMORIA[i].valor = valor;
            return;
        }
    }
    strcpy(MEMORIA[ID_ACTUAL].identificador, nombre);
    MEMORIA[ID_ACTUAL].valor = valor;
    ID_ACTUAL++;
}

int Obtener(char nombre[TAMNOM])
{
    for (int i = 0; i < ID_ACTUAL; i++)
    {
        if (strcmp(MEMORIA[i].identificador, nombre) == 0)
        {
            return MEMORIA[i].valor;
        }
    }
    Error("[Memoria] Identificador no declarado: %s\n", nombre);
    exit(EXIT_FAILURE);
}