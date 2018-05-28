#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int tiempoAyuda(const Arbin<char>& falda, int dis) {
	int t = 0;

	if (falda.raiz() == 'X') t = 2 * dis;

	if (!falda.hijoIz().esVacio()) t += tiempoAyuda(falda.hijoIz(),dis+1);
	if (!falda.hijoDer().esVacio()) t += tiempoAyuda(falda.hijoDer(),dis+1);
	return t;
}

int tiempoAyuda(const Arbin<char>& falda) {
	// A IMPLEMENTAR
	return tiempoAyuda(falda, 0);
}

Arbin<char> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = leeArbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = leeArbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<char> falda;
	while (cin.peek() != EOF)  {
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}