# Introducción a la solución

El problema pide encontrar un orden válido en el que Fiona pueda derrotar
a los guerreros de los $N$ niveles de la torre, comenzando por cualquier
nivel y moviéndose siempre al siguiente nivel no vacío (arriba o abajo)
respecto al último nivel conquistado. Cada victoria incrementa su poder en
$1$. Si hay varias soluciones, hay que devolver la que priorice los niveles
más bajos en cada paso.

La observación clave es que, como cada nivel derrotado se vacía y solo se
puede saltar al siguiente nivel *no vacío*, los niveles ya conquistados
forman en todo momento un intervalo contiguo alrededor del nivel de
partida. El estado relevante en cada paso es por tanto solo
$(L, R)$: el índice más bajo y el más alto del intervalo derrotado. Además,
el poder actual de Fiona queda determinado por el número de niveles
derrotados ($V_{\text{actual}} = V_{\text{inicial}} + k$, donde $k$ es la
cantidad de victorias acumuladas), de modo que no es necesario propagarlo
de manera independiente.

Desde el estado $(L, R)$ las dos únicas opciones son:

- Bajar y enfrentarse al guerrero del nivel $L - 1$.
- Subir y enfrentarse al guerrero del nivel $R + 1$.

## Greedy: empezar por el nivel más bajo posible y bajar siempre que se pueda

La estrategia:

1. Probar como nivel inicial $s = 1, 2, \dots, N$ en orden creciente. Para
   cada $s$ tal que $V \geq P_s$, simular la misión empezando ahí.
2. En la simulación, mantener dos punteros $L$ y $R$ (al principio
   $L = R = s$) y la regla: si se puede bajar (es decir, $L \geq 1$ y
   $V_{\text{actual}} \geq P_{L-1}$), bajar; si no, intentar subir; si
   tampoco, declarar la simulación fallida.
3. Devolver el primer recorrido que consiga conquistar los $N$ niveles. Si
   ninguno lo consigue, imprimir `FALLIDA`.

## Complejidad

- **Tiempo:** $O(N^2)$ en el peor caso, porque se prueban hasta $N$
  inicios y cada simulación realiza $N$ pasos.
- **Espacio:** $O(N)$ para los poderes y para almacenar el orden de
  visita.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [H.cpp](src/H.cpp) | Pruebas en orden creciente de nivel inicial; simulación greedy con dos punteros bajando siempre que sea posible | :white_check_mark: |
