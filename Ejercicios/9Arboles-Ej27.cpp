
/*
(Junio 2013) Dado un árbol binario, diremos que un nodo es hijo único si su nodo padre solamente tiene un hijo (él mismo). 
Dado un árbol binario, diseña una función que calcule el número de hijos únicos con una complejidad O(n).
*/

/*
	Codigo de yaco. Contenido en el TAD.
*/
int hijoUnico(){
	int n=0;
	bool iz=hijoIz().esVacio(), der=hijoDer().esVacio();
	if(esVacio()) return 0;
	else{
		n=hijoIz().hijoUnico() + hijoDer().hijoUnico();
	}
	if((iz && !der) ||(!iz && der)) n++;
	return n;
}


/*
	Codigo de profesora mostrado en clase. Externo al TAD.
*/
int hijoUnicoProfesora(Arbin<T> a){
	if(esVacio()) return 0;
	else{
		Arbin<T> HI = a.hijoIz();
		Arbin<T> HD = a.hijoDer();
		if(HI.esVacio() && !HD.esVacio()) 
			return 1 + hijoUnicoProfesora(HD);
		else if(!HI.esVacio() && HD.esVacio()) 
			return 1 + hijoUnicoProfesora(HI);
		else 
			return  hijoUnicoProfesora(HI)+  hijoUnicoProfesora(HD);
	}
}