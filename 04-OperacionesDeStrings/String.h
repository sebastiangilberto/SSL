/* string.h
 * prototipos de funciones sobre string
 * Sebastian Gilberto
 * 20200621
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/*
Descripción: Calcula la longitud de una cadena.

Argumentos:
    1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.

Resultado:
    1. size_t: entero positivo indicando la cantidad de caracteres que componen esa cadena.

Precondiciones:
    1. La cadena enviada como argumento debe finalizar con caracter nulo '\0': en caso contrario el programa no podrá terminar.
*/
size_t GetLength(const char * string);

/*
Descripción: Comprueba si una cadena está vacía.

Argumentos:
    1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.

Resultado:
    1. bool: valor bool indicando True si la cadena está vacía y False si la cadena NO está vacía.

Precondiciones:
    1. La cadena enviada como argumento debe finalizar con caracter nulo '\0': en caso contrario el programa no podrá terminar.
*/
bool IsEmpty(const char * string);

/*
Descripción: Concatena dos cadenas y devuelve un puntero a una nueva cadena que es el resultado de las dos cadenas originales concatenadas.

La nueva cadena es instanciada de forma dinámica.
Argumentos:
    1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.

Resultado:
    1. bool: valor bool indicando True si la cadena está vacía y False si la cadena NO está vacía.

Precondiciones:
    1. No hay precondición. La cadena puede o no contener caracter nulo '\0' indicando el fin de la cadena.
*/
char * ConcatDynamic(const char * a, const char * b);

/*
Descripción: Concatena dos cadenas y devuelve un puntero a una nueva cadena que es el resultado de las dos cadenas originales concatenadas.
        
La nueva cadena es depositada en el tercer argumento. La cadena resultante no es instanciada de forma dinámica.
Argumentos:
    1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.

Resultado:
    1. bool: valor bool indicando True si la cadena está vacía y False si la cadena NO está vacía.

Precondiciones:
    1. Las cadenas deben finalizar con caracter nulo '\0'.
    2. El tercer argumento (de salida) debe apuntar a un arreglo de char lo suficientemente grande como para contener el resultado de la concatenación de las cadenas originales.
*/
void ConcatStatic(const char * a, const char * b, char * result);

/*
Descripción: Potencia una cadena a un exponente natural N (con cero incluido) dando como resultado la cadena N veces.

La cadena resultante es instanciada de forma dinámica.
Argumentos:
    1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
    2. unsigned int power: valor entero natural al que se quiere potenciar la cadena.

Resultado:
    1. char *: puntero a un arreglo char dinámico conteniendo el resultado de la potencia de la cadena.

Precondiciones:
    1. La cadena original debe finalizar con caracter '\0'.
*/
char * PowerDynamic(const char * string, unsigned int power);

/*
Descripción: Potencia una cadena a un exponente natural N (con cero incluido) dando como resultado la cadena N veces.
       
La cadena resultante se deposita en un arreglo pre-existente. Se asume que el arreglo tiene la longitud necesaria para contener el resultado.
Argumentos:
    1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
    2. unsigned int power: valor entero natural al que se quiere potenciar la cadena.
    3. char * result: puntero a arreglo donde se quiere depositar el resultado de la potencia de la cadena.
Resultado:
    1. void: la funcion no devuelve un valor por retorno.

Precondiciones:
    1. La cadena original debe finalizar con caracter '\0'.
    2. El tercer argumento (de salida) debe apuntar a un arreglo de char lo suficientemente grande como para contener el resultado de la potencia de la cadena original.
*/
void PowerStatic(const char * string, unsigned int power, char * result);

/*
Descripción: compara dos cadenas de caracteres

Argumentos:
    1. const char * stringA: puntero const a un arreglo char tratado como una cadena A.
    2. const char * stringB: puntero const a un arreglo char tratado como una cadena B.
    3. size_t index: indice inicial desde donde se empiezan a recorrer las cadenas A y B para compararlas.
    
Resultado:
    1. int: la funcion devuelve 3 posibles valores.
            0: ambas cadenas son iguales
        -1: cadena A es menor a cadena B.
        +1: cadena A es mayor a cadena B.

Precondiciones:
    1. Las cadenas A y B deben finalizar con caracter nulo '\0'.
    2. El tercer argumento index debe ser 0 la primera vez que se llama a la función.
*/
int Compare(const char * a, const char * b, size_t index);