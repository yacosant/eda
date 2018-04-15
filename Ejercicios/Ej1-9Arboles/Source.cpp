/*
*Ejercicio 1:
*/


#include "Arbin.h"
#include <iostream>
#include <queue>
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

void mostrarFrontera(queue<int> s) {
	while (!s.empty())
	{
		cout << s.front() << " ";
		s.pop();
	}
	cout << endl;
}

int main() {
	Arbin <int> raiz=	construir();
	int n;
	queue<int> s;
	//cout<< raiz.numNodos()<<endl;
	//cout << ""; 
	
	//raiz.frontera(s);
	//mostrarFrontera(s);
	
	cout<< raiz.minElem();

	return 0;
}
