# Introducción a la solución

El problema pide convertir cada uno de los $t$ números recibidos en base
decimal a una base $b$ entre $2$ y $9$ y mostrar el resultado. Es la
conversión clásica de cambio de base, que se reduce a extraer los dígitos
de menor a mayor peso mediante divisiones y restos sucesivos.

## Algoritmo: divisiones sucesivas

Mientras el número $n$ no sea cero, su dígito menos significativo en base
$b$ es $n \bmod b$. Una vez registrado ese dígito, se elimina dividiendo:
$n \gets \lfloor n / b \rfloor$. Repitiendo el proceso se obtienen los
dígitos en orden inverso (de menor a mayor peso). Para imprimir el número
se recorren al final en orden inverso al de obtención.

```
digitos = []
mientras n != 0:
    digitos.append(n mod b)
    n = n / b
imprimir digitos en orden inverso
```

## El caso especial $n = 0$

La única trampa del problema está en el límite inferior del rango,
$0 \leq n \leq 100000$: el número $0$ se representa en cualquier base como
`0`, pero el bucle anterior **no ejecuta ninguna iteración** cuando $n =
0$, así que la lista de dígitos queda vacía y la implementación ingenua
imprime una línea en blanco.

Hay que tratarlo explícitamente. La forma habitual es comprobar tras el
bucle si la lista de dígitos está vacía y, en ese caso, añadir un $0$
antes de imprimir:

```
si digitos esta vacio:
    digitos.append(0)
```

## Variante: extraer dígitos manteniendo $n$ y un multiplicador

Es la técnica que usa [K_multiplicador.cpp](src/K_multiplicador.cpp). Parte de la representación de
$n$ en base $b$ como una suma de potencias:

$$n = d_0 + d_1 \cdot b + d_2 \cdot b^2 + d_3 \cdot b^3 + \dots$$

donde $d_0, d_1, \dots$ son los dígitos buscados (de menor a mayor peso).
La idea es ir despejando un dígito en cada iteración sin modificar $n$ con
una división entera, sino llevando aparte un *multiplicador* $m$ que vale
$1, b, b^2, b^3, \dots$ en cada paso. En la iteración $i$:

- $d_i = \lfloor n / m \rfloor \bmod b$: la división entera por $m$
  descarta los $i$ dígitos ya extraídos y el módulo se queda con el
  siguiente.
- Se descuenta la contribución del nuevo dígito de $n$:
  $n \gets n - d_i \cdot m$.
- Se actualiza el multiplicador: $m \gets m \cdot b$.

El bucle termina cuando $n$ llega a $0$. Es matemáticamente equivalente al
algoritmo estándar de divisiones sucesivas, solo que en lugar de "encoger"
$n$ dividiendo por $b$ cada vez, se mueve el "puntero de lectura" hacia
los dígitos de mayor peso a través de $m$.

## Complejidad

Por consulta:

- **Tiempo:** $O(\log_b n)$, una división por dígito generado. Para los
  límites del problema son a lo sumo $17$ dígitos (caso $n = 100000$ en
  base $2$).
- **Espacio:** $O(\log_b n)$ para el vector de dígitos.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [K_alternative.cpp](src/K_alternative.cpp) | Divisiones sucesivas $n \gets n / b$ | :white_check_mark: |
| [K_multiplicador.cpp](src/K_multiplicador.cpp) | Extracción de dígitos con multiplicador creciente $m = 1, b, b^2, \dots$ | :white_check_mark: |
