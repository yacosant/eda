/**
  @file Pila.h

  Implementaci�n del TAD Pila utilizando un
  array est�tico.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Antonio S�nchez Ruiz-Granados, 2013  Mercedes G�mez Albarr�n, 2016
*/
#ifndef __PILAE_H
#define __PILAE_H


/// Excepciones generadas por algunos m�todos
class EPilaLlena {};
class EPilaVacia {};

/**
 Implementaci�n del TAD Pila utilizando un array est�tico.

 Las operaciones son:

 - PilaVacia: -> Pila. Generadora implementada en el
   constructor sin par�metros.
 - apila: Pila, Elem -> Pila. Generadora parcial.
 - desapila: Pila - -> Pila. Modificadora parcial.
 - cima: Pila - -> Elem. Observadora parcial.
 - esVacia: Pila -> Bool. Observadora.

 @author Antonio S�nchez Ruiz-Granados   Mercedes G�mez Albarr�n
 */
template <class T>
class Pila {
public:

	unsigned int numElems(){
		return _numElems;
	}
	


	/** N�mero m�ximo de elementos. */
	static const int TAM_MAX = 100;

	/** Constructor; operaci�n PilaVacia */
	Pila() : _numElems(0) {	}

	
	/**
	 Apila un elemento. Operaci�n generadora parcial.

	 @param elem Elemento a apilar.
	 error: no se puede apilar cuando la pila est� llena
	*/
	void apila(const T &elem) {
		if (_numElems == TAM_MAX)
			throw EPilaLlena();
		_v[_numElems] = elem;
		_numElems++;
	}
	
	/**
	 Desapila un elemento. Operaci�n modificadora parcial,
	 que falla si la pila est� vac�a.
	 error: no se puede desapilar una pila vac�a
	*/
	void desapila() {
		if (esVacia())
			throw EPilaVacia();
		_numElems--;
	}

	/**
	 Devuelve el elemento en la cima de la pila. Operaci�n
	 observadora parcial
	 error: falla si la pila est� vac�a.
	 @return Elemento en la cima de la pila.
	 */
	const T &cima() const {
		if (esVacia())
			throw EPilaVacia();
		return _v[_numElems-1];
	}

	/**
	 Devuelve true si la pila no tiene ning�n elemento
	 @return true si la pila no tiene ning�n elemento.
	 */
	bool esVacia() const {
		return _numElems == 0;
	}

	/** 
	 Operador de comparaci�n. 
	*/
	bool operator==(const Pila<T> &rhs) const {
		bool iguales = true;
		if (_numElems != rhs._numElems)
			iguales = false;
		else{
			unsigned int i = 0;
			while (iguales && i < _numElems) {
				if (_v[i] != rhs._v[i])
					iguales = false;
				i++;
			}
		}
		return iguales;			
	}

	bool operator!=(const Pila<T> &rhs) const {
		return !(*this == rhs);
	}

private:

	/** Array de elementos. */
	T _v[TAM_MAX]; 	
	/** N�mero de elementos almacenados en la pila. */
	unsigned int _numElems;
};

#endif // __PILAE_H
