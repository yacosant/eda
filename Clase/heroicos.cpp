//EJERCICIO 16 - LOS HEROICOS


//PRE { 0 <= n <= long(v)}
//POST { heroes = #k : 0<= k < n : heroicos(v,k) } 
	//heroicos(v,k) = v[k] > fib(k);
	/*
	
		fib(n) = 1 si n<2
		fib(n) = gib(n-1) + fib(n-2) si n>=2
		
	*/

int heroicos(int v[], int n){
	int fiback =1;	//fib(i)
	int fibant = 0;
	int heroes=0;	//fib(i-1)	
											//INV= 0 <= i <=n ^fiback = fib(i) ^ fibant = fib(i-1) ^ heroes = #k : 0<= k < i : heroicos(v,k)
	while(i<n){								// COTA = n-i
		if(fiback < v[i]) heroes++;
		
		int fiaux= fibact;
		fiant = fiback;
		fiback = fiback + fiaux;
		
		
		i++;
	}
	return heroes;
}