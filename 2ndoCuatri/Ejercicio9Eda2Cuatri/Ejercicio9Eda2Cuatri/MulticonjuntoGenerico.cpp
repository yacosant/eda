#include "MulticonjuntoGenerico.h"
#include <iostream>
#include <string>

using namespace std;



int main() {
	MulticonjuntoGenerico<int> c; //creo el multiconjunto de tipo int

	if (c.esVacio()) cout << "El multiconjunto está vacío" << endl;
	
	try {
		c.añadirElem(3); 
		cout << "HEmos metido el 3" << endl;
	}
	catch (const char* &cadena) {
		cout << cadena << endl;
	}

	return 0;

}