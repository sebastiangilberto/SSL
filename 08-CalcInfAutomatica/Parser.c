#include "Parser.h"

/* DECLARACION DE FUNCIONES PRIVADAS */

static void Programa(void);
static void ListaSentencias(void);
static void Sentencia(void);
static int Expresion(void);
static int Termino(void);
static int Factor(void);
static void Match(Token esperado);

/* FUNCIONES PUBLICAS */

void Objetivo(void)
{
  Programa();
  Match(FDT);
}

/* FUNCIONES PRIVADAS */

static void Programa(void)
{
  Match(INICIO);
  ListaSentencias();
  Match(FIN);
}

static void ListaSentencias(void)
{
  /* <listaSentencias> -> <sentencia> {<sentencia>} */
  Sentencia();
  while (1)
  {
    switch (GetNextToken())
    {
    case IDENTIFICADOR:
    case EVALUACION:
      Sentencia();
      break;
    default:
      return;
    }
  }
}

static void Sentencia(void)
{
  char variable[100];
  int resultado = 0;

  switch (GetNextToken())
  {
  case IDENTIFICADOR: /* <sentencia> -> IDENTIFICADOR = <expresion> ; */
    Match(IDENTIFICADOR);
    strcpy(variable, LEXEMA);
    Match(ASIGNACION);
    resultado = Expresion();
    Match(PUNTO_Y_COMA);
    Agregar(variable, resultado);
    break;
  case EVALUACION: /* <sentencia> -> EVALUACION <expresion> ; */
    Match(EVALUACION);
    resultado = Expresion();
    Match(PUNTO_Y_COMA);
    printf("[Parser] Resultado de evaluación: %d\n", resultado);
    break;
  default:
    return;
  }
}

static int Expresion(void)
{
  int resultado = Termino();
  switch (GetNextToken())
  {
  case ADICION:
    Match(ADICION);
    return resultado + Expresion();
  default:
    return resultado;
  }
}

static int Termino(void)
{
  int resultado = Factor();
  switch (GetNextToken())
  {
  case MULTIPLICACION:
    Match(MULTIPLICACION);
    return resultado * Termino();
  default:
    return resultado;
  }
}

static int Factor(void)
{
  int resultado;
  switch (GetNextToken())
  {
  case IDENTIFICADOR:
    Match(IDENTIFICADOR);
    resultado = Obtener(LEXEMA);
    break;
  case CONSTANTE:
    Match(CONSTANTE);
    resultado = atoi(LEXEMA);
    break;
  case PARENTESIS_IZQ:
    Match(PARENTESIS_IZQ);
    resultado = Expresion();
    Match(PARENTESIS_DER);
    break;
  default:
    ErrorSintactico(3, IDENTIFICADOR, CONSTANTE, PARENTESIS_IZQ);
    resultado = 0;
    break;
  }

  return resultado;
}

static void Match(Token esperado)
{
  if (esperado != GetNextToken())
    ErrorSintactico(1, esperado);
  FLAG_TOKEN = 0;
}