#include "Calc.h"

/* DECLARACION DE FUNCIONES PRIVADAS */

static void Ejemplos(void);

/* FUNCIONES PUBLICAS */

int main()
{
    printf("[Calc] Comienzo de objetivo\n");
    Ejemplos();
    printf("[Calc] Para terminar el programa envíe señal de FDT: Ctrl+D (Unix), Ctrl+Z (Windows)\n");
    printf("[Calc] Ingrese cada sentencia en una nueva línea\n\n");
    Objetivo();
    printf("[Calc] Fin de objetivo\n");

    return EXIT_SUCCESS;
}

/* FUNCIONES PRIVADAS */

static void Ejemplos(void)
{
    printf("[Calc] El formato válido es el siguiente:\n");
    printf("Token Inicio '{'\n"
           "\tLista de sentencias [asignación|evaluación]\n"
           "Token Fin '}'\n");

    printf("\n[Calc] Ejemplo de programa:\n");
    printf("{\n"
           "\tA=24;\n"
           "\tB=(3+2)*4;\n"
           "\t$A+B;\n"
           "}\n");

    printf("\n[Calc] Ejemplos de asignación:\n");
    printf("\tA=24;\n"
           "\tA=2+7;\n"
           "\tB=(3+2)*4;\n"
           "\tA=B;\n");

    printf("\n[Calc] Ejemplos de Evaluación:\n");
    printf("\t$A;\n"
           "\t$2+2;\n"
           "\t$A+2;\n"
           "\t$A*(2+5)+B;\n");
}