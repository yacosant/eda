#include <iostream>
#include <string>
using namespace std;

string resuelve() {
	string in,out;
	cin >> in;
	cin >> out;

	return "Hola, " + out+".";
}

int main() {
	int n, i = 0;

	cin >> n;
	while (i < n) {
		cout << resuelve() << endl;
		i++;
	}

	return 0;
}