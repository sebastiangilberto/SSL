# Sintaxis y Semántica de los Lenguajes

## UTN FRBA – SSL – K2051 – Trabajo #02


### C

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

### C++

```c++
#include <iostream>

int main() {
    std::cout << "Hello World!\n";
    return 0;
}
```

### Java

```java
public class HelloWorld {
    
    public static void main(String[] args) {
        System.out.printn("Hello, World!\n");
    }

}

```

### Similitudes y diferencias


|           | Similitudes                                                                                                                                                                  | Diferencias                                                                                                                                     |
|-----------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| Léxico    | Caracteres especiales como ";", "{}", "()"                                                                                                                                   | Palabras reservadas de cada lenguaje: Ej: Java (public) Bibliotecas particulares de cada lenguaje: C++ (iostream) C (stdio.h)                   |
| Sintaxis  | Entre C y C++, la función tiene una estructura similar: tipo de retorno + identificador de la función Se utiliza el standard output como salida para la cadena de caracteres | En Java se utiliza otra estructura semántica: nivel de acceso + palabra reservada + tipo de retorno + identificador de la función + argumentos |
| Semántica | Son iguales ya que todos tienen el mismo significado                                                                                                                         |                                                                                                                                                 |