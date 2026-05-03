# Introducción a la solución

El problema pide minimizar el número de escaleras que hay que subir para
ir del piso $1$ al piso $h$, pudiendo combinar libremente escaleras (subir un
piso, peso $1$) y ascensores (saltar de $a_j$ a $b_j$ con $a_j < b_j$, peso
$0$).

Modelando los pisos como nodos y las transiciones como aristas dirigidas
ponderadas con $0$ o $1$, el problema es un **camino más corto** desde el
piso $1$ hasta el piso $h$. Como todos los movimientos suben, el grafo es
además un DAG (los nodos están ordenados topológicamente por su número de
piso), y los pesos son solo $0$ o $1$. Cualquiera de estas tres propiedades
permite resolverlo de forma más eficiente que un Dijkstra genérico.

## Programación dinámica sobre los pisos

Como toda arista va de un piso menor a uno mayor, el grafo es un DAG con
ordenación topológica trivial: $1, 2, \dots, h$.

Definimos $dp[i]$ como el mínimo número de escaleras necesarias para llegar
al piso $i$. Inicializamos $dp[1] = 0$ y $dp[i] = +\infty$ para el resto.
Recorremos los pisos en orden creciente y, desde cada piso $i$, **relajamos
las aristas salientes**:

- Escalera $i \to i+1$: $dp[i+1] \gets \min(dp[i+1],\ dp[i] + 1)$.
- Cada ascensor $i \to b$: $dp[b] \gets \min(dp[b],\ dp[i])$.

Cuando llegamos a procesar el piso $i$, $dp[i]$ ya es definitivo: cualquier
mejora futura tendría que provenir de un piso mayor que $i$, lo cual es
imposible porque ni escaleras ni ascensores bajan. La respuesta es $dp[h]$.

Esta versión es la más sencilla de implementar y la más eficiente: una única
pasada lineal sobre los pisos sin estructuras de datos auxiliares.

### Complejidad

- **Tiempo:** $O(h + n)$.
- **Espacio:** $O(h + n)$ para el vector $dp$ y la lista de ascensores por
  piso.

## BFS 0-1 con deque

Cuando los pesos del grafo son solo $0$ y $1$, hay una variante de BFS,
**0-1 BFS**, que mantiene las distancias en orden no decreciente sobre un
*deque* en lugar de una cola de prioridad:

- Las aristas de peso $0$ insertan al **principio** del deque (no aumentan
  la distancia, así que siguen siendo lo "más barato" pendiente).
- Las aristas de peso $1$ insertan al **final** del deque.

La invariante es análoga a la de BFS estándar: las distancias presentes en
el deque difieren en a lo sumo $1$ y están ordenadas. Cuando un nodo se
extrae del deque por primera vez, su distancia ya es óptima. Para evitar
trabajo redundante por nodos que aparecen varias veces en el deque
(consecuencia de relajaciones sucesivas), conviene marcar cada nodo como
visitado al sacarlo y descartar las visitas posteriores.

En este problema las aristas son simplemente:

- Escalera (peso $1$): de $i$ a $i+1$.
- Ascensor (peso $0$): de $a_j$ a $b_j$.

### Complejidad

- **Tiempo:** $O(h + n)$. Cada nodo se procesa una sola vez (gracias al
  marcado de visitados) y cada arista se relaja un número constante de veces.
- **Espacio:** $O(h + n)$.

## Dijkstra

Es el enfoque más general, y resulta natural si ya se tiene una implementación
lista (la solución `D_dijkstra.cpp` reutiliza con una modificación mínima la de
otro problema). Tiene la ventaja de no requerir análisis adicional sobre la
estructura del grafo: funciona con pesos arbitrarios no negativos.

Es también el menos eficiente de los tres por el factor logarítmico de la
cola de prioridad, pero el grafo es lo bastante pequeño como para que
también funcione cómodamente dentro del límite de tiempo.

### Complejidad

- **Tiempo:** $O((h + n) \log h)$ con cola de prioridad binaria.
- **Espacio:** $O(h + n)$.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [D_dp.cpp](src/D_dp.cpp) | DP en una pasada sobre los pisos en orden creciente | :white_check_mark: |
| [D_bfs01.cpp](src/D_bfs01.cpp) | BFS 0-1 con deque (peso $0$ al frente, peso $1$ al final) | :white_check_mark: |
| [D_dijkstra.cpp](src/D_dijkstra.cpp) | Dijkstra con cola de prioridad sobre el grafo de escaleras y ascensores | :white_check_mark: |
