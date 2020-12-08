#include "Calc.h"

/* DECLARACION DE FUNCIONES PRIVADAS */

static void Configuracion(int argc, char **argv);
static void Ejemplos(void);

/* FUNCIONES PUBLICAS */

int main(int argc, char **argv)
{
       Configuracion(argc, argv);
       Ejemplos();
       printf("[Calc] Comienzo de objetivo\n");
       printf("[Calc] Ingrese programa:\n\n");
       Objetivo();
       printf("[Calc] Fin de objetivo\n");

       return EXIT_SUCCESS;
}

/* FUNCIONES PRIVADAS */

static void Configuracion(int argc, char **argv)
{
       if (argc > 1 && strcmp("-d", argv[1]) == 0)
       {
              DEBUG = 1;
       }
}

static void Ejemplos(void)
{
       printf("========================================CALCULADORA INFIJA AUTOMÁTICA========================================\n");
       printf("[Calc] Modo de uso:\n");
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
       printf("\n[Calc] Los identificadores tienen un máximo de 20 caracteres cada uno\n");
       printf("[Calc] Cada sentencia se debe ingresar en una línea nueva, terminada con punto y coma ';'\n");
       printf("[Calc] Para terminar el programa envíe señal de FDT: Ctrl+D (Unix), Ctrl+Z (Windows)\n");
       printf("========================================COMENZANDO EJECUCIÓN========================================\n");
}