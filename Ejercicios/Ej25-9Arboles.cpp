/*
Dado un árbol binario, en cuya raíz se encuentra situado un tesoro y cuyos nodos internos pueden contener un dragón o no contener nada, 
se pide diseñar un algoritmo que nos indique la hoja del árbol cuyo camino hasta la raíz tenga el menor número de dragones. 
En caso de que existan varios caminos con el mismo número de dragones, el algoritmo devolverá el que se encuentre más a la izquierda de todos ellos. 
Para ello implementar una función que reciba un árbol binario cuyos nodos almacenan cadenas de caracteres:
• La raíz tiene la cadena Tesoro
• Los nodos internos tienen la cadena Dragón para indicar que en el nodo hay un dragón o la cadena Vía libre para indicar que no hay dragón.
• En cada hoja se almacena un identificador que no puede estar repetido.
La función debe devolver el identificador de la hoja del camino seleccionado. El árbol tiene como mínimo un nodo raíz y un nodo hoja diferente de la raíz. 
La operación no se implementa como parte de ningún TAD.
El coste de la operación implementada debe ser O(n).
Por ejemplo, dado el siguiente árbol el algoritmo devolverá la cadena de caracteres Puerta falsa.
*/

