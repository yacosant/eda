#include "GestionAdmisiones.h"


/** 
Implementación de las operaciones de la clase Paciente 
*/

Paciente::Paciente(const string& nombre, unsigned int edad, const string& sintomas):
    _nombre(nombre),  _sintomas(sintomas), _edad(edad) {}	

unsigned int Paciente::edad() const {
   return _edad;	
}
const string& Paciente::nombre() const {
   return _nombre;	
}
const string& Paciente::sintomas() const {
   return _sintomas;	
}

/**
Implementa aquí los métodos de las clases adicionales
*/
Envol::Envol(const Paciente& p, const Lista<CodigoPaciente>::Iterator &i, Gravedad &g) :
	_i(i), _p(p), _g(g) {}

const Paciente& Envol::p() const {
	return _p;
}
const Lista<CodigoPaciente>::Iterator& Envol::i() const {
	return _i;
}


const Gravedad& Envol::g() const {
	return _g;
}

/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de los mismos.
*/ 


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
	
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 an_paciente(codigo, nombre, edad, sintomas, gravedad): Añade al sistema
un nuevo paciente con código de identificación codigo, con nombre
nombre, con edad edad, con una descripción de síntomas sintomas, y con
código de gravedad gravedad. En caso de que el código esté duplicado, la
operación señala un error “Paciente duplicado”.*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad) {
	// A IMPLEMENATR
	if (pacientes.contiene(codigo)) throw EPacienteDuplicado();
	orden[gravedad].pon_ppio(codigo);
	Paciente p(nombre, edad, sintomas);
	Envol e(p, orden[gravedad].begin(), gravedad);
	pacientes.inserta(codigo, e);
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 info_paciente(codigo, nombre, edad, sintomas): Almacena en nombre,
 edad y síntomas la información correspondiente del paciente con código
 codigo. En caso de que el código no exista, levanta un error “Paciente
 inexistente”.
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENATR
	if (!pacientes.contiene(codigo)) throw EPacienteNoExiste();
	Paciente p = pacientes.valorPara(codigo).p();
	nombre =p.nombre();
	edad = p.edad();
	sintomas = p.sintomas();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 siguiente(codigo, gravedad): Almacena en codigo y gravedad,
 respectivamente, el código y la gravedad del siguiente paciente a ser
 atendido. Como se ha indicado antes, se atiende primero a los pacientes
 graves, después a los de nivel de gravedad normal, y por último a los
 leves. Dentro de cada nivel, los pacientes se atienden por orden de
 llegada. En caso de que no haya más pacientes, esta operación levanta un
 error “No hay pacientes”.
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	// A IMPLEMENATR
	if (!orden[GRAVE].esVacia()) {
		codigo= orden[GRAVE].ultimo();
		gravedad = GRAVE;
	}
	else if (!orden[NORMAL].esVacia()) {
		codigo = orden[NORMAL].ultimo();
		gravedad = NORMAL;
	}
	else if (!orden[LEVE].esVacia()) {
		codigo = orden[LEVE].ultimo();
		gravedad = LEVE;
	}
	else throw ENoHayPacientes();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 hay_pacientes(). Devuelve true si hay más pacientes en espera, y false en
 otro caso.
*/
bool GestionAdmisiones::hay_pacientes() const {  
	// A IMPLEMENATR
	return (!orden[GRAVE].esVacia() || !orden[NORMAL].esVacia() || !orden[LEVE].esVacia());
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación

 elimina(codigo): Elimina del sistema todo el rastro del paciente con
 código codigo. Si no existe tal paciente, la operación no tiene efecto.
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
  // A IMPLEMENATR
	if (pacientes.contiene(codigo)) {
		Envol e = pacientes.valorPara(codigo);
		orden[e.g()].eliminar(e.i());
		pacientes.borra(codigo);
	}
}
   