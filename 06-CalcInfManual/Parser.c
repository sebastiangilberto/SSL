#include "Parser.h"

static void Programa(void);
static void Expresion(void);
static void Operador(void);
static void Primaria(void);
static void ErrorSintactico(Token esperado, Token alternativa);

void Objetivo(void) {
    Programa();
    printf("[Parser] Expresión Válida\n");
}

static void Programa(void) {
    Expresion();
}

static void Expresion(void) {
    Primaria();
    
    while(1) {
        switch(GetNextToken()) {
            case ADICION:
            case MULTIPLICACION:
                Primaria();
                break;
            case IDENTIFICADOR:
            case CONSTANTE:
                Operador();
                break;
            case FDT:
                return;
            default:
                break;
        }
    }
}

static void Operador(void) {
    Token t = GetNextToken();
    if (t == ADICION || t == MULTIPLICACION)
        return;
    else
        ErrorSintactico(ADICION, MULTIPLICACION);
}

static void Primaria(void) {
    Token t = GetNextToken();
    if (t == IDENTIFICADOR || t == CONSTANTE)
        return;
    else
        ErrorSintactico(IDENTIFICADOR, CONSTANTE);
}

static void ErrorSintactico(Token esperado, Token alternativa) {
    printf("[Parser] Error Sintáctico\n");
    printf("[Parser] Token esperado: %s o %s\n", TokenString(esperado), TokenString(alternativa));
    printf("[Parser] Token actual: %s\n", TokenString(tokenActual));
    exit(EXIT_SUCCESS);
}