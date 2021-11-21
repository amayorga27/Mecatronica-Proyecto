# Mecatronica-Proyecto
En este repositorio iremos desarrollando nuestro proyecto de la asignatura de Mecatrónica sobre la creación de un robot.
El Robot que hemos decidido realizar para este proyecto lo hemos encontrado [aquí](https://www.instructables.com/Critter-3D-Printed-Crawling-Arduino-Robot/).
Este es un proyecto basado en arduino desarrollado y explicado por [LittleBots](https://www.instructables.com/member/LittleBots/) en codigo libre, que esta bastante bien explicado tanto el diseño de las piezas como el montaje del mismo. 
Por otro lado tambien esta pensado para controlarlo por bluetooth desde el movil, pero nosotros en principio no lo controlaremos de esa forma.

<p align="center">
<img src="/Doc/images/Critter.png" alt="Generic version"></a>
</p>

---
## ELEMENTOS

Para comenzar expondremos los elementos que necistaremos para realizar este robot:

- [x] 4 Micro Servos
- [x] Piezas impresas en 3D (Más adelante se explicarán con detalle)
- [x] Placa controladora (En principio usaremos arduino)
- [ ] Sensor Ultra Sonidos
- [ ] Más sensores (opcional)

<p align="center">
<img src="/Doc/images/piezas.png" alt="Generic version"></a>
</p>

---
## PIEZAS 3D

En cuanto a las piezas 3D que utilizaremos para fabricar nuestro robot, hemos partido de las piezas que nos proporciona [LittleBots](https://www.instructables.com/Critter-3D-Printed-Crawling-Arduino-Robot/) y en el caso que hiciese falta se modificarían. Las piezas de las que consta este robot son las siguientes:

- [x] Base del robot
- [x] Punta de la patas (igual para ambas patas)
- [x] Hombro de la pata izquierda
- [x] Hombro de la pata derecha
- [ ] Caparazón
- [ ] (Opcional) Rueda loca trasera

---
## PRIMEROS PASOS DE MONTAJE

Para comenzar con el montaje, primero nos imprimimos las dos partes de una pata, en este caso imprimimos la derecha.
Una vez impresas las dos partes de la pata probamos a juntarlas con el micro servo. Sorprendentemente entro perfectamente, ya que el diseño que habian hecho en [LittleBots](https://www.instructables.com/Critter-3D-Printed-Crawling-Arduino-Robot/) funcionaba perfectamente (más adelante veremos que tuvimos que modificar una parte).

Una vez teníamos la primera pata unida, procedimos a intentar moverla con nuestra placa Arduino.
En este paso tuvimos algunos problemas, pero finalmente pudimos controlar el movimiento de la pata con un botón.

--

Antes de imprimir la segunda pata, probaremos que funciona la parte de unión a la base, ya que si por lo que sea no encajan, habria que modificar el diseño y de este modo nos ahorramos hacer las dos patas dos veces.
Y efectivamente nos encontramos con un leve fallo en el modelo. Lo que nos ocurrió es que el micro servo se nos quedaba un poco fuera del encajeque tiene, por lo que al intentar ponerle la corona al otro lado de la base para encajarlo todo, no engarzaban.

Para solucionarlo simplemente hicimos el hueco para el micro servo en el hombro de la pata un poco más profundo. No obstante también nos encontramos con otros problemas para encajar las piezas, pero no tanto por el diseño de estas sino por la impersión, y es que en especial con el hueco para la corona del micro servo en la parte baja de la base, no salieron del todo bien y tuvimos que lijar y moldear un poco la pieza para que entrase.
Otra opción habria sido poner un poco de silicona caliente para sellar la unión, pero como todavía estamos haciendo pruebas puede que tengamos que quitarlos.


Una vez hecho todo esto, finalmente podemos unir la pata a la base, por lo que procedimos a imprimir la segunda pata y montarla también. Llegados a este punto, tenemos la base del robot con las dos patas en teoría funcionales. El siguiente paso es calibrar los micro servos para que funcionen en el rango que necesitan, ya que son micro servos de 180º.


---
## CALIBRACIÓN

Como ya hemos dicho, llegados a este punto lo que tenemos que hacer es calibrar los micro servos. Esto se debe a que puede darse el caso de que por ejemplo tu montes el servo en una posición que tu quieres que sea su inicial (0º típicamente), pero a lo mejor el servo ya estaba puesto en sus 100º por ejemplo, por lo que el robot en ese caso sólo tendría un rango de trabajo de 80º (180-100).
Para ello el primer paso fue mandar a todos los servos la posición de 0º para asegurarnos que estaban en su posición inicial. Otra cosa a tener en cuenta fue saber en qué sentido giraban de manera positiva ya que por la distribución del robot, las patas son opuestas, es decir, estan como en modo espejo.
Para los servos de las puntas de las patas los pusimos a 90º ya que ese sería el estado en reposo, es decir, la pata recta. Ya que al ser micro servos de 180º, la posición 0 sería con la pata hacia abajo, la posición 90 sería la pata recta y la posición 180 sería la pata levantada (las posiciones 0 y 180 opuestas en la pata contraria por lo que hemos explicado anteriormente).
Una vez colocadas las patas en sus posiciones correctas, nos hicimos un [código](Code/Motor_calibrator/Motor_calibrator.ino) para que con dos botones, se fuese poniendo en los ángulos que queríamos, y viendo el comportamiento que hacían podíamos saber qué rango de actuación tenían.
De este modo obtuvimos que, los servos de la punta trabajaban de 0º a 180º (como era de esperar) y los micro servos de los hombros trabajaban entre 40º y 180º.

---
## COMPORTAMIENTOS

Una vez calibrado nuestro robot, para probar que el comportamiento era el esperado, hicimos un [código](Code/Walk/Walk.ino) para que el robot hiciese un comportamiento de avance, de manera que moviese los servos de la manera oportuna para que el robot andas hacia delante. Este paso, a nivel de programación fue bastante sencillo, sobre todo conociendo ya cómo se comportan nuestros motores. Llegados a este punto nos encontramos con un pequeño problema y es que, las piezas al ser de PLA, tenian poca fricción con el suelo (dependiendo del material y el terreno claro) y estas se resvalaban bastante. Como primera solución temporal probamos a ponerle una tira de cinta adesiva para que tuviese algo más de fricción, pero finalmente optamos por la opción que ofrecen [LittleBots](https://www.instructables.com/Critter-3D-Printed-Crawling-Arduino-Robot/) que es muy original. Simplemente consiste en poner un pequeño pegote de silicona caliente en la punta de la pata para que tenga más agarre y no se resbale. De este modo conseguimos un comportamiento de avance bastante óptimo.