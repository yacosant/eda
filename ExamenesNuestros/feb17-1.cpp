#include <iostream>

using namespace std;

void swap(int v[], int a, int b) {
	int tmp=v[a];
	v[a] = v[b];
	v[b] = tmp;
}

void reOrdenar(int v[], int n, int &m) {
	int i = 0, j = n - 1;

	while (i <= j) {

		while (i < j && v[i] >= 0 ) i++;
		while (i < j && v[j] <0) j--;

		swap(v,i, j);
		
		
		i++;
		j--;
	}
	m = i; //FALLA ESTO!

}

void resuelve() {

	int v[100000];
	int n = 0, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	reOrdenar(v, n, m);
	cout << m << endl;

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
}



int main() {
	int n, i=0;
	cin >> n;
	while (i < n) {
		resuelve();
		i++;
	}
	system("pause");
	return 0;
}