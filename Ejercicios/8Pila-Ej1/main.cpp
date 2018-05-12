#include "pila.h"
#include <iostream>
#include <string>
using namespace std;

/*
Implementa, con ayuda de una pila, un procedimiento no recursivo que reciba como parámetro un número entero n >= 0 
y escriba por pantalla sus dígitos en orden lexicográfico y su suma. Por ejemplo, ante n = 64323 escribirá:
6 + 4 + 3 + 2 + 3 = 18
*/

void resolver(int num) {
	Pila<int> p = Pila<int>();
	int ac=0;
	string s = "";
	while (num % 10 != 0) {
		p.apila(num % 10);
		num = num / 10;
		
	}

	while(!p.esVacia()) {
		cout<< p.cima();
		ac += p.cima();
		p.desapila();
		if (!p.esVacia())cout<< " + "; 
	}
	cout << " = " << ac<<endl;
}

int main() {
  int num;
  cin >> num;
  while (num!=-1) {
	 resolver(num);
	 cin >> num;
  }
  return 0;   
}