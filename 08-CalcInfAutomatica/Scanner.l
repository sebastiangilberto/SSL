%{
#include "Scanner.h"

/* DEFINICION DE VARIABLES */

char LEXEMA[TAMNOM];
int FLAG_TOKEN = 0;

/* FUNCIONES FLEX */

%}

%option noyywrap
%%

[0-9]+ {
          strcpy(LEXEMA,yytext);
          return (CONSTANTE);
          }
\{ {

          strcpy(LEXEMA,yytext);
          return INICIO;
          }
\} {

          strcpy(LEXEMA,yytext);
          return FIN;
          }
\( {

          strcpy(LEXEMA,yytext);
          return PARENTESIS_IZQ;
          }
\) {
          strcpy(LEXEMA,yytext);
          return PARENTESIS_DER;
          }
\* {
          strcpy(LEXEMA,yytext);
          return MULTIPLICACION;
          }
\+ {
          strcpy(LEXEMA,yytext);
          return ADICION;
          }
\$ {
          strcpy(LEXEMA,yytext);
          return EVALUACION;
          }
\= {
          strcpy(LEXEMA,yytext);
          return ASIGNACION;
          }
\; {
          strcpy(LEXEMA,yytext);
          return PUNTO_Y_COMA;
          }
[a-zA-Z_][a-zA-Z0-9_]* {
          strcpy(LEXEMA,yytext);
          return IDENTIFICADOR;
          }
<<EOF>> { return FDT; }
[ ]+ ;
. { 
    Error("[Scanner] Error Léxico, carácter inválido: %s\n", yytext);
    return ERROR_LEXICO; 
  }

%%

/* FUNCIONES PUBLICAS */


Token GetNextToken()
{

  if (!FLAG_TOKEN)
  {

    TOKEN_ACTUAL = yylex();
    if (TOKEN_ACTUAL == ERROR_LEXICO)
      exit(EXIT_FAILURE);
    Debug("[Scanner] Token identificado: %s\n", TokenString(TOKEN_ACTUAL));
    FLAG_TOKEN = 1;
  }
  return TOKEN_ACTUAL;
}