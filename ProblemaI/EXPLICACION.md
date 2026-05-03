# Introducción a la solución

El problema pide encontrar la submatriz $M \times N$ de un terreno $H \times W$
cuya diferencia entre la altura máxima y la mínima (su coste de nivelación)
sea mínima.

Un primer enfoque ingenuo, recorrer las $(H-M+1)(W-N+1)$ submatrices y calcular
para cada una su máximo y mínimo, da $O(H \cdot W \cdot M \cdot N)$, demasiado
lento dado que $H \cdot W$ puede llegar a $10^6$.

La idea clave es descomponer el problema en dos pasadas independientes de
**ventana deslizante**:

1. Para cada fila, calcular el máximo y el mínimo de cada ventana de $N$
   columnas consecutivas. El resultado son dos matrices auxiliares,
   `rowMax` y `rowMin`, de tamaño $H \times (W - N + 1)$.
2. Para cada columna de cada matriz auxiliar, calcular el máximo (sobre
   `rowMax`) y el mínimo (sobre `rowMin`) de cada ventana de $M$ filas
   consecutivas. Esos valores son, respectivamente, el máximo y el mínimo
   de cada submatriz $M \times N$ del terreno original. El coste de
   nivelación de esa submatriz es la diferencia, y la respuesta es el
   mínimo de esos costes.

La estructura de datos óptima para modelar la ventana es la *monotonic queue*,
que permite un coste amortizado constante para inserción, extracción y consulta
de máximo/mínimo.

## Monotonic queue (deque) para el máximo en ventana deslizante

Mantenemos un *deque* que almacena **índices** del vector de entrada con
estas dos invariantes:

- Los índices del deque corresponden a posiciones aún dentro de la ventana
  actual (los que han caducado se eliminan por el frente).
- Los valores asociados están en orden estrictamente decreciente desde el
  frente hasta el fondo (para el máximo; estrictamente creciente para el
  mínimo).

Al avanzar la ventana una posición a la derecha y leer el nuevo elemento
$a[i]$:

1. Si el índice del frente ha caducado ($\text{front} \leq i - k$), lo
   eliminamos.
2. Eliminamos por el fondo todos los índices cuyo valor sea $\leq a[i]$
   (no podrán volver a ser máximo en ninguna ventana futura: $a[i]$ es más
   grande y entrará más tarde).
3. Insertamos $i$ por el fondo.
4. Si la ventana ya está llena ($i \geq k - 1$), el máximo de la ventana
   actual es el valor del índice del frente.

Cada índice entra y sale del deque a lo sumo una vez, así que la pasada es
$O(n)$ amortizado, con consultas $O(1)$ del máximo. La versión para el
mínimo es idéntica cambiando $\leq$ por $\geq$ en el paso 2.

Aplicado a las dos pasadas del problema (fila a fila primero, columna a
columna después, sobre las matrices auxiliares), el coste total por caso
de prueba es $O(H \cdot W)$.

## Alternativa con multiset en C++

La misma estrategia de dos pasadas funciona usando un `multiset<int>` como
ventana en lugar de la *monotonic queue*. El multiset mantiene los valores
de la ventana ordenados; al avanzar una posición se inserta el nuevo
elemento y se borra el que sale, con coste $O(\log k)$ cada operación, y
las consultas de máximo y mínimo son $O(1)$ (`begin()` y `rbegin()`).

El coste total sube a $O(H \cdot W \cdot (\log M + \log N))$, pero sigue
entrando con holgura en los límites del problema y la implementación es más
simple si no se quiere escribir la *monotonic queue* desde cero.

## Complejidad

Por caso de prueba:

- **Solución con monotonic queue:**
  - Tiempo: $O(H \cdot W)$.
  - Espacio: $O(H \cdot W)$ por las matrices auxiliares.
- **Solución con multiset:**
  - Tiempo: $O(H \cdot W \cdot (\log M + \log N))$.
  - Espacio: $O(H \cdot W)$.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [I_monotonic.cpp](src/I_monotonic.cpp) | Doble pasada de ventana deslizante con *monotonic queue* | :white_check_mark: |
| [I_multiset.cpp](src/I_multiset.cpp) | Misma estrategia con `multiset<int>` como ventana | :white_check_mark: |
