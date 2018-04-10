/*
*Ejercicio 2
*Implementa las mismas operaciones del ejercicio anterior pero como funciones externas al TAD.
*/
arbin<T> espejo(const Arbin<T> &a) {
	if (a.esVacio()) return a;
	//opcion2:
	//if (a.esVacio())return Arbin<t>
	else Arbin <T>(espejo(a.hijoDer()), a.raiz(), espejo(a.hijoIz()));
}

/*
*Ejercicio 5:
*
*Un árbol binario es homogéneo cuando todos los nodos interiores tienen dos
hijos no vacíos. Escribe una función que determine cuándo un árbol es
homogéneo.
*/

bool esHomogeneo(const Arbin<T> &a) {
	return a.esVacio() //es vacio
		|| 
			a.hijoIz().esVacio() && a.hijoDer().esVacio() //es una hoja
		||
			!a.hijoIz().esVacio() && !a.hijoDer().esVacio() //es un nodo interior
			&& esHomogeneo(a.hijoIz()) && esHomogeneo(a.hijoDer());
		 
}

/*
*Ejercicio 6:
*
*Un árbol binario es degenerado cuando cada nodo tiene, a lo sumo, un hijo
izquierdo o un hijo derecho. Implementa una función que determine si un árbol
es degenerado. Implementa una versión recursiva y otra iterativa de dicha
función.
*/

//yaco
bool esDegenerado(const Arbin<T> &a) { //recursiva
	return !(a.hijoIz().esVacio() && a.hijoDr().esVacio()) && esDegenerado(a.hijoIz()) && esDegenerado(a.hijoDr());
}

//solucion BUENA
bool esDegeneradoRec(const Arbin<T> &a) { //recursiva
	return a.esVacio() //es arbol vacio
		||
		a.hijoIz().esVacio() && esDegeneradoRec(a.hijoDer()) //no tiene hijo izquierdo
		||
		a.hijoDer().esVacio() && esDegenerado(a.hijoIz())
}

/*
*Ejercicio 8:
*
*Dado un árbol binario de enteros:
	I. Escribe una función que determine si existe un camino desde la raíz
		hasta una hoja cuyos nodos sumen un valor dado como parámetro.
	II. Escribe una función que determine el número de caminos desde la raíz
	hasta las hojas tales que sus nodos suman un valor dado como parámetro.
*/

bool caminoSuma(const Arbin<T> &a, int suma) {
	if (a.esVacio()) return false;
	return 
}

int numCaminos(const Arbin<T> &a, int suma) {
	return n;
}
