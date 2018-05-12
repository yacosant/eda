#include "pila.h"
#include <iostream>
#include <string>
using namespace std;
/*
Implementa un subprograma que reciba una pila y escriba todos sus elementos,
desde la base hasta la cima, separados por espacios. Haz dos versiones, una
versión recursiva y otra iterativa.
Haz una tercera versión, implementando la funcionalidad como parte del TAD
Pila soportado por lista enlazada.
*/

//Version 1: Iterativa
void recorre1(Pila<T> p) {
	Pila<T> aux;
	while (!p.esVacia()) {
		aux.apila(p.cima());
		p.desapila();
	}

	while (!aux.esVacia()) {
		cout << aux.cima << " ";
		aux.desapila();
	}
}

//Version 2: Recursiva

T recorre2(Pila<T> p) {
	T aux;
	if (!p.esVacia()) {
		aux = p.cima();
		p.desapila();
		recorre2(p);
		cout <<aux <<" ";
	}
}

//Version 3: Como si se integrase en el TAD Lista enlazada
void recorre3() {
	//Falto de ideas
}
