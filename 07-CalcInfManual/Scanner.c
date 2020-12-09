#include "Scanner.h"

/* DECLARACION DE FUNCIONES PRIVADAS */

static bool FinDeTexto(int c);
static void DevolverCaracter(char c);
static bool Adicion(int c);
static bool Multiplicacion(int c);
static bool Identificador();
static bool Constante();
static bool Digito(int c);
static bool Letra(int c);
static bool Espacio(int c);
static bool ParentesisIzquierdo(int c);
static bool ParentesisDerecho(int c);
static bool Asignacion(int c);
static bool Evaluacion(int c);
static bool PuntoYComa(int c);

/* DEFINICION DE VARIABLES */

Token TOKEN_ACTUAL;
char LEXEMA[TAMNOM];
int FLAG_TOKEN = 0;

/* FUNCIONES PUBLICAS */

Token GetNextToken()
{
    if (!FLAG_TOKEN)
    {

        TOKEN_ACTUAL = Scanner();
        if (TOKEN_ACTUAL == ERROR_LEXICO)
            exit(EXIT_FAILURE);
        Debug("[Scanner] Token identificado: %s\n", TokenString(TOKEN_ACTUAL));
        FLAG_TOKEN = 1;
    }
    return TOKEN_ACTUAL;
}

// TODO: esto ya me tendría que llenar el LEXEMA
Token Scanner()
{
    Token token = INICIAL;
    int c;

    c = getchar();

    while (Espacio(c))
        c = getchar();

    if (FinDeTexto(c))
    {
        token = FDT;
    }
    else if (Digito(c))
    {
        Constante();
        token = CONSTANTE;
    }
    else if (Letra(c))
    {
        Identificador();
        token = IDENTIFICADOR;
    }
    else if (Adicion(c))
    {
        token = ADICION;
    }
    else if (Multiplicacion(c))
    {
        token = MULTIPLICACION;
    }
    else if (ParentesisIzquierdo(c))
    {
        token = PARENTESIS_IZQ;
    }
    else if (ParentesisDerecho(c))
    {
        token = PARENTESIS_DER;
    }
    else if (Asignacion(c))
    {
        token = ASIGNACION;
    }
    else if (Evaluacion(c))
    {
        token = EVALUACION;
    }
    else if (PuntoYComa(c))
    {
        token = PUNTO_Y_COMA;
    }
    else
    {
        Error("[Scanner] Error Léxico, carácter inválido: %s\n", c);
        token = ERROR_LEXICO;
    }

    return token;
}

/* FUNCIONES PRIVADAS */

static void DevolverCaracter(char c)
{
    ungetc(c, stdin);
}

static bool FinDeTexto(int c)
{
    return c == EOF;
}

static bool Adicion(int c)
{
    return c == '+';
}

static bool Multiplicacion(int c)
{
    return c == '*';
}

static bool Identificador()
{
    bool r = false;
    int c = getchar();
    while (Letra(c))
    {
        c = getchar();
        r = true;
    }
    DevolverCaracter(c);
    return r;
}

static bool Constante()
{
    bool r = false;
    int c = getchar();
    while (Digito(c))
    {
        c = getchar();
        r = true;
    }
    DevolverCaracter(c);
    return r;
}

static bool Digito(int c)
{
    return isdigit(c);
}

static bool Letra(int c)
{
    return isalpha(c);
}

static bool Espacio(int c)
{
    return isspace(c);
}

static bool ParentesisIzquierdo(int c)
{
    return c == '(';
}

static bool ParentesisDerecho(int c)
{
    return c == ')';
}

static bool Asignacion(int c)
{
    return c == '=';
}

static bool Evaluacion(int c)
{
    return c == '$';
}

static bool PuntoYComa(int c)
{
    return c == ';';
}