# aedi-tp
TPI del grupo 1, comision 3 de "Algoritmos y Estructuras de Datos I" (FCEyN)

### Integrantes:

* Freire, Guido   978/21  gfreire@dc.uba.ar

* Hernandez, Agustin  37/20   ahernandez@dc.uba.ar

* Machulsky, Joaquin  521/21  jmachulsky@dc.uba.ar

---

## Notas al corrector

### Auxiliares
* **indiceMenorigual** es la columna vertebral de la resolucion del TP. Dado un "e" y un vector "v", devuelve un indice "i" (de v) tal que todos los elementos anteriores a i son menores o iguales a e y todos los siguientes son estrictamente mayores. Esto se hace por busqueda binaria, lo que significa que indiceMenorigual tiene una doble funcion: permite saber si un elemento pertenece o no a una lista y a su vez donde se deberia insertar para que el vector resultante siga estando ordenado.

    En algun momento nuestra resolucion del tp incluyo este comportamiento en dos funciones separadas: insertarOrdenado y perteneceBinario, aunarlas significa una mejora de rendimiento considerable.

### Ejercicios
* **esEncuestaValida** separa algunos requerimientos en varios ifs en vez de encadenarlos en una sola guarda, esto es para mejorar que sea lo mas fiel posible a su especificacion.

* **generarJoin** ordena th segun HOGCODUSU antes de aparear hogares con individuos - se podria crear una copia ordenada en menor complejidad algoritmica, pero esto aumentaria la complejidad de la resolucion innecesariamente.

* **muestraHomogenea** utilizamos una matriz que describe las diferencias de ingresos entre 2 elementos cualquiera con la intencion de aplicar los conocimientos sobre matrices que adquirimos en la practica 11 y el laboratorio 7.

### Miscelaneas
* En "Funciones_TPI.h" se anadio la linea 7 que incluye la libreria "algorithm", de no hacerlo no compilaban los tests ya que utilizan sort().

* main2.cpp utiliza el graficador de complejidad provisto por la catedra (graficar.py), el archivo esta totalmente desvinculado del resto (a menos que se lo añada en CMakeLists.txt).

## Posibles mejoras

Los ejercicios de este TP conciernen la manipulacion de secuencias, la mayoria de ellos implican ordenarlas de una forma u otra. Bajo esta idea se podria generalizar gran parte del trabajo algoritmico abstrayendo tipos y criterios de comparacion. Investigar objetos funcion y experimentar (ver: branch lambda).