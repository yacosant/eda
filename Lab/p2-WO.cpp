#include <iostream>

using namespace std;


// { 0 < n <= long(v) }
// fun miradores ( int v[], int n) //return suma; 
// { suma = : k < i < n : v[i]< max }

int miradores(int v[], int n) {
	int suma = 0, max = 0, i = 0;
	//I = {0<i<=n}
	//cota= n	
	while (i < n) {
		if (max <= v[i]) {
			max = v[i];
			suma = max;
		}
		else suma += v[i];

		i++;
	}
	return suma;
}


bool resuelve() {
	// Leer tama�o del vector
	int n, r;
	cin >> n;
	if (n == 0)
		return false;

	// Leer elementos del vector
	int v[100000];
	for (int i = 0; i<n; ++i)
		cin >> v[i];

	r = miradores(v, n);
	// escribir resultado
	cout << r << endl;
	return true;
}

int main() {

	while (resuelve());

	return 0;
}
