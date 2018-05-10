
void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	  // A IMPLEMENTAR
	Diccionario<string, int> d;
	Lista<string>::ConstIterator i = bien.cbegin();
	Lista<string>::ConstIterator e = bien.cend();
	string elem;

	//LISTA BIEN
	while (i != e) {
		elem = i.elem();
		if (d.contiene(elem)){ //Si el alumno ya está en el dic.
			d.inserta(elem, d.valorPara(elem) + 1); //sumamos
		}
		else d.inserta(elem, +1);

		i.next();
	}

	//LISTA MAL
	i = mal.cbegin();
	e = mal.cend();
	while (i != e) {
		elem = i.elem();
		if (d.contiene(elem)){ //Si el alumno ya está en el dic.
			d.inserta(elem,d.valorPara(elem) - 1); //restamos
		}
		else d.inserta(elem, -1);

		i.next();
	}

	//rellenar listado
	Diccionario<string, int>::ConstIterator ini = d.cbegin();
	Diccionario<string, int>::ConstIterator fin = d.cend();

	while (ini != fin) {
		if (ini.valor() != 0) listado.pon_final(Puntuacion(ini.clave(), ini.valor()));
		ini.next();
	}

}
