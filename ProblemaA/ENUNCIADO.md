# Problema A - Muralla de defensa

En un pequeño rincón de Galicia, en una aldea costera llamada Porto da Lua, los habitantes enfrentan
cada invierno la amenaza de grandes tormentas marítimas que erosionan la costa y ponen en peligro
sus hogares. Para protegerse, han decidido construir una gran muralla de defensa junto al puerto.
Esta muralla es su escudo contra las olas y está formada por **bloques de piedra de 1 metro de
ancho** alineados uno al lado del otro.

Sin embargo, debido a la naturaleza rocosa de la región, no todos los bloques tienen la misma altura.
Algunos son enormes y otros más pequeños, dependiendo del tipo de roca disponible. Eso significa
que hay zonas más protegidas que otras. Por ese motivo en la aldea quieren calcular el área del tramo
rectangular más grande que se ha construido utilizando bloques consecutivos de la muralla.

Por restricciones de diseño, la altura del tramo rectangular debe ser uniforme, lo que significa que
estará determinada por el bloque más bajo en ese tramo.

Tu misión como ingeniero del proyecto es ayudar a los lugareños a **calcular el área máxima de un
tramo rectangular construido con los bloques disponibles**. Esto les permitirá conocer la zona
de la muralla que ofrece máxima protección.

Ejemplo: Se dispone de una muralla de 6 bloques de piedra de 1 metro de ancho y las alturas que se
muestran en la siguiente figura (10, 12, 7, 3, 8, 12).

Para este ejemplo, el tramo rectangular más grande se forma utilizando los 3 primeros bloques con
una altura mínima de 7 y un ancho de 3, es decir, un área de 7 x 3 = 21.

## Entrada

La entrada consta de una serie de casos de prueba. Cada caso se compone de dos líneas.

La primera línea contiene un único entero $n$, que representa el número de bloques en la muralla,
siendo $1 \leq n \leq 100000$.

La segunda línea representa la secuencia de alturas de cada bloque, separadas por espacios. Cada
altura será un valor entero entre 1 y 10000.

El final de la entrada se reconoce con $n = 0$.

## Salida

Para cada caso de prueba, la salida es una línea con un único número entero que representa el área
del tramo rectangular más grande de la muralla.

## Entrada de ejemplo
```
6
10 12 7 3 8 12
7
100 80 60 70 60 75 85
8
1 3 6 5 4 2 1 2
10
25 530 120 910 330 50 50 102 55 75
15
56 67 45 2 46 57 68 79 80 90 189 200 398 560 72
0
```

## Salida de ejemplo
```
21
420
12
910
796
```
