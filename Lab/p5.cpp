#include <iostream>

using namespace std;

// { 0 <= n <= long(v) }
// fun fib(int v[], int n) return int r
// { r = #i : 0<=i<n: v[i] = 0 }

int fib(int v[], int n) {
	int r = 2;
	int pen = 0, ult=1;
	int masLargo = 0;

	if (n < 2) {
		return n;
	}
	pen = v[0];
	ult = v[1];

	for (int k = 2; k<n; ++k) {
		
		if (v[k] == (pen + ult)){
			r++;
		}
		else{
			if (masLargo <= r)	masLargo = r;
				r = 2;
		}
		pen = ult;
		ult = v[k];

	}

	if (r > masLargo) return r;
	return masLargo;

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
	int num = fib(v, n);

	// Nota: en realidad en este problema no hace falta v, podemos
	// contar el número de ceros directamente leyendo número a número
	// de la entrada. Lo hago así porque el enunciado pide la especificación.

	// escribir resultado
	cout << num << endl;
	return true;
}

int main() {

	while (resuelve());
	
	return 0;
}
