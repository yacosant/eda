#include <iostream>
using namespace std;

void resolver(int n) {
	int v[10];
	int i=0, tmp;
	int moda = 0, max;

	for (int i = 0; i < 10; i++)v[i] = 0;

	while (i < n) {
		cin >> tmp;
		v[tmp-1]++;
		i++;
	}

	for (int i = 0; i < 10; i++) {
		if (moda < v[i]) {
			moda = v[i];
			max = i;
		}
	}
	cout << max + 1 << endl;

} 

int main(){
	int n;
	cin >> n;
	while (n != 0) {
		resolver(n);
	}
	
	return 0;
}