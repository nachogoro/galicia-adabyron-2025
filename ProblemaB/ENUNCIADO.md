# Problema B - Planilandia

En un tranquilo pueblo llamado Planilandia, vivía una joven llamada Sofía, conocida por su pasión por
aprender cosas nuevas. Cada semana, en el centro cultural del pueblo, se ofrecían cursos de todo tipo:
desde arte y cocina hasta programación y astronomía. Sin embargo, había una pequeña complicación:
los horarios de los cursos a menudo se solapaban, lo que hacía imposible asistir a todos.

Un día, Sofía se encontró frente al tablón de anuncios del centro cultural. Había una lista de cursos
para el sábado, y todos parecían emocionantes:

1. **Pintura al óleo**: 09:00 - 11:00
2. **Yoga para principiantes**: 10:00 - 14:10
3. **Introducción a la astronomía**: 11:30 - 13:00
4. **Taller de panadería**: 11:00 - 14:00
5. **Robótica básica**: 13:30 - 15:30
6. **Fotografía con el móvil**: 13:10 - 15:40

Sofía miró los horarios con detenimiento. Se dio cuenta de que, si quería aprovechar el día al máximo,
debía elegir cuidadosamente. Su objetivo era asistir al mayor número posible de cursos sin que sus
horarios se solaparan.

Sofía contactó con los organizadores del Ada Byron para que los participantes implementasen un
**algoritmo óptimo y eficiente** que le ayudase a planificar su día y le indicase a cuántos cursos como
máximo podría asistir.

Por lo tanto, el planificador le aconsejó a Sofía que podía asistir a 3 cursos, por ejemplo:

1. Pintura al óleo (09:00 - 11:00)
2. Introducción a la astronomía (11:30 - 13:00)
3. Robótica básica (13:30 - 15:30)

El sábado, Sofía asistió a los tres cursos y disfrutó de cada minuto. Aprendió a mezclar colores para
crear paisajes, entendió las maravillas del cosmos y dominó la robótica básica. Aunque no pudo asistir
a todos los cursos, estaba feliz porque había aprovechado el día al máximo.

Desde entonces, Sofía compartió su algoritmo con otros vecinos de Planilandia, quienes comenzaron a
aplicar la misma técnica para organizar su tiempo.

## Entrada

La entrada consta de varias líneas. La primera es el número de cursos organizados $m$, siendo
$1 \leq m \leq 500000$.

Las siguientes líneas detallan el nombre del curso (sin espacios en blanco), *hora de inicio* y *hora de fin*
(las horas serán un entero que representan los milisegundos desde una fecha determinada, se garantiza
que *hora de inicio* < *hora de fin*, y que no habrá dos cursos que finalicen a la misma hora).
Estos elementos de información del curso (nombre, hora de inicio y hora de fin) están separados por un
espacio en blanco.

## Salida

Número máximo de cursos a los que se puede asistir.

## Entrada de ejemplo
```
10
Act_1 248974 489861
Act_2 82560 486634
Act_3 140280 758615
Act_4 482461 730495
Act_5 178363 802948
Act_6 690642 754525
Act_7 77710 340315
Act_8 664232 887712
Act_9 510747 920638
Act_10 371699 549522
```

## Salida de ejemplo
```
3
```
