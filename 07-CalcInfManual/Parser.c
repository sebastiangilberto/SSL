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
  char identificador[TAMBUF];
  int resultado = 0;

  switch (GetNextToken())
  {
  case IDENTIFICADOR: /* <sentencia> -> IDENTIFICADOR = <expresion> ; */
    Match(IDENTIFICADOR);
    Debug("[Parser] Sentencia, nombre del identificador guardado en BUFFER: %s\n", BUFFER);
    strcpy(identificador, BUFFER);
    Match(ASIGNACION);
    resultado = Expresion();
    Match(PUNTO_Y_COMA);
    Agregar(identificador, resultado);
    break;
  case EVALUACION: /* <sentencia> -> EVALUACION <expresion> ; */
    Match(EVALUACION);
    resultado = Expresion();
    Match(PUNTO_Y_COMA);
    Info("[Parser] Resultado de evaluación: %d\n", resultado);
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
    resultado = Obtener(BUFFER);
    break;
  case CONSTANTE:
    Match(CONSTANTE);
    resultado = atoi(BUFFER);
    Debug("[Parser] Factor, valor de constante almacenada en BUFFER: %d\n", resultado);
    break;
  case PARENTESIS_IZQ:
    Match(PARENTESIS_IZQ);
    resultado = Expresion();
    Match(PARENTESIS_DER);
    break;
  default:
    Error("[Parser] Error Sintáctico, Tokens esperados: [%s, %s, %s], Token actual: %s", TokenString(IDENTIFICADOR), TokenString(CONSTANTE), TokenString(PARENTESIS_IZQ), TokenString(TOKEN_ACTUAL));
    exit(EXIT_FAILURE);
    break;
  }

  return resultado;
}

static void Match(Token esperado)
{
  if (esperado != GetNextToken())
  {
    Error("[Parser] Error Sintáctico, Tokens esperados: [%s], Token actual: %s", TokenString(esperado), TokenString(TOKEN_ACTUAL));
    exit(EXIT_FAILURE);
  }
  FLAG_TOKEN = 0;
}