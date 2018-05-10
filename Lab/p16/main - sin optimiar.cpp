#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};


void recorre(Lista<string>::ConstIterator i, Lista<string>::ConstIterator e, Diccionario<string, int> &d, int op) {
	string elem;
	while (i != e) {
		elem = i.elem();
		if (d.contiene(elem)) { //Si el alumno ya está en el dic.
			d.inserta(elem, d.valorPara(elem) + 1 * op); //restamos o sumamos segun el valor de op
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
	int valor;
	if(ini!=fin) valor= ini.valor();
	while (ini != fin) {
		if (valor != 0) listado.pon_final(Puntuacion(ini.clave(), valor));
		ini.next();
	}
}


void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();	  
  }  
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;   
}