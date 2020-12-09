#include "Calc.h"

/* DECLARACION DE FUNCIONES PRIVADAS */

static void Configuracion(int argc, char **argv);
static void Ejemplos(void);

/* FUNCIONES PUBLICAS */

int main(int argc, char **argv)
{
       Configuracion(argc, argv);
       Ejemplos();
       Info("[Calc] Comienzo de objetivo\n");
       Info("[Calc] Ingrese programa:\n\n");
       Objetivo();
       Info("[Calc] Fin de objetivo\n");

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
       Info("========================================CALCULADORA INFIJA AUTOMÁTICA========================================\n");
       Info("[Calc] Modo de uso:\n");
       Info("Token Inicio '{'\n"
              "\tLista de sentencias [asignación|evaluación]\n"
              "Token Fin '}'\n");

       Info("\n[Calc] Ejemplo de programa:\n");
       Info("{\n"
              "\tA=24;\n"
              "\tB=(3+2)*4;\n"
              "\t$A+B;\n"
              "}\n");

       Info("\n[Calc] Ejemplos de asignación:\n");
       Info("\tA=24;\n"
              "\tA=2+7;\n"
              "\tB=(3+2)*4;\n"
              "\tA=B;\n");

       Info("\n[Calc] Ejemplos de Evaluación:\n");
       Info("\t$A;\n"
              "\t$2+2;\n"
              "\t$A+2;\n"
              "\t$A*(2+5)+B;\n");
       Info("\n[Calc] Los identificadores y constantes tienen un máximo de %d caracteres cada uno\n", TAMBUF);
       Info("[Calc] Cada sentencia se debe ingresar en una línea nueva, terminada con punto y coma ';'\n");
       Info("[Calc] Para terminar el programa enviar señal de FDT: Ctrl+D (Unix), Ctrl+Z (Windows)\n");
       Info("[Calc] Para ejecutar el programa en modo debug: ./Calc.out -d\n");
       Info("========================================COMENZANDO EJECUCIÓN========================================\n");
}