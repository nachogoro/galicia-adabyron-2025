# Introducción a la solución

El problema es una instancia clásica del **knapsack fraccional** (mochila
fraccional): hay $N$ actividades, cada una con un coste en tiempo $t_i$ y
una recompensa de popularidad $p_i$, y un presupuesto total $T$ minutos.
Como las actividades se pueden hacer parcialmente y la recompensa es
proporcional al tiempo dedicado, no estamos en la versión clásica
0/1: aquí el óptimo se obtiene con una estrategia greedy sencilla.

La idea clave es ordenar las actividades por **densidad de popularidad por
unidad de tiempo**, $p_i / t_i$, y consumirlas de mayor a menor densidad.

## Algoritmo greedy: ordenar por densidad

1. Calcular la densidad $d_i = p_i / t_i$ para cada actividad.
2. Ordenar las actividades por densidad de mayor a menor.
3. Recorrerlas en ese orden manteniendo el tiempo restante $T$:
   - Si la actividad cabe entera ($t_i \leq T$), tomarla completa: sumar
     $p_i$ a la popularidad y restar $t_i$ del tiempo.
   - Si no cabe, tomar la fracción que cabe: sumar $p_i \cdot (T / t_i)$
     a la popularidad y poner $T = 0$ (lo que termina el bucle).

### Detalles de implementación

- No hace falta cortar el bucle anticipadamente cuando $T$ llega a $0$:
  con $T = 0$, cada iteración siguiente toma una fracción nula y no afecta
  al resultado. Si los casos de prueba fueran muy grandes, valdría la pena
  romper el bucle.
- Usar `double` es suficiente para la tolerancia de $10^{-3}$ que pide el
  enunciado, pero si se prefiere evitar cualquier riesgo de error de
  redondeo se pueden hacer las cuentas con aritmética racional exacta
  (por ejemplo, `fractions.Fraction` en Python, como hace [F.py](src/F.py)).

## Complejidad

Por caso de prueba:

- **Tiempo:** $O(N \log N)$ por la ordenación. El recorrido posterior es
  $O(N)$.
- **Espacio:** $O(N)$ para almacenar las actividades.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [F.cpp](src/F.cpp) | Greedy por densidad popularidad / tiempo, tomando fracciones cuando no cabe la actividad entera | :white_check_mark: |
| [F.py](src/F.py) | Misma estrategia greedy usando `fractions.Fraction` para que los cálculos sean exactos | :white_check_mark: |
