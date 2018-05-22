#include <iostream>
using namespace std;

/*
15. Deriva un algoritmo que satisfaga la siguiente especificación:
{N >0} fun suma-buenos(int X[N]) return int s
{s = ([SUMATORIO]i : 0  i < N ^ bueno(i,X) : X[i])}
donde bueno(i,X) = (X[i] = 2i). No se pueden emplear operaciones que calculen
potencias.
*/
int const N = 3;

int sumaBuenos(int X[N]){
	int s=0, i=0, p=1;

	while (i < N) {
		if (p == X[i]) s+=X[i];
		i++;
		p *= 2;
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