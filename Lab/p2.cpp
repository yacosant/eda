#include <iostream>

using namespace std;

/*
P={0<n && r=0 && p=0}
Q={r=(#i forall i: 1<=i<n : v[i-1]%2==0 && v[i+1]%2 ==0) && p=(#j forall j: 1<=j<n : v[j-1]%2==1 && v[j+1]%2 ==1)}


*/
void interpar(int v[], int n, int &r, int &p) {

	int i = 1;
	while (i < n - 1) {

		if (v[i - 1] % 2 == 0 && v[i + 1] % 2 == 0) {
			r++;
		}
		else if (v[i - 1] % 2 != 0 && v[i + 1] % 2 != 0) {
			p++;
		}
		
		i++;
	}

}

bool resuelve() {

	int n,r=0,p=0;
	int v[10000];
	cin >> n;
	if (n == 0) return 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}


	interpar(v, n, r, p);

	cout << r << " " << p << endl;
		return true;

}






int main() {

	while (resuelve());

	return 0;
}