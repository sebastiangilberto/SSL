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

Para el nivel sintáctico se generó una gramática independiente del contexto (GIC)

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

Para el análisis sintáctico se utilizó `Analisis Sintactico Descendente Recursivo`, implementado a través de invocaciones a rutinas de forma recursiva.
Cada función invocada se denomina `Procedimiento de Analisis Sintactico (PAS)`

Algunos `PAS` ejecutan rutinas semánticas, para reducir la expresión a un valor entero, lo cual se utiliza para realizar la evaluación de la expresión y mostrar el valor obtenido.

Para la implementación del nivel sintáctico, se desarrollo un `Parser`, con las siguientes funciones:

- Objetivo(): da comienzo al programa y valida que se ingrese el token FDT
- Programa(): valida que se ingrese el token INICIO, llama a la ListaSentencias y valida que se ingrese el token FIN
- ListaSentencias(): invoca a la función Sentencia(), y opcionalmente otras sentencias
- Sentencia(): invoca a las funciones Match() y Expresión() en base a las producciones. Agrega el valor asociado al identificador en la tabla de símbolos.
- Expresión(): devuelve el resultado devuelto por el término, sumado al valor recursivo de llamar al PAS expresión
- Término(): devuelve el resultado devuelto por el factor, multiplicado por el valor recursivo de llamar al PAS término
- Factor(): devuelve el valor numérico de la constante, o el valor asociado al identificador, o el resultado de una expresión entre paréntesis
- Match(): invoca a la función del Scanner `GetNextToken()`, si el valor no coincide con el esperado se produce un error sintáctico

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