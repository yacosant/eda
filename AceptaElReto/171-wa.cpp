#include <iostream>
using namespace std;

void resolver(int n) {
	int i = 0, tmp, max = 0, cont = 0, pos=n-1;
	int v[10000];

	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = n - 1; 0 <= i; i--) {
		if (max < v[i]) {
			max = v[i];
			pos = i;
		}
		 
	}

	/*while (i < n) {
		cin >> tmp;
		if (max < tmp) {
			max = tmp;
			cont = 0;
		}
		else cont++;
		
		i++;
	}
	*/
	cout << (n-pos)-1 << endl;

} 

int main(){
	int n;
	cin >> n;
	while (n != 0 && 0<n && n<10000) {
		resolver(n);
		cin >> n;
	}
	
	return 0;
}