#include "Scanner.h"

/* DECLARACION DE FUNCIONES PRIVADAS */

static Token Scanner(void);
static bool FinDeTexto(int c);
static void DevolverCaracter(char c);
static bool Adicion(int c);
static bool Multiplicacion(int c);
static void Identificador(int c);
static void Constante(int c);
static bool Digito(int c);
static bool Letra(int c);
static bool Espacio(int c);
static bool ParentesisIzquierdo(int c);
static bool ParentesisDerecho(int c);
static bool Asignacion(int c);
static bool Evaluacion(int c);
static bool PuntoYComa(int c);
static bool Inicio(int c);
static bool Fin(int c);
static void Guardar(int c);
static void CaracterNulo();
static void Limpiar();
static void Chequear();

/* DEFINICION DE VARIABLES */

Token TOKEN_ACTUAL = INICIAL;
int FLAG_TOKEN = 0;
char BUFFER[TAMBUF];
static int POS = 0;

/* FUNCIONES PUBLICAS */

int GetNextToken()
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

static Token Scanner()
{
    Token token = INICIAL;
    int c;
    Limpiar();

    c = getchar();

    while (Espacio(c))
        c = getchar();

    if (FinDeTexto(c))
    {
        Guardar(c);
        token = FDT;
    }
    else if (Digito(c))
    {
        Constante(c);
        token = CONSTANTE;
    }
    else if (Letra(c))
    {
        Identificador(c);
        CaracterNulo();
        token = IDENTIFICADOR;
    }
    else if (Adicion(c))
    {
        Guardar(c);
        CaracterNulo();
        token = ADICION;
    }
    else if (Multiplicacion(c))
    {
        Guardar(c);
        CaracterNulo();
        token = MULTIPLICACION;
    }
    else if (ParentesisIzquierdo(c))
    {
        Guardar(c);
        CaracterNulo();
        token = PARENTESIS_IZQ;
    }
    else if (ParentesisDerecho(c))
    {
        Guardar(c);
        CaracterNulo();
        token = PARENTESIS_DER;
    }
    else if (Asignacion(c))
    {
        Guardar(c);
        CaracterNulo();
        token = ASIGNACION;
    }
    else if (Evaluacion(c))
    {
        Guardar(c);
        CaracterNulo();
        token = EVALUACION;
    }
    else if (PuntoYComa(c))
    {
        Guardar(c);
        CaracterNulo();
        token = PUNTO_Y_COMA;
    }
    else if (Inicio(c))
    {
        Guardar(c);
        CaracterNulo();
        token = INICIO;
    }
    else if (Fin(c))
    {
        Guardar(c);
        CaracterNulo();
        token = FIN;
    }
    else
    {
        Error("[Scanner] Error Léxico, carácter inválido: %c\n", c);
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

static void Identificador(int c)
{
    Guardar(c);
    c = getchar();
    while (Letra(c))
    {
        Guardar(c);
        c = getchar();
    }
    DevolverCaracter(c);
}

static void Constante(int c)
{
    Guardar(c);
    c = getchar();
    while (Digito(c))
    {
        Guardar(c);
        c = getchar();
    }
    DevolverCaracter(c);
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

static bool Inicio(int c)
{
    return c == '{';
}

static bool Fin(int c)
{
    return c == '}';
}

static void Guardar(int c)
{
    Chequear();
    Debug("[Scanner] Guardando caracter '%c', en POS: %d\n", c, POS);
    BUFFER[POS++] = c;
}

static void CaracterNulo()
{
    Guardar('\0');
}

static void Chequear()
{
    if (POS > TAMBUF)
    {
        Error("[Scanner] El lexema supera el máximo definido para el buffer: %d\n", TAMBUF);
        exit(EXIT_FAILURE);
    }
}

static void Limpiar()
{
    POS = 0;
    BUFFER[POS] = '\0';
    Debug("[Scanner] Limpiando BUFFER\n");
}