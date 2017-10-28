#include <iostream>
#include <string>
using namespace std;

int resuelve() {
	int h, c,dif=1;
	cin >> h;
	cin >> c;

	if(h == 0 && c == 0) return 0;

	while (h > c) {
		h -= c;
		dif++;
	}
	cout << 10*dif << endl;

	return 1;
}

int main() {
	
	while (resuelve());

	return 0;
}