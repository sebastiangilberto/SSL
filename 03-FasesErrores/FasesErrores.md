# Sintaxis y Semántica de los Lenguajes

## UTN FRBA – SSL – K2051 – Trabajo #03

### Funcionalidades del compilador para limitar inicio y fin de cada fase:

| **Fase** | **Flag utilizado** | **Comentario** | **Ejemplo** |
|------|----------------|------------|---------|
| Preprocesamiento | `-E` | El resultado se envía por defecto al standard output, pudiendo redireccionarlo a un archivo con nombre a elección | gcc -E hello.c > hello.i |
| Compilación| `-S` | El resultado por defecto, es un archivo con el mismo nombre que el utilizado como fuente, con extensión `.s` | gcc -S hello.c |
| Ensamblado| `-c` | El resultado por defecto, es un archivo con el mismo nombre que el utilizado como fuente, con extensión `.o` | gcc -c hello.c |
| Vinculación| `-o output_filename` `-llibname` | El resultado por defecto, es un archivo `a.out`. Opcionalmente puede especificarse el nombre del archivo de salida, con el primer flag mencionado. También es posible vincular bibliotecas, utilizando el segundo flag, concatenado al nombre de la biblioteca | gcc hello.c -lstdio -o hello |

> [GCC Options Controlling the Kind of Output](https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html)

---

### Secuencia de pasos

#### Pasos 1 y 2

##### Comando ejecutado:

    $ gcc -E hello2.c > hello2.i

##### Resultado obtenido:

- Archivo **hello2.i**
- Se eliminó el comentario en el código
- Se reemplazó la inclusión del header de la biblioteca, por la ruta donde se encuentra dicho archivo
- Se agregó una definición del archivo con la forma: `# hello2.c`

##### Errores:

- No se presentaron errores durante esta fase

---

#### Pasos 3, 4 y 5

##### Análisis semántico de la primera línea

```c
int printf(const char *s, ...);
```

- Se está declarando la función printf
- Recibe como parámetro una cadena de caracteres, y opcionalmente un número arbitrario de parámetros "`...`"
- Devuelve un valor de tipo entero

##### Comando ejecutado:

    $ gcc -E hello3.c > hello3.i

##### Resultado obtenido:

- Archivo **hello3.i**
- Se agregó una definición del archivo con la forma: `# hello3.c`

##### Errores:

- No se presentaron errores durante esta fase

---

#### Paso 6

##### Comando ejecutado:

    $ gcc -S hello3.c

##### Resultado obtenido:

- Falla la traducción debido a errores sintácticos, durante la compilación del código

##### Errores:

```cmd
hello3.c:4:5: warning: implicit declaration of function 'prontf' is invalid in C99 [-Wimplicit-function-declaration]
prontf("La respuesta es %d\n");
    ^
hello3.c:4:36: error: expected '}'
    prontf("La respuesta es %d\n");
                                   ^
hello3.c:2:16: note: to match this '{'
int main(void) {
asd
```

- No se reconoce la función `prontf` como válida **(warning)**
- La sintaxis de la función main es inválida, debido a que falta el `}` de cierre **(error)**

---

#### Pasos 7 y 8

##### Comando ejecutado:

    $ gcc -S hello4.c

##### Resultado obtenido:

- Archivo **hello4.s**
- Se genera el archivo en lenguaje assembler, equivalentes al código del archivo fuente

##### Errores:

```cmd
hello4.c:4:5: warning: implicit declaration of function 'prontf' is invalid in C99 [-Wimplicit-function-declaration]
    prontf("La respuesta es %d\n");
```

- No se reconoce la función `prontf` como válida **(warning)**

---

#### Paso 9

##### Comando ejecutado:

    $ gcc -c hello4.c

##### Resultado obtenido:

- Archivo **hello4.o**
- Se genera el archivo binario, equivalente al código del archivo fuente

##### Errores:

```cmd
hello4.c:4:5: warning: implicit declaration of function 'prontf' is invalid in C99 [-Wimplicit-function-declaration]
    prontf("La respuesta es %d\n");
```

- No se reconoce la función `prontf` como válida **(warning)**

---

### Paso 10

##### Comando ejecutado:

    $ gcc hello4.o -o hello4.out

##### Resultado obtenido:

- Falla la traducción, debido a errores en la etapa de vinculación

##### Errores:

```cmd
Undefined symbols for architecture x86_64:
  "_prontf", referenced from:
      _main in hello4.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

- No se reconoce la función prontf como válida, generando un error en el linker **(error)**

---

### Paso 11

##### Comando ejecutado:

    $ gcc hello5.c -o hello5.out

##### Resultado obtenido:

- Archivo `hello5.out`
- Se genera el archivo ejecutable, equivalente al código del archivo fuente

##### Errores:

```cmd
hello5.c:4:30: warning: more '%' conversions than data arguments [-Wformat]
    printf("La respuesta es %d\n");
```

- Se indica a la función printf, que se pasará un argumento, pero ninguno es provisto **(warning)**

---

### Paso 12

##### Comando ejecutado:

    $ ./hello5.out

##### Resultado obtenido:

- Al ejecutar el archivo resultante, se visualiza por consola `La respuesta es -410671312`

##### Errores:

- El resultado obtenido `-410671312`, no se corresponde con el deseado `42`, almacenado en la variable `i`

---

### Paso 13

##### Comando ejecutado:

    $ gcc hello6.c -o hello6.out
    $ ./hello6.out

##### Resultado obtenido:

- Archivo `hello6.out`
- Se genera el archivo ejecutable, equivalente al código del archivo fuente
- Al ejecutar el archivo resultante, se visualiza por consola `La respuesta es 42`

##### Errores:

- No se presentaron errores durante esta fase

---

### Paso 14 y 15

##### Comando ejecutado:

    $ gcc hello7.c -o hello7.out
    $ ./hello7.out

##### Resultado obtenido:

- Archivo `hello7.out`
- Se genera el archivo ejecutable, equivalente al código del archivo fuente
- Al ejecutar el archivo resultante, se visualiza por consola `La respuesta es 42`
- El código funciona debido a que la firma de la función printf declarada, coincide con la de la biblioteca estándar, la cual es incluída por defecto por GCC durante la fase de vinculación. 

> [GCC Link Options](https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html)

##### Errores:

```cmd
hello7.c:3:5: warning: implicitly declaring library function 'printf' with type 'int (const char *, ...)' [-Wimplicit-function-declaration]
    printf("La respuesta es %d\n", i);
    ^
hello7.c:3:5: note: include the header <stdio.h> or explicitly provide a declaration for 'printf'
1 warning generated.
```

- Se está utilizando la función printf de manera implícita, es decir no se incluyó el header con la biblioteca estándar, ni tampoco se agregó explicitamente la declaración de la función **(warning)**
