# Problema D - La Torre Oscura

Saurito, el hijo de Sauron, hereda la imponente Torre Oscura (Barad-dur) tras la trágica muerte de su
padre, injustamente asesinado. La Torre Oscura representaba el mayor proyecto y sueño de Sauron:
una prisión de lujo equipada con vistas incomparables al Monte del Destino. Hoy en día, gracias a la
visión y legado de su progenitor, Saurito se ha consolidado como un hombre de éxito. La Torre, ahora
completamente operativa, alberga a una peculiar clientela compuesta de hobbits y enanos, quienes,
según el estilo distintivo de Saurito, disfrutan de rigurosas sesiones diarias de tortura.

Una mañana, al llegar a la Torre, Saurito descubre con sorpresa que uno de sus prisioneros, Frodo
Bolsón, ha logrado escapar de su celda. Para su asombro, Frodo se encuentra en la cima de la Torre,
dedicándose a la construcción de una cometa con la evidente intención de aprovechar los fuertes vientos
que atraviesan el Valle de Gorgoroth y así consumar su huida.

Para evitar la fuga y preservar su reputación como el mejor carcelero de Mordor, Saurito se ve obligado
a ascender hasta el último piso de la Torre. Allí, deberá enfrentarse a Frodo y frustrar su intento de
escape antes de que logre surcar los cielos con su improvisada cometa.

La Torre Oscura tiene $h$ pisos numerados de 1 a $h$. Para cada piso $i$ ($1 \leq i < h$) existe una escalera
que puede ser usada para subir al piso $i + 1$. Adicionalmente, la torre posee $n$ ascensores. Debido a la
humedad, estos están en muy malas condiciones y por lo tanto el ascensor $j$ solo sirve para subir desde
el piso $a_j$ hasta el $b_j$, sin parar entre medio. Además, cabe mencionar que estos solo son ascensores y
no descensores, por lo que no es posible utilizarlos para bajar.

Después de tantos años vigilando la torre, la salud de Saurito ya no es la que era. La humedad y el
moho han perjudicado su salud por lo que quiere minimizar la cantidad de escaleras que necesita subir
y evitar a toda costa bajarlas por el reúma. Específicamente, usando los ascensores y las escaleras
para subir, Saurito quiere encontrar una ruta desde el piso 1 al $h$ que minimice la cantidad de escaleras
que debe subir. Normalmente lo calcularía mentalmente, pero está demasiado ocupado planificando
cómo impedir que Frodo escape, por lo que te pidió ayuda con esta tarea.

Podrás ayudar a Saurito a subir la torre para evitar que Frodo escape y así mantener su impoluta
reputación en Mordor?

## Entrada

La primera línea de la entrada contiene dos enteros $n$ y $h$ ($0 \leq n \leq 10^5$, $1 \leq h \leq 10^6$)
correspondientes a la cantidad de ascensores y la cantidad de pisos en la torre respectivamente.

Luego, siguen $n$ líneas describiendo cada uno de los ascensores.

La $j$-ésima línea contiene dos enteros $a_j, b_j$ ($1 \leq a_j < b_j \leq h$), que corresponden respectivamente al
piso de inicio y al de llegada del ascensor $j$.

## Salida

La salida debe tener un único entero, correspondiente a la cantidad mínima de escaleras con la que es
posible ir desde el piso 1 al $h$.

## Entrada de ejemplo
```
1 5
1 3
```

```
2 10
1 4
2 10
```

## Salida de ejemplo
```
2
1
```
