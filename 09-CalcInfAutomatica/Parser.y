%{
#include "Parser.h"

/* DECLARACION DE FUNCIONES PRIVADAS */

static void evaluacion(int valor);
static int yylex(void);
static void yyerror(char const *s);

%}

%union 
{
  int number;
  char string[100];
}

%token <string> ADICION
%token <string> ASIGNACION
%token <number> CONSTANTE
%token <string> ERROR_LEXICO
%token <string> EVALUACION
%token <string> FDT 0
%token <string> FIN
%token <string> IDENTIFICADOR
%token <string> INICIO
%token <string> MULTIPLICACION
%token <string> PARENTESIS_DER
%token <string> PARENTESIS_IZQ
%token <string> PUNTO_Y_COMA
%type <string> objetivo
%type <string> programa
%type <number> listaSentencias
%type <number> sentencia
%type <number> expresion
%type <number> termino
%type <number> factor
%start objetivo

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
       | termino MULTIPLICACION factor { $$ = $1 * $3; }
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