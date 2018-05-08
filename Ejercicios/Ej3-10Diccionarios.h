/**
3. Extiende con las siguientes operaciones la implementación de los diccionarios:
• consultaK: recibe un entero k y devuelve la k-ésima clave del diccionario 
            (considera que en un diccionario con n elementos las claves se numeran desde k=0 hasta k=n-1)
const tClave& consultaK(int k);

• recorreRango: recibe dos claves, a y b, y devuelve la lista con los valores asociados a las claves que están en el intervalo [a, b]
Lista<tValor> recorreRango(const tClave& a, const tClave& b);

• erase: recibe un iterador no constante, elimina el elemento apuntado por él y devuelve un iterador al siguiente elemento del diccionario
Iterator erase(const Iterator & it);
*/

const tClave& consultaK(int k){
    ConstIterator it = cbegin();
    ConstIterator fin = cend();
    int i=0;
    while(i<k && it!=fin){
        it.next();      
        i++;
    }
    return it.clave();
}

Lista<tValor> recorreRango(const tClave& a, const tClave& b){
    ConstIterator it = cbegin();
    ConstIterator fin = cend();
    Lista<tValor> list;

    while(it.valor()<a) it.next();

    while(it.valor()<=b && it!=fin){
        list.add(it.valor());
        it.next();
    }
    return list;
}

Iterator erase(const Iterator & it){
    //incompleto
    return aux;
}
