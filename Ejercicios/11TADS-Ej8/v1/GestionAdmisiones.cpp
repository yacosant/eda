/**
  NOMBRE Y APELLIDOS:
  LABORATORIO:
  PUESTO:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "GestionAdmisiones.h"

/** 
Implementación de las operaciones de la clase Paciente 
*/

Paciente::Paciente(const string& nombre, unsigned int edad, const string& sintomas):
    _nombre(nombre), _sintomas(sintomas), _edad(edad) {}	

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

 
/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de las mismas.
*/ 

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
}

/**
 COMPLEJIDAD: Constante.

an_paciente(codigo, nombre, edad, sintomas) : 
añade al sistema un nuevo paciente con código de identificación codigo, con nombre nombre, con edad edad y con una descripción de síntomas sintomas.
En caso de que el código esté duplicado, la operación señala un error “Paciente duplicado”.*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas) {
	// A IMPLEMENTAR
	if (pacientes.contiene(codigo)) 
		throw EPacienteDuplicado();
	
	Paciente p(nombre, edad, sintomas);
	pacientes.inserta(codigo, p);
	orden.pon_final(codigo);
}

/**
 COMPLEJIDAD: Constante.

 info_paciente(codigo, nombre, edad, sintomas): nombre, edad y sintomas devuelven la información correspondiente al paciente con código codigo.
 En caso de que el código no exista, levanta un error “Paciente inexistente”.
 */
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
	if (pacientes.esVacio() || !pacientes.contiene(codigo)) throw EPacienteNoExiste();

		Paciente p = pacientes.valorPara(codigo);
		nombre = p.nombre();
		edad = p.edad();
		sintomas = p.sintomas();
}

/**
 COMPLEJIDAD:Contante.

 siguiente(codigo): almacena en codigo el código del siguiente paciente a ser atendido. 
 En caso de que no haya más pacientes, esta operación levanta un error “No hay pacientes”.
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo) const {
  // A IMPLEMENTAR
	if (orden.esVacia()) throw ENoHayPacientes();
	codigo = orden.primero();
}

/**
 COMPLEJIDAD: Complejidad constante. Solo es una consulta de si la lista está vacia o no.

 hay_pacientes(): devuelve true si hay más pacientes en espera, y false en otro caso.
*/
bool GestionAdmisiones::hay_pacientes() const {  
  // A IMPLEMENTAR
	return !orden.esVacia();
}

/**
 COMPLEJIDAD: Lineal, en funcion de la posicion del paciente en la lista del orden.

 elimina(codigo): elimina del sistema todo el rastro del paciente con código codigo. Si no existe tal paciente, la operación no tiene efecto.
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	// A IMPLEMENTAR
	if (pacientes.contiene(codigo)) {
		Lista<int>::Iterator i = orden.begin();
		bool fin = false;

		while (!fin && i!=orden.end()){
			if (codigo == i.elem())fin = true;
			else i.next();
		}
		orden.eliminar(i); //se elimina de la lista de orden 
		pacientes.borra(codigo);//y del diccionario

	}
}
   
