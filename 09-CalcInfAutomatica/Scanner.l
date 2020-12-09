%{

#include "Scanner.h"

%}

/* FUNCIONES FLEX */

%option noyywrap
%%

[0-9]+    {
            yylval.intVal=atoi(yytext);
            return CONSTANTE;
          }
\(        return PARENTESIS_IZQ;
\)        return PARENTESIS_DER;
\*        return MULTIPLICACION;
\+        return ADICION;
\$        return EVALUACION;
\=        return ASIGNACION;
\{        return INICIO;
\}        return FIN;
\;        return PUNTO_Y_COMA;
[a-zA-Z_][a-zA-Z0-9_]*  {
                          strcpy(yylval.strVal, yytext);
                          return IDENTIFICADOR;
                        }
<<EOF>>   return FDT;
[ ]+ ;
.                       {
                          Error("[Scanner] Error Léxico, carácter inválido: %s\n", yytext);
                          return ERROR_LEXICO;
                        }

%%

/* FUNCIONES PUBLICAS */

int GetNextToken()
{
  int t = yylex();
  if (t == ERROR_LEXICO)
    exit(EXIT_FAILURE);
  Debug("[Scanner] Token identificado: %s\n", TokenString(t));
  return t;
}