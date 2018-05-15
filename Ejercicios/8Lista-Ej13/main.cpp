#include "dcola.h"
#include <iostream>
#include <string>
using namespace std;

/*
13. Se dice que una frase es palíndroma si la sucesión de caracteres obtenida al recorrerla de izquierda a derecha es la misma que si se recorre de derecha a izquierda 
(asumiendo que la sucesión no tendrá tildes y todo serán o bien letras o bien espacios). 
Esto sucede, por ejemplo, con la socorrida frase dábale arroz a la zorra el abad si ignoramos la tilde de la primera palabra y los espacios en blanco. 
Implementa un subprograma iterativo de coste lineal en tiempo que decida si una frase leída de teclado es o no palíndroma. En tu solución debes utilizar TADs auxiliares, en concreto una doble cola.
*/

//dabale arroz a la zorra el abad

bool procesa(string in) {
	int size = in.size(), i = 0;
	DCola<char> cola = DCola<char>();
	bool ok = true;

	//Rellenar DobleCola
	while (i < size) {
		if (in[i] != ' ') cola.pon_final(in[i]);
		i++;
	}

	//Comprueba si es palindroma
	while (ok && !cola.esVacia()) {
		ok = (cola.primero() == cola.ultimo());
		cola.quita_final();
		if(!cola.esVacia()) cola.quita_ppio();
	}

	return ok;
}

int main() {
	string in;
	cout << "Introduce la frase para comprobar si es palindroma. (0 para salir)";
	getline(cin, in);
	cout << endl;

	if (in != "0") {
		if (procesa(in)) cout << "SI es PALINDROMA" << endl;
		else cout << "NO es palindroma" << endl;
	}

	cin >> in;
	
	return 0;
}
