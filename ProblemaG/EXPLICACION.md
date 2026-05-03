# Introducción a la solución

El problema pide sumar el valor de las monedas no malditas. Una moneda está
maldita si su valor coincide con el de alguna moneda maldita conocida, así
que basta con tener un test rápido de pertenencia al conjunto de valores
malditos y recorrer las monedas una única vez sumando las que no caigan en
ese conjunto.

## Conjunto de valores malditos como tabla booleana

Como el rango de valores es pequeño ($1 \leq v \leq 1000$), el conjunto
de valores malditos se puede representar directamente como una tabla
booleana `cursed` de tamaño $1001$, donde `cursed[v] = true` indica que
todas las monedas de valor $v$ están malditas. Las consultas y las inserciones
son entonces $O(1)$.

Algoritmo:

1. Leer las $N$ monedas.
2. Inicializar la tabla `cursed` a `false` y marcar a `true` cada uno de los
   $M$ valores malditos.
3. Recorrer las monedas y sumar las que cumplan `!cursed[v]`.

Si el rango de valores fuera mucho mayor, la misma idea funcionaría con un
`unordered_set<int>` o un `set<int>` a costa de un factor constante (o
logarítmico) en cada consulta.

## Complejidad

Por caso de prueba:

- **Tiempo:** $O(N + M + V)$, donde $V = 1000$ es el tamaño del rango de
  valores..
- **Espacio:** $O(N + V)$.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [G.cpp](src/G.cpp) | Tabla booleana de valores malditos y suma directa de las monedas no marcadas | :white_check_mark: |
