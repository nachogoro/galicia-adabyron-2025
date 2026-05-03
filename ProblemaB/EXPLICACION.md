# Introducción a la solución

El problema pide elegir el máximo número de cursos a los que se puede asistir
sin que sus horarios se solapen.

La idea clave es que, si en cada momento elegimos el curso compatible con la
selección hasta ese momento que **termina antes**, dejamos la mayor cantidad
posible de tiempo libre por delante para encajar más cursos después.

## Algoritmo greedy: ordenar por hora de fin

1. Ordenar todos los cursos por su hora de fin (de menor a mayor).
2. Recorrer la lista en ese orden manteniendo un contador `busy_until` con
   la hora a la que termina el último curso seleccionado (inicialmente $0$, o
   $-\infty$).
3. Para cada curso, si su hora de inicio es $\geq$ `busy_until`, lo
   seleccionamos, incrementamos el contador de cursos elegidos y actualizamos
   `busy_until` a su hora de fin. En caso contrario, se descarta.

### Detalles de implementación

- El nombre del curso es irrelevante para el cálculo, basta con leerlo y
  descartarlo.
- Las horas están en milisegundos y caben holgadamente en un `int`.
- El enunciado garantiza que no hay dos cursos que terminen a la misma hora,
  así que el orden estricto por hora de fin está bien definido. El criterio
  de desempate por hora de inicio es un detalle defensivo.
- La comparación para decidir si un curso es compatible es
  `start >= busy_until`, lo que permite encadenar cursos que terminan e
  inician en el mismo instante.

## Complejidad

- **Tiempo:** $O(m \log m)$ por la ordenación. El recorrido posterior es
  $O(m)$.
- **Espacio:** $O(m)$ para almacenar los cursos.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [B.cpp](src/B.cpp) | Greedy ordenando por hora de fin | :white_check_mark: |
