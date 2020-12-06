#include "Token.h"

/* DEFINICION DE VARIABLES */

Token TOKEN_ACTUAL = INICIAL;

/* FUNCIONES PUBLICAS */

char *TokenString(Token t)
{
    switch (t)
    {
    case CONSTANTE:
        return "CONSTANTE";
        break;
    case IDENTIFICADOR:
        return "IDENTIFICADOR";
        break;
    case ADICION:
        return "ADICION";
        break;
    case MULTIPLICACION:
        return "MULTIPLICACION";
        break;
    case PARENTESIS_IZQ:
        return "PARENTESIS_IZQ";
        break;
    case PARENTESIS_DER:
        return "PARENTESIS_DER";
        break;
    case ASIGNACION:
        return "ASIGNACION";
        break;
    case EVALUACION:
        return "EVALUACION";
        break;
    case PUNTO_Y_COMA:
        return "PUNTO_Y_COMA";
        break;
    case FDT:
        return "FDT";
        break;
    default:
        return "ERROR_LEXICO";
        break;
    }
}