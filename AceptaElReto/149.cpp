#include <iostream>
using namespace std;

bool casoDePrueba() {
	int n, i = 0, tmp=0, t;
	cin >> n;
		if (!cin)
			return false;
		else {
			while (i < n) {
				cin >> t;
				if (tmp < t)tmp = t;
				i++;
			}
			cout << tmp << endl;
			return true;
		}
} 

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}