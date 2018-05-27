/*
T04 - Ej16

16. Especifica e implementa un algoritmo recursivo que dado un vector v de enteros, que
viene dado en orden estrictamente creciente, determine si el vector contiene alguna
posición i que cumpla v[i] = i. Utilizando el método de despliegue de recurrencias,
*/

#include <iostream>
using namespace std;

bool coincidencia(int v[],int n, int i) {
	if (n == i) return false;
	else if (v[i] == i) return true;
	else return coincidencia(v, n, i+1);
}

int main() {
	int n, i=0;
	int v[10];

	cin >> n;
	while (i<10 && n>=0) {
		v[i] = n;
		cin >> n;
		i++;
	}
	cout << coincidencia(v, i, 0);
	system("pause");
	return 0;
}