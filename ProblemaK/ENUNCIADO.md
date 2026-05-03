# Problema K - Ciudad Futura

En un futuro lejano, la humanidad expandirá sus dominios más allá de la Tierra y comenzará a
colonizar otros planetas. Para poder comunicarse con todos ellos, los científicos de **Ciudad Futura**
han comenzado a desarrollar un avanzado sistema de comunicación interestelar. Para ello, han de
tener en cuenta que cada civilización alienígena utiliza un sistema numérico diferente, con bases que
van desde 2 hasta 9. Con el fin de facilitar esta comunicación, se necesita un programa que permita
convertir cualquier número decimal a su equivalente en una base entre 2 y 9. Podrías ayudarles?

## Entrada

Un entero $t$ ($1 \leq t \leq 125000$) que indica cuántos números se van a transformar de base. A continuación,
cada una de las $i$ líneas siguientes ($1 \leq i \leq t$) presentará un número natural $n_i$ en base decimal, donde
$0 \leq n_i \leq 100000$ y un segundo número natural $b_i$ que representa la base a la que se quiere convertir
dicho número, siendo $2 \leq b_i \leq 9$.

## Salida

Los resultados de conversión de cada número $n_i$ proporcionados en la correspondiente base $b_i$, cada
uno en una línea diferente y en el mismo orden de entrada.

## Entrada de ejemplo
```
3
5 2
102 5
89537 8
```

## Salida de ejemplo
```
101
402
256701
```
