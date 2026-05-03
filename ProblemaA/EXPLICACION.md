# Introducción a la solución

El problema pide encontrar el rectángulo de área máxima que se puede inscribir
en un histograma cuyas barras tienen ancho 1 y alturas dadas.

La idea clave es que **todo rectángulo maximal está limitado en altura por
alguna barra concreta**. Es decir, para cada barra $i$ basta calcular el
rectángulo más grande cuya altura sea exactamente $h[i]$, y quedarse con el
máximo. Ese rectángulo se extiende desde $i$ hacia la izquierda y la derecha
mientras las barras vecinas tengan altura $\geq h[i]$, y se detiene en cuanto
encuentra una barra estrictamente más baja (o el borde del histograma).

Si para cada $i$ conocemos:
- $L(i)$: índice de la primera barra a la izquierda con altura $< h[i]$ (o $0$ si no existe).
- $R(i)$: índice de la primera barra a la derecha con altura $< h[i]$ (o $n+1$ si no existe).

Entonces el área asociada a la barra $i$ es

$$\text{area}(i) = h[i] \cdot (R(i) - L(i) - 1)$$

y la respuesta es $\max_i \text{area}(i)$.

Toda la dificultad está, por tanto, en calcular $L$ y $R$ rápido.

## Enfoque naive: búsqueda lineal en ambos sentidos

La forma más directa de calcular $L(i)$ y $R(i)$ es, para cada barra $i$,
recorrer hacia la izquierda hasta encontrar una barra más baja, y luego
recorrer hacia la derecha hasta encontrar otra. Una vez conocidos esos dos
límites, el área de la barra $i$ se calcula con la fórmula anterior.

```
para cada i en [1, n]:
    j = i - 1
    mientras j >= 1 y h[j] >= h[i]: j--
    L(i) = j
    j = i + 1
    mientras j <= n y h[j] >= h[i]: j++
    R(i) = j
    area_i = h[i] * (R(i) - L(i) - 1)
```

Es correcto y muy fácil de implementar, pero en el peor caso (por ejemplo, un
histograma cuyas alturas son todas iguales o estrictamente crecientes) cada
búsqueda recorre $O(n)$ barras, dando una complejidad total de $O(n^2)$. Con
$n$ hasta $100000$ esto puede ser demasiado lento si hay muchos casos de
prueba.

## Mejora con pila monotónica

La observación clave es que el trabajo del enfoque naive se repite: cuando
buscamos hacia la izquierda desde $i$ y "saltamos" varias barras más altas,
estamos descartando información que podríamos reutilizar para barras
posteriores.

Una **pila monotónica creciente** permite calcular todos los $L(i)$ en una
sola pasada de izquierda a derecha:

- Mantenemos una pila con índices cuyas alturas forman una secuencia
  estrictamente creciente.
- Al procesar la barra $i$, sacamos de la pila todos los índices con altura
  $\geq h[i]$ (no nos sirven como límite izquierdo de $i$, porque no son más
  bajos que ella).
- El índice que queda en la cima es exactamente $L(i)$: la primera barra a la
  izquierda más baja que $h[i]$.
- Apilamos $i$ y seguimos.

El cálculo de $R(i)$ es simétrico: misma idea recorriendo de derecha a
izquierda.

Para evitar comprobar si la pila está vacía se usa un truco habitual de
**centinelas**: se reserva el índice $0$ con altura $0$ a la izquierda y el
índice $n+1$ con altura $0$ a la derecha. Como ambas son estrictamente menores
que cualquier altura del histograma (que es $\geq 1$), nunca se sacarán de la
pila y siempre habrá un valor válido en la cima.

Cada índice entra y sale de la pila a lo sumo una vez, por lo que las dos
pasadas son $O(n)$ amortizado. El recorrido final que calcula el área es otro
$O(n)$.

## Complejidad

- **Tiempo:** $O(n)$ por caso de prueba.
- **Espacio:** $O(n)$ para los vectores $L$, $R$ y la pila.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [A.cpp](src/A.cpp) | Pila monotónica para calcular en $O(n)$ los límites izquierdo y derecho de cada barra | :white_check_mark: |
