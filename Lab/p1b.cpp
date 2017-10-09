

#include <iostream>
#include <cmath>

using namespace std;

// {b > 1 ∧ n > 0}
//fun log(int b, int n) return int r
// {b^r ≤ n < b^(r + 1)}

int log(int b, int n) {
	
	return (int)(log(n) / log(b));
}


void resuelve() {
	int b, n;

	
	cin >> b;
	cin >> n;

	int r = log(b, n);

	
	// escribir resultado
	cout << r << endl;
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i<n; ++i)
		resuelve();
	return 0;
	
}
