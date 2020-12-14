# Calculadora Infija Manual

## Nivel Léxico

Para esta iteración el `Scanner` se desarrollo con la herramienta `flex`.

Dada una expresión regular, se identifica un lexema y se asocia un token válido para el LP.

La interface se mantiene igual respecto a la comunicación entre Parser y Scanner, mediante la función `GetNextToken()` la cuál invoca a la función de flex `yylex()`.

Por cada acción realizada al evaluar la expresión regular y encontrar una coincidencia, se realiza una copia del valor de la variable `yytext` al `BUFFER`, logrando de esta forma mantener el funcionamiento de la tabla de símbolos (memoria) desarrollada en la iteración anterior.

## Expresiones regulares

A continuación se listan las expresiones regulares utilizadas por flex, para identificar los tokens válidos del LP:

| Regex             | Token                                                           |
|-------------------|-----------------------------------------------------------------|
| [ 0-9 ] +         | CONSTANTE                                                       |
| [a-zA-Z][a-zA-Z]* | IDENTIFICADOR                                                   |
| \{                | INICIO                                                          |
| \}                | FIN                                                             |
| \(                | PARENTESIS_IZQ                                                  |
| \)                | PARENTESIS_DER                                                  |
| \*                | MULTIPLICACION                                                  |
| \+                | ADICION                                                         |
| \=                | ASIGNACION                                                      |
| \$                | EVALUACION                                                      |
| \;                | PUNTO_Y_COMA                                                    |
| <<EOF>>           | FDT                                                             |
| [ ]+              | espacios en blanco, tabulados, marcas de fin de línea (ignorar) |
| .                 | ERROR_LEXICO                                                    |


## Nivel Sintáctico

Para esta iteración el `Parser` se desarrollo con la herramienta `bison`.

La interface se mantiene igual entre Calc y Parser, mediante la función `Objetivo()`, que internamente llama a la función de bison `yyparse()`, la cual lee una secuencia de tokens mediante la función del Scanner `yylex()`.

En el archivo `Parser.y`, se declararon las gramáticas sintácticas.

Debido a que bison realiza una llamada a la función `yylex()` para obtener los tokens, se implementó dicha función, la cual internamente llama a `GetNextToken()` del `Scanner`.

### Recursividad

Para las gramáticas definidas, se puede utilizar 
recursividad izquierda o derecha.

Para evitar posibles problemas de memoria, y por propias recomendaciones de bibliografías consultadas, se utilizó recursividad izquierda.

#### Recursividad izquierda

Con recursividad izquierda, bison va reduciendo a medida que avanza en el análisis, manteniendo como mucho tres términos en el stack.

Ejemplo:

```
lista:
      item
      | lista ',' item
      ;
```

#### Recursividad derecha

Con recursividad derecha, bison mantiene todos los términos en el stack, realizando la reducción al encontrar el último término.

Ejemplo:

```
lista:
      item
      | item ',' lista
```

Para el ejemplo todos los items de la lista serían pusheados al stack, y cuando se detecta el último item, recién en ese momento se realiza la reducción.

### Tokens

Los tokens válidos para el LP se definen en el mismo archivo `Parser.y`, junto con los valores que debe retornar cada uno:

- Identificadores: cadena de caracteres
- Constantes: int
- Resto de tokens: cadena de caracteres

Al compilar el archivo fuente, el mismo genera un archivo header `Token.h` con la definición de los tokens.

### Gramática Sintáctica

```xml
<objetivo>          ->  <programa>
<programa>          ->  <inicio> <listaSentencias> <fin>
<listaSentencias>   ->  <sentencia> { <sentencia> } 
<sentencia>         ->  <identificador> <asignacion> <expresion> <separador> |
			            <evaluacion> <expresion> <separador>
<expresión>         ->  <termino> { <adicion> <expresion> }
<termino>           ->  <factor> { <multiplicacion> <termino> }
<factor>            ->  <identificador> |
                        <constante> |
                        <parentesis_izq> <expresión> <parentesis_der>
```

## Tabla de símbolos

Para almacenar los valores asociados a los identificadores, y poder utilizarlo en otras sentencias, se utilizó una tabla de símbolos (memoria) donde se almacena un array de structs, con el nombre del identificador y el valor numérico asociado.

La tabla de símbolos soporta hasta 100 identificadores, y utiliza un índice, que comienza en 0, para manejar la posición de inserción del próximo identificador.

Al realizar una asignación de una expresión a un identificador, se realiza un búsqueda lineal sobre el array para buscar coincidencia con el nombre del identificador.

En caso de no encontrarse en memoria, se guarda en la posición que indique el índice y posteriormente se incrementa este último.

En caso de encontrarse en memoria, se sobreescribe el valor almacenado por el nuevo valor resultado de evaluar la expresión.

Cuando se utilice el identificador en una evaluación o asignación, se buscará en la tabla de símbolos y en caso de encontrarse se devolverá el valor entero asociado.

En caso de no encontrarse el identificador en la tabla de símbolos se producirá un error (informado por stdout) y se abortará el programa.

## Escenarios de error

Ante los siguientes escenarios, se considera que el programa alcanzó un estado de error, y se aborta el mismo.

- Error léxico: al detectar un carácter que no es válido para ningún lexema en el LP
- Error sintáctico: la secuencia de tokens no forma parte de la gramática del programa
- Error memoria: el identificador utilizado no tiene ningún valor asociado en la tabla de símbolos