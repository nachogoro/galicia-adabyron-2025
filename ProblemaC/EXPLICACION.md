# Introducción a la solución

El problema pide encontrar el camino más corto en un **grafo dirigido y
ponderado** que va de un punto de salida $S$ a un punto de meta $M$, pasando
por una secuencia de *waypoints* obligatorios. Los pesos representan
segundos y todos son positivos.

Hay un detalle del enunciado que conviene aclarar antes de plantear la
solución: **los waypoints se recorren en el orden en que se indican.** El
enunciado no es del todo claro al respecto, pero esa es la interpretación
correcta: el primer waypoint listado es el primero por el que hay que pasar, el
segundo es el segundo, etc. No es libre elección del piloto.

Con estas dos reglas, el problema se descompone de forma natural en una
secuencia de problemas de camino más corto independientes.

## Dijkstra por tramos prohibiendo waypoints intermedios

Sea $W = [w_1, w_2, \dots, w_k]$ la lista de waypoints en orden, y
considérese la secuencia ampliada $[S, w_1, w_2, \dots, w_k, M]$. La ruta
óptima global es la concatenación del camino más corto entre cada par de
puntos consecutivos de esa secuencia, siempre que dentro de cada tramo no
se visite ningún otro waypoint, ni la salida, ni la meta.

Esa restricción se implementa de forma muy cómoda durante un Dijkstra estándar:
cuando extraemos de la cola de prioridad un nodo $u$ que es salida, meta o
waypoint (y $u$ no es el origen del tramo actual), simplemente no utilizamos
sus aristas salientes. Así $u$ puede ser destino de un tramo (lo necesitamos
para leer su distancia), pero nunca punto de paso de otro tramo. El resto del
algoritmo es Dijkstra estándar.

Esquema:

```
marcar como "bloqueables" salida, meta y todos los waypoints
secuencia = [salida, w_1, ..., w_k, meta]
coste_total = 0
para i de 0 a len(secuencia) - 2:
    coste_total += dijkstra(secuencia[i], secuencia[i+1])
                       sin pasar por otros nodos bloqueables
imprimir coste_total
```

## Complejidad

Sea $k$ el número de waypoints. Se ejecutan $k+1$ Dijkstras sobre un grafo
de $P$ nodos y $C$ aristas. Con cola de prioridad binaria:

- **Tiempo:** $O((k+1) \cdot (P + C) \log P)$.
- **Espacio:** $O(P + C)$ para el grafo, más $O(P)$ por Dijkstra.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [C.cpp](src/C.cpp) | Dijkstra por tramos consecutivos prohibiendo otros waypoints como nodos intermedios | :white_check_mark: |
