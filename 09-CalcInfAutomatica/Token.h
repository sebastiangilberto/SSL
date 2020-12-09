/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FDT = 0,
     ADICION = 258,
     ASIGNACION = 259,
     CONSTANTE = 260,
     ERROR_LEXICO = 261,
     EVALUACION = 262,
     FIN = 263,
     IDENTIFICADOR = 264,
     INICIO = 265,
     MULTIPLICACION = 266,
     PARENTESIS_DER = 267,
     PARENTESIS_IZQ = 268,
     PUNTO_Y_COMA = 269
   };
#endif
/* Tokens.  */
#define FDT 0
#define ADICION 258
#define ASIGNACION 259
#define CONSTANTE 260
#define ERROR_LEXICO 261
#define EVALUACION 262
#define FIN 263
#define IDENTIFICADOR 264
#define INICIO 265
#define MULTIPLICACION 266
#define PARENTESIS_DER 267
#define PARENTESIS_IZQ 268
#define PUNTO_Y_COMA 269




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "Parser.y"
{
  int number;
  char string[100];
}
/* Line 1529 of yacc.c.  */
#line 84 "Token.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

