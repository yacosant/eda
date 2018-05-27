/*
T04 - Ej4

4. Implementa una función recursiva simple cuadrado que calcule el cuadrado de un
número natural n, basándote en el siguiente análisis de casos:
Caso directo: Si n = 0, entonces n2 = 0
Caso recursivo: Si n > 0, entonces n2 = (n − 1)^2 + 2*(n − 1) + 1
*/

#include <iostream>

using namespace std;

int potencia(int n) {
	if (n == 0) return 0;
	else return potencia(n - 1) + 2 * (n - 1) + 1;
}

int main() {
	int n;
	cin >> n;
	while (n > 0) {
		cout << "El cuadrado de " << n << " es: " << potencia(n) << endl;
		cin >> n;
	}
	return 0;
}