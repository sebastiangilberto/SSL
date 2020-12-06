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
    printf("[Calc] Ejemplos de asignación:\n");
    printf("\tA=24;\n"
           "\tA=2+7;\n"
           "\tB=(3+2)*4;\n"
           "\tA=B;\n");

    printf("[Calc] Ejemplos de Evaluación:\n");
    printf("\t$A\n"
           "\t$2+2\n"
           "\t$A+2\n"
           "\t$A*(2+5)+B\n");
}