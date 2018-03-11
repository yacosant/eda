#ifndef _MulticonjuntoGenerico_
#define _MulticonjuntoGenerico_
 //class ConjuntoLleno {}; // para las excepciones si se necesitan


template<class T>

class MulticonjuntoGenerico {
	static const int MAX = 100;
	int _tam;
	T _elementos[MAX];

public:
	MulticonjuntoGenerico();

	void crearConjuntoVacio();
	bool esVacio()const;
	void añadirElem(const T& e);
	
	void estaEnMultiConjunto(const T& e)
	int  multiplicidad(const T& e);
	void eliminarOcurrenciaElem();
	void eliminarTodasOcurrenciasEle();
	void vaciarMulticonjunto();


	/*-------------------------------------------*/

	template <class T>
	void MulticonjuntoGenerico<T>::añadirElem(const T& e) {
		if (_tam == MAX) throw ConjuntoLleno();
		T _elementos[_tam] = e;
		_tam++;
	}

	template <class T>
	void MulticonjuntoGenerico <T>::crearConjuntoVacio() {
		return _tam == 0;
	}

	template<T>
	int MulticonjuntoGenerico::multiplicidad(const T& e) {
		int cont;
		for (int i = 0; i < _tam; i++) {
			if (e == _elementos[i]) cont++;
		}

		return cont;
	}

	template <T>
	bool MulticonjuntoGenerico<T>::esVacio() {
		if (_elementos.length() == 0) return true;
	}

};
#endif
