
#include <iostream>
#include <string>

using namespace std;

// { 0 <= n <= long(v) }
// fun pares(int v[], int n) return int r
// { r = #i : 0<=i<n: v[i] = 0 }

string sube(int v[], int n) {
	string r = "SI";
	int anterior =0;
	int k = 0;
	bool acabado = false;
	while ( k<n && !acabado) {
		if (v[k] <= anterior) acabado = true;
		anterior = v[k];
		k++;
	}
	if (acabado) r = "NO";

	return r;
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
	string sol = sube(v, n);

	// Nota: en realidad en este problema no hace falta v, podemos
	// contar el número de ceros directamente leyendo número a número
	// de la entrada. Lo hago así porque el enunciado pide la especificación.

	// escribir resultado
	cout << sol << endl;
	return true;
}

int main() {

	while (resuelve());

	return 0;
}
