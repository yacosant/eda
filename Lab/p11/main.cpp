#include <iostream>
#include <string>
#include "pila.h"
using namespace std;



bool esEquilibrada(const string& cadena) {
	// A IMPLEMENTAR
	Pila<char> p;
	int size = cadena.size();
	char c;
	for (int i = 0; i < size; i++) {
		c = cadena[i];

		if(c=='(' || c=='[' || c=='{') p.apila(c);

		if (c == ')' || c == ']' || c == '}') {
			// estalla si pila vacia
			if (p.esVacia()) return false;

			if (c == ']' && p.cima() == '[') p.desapila();
			else if (c == ')' && p.cima() == '(') p.desapila();
			else if (c == '}' && p.cima() == '{') p.desapila();
			else return false;
		}
	}

	return p.esVacia();
}


int main() {
	string cadena;
	while (getline(cin, cadena)) {
		if (esEquilibrada(cadena))
			cout << "EQUILIBRADA" << endl;
		else
			cout << "NO_EQUILIBRADA" << endl;
	}
	return 0;
}
