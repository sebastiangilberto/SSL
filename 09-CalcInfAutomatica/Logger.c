#include "Logger.h"

/* DEFINICION DE VARIABLES */

int DEBUG = 0;
static const char LOG_LEVEL_INFO[] = "\033[0m";
static const char LOG_LEVEL_DEBUG[] = "\033[1;33m";
static const char LOG_LEVEL_ERROR[] = "\033[1;31m";

/* DECLARACION DE FUNCIONES PRIVADAS */

static void Reiniciar(void);
static void Print(const char *level, const char *formato, va_list args);

/* FUNCIONES PUBLICAS */

void Info(const char *formato, ...)
{
    va_list arg;
    va_start(arg, formato);
    Print(LOG_LEVEL_INFO, formato, arg);
    va_end(arg);
}

void Error(const char *formato, ...)
{
    va_list arg;
    va_start(arg, formato);
    Print(LOG_LEVEL_ERROR, formato, arg);
    va_end(arg);
}

void Debug(const char *formato, ...)
{
    if (DEBUG)
    {
        va_list arg;
        va_start(arg, formato);
        Print(LOG_LEVEL_DEBUG, formato, arg);
        va_end(arg);
    }
}

char *TokenString(int t)
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
    case INICIO:
        return "INICIO";
        break;
    case FIN:
        return "FIN";
        break;
    case FDT:
        return "FDT";
        break;
    default:
        return "ERROR_LEXICO";
        break;
    }
}

/* FUNCIONES PRIVADAS */

static void Print(const char level[], const char *formato, va_list args)
{
    printf("%s", level);
    vfprintf(stdout, formato, args);
    Reiniciar();
}

static void Reiniciar(void)
{
    printf("%s", LOG_LEVEL_INFO);
}