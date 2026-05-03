# Problema L - La fusión de los reinos digitales

En un mundo donde la informática domina la civilización, existen dos poderosos reinos: **Algorithmlandia**
y **Datastructuria**.

Estos reinos han estado en competencia durante siglos, cada uno desarrollando su propio conjunto de
procesadores ordenados según su eficiencia en operaciones computacionales. Sin embargo, han decidido
unirse para crear una **supercomputadora definitiva**, combinando sus procesadores de manera justa.

Para lograrlo, necesitan encontrar el punto de equilibrio entre ambas arquitecturas: *el nivel de
rendimiento mediano* de la nueva red de cómputo.

## Tu misión

Dadas dos listas ordenadas de números enteros positivos, representando los índices de eficiencia de los
procesadores de cada reino, escribe un programa eficiente que calcule la mediana de la combinación
de ambos reinos.

## Entrada

En la primera línea se indica el tamaño $n$ de las dos listas, siendo $1 \leq n \leq 1000000$ (se garantiza
que ambas tienen el mismo tamaño). En la segunda y tercera línea se muestra cada una de las listas
de enteros ordenadas de menor a mayor, representando la eficiencia de los procesadores en cada reino.
Se garantiza que ambos reinos han ordenado correctamente sus datos antes de la fusión.

## Salida

Un número decimal que representa la **mediana** del rendimiento de la nueva supercomputadora.

## Entrada de ejemplo
```
3
1 3 5
2 4 6
```

```
4
2 5 12 14
3 6 10 13
```

## Salida de ejemplo
```
3.5
8.0
```
