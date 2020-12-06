#pragma once
#ifndef MEMORIA_H_
#define MEMORIA_H_

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXVAL 100

#include "Token.h"

typedef struct
{
    char identificador[MAXVAL];
    int valor;
} RegEx;

extern RegEx MEMORIA[MAXVAL];
extern int ID;

void Agregar(char identificador[], int valor);
int Obtener(char identificador[]);

#endif