#pragma once
#ifndef MEMORIA_H_
#define MEMORIA_H_

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "Logger.h"
#include "Token.h"

#define TAMMEM 100

typedef struct
{
    char identificador[TAMNOM];
    int valor;
} RegEx;

extern int ID;
extern RegEx MEMORIA[TAMMEM];

void Agregar(char identificador[], int valor);
int Obtener(char identificador[]);

#endif