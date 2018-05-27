/*
T04 - Ej16

16. Especifica e implementa un algoritmo recursivo que dado un vector v de enteros, que
viene dado en orden estrictamente creciente, determine si el vector contiene alguna
posición i que cumpla v[i] = i. Utilizando el método de despliegue de recurrencias,
*/

#include <iostream>
using namespace std;

void mesetas(int v[], int n, int &q, int& r) {
	int i = n - 1, max = 0;
	while (i > 0) {
		if (v[i - 1] == v[i]) {
			max++;
		}
		else {
			if (max >= r) {
				r = max;
				q = i;
				max = 0;
			}
		}
		i--;
	}
	if (r == 0) q = 0;
}

bool resolver() {
	int v[100];
	int n, in;
	int q = 0, r = 0;
	cin >> n;
	if (n == 0) return false;

	for (int i = 0; i < n; i++) {
		cin >> in;
		v[i] = in;
	}
	mesetas(v, n, q, r);
	cout << q<<" "<<q+r << endl;
	return true;
}

int main() {
	while (resolver());
	return 0;
}