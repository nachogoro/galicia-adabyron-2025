# Problema E - Rompecabezas 3D

Estas navidades, con la intención de que se olviden de sus teléfonos móviles durante el mayor tiempo
posible, Luis ha regalado a sus dos hijos, Antía y José, un antiguo rompecabezas 3D que se ha
transmitido de padres a hijos durante varias generaciones. Se trata de una caja de madera de castaño
que alberga en su parte superior un rompecabezas tallado a mano. Esta caja tiene la peculiaridad de
que esconde un compartimento secreto que solo se abrirá una vez que se resuelva el rompecabezas.
Para ponerlo más interesante, Luis ha escondido dentro del rompecabezas dos entradas para ver la
próxima película de la saga Star Wars, de la que sus dos hijos son muy fans.

Junto a las instrucciones que acompañan al rompecabezas se encuentra una lámina en la que hay
dibujada una cuadrícula de $n$ filas y $m$ columnas. Las filas están numeradas de arriba hacia abajo
desde 1 a $n$, mientras que las columnas están numeradas de izquierda a derecha desde 1 a $m$. La
casilla correspondiente a la fila $i$ y columna $j$ se identifica con el par $(i, j)$.

Algunas de las casillas dibujadas en la lámina se han decorado con el escudo de la familia de Luis (la
cabeza de un león) formando una *figura conexa*, es decir, todas las casillas decoradas son *adyacentes*
a al menos otra casilla decorada. Dos casillas decoradas se consideran adyacentes si comparten un
borde vertical u horizontal.

En la parte superior de la caja de madera se encuentra el tablero del rompecabezas formado también
por una cuadrícula de $n \times m$ casillas. Sobre el tablero, hay fichas que pueden moverse entre sus
casillas. La cantidad de fichas es la misma que la de casillas decoradas que aparecen en la lámina que
se encontraba junto a las instrucciones del rompecabezas, pero están dispuestas de forma distinta.

De acuerdo a las indicaciones de su padre, para acceder al compartimento secreto y así poder ir al
cine gratis, Antía y José tendrán que resolver el rompecabezas. Para ello, deben mover las fichas
del tablero hasta que coincidan con las casillas de la lámina. A priori esto parece una tarea fácil, pero
para poder acceder al compartimento secreto, las fichas deben moverse siguiendo una regla especial.
Así, el único movimiento permitido es coger una ficha y colocarla adyacente a otra ficha de manera
que en todo momento se forme una figura conexa.

Antía y José están ansiosos por ir al cine y quieren resolver el rompecabezas lo más rápido posible,
pero están teniendo problemas. En particular, les gustaría saber la mínima cantidad de movimientos
en que es posible hacer coincidir las fichas del rompecabezas con la figura de la lámina y así acceder
a su premio. Podrías ayudarlos?

## Entrada

La primera línea de la entrada contiene dos enteros $n$ y $m$ ($n \times m \leq 2 \times 10^5$) correspondientes a las
dimensiones del tablero del rompecabezas y a la cuadrícula de la lámina. Luego vienen $2 \times n$ líneas
describiendo el tablero y la cuadrícula de la lámina.

Las primeras $n$ líneas describen el tablero. Cada línea contiene $m$ enteros iguales a 0 o 1. El $j$-ésimo
entero en la línea $i$ describe la casilla $(i, j)$ del tablero. Un 1 indica que la casilla contiene una ficha y
un 0 indica que está vacía.

Las últimas $n$ líneas describen las casillas tal y como aparecen en la cuadrícula de la lámina usando
el mismo formato.

Se garantiza que la entrada cumple las siguientes condiciones:

- La cantidad de unos en el tablero y en la lámina es la misma.
- La cantidad de unos en el tablero y en la lámina es mayor o igual que 2.
- Los unos en el tablero y en la lámina forman ambos una figura conexa.

## Salida

La salida debe contener un entero igual al número mínimo de movimientos requeridos para mover las
casillas de forma que coincidan con casillas talladas en la lámina.

## Entrada de ejemplo
```
1 4
1 1 0 0
0 0 1 1
```

```
3 5
0 1 1 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 1 1
```

## Salida de ejemplo
```
2
3
```
