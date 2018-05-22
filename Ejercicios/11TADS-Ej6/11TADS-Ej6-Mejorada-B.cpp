// Examen junio 2016
// Implementación de un sistema de reproducción de música

#include "lista.h"
#include "DiccionarioHash.h"

#include <iostream>
#include <string>
using namespace std;


typedef string Cancion;
typedef string Artista;


// Aquí definimos clase equivalente a lo dado en el enunciado
class SongInfo {
public:
	Artista artist;
	int duration;
	//bool inPlaylist;
	//bool played;
	Lista<Cancion>::Iterator itPlaylist;
	Lista<Cancion>::Iterator itPlayed;
	
	SongInfo(const Lista<Cancion>::Iterator &itplaylist, const Lista<Cancion>::Iterator &itplayed): itPlaylist(itplaylist), itPlayed(itplayed) {}
};

// clases excepcion para iPud
class ECancionExistente{};
class ECancionNoExistente{};

// clase iPud
class iPud {
	DiccionarioHash<Cancion,SongInfo> songs;
	Lista<Cancion> playlist;
	Lista<Cancion> played;
	int duration;
    
public:
	iPud() : duration(0) {}
	void addSong(const Cancion& c, const Artista& a, int d);
	void addToPlaylist(const Cancion& c);
	void deleteSong(const Cancion& c);
	void play();
	Cancion current();
	int totalTime();
	Lista<Cancion> recent(int n);
};


// Añade una cancion al ipud.
/*
addSong(S, A, D): Añade la canción S (string) del artista A (string) con duración D (int) al iPud. 
Si ya existe una canción con el mismo nombre la operación dará error.
*/
void iPud::addSong(const Cancion& c, const Artista& a, int d){
	if (songs.contiene(c)) throw ECancionExistente();
	//Crear y Añadir a Dicc
	SongInfo s = SongInfo(playlist.end(), played.end()); //++++++++++++
	s.artist = a;
	s.duration = d;
	songs.inserta(c, s);
}

// Añade una cancion a la lista de reproduccion
/*
addToPlaylist(S): Añade la canción S al final de la lista de reproducción. 
Si la canción ya se encontraba en la lista entonces no se añade (es decir, la lista no tiene canciones repetidas). 
Si la canción no está en el iPud se devuelve error.
*/
void iPud::addToPlaylist(const Cancion& c){

	//Si no está guardada y EXISTE en ipod, la guardo
	if (songs.contiene(c)) {
		SongInfo s = songs.valorPara(c);

		if (s.itPlaylist!=playlist.end()) {//+++++++++++
			//s.inPlaylist = true;
			playlist.pon_final(c);
			duration += s.duration;
			songs.inserta(c, s); 
			
			s.itPlaylist = getIterator(playlist,c);//++++++++++++
		}
	}
	else throw ECancionNoExistente();
}

// devuelve la primera cancion de la lista de reproduccion
/*
current: Devuelve la primera canción de la lista de reproducción. Si es vacía se devuelve error.
*/
Cancion iPud::current(){
	if (playlist.esVacia()) throw ECancionNoExistente();
	return playlist.elem(0); 
}

// Devuelve el tiempo total de la lista de reproduccion
/*
totalTime: Obtiene la suma de las duraciones de las cancione
*/
int iPud::totalTime(){
	if (playlist.esVacia())return 0;
	return duration;
}

// Elimina una cancion del ipud
/*
deleteSong(S): Elimina todo rastro de la canción S. Si la canción no existe la operación no tiene efecto.
*/

Lista<Cancion>::Iterator getIterator(Lista<Cancion> l, Cancion c) {
	Lista<Cancion>::Iterator i = l.begin();
	Lista<Cancion>::Iterator f = l.end();
	bool fin = false;

	while (!fin && i != f) {
		if (c == i.elem()) fin = true;
		else i.next();
	}
	return i;
}

void iPud::deleteSong(const Cancion& c){
	if (songs.contiene(c)) {
		SongInfo s = songs.valorPara(c);
		Lista<Cancion>::Iterator i = playlist.begin();

		if (s.itPlaylist!=playlist.end()) { //Para borrarla de la playlist
			//i=getIterator(playlist, c);
			playlist.eliminar(s.itPlaylist);//+++++++
			duration -= s.duration;
		}

		if (s.itPlayed!=played.end()) { //para borrarla de las reproducidas
			//i = getIterator(played, c);
			played.eliminar(s.itPlayed);//+++++++
		}

		songs.borra(c);
	}
	//else no tiene efecto.
}


// Registra la reproduccion de una cancion
/*
play: La primera canción de la lista de reproducción abandona la lista de reproducción y se registra como reproducida. 
Si la lista es vacía la acción no tiene efecto.
*/
void iPud::play(){
	if (!playlist.esVacia()) {
		Cancion c = current();

		playlist.quita_final();

		//Actualizar los flags de la cancion
		SongInfo s = songs.valorPara(c);
		//s.inPlaylist = false;
		//s.played = true;
		s.itPlaylist = playlist.end(); //++++++++++++
		songs.inserta(c, s);
		duration -= s.duration;

		//Comprobamos que existe o no
		if(s.itPlayed!=played.end()) played.eliminar(s.itPlayed); //si exite, se elimina. //++++++++++++

		s.itPlayed= getIterator(played, c);//++++++++++++
		played.pon_final(c);
	}
}

// Obtiene la lista con las N últimas canciones que se han reproducido (mediante la operación play), 
// de la más reciente a la más antigua.
Lista<Cancion> iPud::recent(int n){
	Lista<Cancion>::ConstIterator i = played.cbegin();
	Lista<Cancion>::ConstIterator f = played.cend();
	int j = 0;
	Lista<Cancion> l;
	while (j<n && i!=f){
		l.pon_ppio(i.elem());
		i.next();
		j++;
	}
}



int main(){
	

	
	return 0;
}