# Introducción a la solución

El problema pide contar el número de componentes conexas de tierra en una
cuadrícula de $N \times M$, donde dos celdas de tierra (valor $1$) se
consideran adyacentes si comparten lado o esquina (es decir, conectividad de
$8$ vecinos en lugar de $4$).

## Recorrido de componentes conexas con DFS

Se recorre la cuadrícula celda a celda. Cada vez que se encuentra una
celda de tierra todavía sin visitar, se incrementa el contador de islas y
se lanza un DFS (o BFS) que marca como visitadas todas las celdas de
tierra alcanzables desde ahí a través de los $8$ vecinos.

Para evitar usar memoria adicional se reutiliza la propia matriz como
marcador: cuando el DFS visita una celda, le asigna un valor distinto de
$1$ (en la implementación, $2$). Así el bucle exterior solo dispara un
DFS la primera vez que entra en cada componente.

Esquema:

```
contador = 0
para cada celda (i, j):
    si matrix[i][j] == 1:
        dfs(i, j)        // marca la componente como visitada
        contador++
imprimir contador
```

El DFS prueba los $8$ desplazamientos $(\pm1, \pm1), (\pm1, 0), (0, \pm1)$
y se detiene en el borde de la cuadrícula o en celdas que no sean tierra
sin visitar.

### Detalles de implementación

- Como la recursividad puede llegar hasta $N \cdot M$ niveles en el peor caso
  (toda la cuadrícula es una sola isla), conviene comprobar que la pila del
programa es suficiente. Para $N, M \leq 250$ se llega como mucho a $62\,500$
llamadas anidadas, que entra en el juez sin problemas; si no, se sustituye el
DFS recursivo por un BFS iterativo con una cola.

## Complejidad

Por caso de prueba:

- **Tiempo:** $O(N \cdot M)$. Cada celda se visita un número constante de
  veces.
- **Espacio:** $O(N \cdot M)$ por la matriz, más la pila del DFS.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [J.cpp](src/J.cpp) | DFS recursivo sobre la cuadrícula con conectividad de $8$ vecinos, marcando in situ las celdas visitadas | :white_check_mark: |
