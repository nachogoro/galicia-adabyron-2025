# Problema I - Cimientos

A Gaellicus Maximus le han encargado construir una nueva torre a semejanza de la de Hércules. En
un principio todo apuntaba a ser una construcción rutinaria más, hasta que Gaellicus vio el plano del
terreno y se dio cuenta de que este era totalmente irregular.

El plano describe el terreno como una matriz de enteros de tamaño $H \times W$ ($H$ filas y $W$ columnas).
Cada elemento en la matriz representa la altura del terreno en esa posición. La nueva torre debe
construirse sobre una submatriz de tamaño $M \times N$. Antes de construirla, Gaellicus tiene que nivelar
la submatriz sobre la cual se construirá. El coste de nivelación de una submatriz es igual a la diferencia
entre las alturas de la celda más alta y la más baja en la submatriz.

A continuación se muestra un ejemplo para un terreno de tamaño $4 \times 5$ donde se ha marcado una
submatriz de tamaño $3 \times 2$. Para esta submatriz, la celda más baja tiene altura 8 y la más alta tiene
altura 80. Por lo tanto, el coste de nivelación de esta submatriz es $80 - 8 = 72$.

Gaellicus desea encontrar una submatriz de forma que el coste de nivelación sea mínimo.

## Entrada

La primera línea de la entrada contiene un entero positivo $T$ ($1 \leq T \leq 6$) indicando el número de
casos de test. Cada uno de los casos de test se describen a continuación de la siguiente manera:

- La primera línea contiene cuatro enteros $H$, $W$, $M$ y $N$ ($0 < M \leq H$, $0 < N \leq W$, $H \times W \leq 10^6$).
  Estos enteros corresponden respectivamente al alto y ancho de la matriz que describe el terreno,
  y al alto y ancho de la submatriz donde se debe construir la torre.
- Las siguientes $H$ líneas describen la matriz que representa el terreno. Cada línea contiene $W$
  enteros entre 0 y $10^6$. El $j$-ésimo entero en la línea $i$-ésima corresponde al entero en la fila $i$-ésima
  y columna $j$-ésima de la matriz.

## Salida

La salida debe contener para cada test un único entero correspondiente al coste de nivelación de la
submatriz de tamaño $M \times N$ de menor coste.

## Entrada de ejemplo
```
3
4 4 4 4
10 11 12 13
9 8 7 5
10 8 9 1
100 2 3 99
4 5 3 2
20 100 50 3 22
7 40 8 100 33
60 80 33 9 55
33 56 44 21 88
1 10 1 3
88 22 100 2 200 101 0 500 100 0
```

## Salida de ejemplo
```
99
72
78
```
