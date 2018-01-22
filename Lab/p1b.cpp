#include <iostream>

using namespace std;


int log(int b, int n) {
	int ac = 1, i = 0;

	while (ac<=n) {
		ac *= b;
		i++;
	}

	return i - 1;
}



void resuelve() {

	int b, n ;

	cin >> b;
	cin >> n;

	cout<< log(b,n)<<endl;
}




int main() {

	int r = 0;
	cin >> r;
	for ( int i =0; i < r; i++){
		resuelve();
	}

	return 0;
}