
/**
Este programa lee �rboles de la entrada est�ndar,
codificados de acuerdo con las siguientes reglas:
(1) El �rbol vac�o se codifica como #
(2) Los �rboles simples se codifican como [v], con
v el valor del nodo
(3) Los �rboles complejos se codifican como (IvD),
con I la codificaci�n del hijo izquierdo,
v el valor de la ra�z, y D la codificaci�n
del hijo derecho.
Para cada �rbol le�do, escribe en la salida est�ndar
el n�mero de nodos singulares de dicho �rbol.

Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

-El primero representa el �rbol vac�o. Al no tener nodos,
un �rbol vac�o tiene 0 nodos sigulares.
-El segundo representa un �rbol con un �nico nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0.
-El tercero representa otro �rbol con un �nico nodo, cuyo
valor es 5. Por la misma raz�n que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente �rbol:

1
/  \
3  -4
/ \
4  -3

Este �rbol tiene 2 nodos sigulares: la ra�z, y la ra�z del hijo
izquierdo.

Por tanto, la salida del programa para estos casos ser�:

0
1
1
2

*/
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/**
COMPLEJIDAD: 
La complejidad es lineal en funcion del numero de nodos.
Es decir, O(n);
*/

	//Funcion auxiliar
int aux_singulares(Arbin<int> a, int ac, int &n) {

	if (a.esVacio()) return 0;

	int hijos =	aux_singulares(a.hijoIz(), ac + a.raiz(), n) +
		aux_singulares(a.hijoDer(), ac + a.raiz(), n);

	if (ac == hijos) n++;

	return hijos + a.raiz();
}

unsigned int numero_singulares(Arbin<int> a) {
	// A IMPLEMENTAR
	int n = 0;
	if(!a.esVacio())aux_singulares(a, 0, n);
	return n;
}



Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
