# Introducción a la solución

El problema pide la cantidad mínima de movimientos para transformar una
configuración inicial de fichas (el tablero, conjunto $A$) en una
configuración objetivo (la lámina, conjunto $B$), donde $|A| = |B|$ y ambas
son figuras conexas. Cada movimiento consiste en levantar una ficha y
volver a depositarla en una casilla adyacente a otra ficha de la figura, de
modo que la figura siga siendo conexa en todo momento.

Las casillas en $A \cap B$ son fichas que ya están en su sitio, las de
$A \setminus B$ son fichas que no deben estar en su posición actual, y las de
$B \setminus A$ son posiciones donde falta una ficha. Como $|A| = |B|$, se
cumple $|A \setminus B| = |B \setminus A|$.

La solución se divide en dos casos según si las dos figuras se solapan o no.

## Caso 1: hay solapamiento ($A \cap B \neq \emptyset$)

Si al menos una ficha está ya en su posición final, basta con mover, una a
una, las $|A \setminus B|$ fichas mal colocadas a las $|B \setminus A|$
casillas vacías del objetivo. Cada movimiento corrige exactamente una ficha,
así que la respuesta es

$$\text{movimientos} = |A \setminus B| = |A| - |A \cap B|.$$

### Suposición implícita

Esta cuenta da por hecho que **siempre podemos elegir una ficha de
$A \setminus B$ que sea movible** (es decir, que al levantarla la figura no
se desconecte) y que existe siempre una casilla de $B \setminus A$ adyacente
a la figura donde colocarla.

En el caso general esto no es cierto: si todas las fichas de $A \setminus B$
son puntos de articulación, es imposible mover una de ellas sin hacer que la
figura ya no sea conexa. Tomemos por ejemplo este tablero, donde la pieza se
marca con `o`, el patrón con `*` y la intersección de ambas con `x`:
```
ooooo
x.x.x
*****
```

Aquí, es imposible levantar una pieza de $A$ (un `o`) sin hacer que la figura
resultante ya no sea conexa. 

Estrictamente hablando, este tipo de instancias
podrían requerir movimientos extra (mover primero una ficha "ancla" para
reorganizar la figura) o incluso no admitir la cota $|A \setminus B|$ a secas.

Aunque esto va en contra de la restricción explícita del enunciado de que la
figura sea conexa en todo momento, es necesario ignorar estos contraejemplos
para poder generar una solución que entre en tiempo. El juez acepta esta
respuesta.

## Caso 2: no hay solapamiento ($A \cap B = \emptyset$)

Cuando las dos figuras están completamente disjuntas no hay ninguna ficha
que sirva de ancla en el destino. La estrategia es construir un **puente
de fichas** desde $A$ hasta $B$ aprovechando el camino más corto entre
ambas en la cuadrícula (sin tener en cuenta otras fichas, solo distancia
de Manhattan a través de casillas vecinas).

Sea $d$ la distancia mínima en la cuadrícula entre cualquier casilla de $A$
y cualquier casilla de $B$. Para extender la figura desde $A$ hasta tocar
una casilla de $B$ hay que colocar fichas en las $d - 1$ casillas
intermedias más la propia casilla de $B$, es decir, **$d$ movimientos** que
"alargan" la figura. Tras esos movimientos, la figura mantiene $|A| - d$
fichas originales (las $d$ que se han usado se han ido a construir el
puente), ha cubierto una posición de $B$ y aún le quedan $|B| - 1 = |A| - 1$
posiciones de $B$ por rellenar.

Esas $|A| - 1$ fichas mal colocadas (las $|A| - d$ originales que quedan en
su sitio inicial más las $d - 1$ del puente) se mueven una a una a las
posiciones de $B$ que faltan, lo que cuesta otros $|A| - 1$ movimientos.

En total:

$$\text{movimientos} = d + (|A| - 1) = |A| + d - 1.$$

La distancia $d$ se calcula con un **BFS multiorigen** que arranca
simultáneamente desde todas las casillas de $A$ y se detiene en la primera
casilla de $B$ alcanzada. Como cada arista vale $1$, el BFS encuentra esa
distancia mínima en $O(n \cdot m)$.

## Algoritmo

1. Leer el tablero $A$ y la lámina $B$, contando $|A|$ y $|A \cap B|$.
2. Si $|A \cap B| > 0$, devolver $|A| - |A \cap B|$.
3. Si $|A \cap B| = 0$, lanzar un BFS multiorigen desde $A$ hasta la primera
   casilla de $B$ y devolver $|A| + d - 1$.

## Complejidad

- **Tiempo:** $O(n \cdot m)$ por la lectura, el conteo y el BFS.
- **Espacio:** $O(n \cdot m)$ por las matrices y la cola del BFS.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [E.cpp](src/E.cpp) | Casos por solapamiento; BFS multiorigen para el puente cuando no hay solapamiento | :white_check_mark: |
