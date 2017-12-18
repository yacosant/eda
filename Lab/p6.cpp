/*
* Para cada numero de la entrada se debe escribir el correspondiente n´umero en base 6.
*
*/

#include <iostream>

using namespace std;

int recursiva(int n) {
	int d=0, r = 0;
	if ((n/6)==0) return n%6;
	else{
		r = n % 6;
		d = recursiva(n / 6);
	}
	return d*10+r;
}


void resuelve() {
	
	int n;
	cin >> n;
	int base6 = recursiva(n);

	// escribir resultado
	cout << base6 << endl;
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i<n; ++i)
		resuelve();

	return 0;
}
