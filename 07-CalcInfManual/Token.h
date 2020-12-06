#pragma once
#ifndef TOKEN_H_
#define TOKEN_H_

#define MAXVAL 100

typedef enum
{
    INICIAL,
    ADICION,
    MULTIPLICACION,
    IDENTIFICADOR,
    CONSTANTE,
    PARENTESIS_IZQ,
    PARENTESIS_DER,
    ASIGNACION,
    EVALUACION,
    PUNTO_Y_COMA,
    ERROR_LEXICO,
    FDT
} Token;

extern Token TOKEN_ACTUAL;

char *TokenString(Token token);

#endif