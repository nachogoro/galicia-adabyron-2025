# Problema G - Monedas

En la cueva del temido Dragón Dormido un montón de monedas mágicas esparcidas por el suelo.
Pero, cuidado! algunas están malditas!. Cuando alguien se adentra en la cueva, el dragón abre un
ojo y maldice todas las monedas que ve. Es más, maldice todas las monedas que tengan el mismo
valor de alguna moneda que ve. Lo bueno es que las monedas malditas se vuelven brillantes y son
fáciles de distinguir. Lo malo, que cuando se intentan coger las no malditas es posible que se despierte
completamente y la vida de esa persona que intenta coger las monedas se pone en peligro.

El Consejo de Magos te ha encargado una tarea importante: sumar el valor total del tesoro, ignorando
las monedas malditas, para que aquellas personas aventureras que quieran adentrarse en la cueva sepan
cuánto oro pueden llevarse y si les compensa el riesgo.

## Entrada

La primera línea de la entrada contiene un entero positivo $T$ ($1 \leq T \leq 10$) indicando el número de casos
de test. Cada uno de los casos de test se describen a continuación de la siguiente manera:

- Un entero $N$ ($1 \leq N \leq 1000$): el número total de monedas en la cueva.
- Una línea con $N$ enteros separados por espacios: los valores de cada una de las monedas la cueva,
  ordenados según se encuentran esparcidas en la cueva. El valor de las monedas está entre 1 y 1000.
- Un entero $M$ ($1 \leq M \leq 100$): el número de valores diferentes las monedas malditas.
- Una línea con $M$ enteros: los valores de las monedas malditas, en orden creciente. De nuevo,
  estos valores están entre 1 y 1000.

## Salida

La salida estará formada por una línea por cada caso de test, en el mismo orden de la entrada, en
donde se debe indicar la suma total de las monedas buenas (no malditas) para ese caso de test.

## Entrada de ejemplo
```
3
8
5 2 7 3 2 9 1 5
3
2 3 9
4
4 4 4 4
1
4
6
10 5 7 5 9 2
2
5 9
```

## Salida de ejemplo
```
18
0
19
```
