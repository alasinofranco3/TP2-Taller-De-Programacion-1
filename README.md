# TP2
TP2 taller de programacion 1

* Alumno: Alasino Franco
* Padron: 102165
* URL: https://github.com/alasinofranco3/TP2

## Descripcion de la resolucion del trabajo:
Para este trabajo decidi comenzar por el disenio y programacion de los "contenedores" (ProtectedCounter,CharBlockingQueue y BlockingInventory).La implementacion de los primeros dos no me genero muchas dificultades ya que el contador de puntos es bastante simple (cuenta con un contador y un mutex) y en clase habiamos visto las mayores dificultades de la cola bloqueante y como resolverlas.Creo que uno de los principales problemas lo tuve a la hora de implementar el inventario,en especial, cuando y como  este debia cerrarse, porque no era como el caso de la cola bloqueante en donde una vez que el parser del mapa terminaba su trabajo la cerraba y listo ,sino que este debia saber por si mismo cuando cerrarse teniendo en cuenta si los multiples recolectores habian terminado o no su tarea.Para resolver este problema decidi crear un atributo en el inventario (gahtererStates) que guardase referencias a los estados de trabajo de cada uno de los recolectores creados ,asi el mismo inventario podria verificar si todos ellos habian terminado de trabajar o no y saber cuando cerrarse.
Los 3 contenedores son monitores,por lo tanto ,pueden ser utilizados por varios hilos correctamente sabiendo que no habra hilos que accedan a estos recursos simultaneamente.

Luego continue con la implementacion de los parser de los archivos,uno que se encargara de llenar las colas con recursos y otro cuya tarea fuese ir creando los "personajes" indicados en el archivo.
Para el parser del mapa no tuve mayores complicaciones, voy leyendo el archivo caracter a caracter y se pushea el recurso a la cola correspondiente.Cabe aclarar que el MapParser guarda referencias a las colas de almacenamiento de recursos.Una vez terminado el archivo, cierra las colas para indicarle a los recolectores que ya no hay mas materias primas para utilizar.
Por otro lado,en el parser del archivo de trabajadores (WorkersParser) se hace algo parecido: se va leyendo el archivo linea por linea y se van creando y lanzando los hilos de cada uno de los trabajadores.Finalmente, cada hilo es agregado a un vector para al final del programa, poder hacer un join de todos estos.

Finalmente implemente los trabajadores.Como cada uno debia realizar su tarea en un hilo distinto claramente cada uno de ellos iba heredar de la clase Thread.En esta clase Thread tenemos un metodo start que comienza la ejecucion del hilo con el metodo run,que es un metodo abstracto puro permitiendo asi que cada trabajador sobreescriba este metodo,un claro ejemplo de polimorfismo.En este metodo run cada trabajador obtiene recursos de su contenedor asociado,trabaja con estos recursos y luego deposita el resultado donde corresponde.Las relaciones entre estas clases se podran ver en la seccion de diagramas donde adjunto imagenes que las clarifican.

La dificultad mas grande que tuve en este trabajo fue el de la sincronizacion a la hora de sacar recursos del inventario(metodo take).Con mi implementacion inicial me encontraba con que a veces cuando corria mi programa este se quedaba colgado y a veces devolvia los resultados esperados,esto tambien dependia de si utilizaba valgrind o no.Este problema se producia ya que cuando chequeaba si debia cerrar el archivo solo notificaba en caso de que efectivamente debiera cerrarse.Se soluciono,notificando a los hilos en espera al final del metodo shouldClose del inventario.

## Diagramas:
![diagrama_trabajadores_tp2](https://user-images.githubusercontent.com/50004705/82240127-471f9500-9910-11ea-8662-10253fe4a83d.png)

* Diagrama de clases que muestra las relaciones entre la clase Thread y los trabajadores.

![diagrama_prod_rec_tp2](https://user-images.githubusercontent.com/50004705/82240133-48e95880-9910-11ea-9071-2b42dd441c7f.png)

* Diagrama de clases que muestra los componentes mas importante de la clase Productor y Recolector.

## Aclaraciones:

* Como codigo de error se respeto el designado en el enunciado,se utilizo el 1 para errores de apertura lectura o parseo de archivo.Ademas, se utilizo 0 en caso de exito y agregue un codigo CLOSED ,cuyo valor es 2,que se devuelve en caso de que algun contenedor (el inventario o alguna cola) se encuentre cerrado.

* Los atributos de las clases Productor y Recolector son protegidos asi las clases hijas pueden acceder a estos,en el resto de los casos los atributos son privados para porteger el estado del objeto.
