/*
*Ejercicio 8:
*
*Dado un árbol binario de enteros:
I. Escribe una función que determine si existe un camino desde la raíz
hasta una hoja cuyos nodos sumen un valor dado como parámetro.
II. Escribe una función que determine el número de caminos desde la raíz
hasta las hojas tales que sus nodos suman un valor dado como parámetro.

YACO & CARMEN
*/


#include "Arbin.h"
#include <iostream>
using namespace std;

Arbin<int> construir() {
	Arbin <int> raiz;
	/*
	Arbol que genero:
	*			[5]
		[3]				[6]	
							[7]
	*/
	raiz = Arbin <int>(Arbin <int>(3), 5, Arbin <int>(Arbin <int>(), 6, Arbin <int>(Arbin <int>(), 7, Arbin <int>())));
	return raiz;
}

bool caminoSuma(const Arbin<int> &a, int suma) {
	//FUNCIONA
	if (a.esVacio()) return false;
	else if (suma-a.raiz() == 0 && a.hijoIz().esVacio() && a.hijoDer().esVacio()) return true;
	else  return caminoSuma(a.hijoIz(), suma - a.raiz()) || caminoSuma(a.hijoDer(), suma - a.raiz());
	/*
	Con el arbol que genero:
	TRUE A: 8 (que es 5+3) y a 18 (que es 5+6+7)
	FALSE A Todo lo demas 
	*/
}


int numCaminos(const Arbin<int> &a, int suma) {
	//FUNCIONA
	if (a.esVacio()) return 0;
	else if (suma - a.raiz() == 0 && a.hijoIz().esVacio() && a.hijoDer().esVacio()) return 1;
	else  return numCaminos(a.hijoIz(), suma - a.raiz()) + numCaminos(a.hijoDer(), suma - a.raiz());
	/*
	Con el arbol que genero:
	1 A: 8 y a 18 
	0 A Todo lo demas
	*/
}

int main() {
	Arbin <int> raiz=	construir();
	int n;
	cout<< raiz.numNodos()<<endl;
	do {
		cin >> n;
		//cout << caminoSuma(raiz, n) << endl; para elegir una u otra funcion a probar.
		cout << numCaminos(raiz, n) << endl;
	} while (n != 0);
	return 0;
}
