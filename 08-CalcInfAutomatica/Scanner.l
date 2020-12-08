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
          printf("[Scanner] Token identificado: %s\n", TokenString(CONSTANTE));
          return (CONSTANTE);
          }
\{ {

          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(INICIO));
          return INICIO;
          }
\} {

          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(FIN));
          return FIN;
          }
\( {

          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(PARENTESIS_IZQ));
          return PARENTESIS_IZQ;
          }
\) {
          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(PARENTESIS_DER));
          return PARENTESIS_DER;
          }
\* {
          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(MULTIPLICACION));
          return MULTIPLICACION;
          }
\+ {
          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(ADICION));
          return ADICION;
          }
\$ {
          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(EVALUACION));
          return EVALUACION;
          }
\= {
          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(ASIGNACION));
          return ASIGNACION;
          }
\; {
          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(PUNTO_Y_COMA));
          return PUNTO_Y_COMA;
          }
[a-zA-Z_][a-zA-Z0-9_]* {
          strcpy(LEXEMA,yytext);
          printf("[Scanner] Token identificado: %s\n", TokenString(IDENTIFICADOR));
          return IDENTIFICADOR;
          }
<<EOF>> { 
          printf("[Scanner] Token identificado: %s\n", TokenString(FDT));
          return FDT; 
          }
[ ]+ ;
. {return ERROR_LEXICO;}

%%

/* FUNCIONES PUBLICAS */

Token GetNextToken()
{

  if (!FLAG_TOKEN)
  {

    TOKEN_ACTUAL = yylex();
    if (TOKEN_ACTUAL == ERROR_LEXICO)
      ErrorLexico(TOKEN_ACTUAL);
    FLAG_TOKEN = 1;
  }
  return TOKEN_ACTUAL;
}