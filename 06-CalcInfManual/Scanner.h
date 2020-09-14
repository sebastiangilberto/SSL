#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum {
    INICIAL, ADICION, MULTIPLICACION, IDENTIFICADOR, CONSTANTE, FDT, UNDEFINED
} Token;

Token tokenActual;
Token tokenList[100];
unsigned lastToken;

Token GetNextToken();
char* TokenString(Token token);
void LeerCaracteres();
void MostrarTokens();

#endif