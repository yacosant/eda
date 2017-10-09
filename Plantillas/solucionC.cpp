/*
 * Contar el número de ceros de un vector. La entrada termina cuando
 * termina el fichero.
 */


/*
ESTRCUTURA:

Entrada de ejemplo
10 1 2 3 4 5 6 7 8 9 10
3 3 3 3
1 0
7 4 32 64 5 1 2 21
0

Salida de ejemplo
5
0
1
4


*/
 #include <iostream>

using namespace std;

// { 0 <= n <= long(v) }
// fun pares(int v[], int n) return int r
// { r = #i : 0<=i<n: v[i] = 0 }

int ceros(int v[], int n) {
    int r = 0;
    for (int k=0; k<n; ++k) {
        if (v[k] == 0)
            ++r;
    }
    return r;
}


bool resuelve() {
    // Hay más datos?
    int n;
    cin >> n;
    if (!cin)
        return false;

    // Leer elementos del vector
    int v[100000];
    for (int i=0; i<n; ++i)
        cin >> v[i];

    // Contar ceros
    int numCeros = ceros(v, n);

    // Nota: en realidad en este problema no hace falta v, podemos
    // contar el número de ceros directamente leyendo número a número
    // de la entrada. Lo hago así porque el enunciado pide la especificación.

    // escribir resultado
    cout << numCeros << endl;
    return true;
}

int main() {
    
    while (resuelve())
        ;

    return 0;
}
