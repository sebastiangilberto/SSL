#pragma once
#ifndef TOKEN_H_
#define TOKEN_H_

#define TAMNOM (20 + 1)

typedef enum
{
    ADICION,
    ASIGNACION,
    CONSTANTE,
    ERROR_LEXICO,
    EVALUACION,
    FDT,
    FIN,
    IDENTIFICADOR,
    INICIAL,
    INICIO,
    MULTIPLICACION,
    PARENTESIS_DER,
    PARENTESIS_IZQ,
    PUNTO_Y_COMA
} Token;

extern Token TOKEN_ACTUAL;

char *TokenString(Token token);

#endif