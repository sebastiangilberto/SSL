// PARSER AUTOMATICO
%{
#include "Parser.h"

/* DECLARACION DE FUNCIONES PRIVADAS */

static void evaluacion(int valor);
static int yylex(void);
static void yyerror(char const *s);

%}

%union {
  int intVal;
  char strVal[20+1];
}

%token <strVal> ADICION
%token <strVal> ASIGNACION
%token <intVal> CONSTANTE
%token <strVal> ERROR_LEXICO
%token <strVal> EVALUACION
%token <strVal> FDT 0
%token <strVal> FIN
%token <strVal> IDENTIFICADOR
%token <strVal> INICIO
%token <strVal> MULTIPLICACION
%token <strVal> PARENTESIS_DER
%token <strVal> PARENTESIS_IZQ
%token <strVal> PUNTO_Y_COMA
%type <strVal> objetivo
%type <strVal> programa
%type <intVal> listaSentencias
%type <intVal> sentencia
%type <intVal> expresion
%type <intVal> termino
%type <intVal> factor

%%
objetivo: programa FDT;

programa: INICIO listaSentencias FIN;

listaSentencias: sentencia
               | listaSentencias sentencia
;

sentencia: IDENTIFICADOR ASIGNACION expresion PUNTO_Y_COMA { Agregar($1, $3); }
         | EVALUACION expresion PUNTO_Y_COMA { evaluacion($2); }
;

expresion: termino { $$ = $1; }
         | expresion ADICION termino { $$ = $1 + $3; }
;

termino: factor { $$ = $1; }
       | factor MULTIPLICACION termino { $$ = $1 * $3; }
 ;

factor: IDENTIFICADOR { $$ = Obtener($1); }
      | CONSTANTE { $$ = $1; }
      | PARENTESIS_IZQ expresion PARENTESIS_DER { $$ = $2; }
;

%%

/* FUNCIONES PUBLICAS */

void yyerror(char const *s){
  Error("[Parser] Error Sintáctico: %s\n", s);
}

int yylex(void){   
    return GetNextToken();
}

void Objetivo(void){
  switch(yyparse()){
    case 0:
      return;
    case 1:
      return;
    default:
      Error("[Parser] Error indefinido\n");
      return;
  }
}

/* FUNCIONES PRIVADAS */
static void evaluacion(int valor) {
    Info("[Parser] Resultado de evaluación: %d\n", valor);
}