#include <iostream>

using namespace std;



void esMeseta(int v[], int n, int &ini, int &fin) {
	int i = 0;
	ini = 0;
	fin = 0;

	while (i < n) {
		int j = i;
		while (j + 1 < n && v[i] == v[j + 1]) {
			j++;

			if (j - i + 1 > fin - ini + 1) {
				ini = i;
				fin = j;
			}
			
		}
		i = j + 1;
	  }
	
}

bool resuelve() {

	int v[100000];
	int n = 0, p, r ;
	cin >> n;
	if (n == 0) return 0;
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		
		esMeseta(v, n, p, r);
		cout << p << " " << r << endl;
	}



	return 1;
}


int main() {

	while (resuelve());

	return 0;
}