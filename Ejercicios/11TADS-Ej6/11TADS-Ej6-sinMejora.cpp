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
	bool inPlaylist;
	bool played;

	SongInfo(): inPlaylist(false), played (false) {}
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
	SongInfo s = SongInfo();
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
	//Buscar si ya está - No hace falta. existe boolean que lo indica.
	/*Recorriendo:
	Lista<Cancion>::ConstIterator i = playlist.cbegin();
	Lista<Cancion>::ConstIterator f = playlist.cend();
	bool fin = false;
	while (!fin && i != f) {
		fin=(c==i.elem());
		i.next();
	}
	*/

	//Si no está guardada y EXISTE en ipod, la guardo
	if (songs.contiene(c)) {
		SongInfo s = songs.valorPara(c);

		if (!s.inPlaylist) {
			s.inPlaylist = true;
			playlist.pon_final(c);
			duration += s.duration;
			songs.inserta(c, s); //actualizamos el valor (flag a true).
		}
	}
}

// devuelve la primera cancion de la lista de reproduccion
/*
current: Devuelve la primera canción de la lista de reproducción. Si es vacía se devuelve error.
*/
Cancion iPud::current(){
	if (playlist.esVacia()) throw ECancionNoExistente();
	return playlist.elem(playlist.longitud() - 1);
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

void iPud::deleteSong(const Cancion& c){
	if (songs.contiene(c)) {
		SongInfo s = songs.valorPara(c);

		Lista<Cancion>::Iterator i = playlist.begin();
		Lista<Cancion>::Iterator f = playlist.end();
		bool fin = false;

		if (s.inPlaylist) { //Para borrarla de la playlist
			while (!fin && i != f) {
				if (c == i.elem()) fin = true;
				else i.next();
			}
			playlist.eliminar(i);
			duration -= s.duration;
		}

		if (s.played) { //para borrarla de las reproducidas
			fin = false;
			i = played.begin();
			f = played.end();

			while (!fin && i != f) {
				if (c == i.elem()) fin = true;
				else i.next();
			}
			played.eliminar(i);
		}

		songs.borra(c);
	}
	//else no tiene efecto.
}


// Registra la reproduccion de una cancion
void iPud::play(){
	Cancion c= current();
	playlist.quita_final();

	//Actualizar los flags de la cancion
	SongInfo s= songs.valorPara(c);
	s.inPlaylist = false;
	s.played = true;
	songs.inserta(c, s);
	duration -= s.duration;

	played.pon_final(c);
}

// Obtiene la lista con las N últimas canciones que se han reproducido (mediante la operación play), 
// de la más reciente a la más antigua.
Lista<Cancion> iPud::recent(int n){
	Lista<Cancion>::ConstIterator i = played.cbegin();
	Lista<Cancion>::ConstIterator f = played.cend();
	int j = 0;
	Lista<Cancion> l;
	while (j<n && i!=f){
		l.pon_final(i.elem());
		i.next();
		j++;
	}
}



int main(){
	

	
	return 0;
}