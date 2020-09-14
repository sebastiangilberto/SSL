#include "Scanner.h"

static bool FinDeTexto(int c);
static void DevolverCaracter(char c);
static bool Adicion(int c);
static bool Multiplicacion(int c);
static bool Identificador();
static bool Constante();
static bool Digito(int c);
static bool Letra(int c);
static bool Espacio(int c);
static void ErrorLexico(int c);

//Token GetNextToken() {
//    return tokenList[lastToken++];
//}

Token GetNextToken() {
    Token token = INICIAL;
    int c;

    c = getchar();

    while(Espacio(c)) c = getchar();

    if (FinDeTexto(c)) {
        token = FDT;
    } else if (Digito(c)) {
        Constante();
        token = CONSTANTE;
    } else if (Letra(c)) {
        Identificador();
        token = IDENTIFICADOR;
    } else if (Adicion(c)) {
        token = ADICION;
    } else if (Multiplicacion(c)) {
        token = MULTIPLICACION;
    } else {
        token = UNDEFINED;
        ErrorLexico(c);
    }

    printf("[Scanner] Token identificado: %s\n", TokenString(token));

    tokenActual = token;

    return token;
}

void LeerCaracteres() {
    lastToken = 0;
    int index = 0;
    int c;

    while (tokenActual != FDT) {
        c = getchar();

        while(Espacio(c)) c = getchar();

        if (FinDeTexto(c)) {
            tokenActual = FDT;
        } else if (Digito(c)) {
            Constante();
            tokenActual = CONSTANTE;
        } else if (Letra(c)) {
            Identificador();
            tokenActual =  IDENTIFICADOR;
        } else if (Adicion(c)) {
            tokenActual =  ADICION;
        } else if (Multiplicacion(c)) {
            tokenActual =  MULTIPLICACION;
        } else {
            tokenActual =  UNDEFINED;
            ErrorLexico(c);
        }

        printf("[Scanner] Token identificado: %s\n", TokenString(tokenActual));
        tokenList[index++] = tokenActual;
    }
}

void MostrarTokens() {
    for(int index = 0; index < lastToken; index++) {
        printf("[Scanner] tokenList[%d]: %s\n", index, TokenString(tokenList[index]));
    }
}

char* TokenString(Token t) {
    switch (t)
    {
    case CONSTANTE:
        return "CONSTANTE";
        break;
    case IDENTIFICADOR:
        return "IDENTIFICADOR";
        break;
    case ADICION:
        return "ADICION";
        break;
    case MULTIPLICACION:
        return "MULTIPLICACION";
        break;
    case FDT:
        return "FDT";
        break;
    default:
        return "UNDEFINED";
        break;
    }
}

static void DevolverCaracter(char c) {
    // printf("[Scanner] Carácter devuelto: %c\n", c);
    ungetc(c, stdin);
}

static bool FinDeTexto(int c) {
    return c == EOF;
}

static bool Adicion(int c) {
    return c == '+';
}

static bool Multiplicacion(int c) {
    return c == '*';
}

static bool Identificador() {
    bool r = false;
    int c = getchar();
    while(Letra(c)) {
        c = getchar();
        r = true;
    }
    DevolverCaracter(c);
    return r;
}

static bool Constante() {
    bool r = false;
    int c = getchar();
    while(Digito(c)) {
        c = getchar();
        r = true;
    }
    DevolverCaracter(c);
    return r;
}

static bool Digito(int c) {
    return isdigit(c);
}

static bool Letra(int c) {
    return isalpha(c);
}

static bool Espacio(int c) {
    return isspace(c);
}

static void ErrorLexico(int c) {
    printf("[Scanner] Error Léxico\n");
    printf("[Scanner] Carácter inválido: %c\n", c);
    exit(EXIT_SUCCESS);
}

//static void AgregarCaracter(int);

//static void LimpiarBuffer(void);

//static void RepararErrorSintactico(void);