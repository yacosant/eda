#include "lista.h"
#include <iostream>
#include <string>
using namespace std;

/*
[Examen 2º parcial, junio 2014] Extiende el TAD Lista visto en clase con una nueva operación cuya cabecera en C++ es:
void insertarPorPosicion(const T &elem, int pos);
que inserta el elemento elem de acuerdo con la posición pos (operación pon_ppio) de forma que cuando pos es 0 se añade al principio de la lista,
mientras que cuando es igual al número de elementos de la lista se insertará detrás del último (operación pon_final).
Indica la complejidad de la operación. Si llamas a otros métodos, debes implementarlos también.
*/

int main() {
	Lista<int> li = Lista<int>();
	int n, i=0, num;
	cout << "Introduce el numero de elementos y seguidamente los elementos: ";
	cin >> n;
	cout << endl;

	while (i < n) {
		cin >> num;
		li.pon_final(num);
		cout << endl;
		i++;
	}

	cout << "elemento a introducir: ";
	cin >> num;
	cout << "Posicion a insertar: ";
	cin >> i;
	cout << "---Reordenando..." <<  endl;

	li.insertarPorPosicion(num,i);

	i = 0;
	Lista<int>::ConstIterator init = li.cbegin();
	Lista<int>::ConstIterator fin = li.cend();

	while (init != fin) {
		cout << init.elem() <<endl;
		init.next();
	}

	cin >> n;
	
	return 0;
}
