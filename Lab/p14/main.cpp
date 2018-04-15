#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int caudales(const Arbin<int>& cuenca, int &navegables, string pref){
	if (cuenca.esVacio()) return 0;
//	cout << pref << cuenca.raiz() << " " << &cuenca;
	int n = 0;
	if (cuenca.hijoIz().esVacio() && cuenca.hijoDer().esVacio()) return 1;//hoja 

	else{
		 n = caudales(cuenca.hijoIz(),navegables, pref + "  ");
		 n += caudales(cuenca.hijoDer(), navegables, pref + "  ");

		if (cuenca.raiz() < 0) n += cuenca.raiz();
	}
	if (n >= 3){
		navegables++;
	}
	if (n < 0) n = 0;
	return n;
}


int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	int navegables = 0;
	int a=caudales(cuenca, navegables, "\n");
	if (a >= 3) navegables--;
	return navegables;
}


Arbin<int> leeArbol(istream& in) {
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
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF)  {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}