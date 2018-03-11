#include <iostream>


using namespace std;


int diferentes(int v[], int n, int ini, int fin) {
	int m;
	if (v[ini] == v[fin]) return 1;
	else if (ini == fin - 1) return 2;
	else {
		m = (ini + fin) / 2;
		return diferentes(v, n, ini, m) + diferentes(v, n, m, fin) - 1;
	}

}

bool resuelve() {
	int v[1000];
	int n,ini =0;
	cin >> n;

	if (n == 0) return 0;
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
	}

	cout << diferentes(v, n,ini ,n-1) << endl;

	return 1;
}

int main() {
	 
	while (resuelve());
	
return 0;

}
