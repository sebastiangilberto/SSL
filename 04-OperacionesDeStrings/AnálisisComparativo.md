## Análisis Comparativo

Para realizar la comparación, se utilizaron los lenguajes C y Java.

### ¿El tipo es parte del lenguaje en algún nivel?

#### Java

Los String son un tipo de dato dentro del lenguaje, a nivel léxico, sintáctico y semántico. Específicamente son una clase.

- Léxico/Sintáctico: Java reconoce como String a cualquier cadena de caracteres entre comillas dobles `"abcd"`.
- Semántico: este tipo de datos tiene un conjunto de operadores y funciones pre establecido que vienen con el lenguaje.

#### C

Los Strings no son un tipo de dato, ya que no existe una estructura que represente el concepto de String.

Sin embargo el compilador a nivel léxico y sintáctico, procesa cadenas literales como arreglos char.

- Léxico/Sintáctico: el compilador reconoce cadenas encerradas entre comillas dobles `"abcd"`.
- Semántico: el compilador trata un literal `"abcd"` como un arreglo de char : `['a', 'b', 'c', 'd']` y es posible procesarlo como tal.

Para poder usar cadenas en C es necesario incluir una biblioteca **string.h**, o el usuario debe implementar sus propias funciones para manipular cadenas.

### ¿El tipo es parte de la biblioteca?

#### Java

Los String son un tipo de dato propio del lenguaje, y no es necesario importar una biblioteca para manipularlos.

#### C

En las bibliotecas estándar de C no se define propiamente un tipo String. Sin embargo se definen prototipos de funciones que sirven para manipularlos, y el compilador transforma cualquier sucesión de caracteres encerrados entre comillas dobles en un arreglo de char. Dichos arreglos se pueden manipular mediante string.h de la biblioteca estándar.

### ¿Qué alfabeto usa?

#### Java

La clase String utiliza internamente un arreglo de `char[]`.  Los char guardan un valor ASCII (número entre 0 y 127)

#### C

En C el alfabeto que se usa para un char es UTF-8 (este es el alfabeto que viene por defecto pero es posible especificar otros).

### Cómo se resuelve la alocación de memoria?

#### Java

En Java no hay que realizar operaciones especiales para solicitar memoria, ni tampoco liberarla. Junto con la JVM viene incluido un recolector de basura (Garbage Collector), que se encarga de revisar las referencias de los objetos que se van creando en los programas, y cuando dichos objetos o variables dejan de ser referenciados, o se excede el alcance (scope) de los mismo, el recolector se encarga de borrarlos y liberar la memoria.

#### C

En C la alocación de memoria varía dependiendo del alcance y modo en que el programa fue desarrollado.

Es posible definir variables globales que se guarden en el segmento de datos de un programa.

Las llamadas a funciones y argumentos pasados a las mismas, se guardan en la pila de memoria (Stack).

La alocación de memoria para variables que defina el programador, se realiza en el Heap, y se denomina memoria dinámica. Dicha alocación tiene que ser realizada mediante la ejecución de syscalls al sistema operativo. Cuando se solicita memoria se tiene que especificar la cantidad de bytes solicitados, y la syscall devuelve un puntero a la posición de memoria donde comienza la porción de memoria alocada.

Lo mismo aplica para la liberación de la misma, se debe realizar manualmente mediante otra syscall, ya que si no se libera puede quedar memoria ocupada con datos basura.

### ¿El tipo tiene mutabilidad o es inmutable?

#### Java

El lenguaje tiene una mezcla de mutabilidad con inmutabilidad. Los Strings son inmutables y el contenido de mismo no puede ser modificado una vez creado. Sin embargo es posible modificar las referencias de los objetos, que apuntan a los strings literales en memoria.

Por otro lado, la mayoría de tipos de datos que maneja java son mutables, pudiendo cambiar los mismos en cualquier momento.

Es posible forzar la inmutabilidad mediante el uso de palabras reservadas como `final`, o en conjunto con `static`para indicar que son globales a todo el programa.

En versiones nuevas del lenguaje (>9) es posible indicar tipos de variables inmutables, mediante el uso de la palabra reservada `val`.

#### C

En C por defecto las variables creadas son mutables, incluso los String. Para lograr que una variable sea inmutable y sólo pueda leerse el valor que guarda es necesario usar la palabra clave "const" al momento de declararla.

### ¿El tipo es un first class citizen?

#### Java

Es un ciudadano de primer orden (First Class Citizen), ya que cumple con las siguientes condiciones:

- puede ser enviado como parámetro a una función
- puede ser devuelto como resultado de una función
- puede ser sujeto de una asignación de una variable
- puede ser probado en una condición lógica mediante el operador de igualdad

#### C

No es un ciudadano de primer orden, ya que no cumple con las condiciones mencionadas:

- no puede ser enviado directamente como parámetro de una función. Al enviar un arreglo de char, lo que se estaría pasando es un puntero a la primer posición del arreglo
- no puede ser devuelto directamente por una función. 
- para arreglos en general no se pueden asignar valores directamente, excepto en el momento de declaración del arreglo
- no puede ser comparado mediante el operador de igualdad. Para realizar las comparaciones, existen funciones de bibliotecas que facilitan dicha comparación

### ¿Cuál es la mecánica para ese tipo cuando se lo pasa como argumentos?

#### Java

El tipo String en java se pasa por valor a la función, es decir se realiza una copia en la pila, y las modificaciones realizadas dentro de la función no afectan a la variable fuera de ella.

#### C

El tipo String se puede enviar como argumento de una función a través de un puntero señalando el comienzo de la cadena.


### ¿Y cuando son retornados por una función?

#### Java

En Java se devuelve una referencia a un objeto en memoria, que apunta a un String literal en un pool de strings en memoria.

#### C

Como en C no se puede retornar directamente por una función, para lograr algo similar, es posible devolver un puntero a la posición donde apunta el arreglo de char creado, o pasar como parámetro una variable de salida, donde se almacenará el valor del arreglo creado dentro de la función