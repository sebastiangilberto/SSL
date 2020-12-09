#include "Logger.h"

/* DEFINICION DE VARIABLES */

int DEBUG = 0;

/* DECLARACION DE FUNCIONES PRIVADAS */

static void Reiniciar(void);
static void Rojo(void);
static void Amarillo(void);
static void Verde(void);
static void Print(const char *formato, va_list args);

/* FUNCIONES PUBLICAS */

void Info(const char *formato, ...)
{
    va_list arg;
    va_start(arg, formato);
    vfprintf(stdout, formato, arg);
    va_end(arg);
}

void Error(const char *formato, ...)
{
    va_list arg;
    va_start(arg, formato);
    Rojo();
    Print(formato, arg);
    Reiniciar();
    va_end(arg);
}

void Debug(const char *formato, ...)
{
    if (DEBUG)
    {
        va_list arg;
        va_start(arg, formato);
        Amarillo();
        Print(formato, arg);
        Reiniciar();
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

static void Print(const char *formato, va_list args)
{
    vfprintf(stdout, formato, args);
}

static void Reiniciar(void)
{
    printf("\033[0m");
}

static void Rojo(void)
{
    printf("\033[1;31m");
}

static void Amarillo(void)
{
    printf("\033[1;33m");
}

static void Verde(void)
{
    printf("\033[0;32m");
}
