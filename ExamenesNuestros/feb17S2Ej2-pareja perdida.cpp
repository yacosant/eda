#include <iostream>

using namespace std;


int parejaPerdida(int v[], int ini, int fin) {

	if (v[ini] == v[fin]) return ini; 
	else if (v[ini] == v[ini + 1]) return parejaPerdida(v, ini + 2, fin);
	else return ini;

}


void resuelve() {
	int n, ini =0;
	int v[100000];
	cin >> n;

	for ( int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout <<  parejaPerdida(v,ini, n-1) << endl;

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelve();
	}
	
	return 0;
}