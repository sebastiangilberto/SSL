#include "Error.h"

void ErrorLexico(int c)
{
    printf("[Scanner] Error Léxico\n");
    printf("[Scanner] Carácter inválido: %c\n", c);
    exit(EXIT_SUCCESS);
}

void ErrorSintactico(int count, ...)
{
    va_list args;
    int j;
    char *esperados = calloc(10, sizeof(Token));
    char *e = calloc(1, sizeof(Token));

    va_start(args, count);

    for (j = 0; j < count; j++)
    {
        sprintf(e, "[%s]", TokenString(va_arg(args, int)));
        strcat(esperados, e);
    }
    va_end(args);

    printf("[Parser] Error Sintáctico\n");
    printf("[Parser] Tokens esperados: %s, Token actual: %s\n", esperados, TokenString(TOKEN_ACTUAL));

    free(e);
    free(esperados);

    exit(EXIT_SUCCESS);
}