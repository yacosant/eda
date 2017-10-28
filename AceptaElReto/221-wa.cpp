#include <iostream>
#include <string>
using namespace std;

int resuelve() {
	int tam, i = 0, cont = 0;
	bool find = false;
	int v[10000];
	cin >> tam;

	while (i < tam) {
		cin >> v[i];
	i++;
	}
	i = tam-1;

	while (0 <= i) {
		if(v[i] % 2 == 0)find = 1;
		else if (find) return -1;
		else cont++;
		i--;
	}
	if (cont == 0)return -1;
	return tam-cont;
}

int main() {
	int n, i = 0, r;

	cin >> n;

	while (i < n) {
		r = resuelve();
		if (r == -1) cout << "NO" << endl;
		else {
			cout << "SI " << r << endl;
		}
		
		i++;
	}

	return 0;
}