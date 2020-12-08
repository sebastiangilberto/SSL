#include "Memory.h"

/* DEFINICION DE VARIABLES */

int ID = 0;
RegEx MEMORIA[TAMMEM];

/* FUNCIONES PUBLICAS */

void Agregar(char nombre[TAMNOM], int valor)
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

int Obtener(char nombre[TAMNOM])
{
    for (int i = 0; i < ID; i++)
    {
        if (strcmp(MEMORIA[i].identificador, nombre) == 0)
        {
            return MEMORIA[i].valor;
        }
    }
    Error("[Memoria] Identificador no declarado: %s\n", nombre);
    exit(EXIT_FAILURE);
}