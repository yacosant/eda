//Solucion a incluir en Arbin.h en la seccion public:

/*Ejercicio 1- Hoja Alumnos 9 Arboles
Extiende la implementación de los árboles binarios con las siguientes operaciones:

	• numNodos: devuelve el número de nodos del árbol.
	• esHoja: devuelve cierto si el árbol es una hoja (los hijos izquierdo y derecho son vacíos).
	• numHojas: devuelve el número de hojas del árbol.
	• talla: devuelve la talla del árbol.
	• frontera: devuelve una lista con todas las hojas del árbol de izquierda a derecha.
	• espejo: devuelve un árbol nuevo que es la imagen especular del original.
	• minElem: devuelve el elemento más pequeño de todos los almacenados en el árbol. Es un error ejecutar esta operación sobre un árbol vacío.
*/
	int numNodos() {
		if (esVacio()) return 0;
		else return 1 + hijoDer().numNodos() + hijoIz().numNodos();

		/* otra manera:
			int n = 0;	//equivale a if vacio return 0;
			if (!esVacio()){	
				n = 1 + hijoDer().numNodos() + hijoIz().numNodos();
			}
			return n;
		*/
	}

	bool esHoja() {
		return hijoIz().esVacio() && hijoDer().esVacio();
	}

	int numHojas() {
		if (esVacio()) return 0;
		else if (esHoja()) return 1;
		else return hijoIz().numHojas() + hijoDer().numHojas();
	}

	int talla() {
		int iz, der, max;
		if (esHoja()) return 0;
		else {
			iz = hijoIz().talla();
			der=hijoDer().talla();
			
		//Elegir el de mayor profundidad
			if (iz < der) max= der;
			else max = iz;
		}
			return 1 + max;
	}
	
	void frontera(queue<int> &s) {
		//include <queue> en .h y .cpp
		
		if (esVacio()); //nada
		else if (esHoja()) s.push(raiz());
		else {
			hijoIz().frontera(s);
			hijoDer().frontera(s);
		}
	}
	
	/*
	METODO PARA MOSTRAR LA LISTA. implemetar en el .cpp 
	
			
		void mostrarFrontera(queue<int> s) {
			while (!s.empty())
			{
				cout << s.front() << " ";
				s.pop();
			}
			cout << endl;
		}
		
		///main:
		int main() {
			Arbin <int> raiz=	construir();
			int n;
			queue<int> s;
			raiz.frontera(s);
			mostrarFrontera(s);
			system("PAUSE");
		}
	*/

	Arbin<int> espejo() {
		/*Arbin<int> iz, der;

		if (hijoIz().esVacio()) der = Arbin<int>();
		else der = hijoIz().espejo();

		if (hijoDer().esVacio()) iz = Arbin<int>();
		else iz = hijoDer().espejo();

		return Arbin<int>(iz, raiz(), der);
		*/
		if(esVacio()) return Arbin<int>();
		
		return Arbin<int>(hijoDer().espejo(), raiz(), hijoIz().espejo());
	}

	int minElem() {
		int iz= 9999999, der= 9999999, min=9999999;
		if (esHoja()) return raiz();
		else {
			if (!hijoIz().esVacio()) iz= hijoIz().minElem();
			if (!hijoDer().esVacio()) der = hijoDer().minElem();

			if (iz > der ) min = der;
			else min = iz;
			if (min > raiz()) min = raiz();
		}
		return min;
	}