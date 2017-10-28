#include <iostream>
#include <string>
using namespace std;

int resuelve() {
	int n, i = 0, cont=0, tmp;

	cin >> n;
	//cout << endl;

	while (i<n) {
		cin >> tmp;
		if (tmp % 2 == 0) cont++;
		i++;
	}
	
	return cont;
}

int main() {
	int n, i = 0;

	cin >> n;

	while (i < n) {
		cout<< resuelve()<< endl;
		i++;
	}

	return 0;
}