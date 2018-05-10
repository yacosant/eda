void recorre(Lista<string>::ConstIterator i, Lista<string>::ConstIterator e, Diccionario<string, int> &d, int op){
	string elem;
	while (i != e) {
		elem = i.elem();
		if (d.contiene(elem)){ //Si el alumno ya está en el dic.
			d.inserta(elem, d.valorPara(elem) + 1*op); //restamos o sumamos segun el valor de op
		}
		else d.inserta(elem, op); //insertamos 1 o -1 segun el valor de op

		i.next();
	}
}

void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	  // A IMPLEMENTAR
	Diccionario<string, int> d;
	Lista<string>::ConstIterator i = bien.cbegin();
	Lista<string>::ConstIterator e = bien.cend();

	//LISTA BIEN (op = +1 para sumar puntuacion)
	recorre(i, e, d, +1);

	//actualizamos los iteradores por los de la lista mal
	i = mal.cbegin();
	e = mal.cend();
	//LISTA MAL (op = -1 para restar puntuacion)
	recorre(i, e, d, -1);

	//Rellenar listado
	Diccionario<string, int>::ConstIterator ini = d.cbegin();
	Diccionario<string, int>::ConstIterator fin = d.cend();
	int valor = ini.valor();
	while (ini != fin) {
		if (valor != 0) listado.pon_final(Puntuacion(ini.clave(), valor));
		ini.next();
	}
} 
