# Sintaxis y Semántica de los Lenguajes

## UTN FRBA – SSL – K2051 – Examen #0

### Parte 1

1. Indique la tarea más representativa para la cual un Ingeniero en Sistemas de Información está calificado.

La tarea más representativa para la cual un Ingeniero en Sistemas de Información está calificado es realizar el Análisis, Diseño e Implementación de sistemas de información.

2. Defina información

La información es un conjunto de datos que tiene un sentido, no solo porque representa una realidad, sino por qué a alguien le interesa.

3. Indique las asignaturas del área de programación.

Las asignaturas del area de programación son:

- Algoritmos y Estructuras de Datos
- Gestión de Datos
- Matemática Discreta
- Paradigmas de Programación
- Sintaxis y Semántica de los Lenguajes

4. Indique las asignaturas del área de sistemas de información.

Las asignaturas del area de sistemas de información son:

- Análisis de requisitos
- Análisis de sistemas
- Diseño de sistemas
- Proyecto final
- Sistemas y organizaciones

5. Indique el paradigma de programación aplicado en primer año de la carrera.

El paradigma de programación aplicado en primer año de la carrera, fue el procedural.

6. Defina abstracción.

El término abstracción se refiere al proceso de eliminar detalles innecesarios en el dominio del
problema, y quedarse con aquello que es esencial para encontrar la solución.

### Parte 2

1. Indique diferencias entre secuencia y conjunto. 

En una secuencia a diferencia de un conjunto, el orden en que aparecen los términos sí es relevante y un mismo término puede aparecer en más de una posición.

2. Defina el concepto matemático secuencia.

Una secuencia puede definirse como una función, sobre el conjunto de los números naturales (o un subconjunto del mismo).

3. Defina función matemática.

Una función es una regla que asigna a cada elemento de un primer conjunto un único elemento de un segundo conjunto.

4. Defina grafo.

Un grafo es un conjunto de puntos o vértices unidos por aristas, que pueden tener sentido o no.

5. Defina partición de un conjunto.

Una partición de un conjunto es una división del mismo, en subconjuntos que no son vacíos y que no tienen ningún elemento en común.

6. Sea X={a,b} indique P(X).

P(X) es el conjunto de partes, que está formado por todos los conjuntos que se pueden formar por el argumento X:

- conjunto vacío
- conjunto {a}
- conjunto {b}
- conjunto {a,b}

7. Defina Lenguaje Formal.

Un lenguaje formal es un conjunto de palabras y métodos para combinar palabras, que es usado y entendido por un extenso grupo de personas, caracterizado por tener reglas gramaticales preestablecidas.

8. Defina autómata finito.

Un autómata finito se define como una 5-upla, que se utiliza para reconocer un determinado Lenguaje
Regular.
Es un modelo matemático de un sistema, que recibe una cadena formada por caracteres de un
determinado alfabeto y determina si esa cadena pertenece o no al lenguaje que reconoce.

### Parte 3

1. Defina algoritmo.

Secuencia finita de instrucciones, reglas o pasos que describen en forma precisa las operaciones
que una computadora debe realizar para llevar a cabo una tarea en tiempo finito.

2. Defina programación estructurada.

La programación estructurada es un paradigma, que hace uso de estructuras de control para la ejecución de un programa.
También facilita la creación de componentes re-utilizables, dividiendo el programa en módulos más pequeños.

3. Indique las tres estructuras de control de flujo de ejecución de la programación estructurada.

Las tres estructuras de control de flujo de ejecución de la programación estructurada son:

- secuencia
- selección
- iteración

4. Indique las diferencias entre parámetro y argumento.

- Parámetro: variable cuya característica principal es que se utiliza para transferir información entre módulos.
- Argumento: valor que toma un parámetro al momento de la transferencia de información.

5. Explique las dos formas de transferencia de argumentos.

- Por valor: se comparte una copia del dato entre los módulos, por lo cual las modificaciones realizadas por el segundo módulo no afectan al del primero.
- Por referencia: se comparte la dirección de memoria donde el dato se encuentra almacenado, por lo cual tanto el módulo que realiza la llamada, como el llamado pueden acceder a dicho dato y modificarlo.

6. Explique las diferencias entre parámetros de entrada, de salida y de entrada/salida.

- De entrada (dato): se utiliza el dato para realizar el procedimiento del sub-programa.
- De salida (resultado): se devuelve un resultado asignándole un valor al dato.
- De entrada/salida (dato-resultado): ambas cosas.

7. Defina tipo de dato abstracto.

Un tipo de dato abstracto está definido por un conjunto de datos, y de operaciones que representan el comportamiento, sin mencionar cómo van a ser implementadas, ni el tipo específico de los datos.

8. Indique las diferencias entre una pila y una cola.

- Pila: método de organización de datos tipo LIFO (Last In First Out).
- Cola: método de organización de datos tipo FIFO (First In First Out).

9. Defina archivo.

Estructura de datos con almacenamiento físico en memoria secundaria o disco.
 
11. Diseñe un algoritmo que dado un arreglo de naturales a y su longitud n calcule el promedio.

La solución está hecha en el lenguaje de programación C++.

```c++
float promedio(int a[], int n) { 
    int sum = 0;  
 for (int i = 0; i < n; i++) {  
        sum += a[i];  
  }  
    return sum / n;  
}
```
