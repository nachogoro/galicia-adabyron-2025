# Introducción a la solución

El problema pide la mediana de la fusión de dos listas $a$ y $b$ de
enteros, ambas del mismo tamaño $n$ y ya ordenadas de menor a mayor. La
mediana de los $2n$ elementos combinados es la media aritmética de los dos
elementos centrales, los que ocupan las posiciones $n-1$ y $n$ (ambas
0-indexadas) en la lista fusionada y ordenada.

Hay tres formas naturales de resolverlo, de niveles de eficiencia distinto (y
más sencillas de implementar cuanto menos eficientes). Comentaremos las tres,
en orden creciente de eficiencia.

## Concatenar y ordenar ( $O(n \log n)$ )

Es la solución más directa: leer las $2n$ entradas, ordenarlas y devolver
la media de las posiciones $n - 1$ y $n$. Ignora por completo el hecho
de que las dos listas ya vienen ordenadas. Igualmente, entra en tiempo en el
juez.

Implementada en [L_naive.cpp](src/L_naive.cpp).

### Complejidad

- **Tiempo:** $O(n \log n)$.
- **Espacio:** $O(n)$.

## Avance lineal sobre las dos listas ( $O(n)$ )

Hay una solución natural en $O(n)$ que aprovecha que las listas ya están
ordenadas: avanzar $n - 1$ veces descartando el menor de los dos primeros
elementos de cada lista (equivalente a fusionar al estilo *merge sort* pero sin
guardar la lista combinada). Tras $n - 1$ descartes, los dos siguientes
"menores" de la fusión son $x_1$ y $x_2$, los elementos centrales de la
mediana.

Esta es la solución implementada en [L_linear.cpp](src/L_linear.cpp), que
usa dos `deque<int>` para poder hacer `pop_front` en $O(1)$.

### Complejidad

- **Tiempo:** $O(n)$.
- **Espacio:** $O(n)$.

## Búsqueda binaria sobre la partición ( $O(\log n)$ )

Es la solución óptima. Buscamos un índice $i_a \in [0, n]$ tal que
tomando los primeros $i_a$ elementos de $a$ y los primeros
$i_b = n - i_a$ de $b$ se forme la **mitad izquierda** (exactamente $n$
elementos) de la fusión ordenada. Una vez encontrada esa partición, la
mediana es

$$\text{mediana} = \frac{\max(\text{lado izquierdo}) + \min(\text{lado derecho})}{2}.$$

La partición es válida cuando los máximos de cada lado izquierdo son
$\leq$ que los mínimos del lado derecho contrario:

$$a[i_a - 1] \leq b[i_b] \quad \text{y} \quad b[i_b - 1] \leq a[i_a],$$

donde se usan centinelas $-\infty$ y $+\infty$ cuando $i_a$ o $i_b$ caen
en los extremos.

La condición es monótona en $i_a$: si $a[i_a - 1] > b[i_b]$, hemos cogido
demasiado de $a$ y hay que reducir $i_a$; si $b[i_b - 1] > a[i_a]$,
demasiado poco. Esto permite una búsqueda binaria en $[0, n]$ que
converge en $O(\log n)$.

La implementación ([L_binary.cpp](src/L_binary.cpp)) implementa esta aproximación.

### Complejidad

- **Tiempo:** $O(\log n)$ tras la lectura.
- **Espacio:** $O(n)$ para almacenar las dos listas.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [L_binary.cpp](src/L_binary.cpp) | Búsqueda binaria sobre la partición de la fusión en $O(\log n)$ | :white_check_mark: |
| [L_linear.cpp](src/L_linear.cpp) | Fusión estilo *merge sort* descartando el menor en cada paso, $O(n)$ | :white_check_mark: |
| [L_naive.cpp](src/L_naive.cpp) | Concatenar las dos listas y ordenar, $O(n \log n)$ | :white_check_mark: |
