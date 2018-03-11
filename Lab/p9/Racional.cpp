#include "Racional.h"
#include <cmath>

  //Metodos publicos
Racional::Racional(long a, long b) {
	if (b == 0) throw EDenominadorCero();
	_numer = a;
	_denom = b;
	reduce();
}
  
Racional Racional::suma(Racional a) {
	long den = mcm(_denom, a._denom);
	long num = _numer* den/_denom + a._numer* den/a._denom;
	Racional r = Racional(num, den);
	r.reduce();
	return r;
}

Racional Racional::operator-(const Racional &r){
	long den = mcm(_denom, r._denom);
	long num = _numer*(den / _denom) - r._numer*(den / r._denom);
	return Racional(num, den);
}

void Racional::divideYActualiza(Racional a) {
	if (a._numer || _numer) throw EDivisionPorCero();
	long num = _numer*a._denom;
	long den = _denom*a._numer;
	_numer = num;
	_denom = den;
	reduce();
}
 
void Racional::operator*=(const Racional &r) {
	_numer = _numer*r._numer;
	_denom=_denom*r._denom;
	reduce();
}


bool Racional::operator==(const Racional &r) {
	Racional t = r;
	t.reduce();
	reduce();
	return (_numer == t._numer && _denom == t._denom);
}
  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

