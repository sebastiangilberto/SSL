## Especificaciones matemáticas de operaciones con cadenas

### get_length

- Especificación matemática: **Epsilon\* -> N**
- Conjunto de salida: **Epsilon\***: Clausura de Kleene del alfabeto.
- Conjunto de llegada **N** con 0 incluido: Conjunto de números naturales incluyendo 0.

![GetLength](GetLength.png)


### is_empty

- Especificación matemática: **Epsilon\* -> \{V,F\}**
- Conjunto de salida: **Epsilon\***: Clausura de Kleene del alfabeto.
- Conjunto de llegada **{V, F}**: Verdadero si la cadena es vacía. Falso si la cadena NO está vacía.

![IsEmpty](IsEmpty.png)

### power

- Especificación matemática: **Epsilon\* x N -> Epsilon\***
- Conjunto de salida: **Epsilon\* x N**: Conjunto resultante del producto cartesiano de Clausura de Kleene del alfabeto y Conjunto de números naturales N. Es decir conjunto de infinitos pares ordenados (Epsilon\*, N).
- Conjunto de llegada **Epsilon\***: Clausura de Kleene del alfabeto.

![Power](Power.png)

### compare

- Especificación matemática: **Epsilon\* x Epsilon\* -> {-1, 0, 1}**
- Conjunto de salida: **Epsilon\* x Epsilon\***: Conjunto resultante del producto cartesiano de Clausura de Kleene del alfabeto con sigo mismo. Es decir un conjunto de infinitos pares ordenados (Epsilon\*, Epsilon\*).
- Conjunto de llegada: **{-1, 0, 1}**.
	- Si el primer componente (primera cadena) del par ordenado es menor que el segundo entonces el resultado será un número -1.
	- Si ambas cadenas son iguales el resultado será 0.
	- Si la primer cadena es mayor que la segunda el resultado será un 1.
 
![Compare](Compare1.png)

![Compare](Compare2.png)

**Observación:** La palabra vacía pertenece a Epsilon\* pero no pertenece a Epsilon (alfabeto). Se considera que una palabra vacía es menor a todos los símbolos de Epsilon.