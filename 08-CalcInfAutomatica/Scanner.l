%{
  
#include "Scanner.h"

/* DEFINICION DE VARIABLES */

Token TOKEN_ACTUAL = INICIAL;
int FLAG_TOKEN = 0;
char BUFFER[TAMBUF];

%}

/* FUNCIONES FLEX */

%option noyywrap
%%

[0-9]+                  {
                          strcpy(BUFFER,yytext);
                          return (CONSTANTE);
                        }
\{                      {
                          strcpy(BUFFER,yytext);
                          return INICIO;
                        }
\}                      {
                          strcpy(BUFFER,yytext);
                          return FIN;
                        }
\(                      {
                          strcpy(BUFFER,yytext);
                          return PARENTESIS_IZQ;
                        }
\)                      {
                          strcpy(BUFFER,yytext);
                          return PARENTESIS_DER;
                        }
\*                      {
                          strcpy(BUFFER,yytext);
                          return MULTIPLICACION;
                        }
\+                      {
                          strcpy(BUFFER,yytext);
                          return ADICION;
                        }
\$                      {
                          strcpy(BUFFER,yytext);
                          return EVALUACION;
                        }
\=                      {
                          strcpy(BUFFER,yytext);
                          return ASIGNACION;
                        }
\;                      {
                          strcpy(BUFFER,yytext);
                          return PUNTO_Y_COMA;
                        }
[a-zA-Z_][a-zA-Z0-9_]*  {
                          strcpy(BUFFER,yytext);
                          return IDENTIFICADOR;
                        }
<<EOF>>                   return FDT;
[ ]+ ;
.                       { 
                          Error("[Scanner] Error Léxico, carácter inválido: %s\n", yytext);
                          return ERROR_LEXICO; 
                        }

%%

/* FUNCIONES PUBLICAS */

int GetNextToken()
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