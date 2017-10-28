#include <iostream>
using namespace std;

void resolver(int n) {
	int i = 0, tmp, max = 0, cont = 0;

	while (i < n) {
		cin >> tmp;
		if (max < tmp) {
			max = tmp;
			cont = 0;
		}
		else cont++;
		i++;
	}

	cout << cont << endl;

} 

int main(){
	int n;
	cin >> n;
	while (n != 0) {
		resolver(n);
	}
	
	return 0;
}