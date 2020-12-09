#include "Memory.h"

/* DEFINICION DE VARIABLES */

int ID_ACTUAL = 0;
RegEx MEMORIA[TAMMEM];

/* DECLARACION DE FUNCIONES PRIVADAS */

static int Buscar(char nombre[TAMBUF]);

/* FUNCIONES PUBLICAS */

void Agregar(char nombre[TAMBUF], int valor)
{
    int pos = Buscar(nombre);

    if (pos == -1)
    {
        Debug("[Memoria] Agregando identificador '%s' en posición %d, valor: %d\n", nombre, ID_ACTUAL, valor);
        strcpy(MEMORIA[ID_ACTUAL].identificador, nombre);
        MEMORIA[ID_ACTUAL].valor = valor;
        ID_ACTUAL++;
    }
    else
    {
        Debug("[Memoria] Actualizando identificador '%s', valor actual: %d, nuevo valor: %d\n", nombre, MEMORIA[pos].valor, valor);
        MEMORIA[pos].valor = valor;
    }
}

int Obtener(char nombre[TAMBUF])
{
    int pos = Buscar(nombre);

    if (pos == -1)
    {
        Error("[Memoria] Identificador no declarado: %s\n", nombre);
        exit(EXIT_FAILURE);
    }

    Debug("[Memoria] Identificador '%s' obtenido con valor: %d\n", nombre, MEMORIA[pos].valor);
    return MEMORIA[pos].valor;
}

/* FUNCIONES PRIVADAS */

static int Buscar(char nombre[TAMBUF])
{
    for (int i = 0; i < ID_ACTUAL; i++)
    {
        if (strcmp(MEMORIA[i].identificador, nombre) == 0)
        {
            Debug("[Memoria] Identificador '%s' encontrado en posición: %d\n", nombre, i);
            return i;
        }
    }

    Debug("[Memoria] Identificador '%s' no encontrado\n", nombre);
    return -1;
}