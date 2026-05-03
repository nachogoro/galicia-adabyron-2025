# Problema H - El príncipe Shrek

A la intrépida guerrera Fiona se le ha encomendado la difícil misión de rescatar al indefenso príncipe
Shrek de la torre infernal, donde la temida reina roja lo tiene cautivo.

La torre infernal tiene $N$ niveles numerados de 1 a $N$. En cada nivel hay un guerrero de la reina roja
que dará su vida para que Fiona fracase en su misión. Dicho guerrero, después de realizar un cursillo
de Tai Chi del SEPE, posee un nivel de energía $P_i$. Para que la misión sea satisfactoria, esta
debe derrotar a los diferentes enemigos que se encontrará en todos los niveles hasta llegar a lo más
alto de la torre donde se encuentra el príncipe Shrek. Antes de llegar a la torre, Fiona ha decidido
parar en un furancho a tomar un cocido bien completo y así cargar su nivel de energía en $V$.

Cada vez que Fiona se enfrenta a un guerrero de la reina roja solo puede derrotarlo si su poder
$V$ es mayor o igual que el poder $P_i$ de dicho guerrero. Cada vez que Fiona sale victoriosa de un
enfrentamiento con un guerrero, este es eliminado de la torre y el nivel queda *vacío*. Si en cualquier
momento el enfrentamiento es con un guerrero con un poder mayor que el de ella, Fiona perderá
el combate y por lo tanto será encarcelada en las mazmorras de la torre infernal. Afortunadamente,
gracias a la filloa mágica que tomó de postre antes de empezar su aventura, cada vez que Fiona derrota
a un guerrero su nivel de energía aumenta en 1.

Además, gracias a las catiuscas mágicas que le regaló su madre al iniciar la misión, Fiona puede
comenzar en cualquier nivel de la torre y enfrentarse con el guerrero que custodia dicho nivel. Una vez
que Fiona ha seleccionado un nivel, solo puede moverse al siguiente nivel no vacío ya sea hacia arriba
o hacia abajo, pero siempre que derrote al aterrador guerrero que lo defiende. Nuestra heroína está
interesada en saber en qué orden visitar los niveles y enfrentarse a los guerreros para que su misión
sea exitosa.

La siguiente imagen muestra un ejemplo para una torre infernal con $N = 5$ niveles y un poder inicial
para Fiona de 12. Con esas condiciones iniciales, Fiona puede decidir comenzar su misión infiltrándose
en el nivel 3 y derrotar al guerrero cuyo poder también es 12. Después de derrotarlo, el poder de Fiona
pasa a ser de 13. El siguiente guerrero a enfrentar debe ser el del nivel 2 (abajo) o el del nivel 4 (arriba).
El guerrero del nivel 2 tiene poder 14 y por lo tanto Fiona no podrá derrotarlo. Así, está forzada a
enfrentarse al guerrero del nivel 4 cuyo poder es 13. Tras vencerlo, el poder de Fiona es ahora 14
y las posibilidades son moverse al nivel 2 (abajo) o al 5 (arriba). En este caso la única alternativa es
moverse al nivel 2 y enfrentar al guerrero con poder 14. En este punto, Fiona puede decidir derrotar
al guerrero del nivel 1 o al guerrero del nivel 5. Para este ejemplo, elige primero derrotar al guerrero
del nivel 1 y luego al guerrero del nivel 5. La secuencia en la que Fiona visita todos los niveles es la
siguiente: 3, 4, 2, 1, 5. Nota: si inicialmente Fiona hubiese decidido infiltrarse en el nivel 1, hubiese
fallado la misión.

## Entrada

La primera línea de la entrada contiene dos enteros $N$ y $V$ ($0 < N \leq 500$ y $0 < V \leq 10^9$) correspondientes
respectivamente a la cantidad de niveles en la torre infernal y el poder inicial de Fiona.
La siguiente línea contiene $N$ enteros. El $i$-ésimo entero corresponde al poder $P_i$ ($0 < P_i \leq 10^9$) del
guerrero del nivel $i$.

## Salida

La salida debe contener una línea con $N$ enteros entre 1 y $N$ correspondientes a un posible orden en
que Fiona puede visitar los niveles para derrotar a todos los guerreros. En caso de haber más de un
posible orden solo será válido aquel que priorice la conquista de los niveles más bajos en primer lugar.
Si no existe un orden en el que sea posible derrotar a todos los guerreros, la salida debe contener una
línea con la palabra FALLIDA.

## Entrada de ejemplo
```
5 12
11 14 12 13 15
```

```
5 12
14 14 11 14 14
```

## Salida de ejemplo
```
3 4 2 1 5
FALLIDA
```
