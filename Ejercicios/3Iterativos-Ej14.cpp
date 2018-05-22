#include <iostream>
using namespace std;

/*
14. Deriva un algoritmo que satisfaga la siguiente especificación:
{N >0} fun pares(int V[N]) return int x
{x = (#i : 0 =< i < N : V [i]mod 2 = 0)}
*/
int const N = 3;

int pares(int V[N]){
	int x=0, i=0;

	while (i < N) {
		if (V[i] % 2 == 0) x++;
		i++;
	}
	return x;
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
	cout << "+ Numero de pares en el vector: " << pares(V)<<endl;
	system("pause");
	return 0;
}