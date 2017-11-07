#include <iostream>

using namespace std;

/* SOLUCION BUENA DE CLASE */

//PRE { 0 < n <= long(V)}
//POST {meseta(v,ini,fin) ^ fin-ini+1 = Max(a,b) : 0 <= a <= b <n ^ meseta(v,a,b) : b - a + 1 }

//POST ALTERNATIVA { (ParaTodo)a,b : 0<=a<=b<n ^meseta(v,a,b) : b-a+1 <= fin-ini + 1 }

//meseta(v,a,b) = (ParaTodo)k : a <= k <= b : v[k]=v[a];

void mesetaMasLarga(int v[], int n, int &ini, int &fin){
	int i = 0;
	ini =0;
	fin = 0;
	
	while(i < n){
		int j= i;
		while((j+1 < n) && (v[i] == v[j+1])){
			
			j++;
		}
		if(j-i+1 > fin-ini+1){
			ini=i; 
			fin=j;
		}
		i=j+1;
	}
}

void solve(int n, int a, int b){
	int v[10000];
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	mesetaMasLarga(v,n,a,b);
}

void resuelve(int n, int &a, int &b){
	int v[10000];
	int i=0, nCont=0;
	int cont[2];
	int ini[2];

	bool enc = false;
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	cont[0] = 0;
	cont[1] = 0;
	ini[0] = 0;
	ini[1] = 0;
	
	do{
		while (!enc && i < n - 1){
			if (v[i] == v[i + 1]){
				ini[nCont] = i;
				cont[nCont]++;
			}
			else enc = true;
			i++;
		}
		enc = false;

		
	
		if (cont[0] > cont[1]){
			nCont++;
			cont[1] = 0;
		}
		else{
			nCont = 0;
			cont[0] = 0;
		}

	} while (i < n - 1);

	if (nCont == 1){
		a = ini[0]-1;
		b = a + cont[0];
	}
	else {
		a = ini[1]-1;
		b = a + cont[1];
	}
	

}

int main(){
	int n,a=0,b=0;

	cin >> n;
	while (n != 0){
		solve(n,a,b);
		cout << a << " " << b <<endl;
		cin >> n;
	}
	return 0;
}






























