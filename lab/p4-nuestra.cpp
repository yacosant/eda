#include <iostream>

using namespace std;



void esMeseta(int v[], int n, int &p, int &r) {
	int p1 = 0, contA = 0, contB=0, ind=0, i=0;

	while (i<n-1)
	{
		if (v[i] == v[i + 1]) { // es meseta?

			//que cont usamos?
			if (ind == 0) {//A
				contA++;
			}
			else { //B
				contB++;
			}
		}
		else { //NO es meseta //reiniciamos cont menor
			if (contA > contB) {
				ind = 1;
				contB = 0;
				p1 = i+1;
			}
			else {
				ind = 0;
				contA = 0;
				p = i+1;
			}

		}
		i++;
	}

	if (contA > contB) r = p+ contA;
	else { 
		p = p1;
		r = p + contB;
	}
}

bool resuelve() {

	int v[100000];
	int n = 0, p =0, r =0;
	cin >> n;
	if (n == 0) return 0;
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		
		esMeseta(v, n, p, r);
		cout << p << " " << r << endl;
	}



	return 1;
}


int main() {

	while (resuelve());

	return 0;
}