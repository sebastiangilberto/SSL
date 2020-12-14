# Calculadora Infija Manual

## Nivel Léxico

Para esta iteración el `Scanner` se desarrollo con la herramienta `flex`.

Dada una expresión regular, se identifica un lexema y se asocia un token válido para el LP.

La interface se mantiene igual respecto a la comunicación entre Parser y Scanner, mediante la función `GetNextToken()` la cuál invoca a la función de flex `yylex()`.

Por cada acción realizada al evaluar la expresión regular y encontrar una coincidencia, se realiza una copia del valor de la variable `yytex` al `BUFFER`, logrando de esta forma mantener el funcionamiento de la tabla de símbolos (memoria) desarrollada en la iteración anterior.

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

Para el nivel sintáctico se generó un autómata que representa la gramática válida
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

Cada `PAS` reduce la expresión a un valor entero, lo cual se utiliza para realizar la evaluación de la expresión y mostrar el valor obtenido.

Para la implementación del nivel sintáctico, se desarrollo un `Parser`, con las siguientes funciones:

- Expresión(): devuelve el resultado devuelto por el término, sumado al valor recursivo de llamar al PAS expresión
- Término(): devuelve el resultado devuelto por el factor, multiplicado por el valor recursivo de llamar al PAS término
- Factor(): devuelve el valor numérico de la constante, o el valor asociado al identificador, o el resultado de una expresión entre paréntesis
- Match(): invoca a la función del Scanner `GetNextToken()`, si el valor no coincide con el esperado se produce un error sintáctico

## Tabla de símbolos

Para almacenar los valores asociados a los identificadores, y poder utilizarlo en otras sentencias, se utilizó una tabla de símbolos (memoria) donde se almacena un array de structs, con el nombre del identificador y el valor numérico asociado.

Cuando se utilice el identificador en una evaluación o asignación, se buscará en la tabla de símbolos y en caso de encontrarse se devolverá el valor entero asociado.

En caso de no encontrarse el identificador en la tabla de símbolos se producirá un error (informado por stdout) y se abortará el programa.
## Escenarios de error

Ante los siguientes escenarios, se considera que el programa alcanzó un estado de error, y se aborta el mismo.

- Error léxico: al detectar un carácter que no es válido para ningún lexema en el LP
- Error sintáctico: la secuencia de tokens no forma parte de la gramática del programa
- Error memoria: el identificador utilizado no tiene ningún valor asociado en la tabla de símbolos