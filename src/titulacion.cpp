/*
 * Archivo:titulacion.cpp
 *
 * Autores: José Manuel Agúndez García y Jaime Alcántara Arnela
 *
 */

#include "titulacion.h"



titulacion::titulacion () {
	admitidos = new conjuntoEstudiantes;
	enEspera = new conjuntoEstudiantes;
	identificador = "";
	admitidosPosibles = 0;
	nombreTitulacion = "";
	numAdmitidos = 0;
	notaCorte = 5;
}

titulacion::titulacion(string id, string nombre, int admitidosPosibles){
	admitidos = new conjuntoEstudiantes;
	enEspera = new conjuntoEstudiantes;
	identificador = id;
	nombreTitulacion = nombre;
	this->admitidosPosibles = admitidosPosibles;
	numAdmitidos = 0;
	notaCorte = 5;
}

string titulacion::getID(){
	return identificador;
}

string titulacion::getNombre(){
	return nombreTitulacion;
}

void titulacion::setNota(float nota){
	notaCorte = nota;

}

void titulacion::insertarEstudianteAdmitido(Estudiante *e){
	admitidos->insertarOrdenNota(e);
	numAdmitidos++;

}
void titulacion::insertarEstudianteEnEspera(Estudiante *e){
	enEspera->insertarOrdenNota(e);

}

bool titulacion::buscarEstudiante(string dni, Estudiante * &e){
	bool encontrado = false;
	if (admitidos->buscar(dni,e)){
		cout<<nombreTitulacion<<" - Admitido"<<endl;
		encontrado = true;
	}
	else if(enEspera->buscar(dni,e)){
		cout<<nombreTitulacion<<" - En lista de espera"<<endl;
		encontrado = true;
	}

	return encontrado;
}

void titulacion::borrarEstudianteMenorNota(){
	admitidos->borrarMenorNota();
	numAdmitidos--;
}

void titulacion::mostrarEstudiantes(){

	cout << "LISTA DE ADMITIDOS" << endl;
	cout << endl;
	admitidos->mostrarEstudiantes();
	cout << endl;
	cout << "-------------------------------"<< endl;
	cout << "LISTA DE ESPERA" << endl;
	cout << endl;
	enEspera->mostrarEstudiantes();
}

bool titulacion::estaLLena(){
	return admitidosPosibles<=numAdmitidos;
}

void titulacion::obtenerAdmitidoMenorNota(Estudiante *&e){
	admitidos->obtenerEstudianteMenorNota(e);
}

void titulacion::cargaDeArboles(){
	admitidos->cargaDeArboles();
	enEspera->cargaDeArboles();

}

bool titulacion::buscarMat(Estudiante *e){
	return admitidos->buscarMat(e);


}


void titulacion::borrarEstudianteMat(Estudiante *e, string id){
	if (identificador == id){
		admitidos->borrarEstudianteMat(e);
	}
	enEspera->borrarEstudianteMat(e);

}

void titulacion::obtenerEnEsperaMayorNota(Estudiante *&e){
	enEspera->obtenerEstudianteMayorNota(e);
	enEspera->borrar(e->getDNI());
}

void titulacion::insertarEnArbol(Estudiante *&e){
	admitidos->insertarEnArbol(e);

}

void titulacion::mostrarTitulacionMat(){
	cout<<nombreTitulacion<<endl;
	admitidos->mostrarEstudiantesMat();

}

float titulacion::obtenerNotaCorte(){
	Estudiante *e;
	admitidos->obtenerEstudianteMenorNota(e);
	return e->getNota();
}

void titulacion::buscarSimilares(string raiz){
	admitidos->mostrarSimilares(raiz);
	enEspera->mostrarSimilares(raiz);
}

bool titulacion::listaEsperaVacia(){
	return enEspera->vacio();
}

void titulacion::mostrarInfo(){

	cout<<this->identificador<<" "<<this->nombreTitulacion<<" "<<endl;
}

bool titulacion::buscarEstudianteEnArboles(Estudiante *&e, string apellido1, string apellido2, string nombre){

	bool encontrado;
	encontrado = admitidos->buscarEstudianteEnArbol(e,apellido1,apellido2,nombre);
	return encontrado;
}

titulacion::~titulacion () {
	delete admitidos;
	delete enEspera;

}


