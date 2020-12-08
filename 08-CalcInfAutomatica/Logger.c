#include "Logger.h"

/* DEFINICION DE VARIABLES */
int DEBUG = 0;

/* FUNCIONES PUBLICAS */

void Info(const char *prefijo, const char *formato, ...)
{
    va_list arg;

    char *message = malloc(strlen(formato) + strlen(prefijo)) + 1;
    strcpy(message, prefijo);
    strcat(message, " ");
    strcat(message, formato);

    va_start(arg, formato);
    vfprintf(stdout, message, arg);
    va_end(arg);

    free(message);
}

void Debug(const char *prefijo, const char *formato, ...)
{
    if (DEBUG)
    {
        va_list arg;
        va_start(arg, formato);
        Info(prefijo, formato, arg);
        va_end(arg);
    }
}
