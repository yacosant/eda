#include <iostream>

using namespace std;

int mirador(int v[], int n) {
	int  acumulado=v[0], i = 0;

	while (i<n-1){
		if (v[i] > v[i + 1]) acumulado += v[i+1];
		else acumulado = v[i+1];
		i++;
	}

	return acumulado;
}

bool resuelve() {
	int n;
	int v[100000];

	cin >> n;
	if (n == 0)return 0;

	for (int i = 0; i < n; i++) cin >> v[i];

	cout << mirador(v, n) << endl;

	return 1;
}

int main() {

	while (resuelve());

	return 0;
}