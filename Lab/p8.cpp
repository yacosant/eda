/*
* Contar el número de ceros de un vector. La entrada termina con
* un marcador.
*
* Antonio Sánchez Ruiz-Granados
*/

#include <iostream>

using namespace std;

// { 0 <= n <= long(v) }
// fun pares(int v[], int n) return int r
// { r = #i : 0<=i<n: v[i] = 0 }

int picos(int v[], int ini, int fin) {
	int a;
	int b;
	
	if (fin== ini) {
		/*if (v[ini] <= v[fin]) return fin;
		else return ini;*/
		return ini;
	}

	a = picos(v, ini, ((ini + fin)/ 2)-1);
	b = picos(v, ((ini + fin) / 2)+1, fin);

	if (v[a] <= v[b]) return b;
	else return a;
}


bool resuelve() {
	// Leer tamaño del vector
	int n;
	cin >> n;
	if (n == 0)
		return false;

	// Leer elementos del vector
	int v[100000];
	for (int i = 0; i<n; ++i)
		cin >> v[i];

	// Contar ceros
	int pico = picos(v, 0, n-1);

	// Nota: en realidad en este problema no hace falta v, podemos
	// contar el número de ceros directamente leyendo número a número
	// de la entrada. Lo hago así porque el enunciado pide la especificación.

	// escribir resultado
	cout << pico << endl;
	return true;
}

int main() {

	while (resuelve());

	return 0;
}
