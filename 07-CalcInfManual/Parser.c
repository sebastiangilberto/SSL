#include "Parser.h"

static void Programa(void);
static void Sentencia(void);
static void Expresion(void);
static void Primaria(void);
static void PrimariaOParentesisIzquierdo(void);
static void Operador(void);
static void Match(Token esperado);
static void ErrorSintacticoConDosAlternativa(Token esperado, Token primera_alternativa, Token segunda_alternativa);
static void ErrorSintacticoConAlternativa(Token esperado, Token alternativa);
static void ErrorSintactico(Token esperado);

void Objetivo(void) {
    Programa();
    printf("[Parser] Expresión Válida\n");
}

static void Programa(void) {
    Sentencia();
}

static void Sentencia(void) {
    Expresion();
    while(1) {
        switch(GetNextToken()) {
            case FDT:
                return;
            default:
                Operador();
                Expresion();
        }
    }
}

static void Expresion(void) {
    Primaria();

    Token t = GetNextToken();
    
    if(t == ADICION || t == MULTIPLICACION) {
        Operador();
        Primaria();
    }
}

/**
static void Expresion(void) {
    Primaria();
    
    while(1) {
        switch(GetNextToken()) {
            case ADICION:
            case MULTIPLICACION:
                Primaria();
                break;
            case FDT:
                return;
            default:
                break;
        }
    }
}
**/

static void Operador(void) {
    Token t = GetNextToken();
    if (t == ADICION || t == MULTIPLICACION)
        return;
    else
        ErrorSintacticoConAlternativa(ADICION, MULTIPLICACION);
}

static void PrimariaOParentesisIzquierdo(void) {
    Token t = GetNextToken();
    if (t == IDENTIFICADOR || t == CONSTANTE || t == PARENTESIS_IZQ)
        return;
    else
        ErrorSintacticoConDosAlternativa(IDENTIFICADOR, CONSTANTE, PARENTESIS_IZQ);
}

static void Primaria(void) {
    Token t = GetNextToken();
    if (t == IDENTIFICADOR || t == CONSTANTE)
        return;
    else
        ErrorSintacticoConAlternativa(IDENTIFICADOR, CONSTANTE);
}

static void Match(Token esperado) {
    Token t = GetNextToken();
    if (t == esperado)
        return;
    else 
        ErrorSintactico(esperado);
} 

static void ErrorSintacticoConDosAlternativa(Token esperado, Token primera_alternativa, Token segunda_alternativa) {
    printf("[Parser] Error Sintáctico\n");
    printf("[Parser] Token esperado: %s o %s o %s\n", TokenString(esperado), TokenString(primera_alternativa), TokenString(segunda_alternativa));
    printf("[Parser] Token actual: %s\n", TokenString(tokenActual));
    exit(EXIT_SUCCESS);
}

static void ErrorSintacticoConAlternativa(Token esperado, Token alternativa) {
    printf("[Parser] Error Sintáctico\n");
    printf("[Parser] Token esperado: %s o %s\n", TokenString(esperado), TokenString(alternativa));
    printf("[Parser] Token actual: %s\n", TokenString(tokenActual));
    exit(EXIT_SUCCESS);
}

static void ErrorSintactico(Token esperado) {
    printf("[Parser] Error Sintáctico\n");
    printf("[Parser] Token esperado: %s\n", TokenString(esperado));
    printf("[Parser] Token actual: %s\n", TokenString(tokenActual));
    exit(EXIT_SUCCESS);
}