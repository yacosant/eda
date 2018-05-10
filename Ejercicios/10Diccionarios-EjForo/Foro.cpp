#include "Foro.h"


/*** METODOS DE Mensaje ***/

Mensaje::Mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo):
   _id(id), _remitente(remitente), _asunto(asunto), _cuerpo(cuerpo) {}	

const MID Mensaje::id() const {
	return _id;
}

const string& Mensaje::remitente() const {
   return _remitente;	
}

const string& Mensaje::asunto() const {
   return _asunto;	
}

const string& Mensaje::cuerpo() const {
   return _cuerpo;	
}


/*** METODOS DE Foro ***/

Foro::Foro() {
	// A IMPLEMENTAR
	mensajes = 0;
}
   
void Foro::envia_mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo) {
  // A IMPLEMENTAR

	if (_foro.contiene(id)) throw EMIDDuplicado();

	Mensaje m = Mensaje(id, remitente, asunto, cuerpo);
	_lista.pon_final(id);
	_foro.inserta(id, m);
	mensajes++;
}

const Mensaje& Foro::consulta_mensaje(MID id) const {
  // A IMPLEMENTAR
	if (!_foro.contiene(id)) throw ENoHayMensaje();

	return _foro.valorPara(id);
}

void Foro::elimina_mensaje(MID id) {
  // A IMPLEMENTAR
	if (!_foro.contiene(id)) throw ENoHayMensaje();
	
	Lista<MID>::Iterator i = _lista.begin();
	Lista<MID>::Iterator e = _lista.end();
	bool fin = false;

	while(i!=e && !fin){
		if (i.elem() == id) fin = true;
		else i.next();
	}
	_lista.eliminar(i); //elimina de la lista
	_foro.borra(id); //elimina del diccionario
	mensajes--;
}
   
Lista<MID> Foro::recupera_mensajes(unsigned int n) const {
  // A IMPLEMENTAR
	Lista<MID> li = Lista<MID>();
	Lista<MID> aux = Lista<MID>(); //par apoder devolver primero los ultimos elementos del dic. casos que sea ultimo x (x!=mensajes) 

	Lista<MID>::ConstIterator i = _lista.cbegin();
	Lista<MID>::ConstIterator e = _lista.cend();
	int k = 0;

	while (i != e) {
		aux.pon_ppio(i.elem());
		i.next(); 
	}	
	k = 0;
	while (k < n) {
		li.pon_ppio(aux.ultimo());
		aux.quita_final();
		k++;
	}
	
	return li;
}

unsigned int Foro::numero_mensajes() const {
	// A IMPLEMENTAR
	return mensajes;
}