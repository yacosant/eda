/*
Implementa un subprograma que reciba una pila y un número positivo n e
invierta los n valores almacenados en la parte superior de la pila.
*/

#include "pila.h"
#include <iostream>
using namespace std;

void voltea(Pila<T> p, int n){
    Pila<T> aux = Pila<T>();
    int i=0;
    while(i< n){
        aux.apila(p.cima());
        p.desapila();
        i++;
    }
    i=0;
    while(i<n){
        p.apila(aux.cima());
        aux.desapila();
        i++;
    }
}
