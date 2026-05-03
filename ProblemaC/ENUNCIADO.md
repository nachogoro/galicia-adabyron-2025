# Problema C - Dakar

El Rally Dakar es una de las competiciones más emocionantes y desafiantes del mundo. Los pilotos
de los vehículos atraviesan terrenos hostiles, desiertos interminables, montañas y planicies áridas,
enfrentándose no solo a la distancia, sino también al clima extremo y a sus propios límites físicos y
mentales. De ahí que, para muchos participantes, el objetivo no es ganar, sino simplemente llegar al
final. Sin embargo, ese no es el caso de Rápido Furioso, un piloto veterano de motos cuya única meta
es acabar el Rally Dakar por delante de todos sus competidores.

Antes de cada etapa la organización del Rally Dakar le proporciona a cada piloto información sobre
la salida y la meta de esa etapa. Además, les indica varios *waypoints*, puntos por los que tienen que pasar
obligatoriamente. Tanto por los *waypoints* como por la salida y la meta, solo pueden pasar una vez.
Gracias a su experiencia, Rápido Furioso es capaz de estimar cuánto tiempo necesita para moverse de
un punto del desierto a otro. Con esa información necesita planificar la ruta que debe hacer para llegar
a la meta en el menor tiempo posible. Lo debe hacer rápido, ya que en su diccionario no existe la
palabra lento. Como sus habilidades algorítmicas no son las mismas que encima de la moto, contacta
contigo para que le eches una mano y puedas compartir con él la gloria de ganar el Rally Dakar.

Rápido Furioso te informa de la salida, la meta y los *waypoints*. Además, te indica los distintos puntos
por los que puede pasar la etapa y el tiempo que tardaría en pasar por cada uno de los caminos que hay
entre dos puntos. Es importante destacar que, en el desierto, el tiempo necesario para ir de un punto
A a un punto B no siempre es el mismo que en la dirección opuesta. Subir dunas presenta desafíos
muy distintos al de descenderlas! Con esa información, debes ser capaz de calcular cuál es el camino
más rápido para llegar a la meta pasando por los *waypoints*. Realmente, solo necesitarás indicarle
cuánto tiempo tardará, con su veteranía, Rápido Furioso sabrá decidir cuál es la ruta correcta.

## Entrada

La primera línea de entrada contiene dos enteros $P$ ($1 \leq P \leq 1000$) y $C$ ($1 \leq C \leq 4000000$),
representando el número de puntos y el número de caminos que hay entre esos puntos, respectivamente.

Las siguientes $C$ líneas representan los caminos que unen dos puntos en una dirección. Cada línea
contiene el punto origen $O$, el punto destino $D$ y los segundos $T$ ($1 \leq T \leq 100$) que se tarda en llegar
del origen al destino.

La siguiente línea contiene tres enteros que representan el punto de salida $S$, el punto de la meta $M$
y el número de *waypoints* $W$.

Las siguientes $W$ líneas contienen un entero cada una que representa los *waypoints*. La primera línea
contiene el primer *waypoint*, la segunda corresponde al segundo *waypoint*, y así, sucesivamente.

## Salida

La salida será un entero que indique los segundos que se tarda en completar la etapa por la ruta más
rápida, respetando las reglas del Rally Dakar.

## Entrada de ejemplo
```
5 6
1 2 2
2 3 1
2 5 2
3 4 2
3 5 6
4 5 2
1 5 1
3
```

```
5 18
1 2 88
1 3 56
1 4 71
1 5 64
2 1 42
2 3 59
2 4 23
2 5 58
3 1 56
3 4 1
3 5 12
3 5 45
4 1 73
4 3 2
4 5 14
5 1 70
5 2 11
5 3 95
1 5 1
3
```

## Salida de ejemplo
```
7
68
```
