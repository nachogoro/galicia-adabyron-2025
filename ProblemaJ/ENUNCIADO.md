# Problema J - Archipiélagos

A lo largo de la historia, navegantes y exploradores han cartografiado numerosos mares y océanos,
pero aún quedan regiones inexploradas. En distintos puntos del mundo, antiguos mapas han revelado
la posible existencia de archipiélagos olvidados, ocultos en océanos como el Atlántico, el Ártabro, el
Cantábrico y muchos más.

Cada uno de estos mapas está representado como una cuadrícula donde cada celda indica si hay agua
(0) o tierra (1). Sin embargo, con el paso del tiempo, las marcas se han desvanecido, y no es posible
determinar a simple vista cuántas islas hay en cada océano.

Se define una isla como un conjunto de tierras (1) conectadas en dirección horizontal, vertical o
diagonal. Si dos porciones de tierra están separadas por agua (0), pertenecen a islas diferentes.

Para resolver este misterio, es necesario escribir un algoritmo que analice los mapas y cuente con
precisión cuántas islas esconden estos océanos.

Ejemplo de entrada:
Matriz de $5 \times 5$:
```
1 1 0 0 0
1 1 0 0 1
0 0 0 1 1
0 0 0 0 0
1 1 0 0 1
```

Salida esperada:
Número de islas: 4.

## Entrada

La primera línea de la entrada contiene un entero positivo $T$ indicando el número de casos de test,
siendo $1 \leq T \leq 8$. A continuación, cada caso de test tiene una primera línea con dos enteros
positivos $N$ y $M$, $1 \leq N, M \leq 250$, que representan las dimensiones de la cuadrícula ($N$ filas
y $M$ columnas). Las siguientes $N$ líneas contienen $M$ valores (0 o 1), separados por espacios, que
representan el mapa del océano.

## Salida

La salida debe contener $T$ líneas, cada una correspondiente con un caso de test con un único número
entero que indica la cantidad de islas presentes en el mapa.

## Entrada de ejemplo
```
4
5 5
1 1 0 0 0
1 1 0 0 1
0 0 0 1 1
0 0 0 0 0
1 1 0 0 1
6 6
1 1 0 0 1 0
1 1 0 1 1 0
0 0 0 1 1 0
0 1 1 0 0 0
1 1 0 0 1 1
1 1 0 0 1 1
1 1
0
1 3
1 0 1
```

## Salida de ejemplo
```
4
3
0
2
```
