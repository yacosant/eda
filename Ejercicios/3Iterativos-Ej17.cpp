#include <iostream>
using namespace std;

/*
17. Dado un vector de enteros X[N], el índice se llama ”heroico” si X[i] es estrictamente
mayor que el i-ésimo número de la sucesión de Fibonacci. Especifica y deriva un
algoritmo de coste lineal que reciba como argumento un vector y determine cuántos
índices heroicos tiene.
*/
int const N = 3;

int heroico(int X[N]){
	int fib1 = 1, fib2 = 1, i=0, act=1, s=0;

	while (i < N) {
		if (act < X[i]) s++;
		act = fib1 + fib2;
		fib1 = fib2;
		fib2 = act;
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
	cout << "+ Suma de picos: " << heroico(V)<<endl;
	system("pause");
	return 0;
}