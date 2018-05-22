#include <iostream>
using namespace std;

/*
16. Definición: Dado V[N] de enteros, el índice i es un pico si V[i] es el mayor elemento
de V[0..i].
Especifica y deriva un algoritmo de coste lineal que reciba un vector y calcule la suma
de todos los valores almacenados en los picos de V.
*/
int const N = 3;

int picos(int X[N]){
	int i=1, max=X[0], s = X[0];

	while (i < N) {
		if (max < X[i]) {
			max = X[i];
			s += max;
		}
		i++;
	}
	return s;
}

int main() {
	int i = 0;
	int V[N];
	cout << "Introduce los " << N << "valores (int) del vector:" << endl;
	while (i < N) {
		cout << "-" << i + 1 << ":";
		cin >> V[i];
		i++;
	}
	cout << "+ Suma de buenos: " << sumaBuenos(V)<<endl;
	system("pause");
	return 0;
}