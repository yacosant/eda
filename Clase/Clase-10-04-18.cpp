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
*Un �rbol binario es homog�neo cuando todos los nodos interiores tienen dos
hijos no vac�os. Escribe una funci�n que determine cu�ndo un �rbol es
homog�neo.
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
*Un �rbol binario es degenerado cuando cada nodo tiene, a lo sumo, un hijo
izquierdo o un hijo derecho. Implementa una funci�n que determine si un �rbol
es degenerado. Implementa una versi�n recursiva y otra iterativa de dicha
funci�n.
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
*Dado un �rbol binario de enteros:
	I. Escribe una funci�n que determine si existe un camino desde la ra�z
		hasta una hoja cuyos nodos sumen un valor dado como par�metro.
	II. Escribe una funci�n que determine el n�mero de caminos desde la ra�z
	hasta las hojas tales que sus nodos suman un valor dado como par�metro.
*/

bool caminoSuma(const Arbin<T> &a, int suma) {
	if (a.esVacio()) return false;
	return 
}

int numCaminos(const Arbin<T> &a, int suma) {
	return n;
}
