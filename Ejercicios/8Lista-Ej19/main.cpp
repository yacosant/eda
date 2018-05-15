#include "lista.h"
#include <iostream>
#include <string>
using namespace std;
/*
[Examen 2º parcial, junio 2015] Extiende el TAD Lista visto en clase con una nueva operación que modifique la lista intercalando sus nodos de la siguiente forma: 
supongamos que los nodos de la lista enlazada de izquierda a derecha son n1; n2; n3; n4; ... ; nk-3; nk-2; nk-1; nk , 
al finalizar la ejecución del método los nodos estarán colocados como n1; nk; n2; nk-1; n3; nk-2; n4; nk-3; n5; ....
Indica la complejidad de tu implementación. Esta debe ser lo más eficiente posible. Para ello, se debe evitar liberar y reservar memoria,
y hacer copias de los campos. Si haces uso de métodos auxiliares, impleméntalos también.
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
	i = 0;
	cout << "---Reordenando..." <<  endl;

	li.reordenar();

	Lista<int>::ConstIterator init = li.cbegin();
	Lista<int>::ConstIterator fin = li.cend();

	while (init != fin) {
		cout << init.elem() <<endl;
		init.next();
	}

	cin >> n;
	
	return 0;
}
