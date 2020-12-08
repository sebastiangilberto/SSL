%{
#include "Parser.h"

void yyerror(char const *s){
  printf ("[Parser] Error sintáctico: %s\n", s);
}

static int yylex();

%}

%union {
  int intVal;
  char strVal[MAXVAL];
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
%type <intVal> objetivo
%type <intVal> programa
%type <intVal> listaSentencias
%type <intVal> sentencia
%type <intVal> expresion
%type <intVal> termino
%type <intVal> factor

%%
programa: INICIO listaSentencias FIN FDT;

listaSentencias: sentencia 
  | listaSentencias sentencia;

sentencia: IDENTIFICADOR ASIGNACION expresion { Agregar($1, $3); }
  | EVALUACION expresion { printf("[Scanner] Resultado de evaluación: %d\n", $2); };

expresion: termino { $$=$1; }
 | expresion ADICION termino { $$=$1+$3; }
 ;

termino: factor { $$=$1; }
 | factor MULTIPLICACION termino { $$=$1*$3; }
 ;

factor: IDENTIFICADOR { $$=Obtener($1); }
 | CONSTANTE { $$=$1; }
 | PARENTESIS_IZQ expresion PARENTESIS_DER { $$=$2; }
;



%%


static int yylex(void){   
    return GetNextToken();
}

void parser(){
  switch(yyparse()){
    case 0:
      return;
    case 1:
     printf("[Scanner] Error Sintáctico \n");
     return;
    default:
      printf("[Scanner] Error indefinido\n");
      return;
  }
}


