///============================================================================
// Name        : Estudiante.cpp
// Author      : Profesores de la asignatura
// Modified by : José Manuel Agúndez García & Jaime Alcántara Arnela
// Version     : Curso 15/16
// Copyright   : UEx
// Description : implementación de la clase estudiante
//============================================================================


#include "Estudiante.h"

Estudiante::Estudiante() {
	ape1   = "";
	ape2   = "";
	nombre = "";
	dni    = "";
	nota   = 0.0;
	solicitudes = new Cola<string>;

}


Estudiante::Estudiante(string ape1, string ape2, string nombre, string dni, float nota){
	this->ape1   = ape1;
	this->ape2   = ape2;
	this->nombre = nombre;
	this->dni    = dni;
	this->nota   = nota;
	solicitudes = new Cola<string>;

}

void Estudiante::nuevaSolicitud(string n) {
	solicitudes->encolar(n);
}

void Estudiante::mostrar(){
	cout <<ape1 <<" "<<ape2<<" "<<nombre<<" "<<dni<<" \t\t"<<nota <<endl;

}

string Estudiante::getApe2(){
	return ape2;

}
string Estudiante::getApe1(){
	return ape1;
}


float Estudiante::getNota(){
	return nota;
}

string Estudiante::getDNI(){
	return dni;
}

string Estudiante::getNombre(){
	return nombre;
}

string Estudiante::getPrimeraTitulacion(){
	string s;
	if(!solicitudes->vacia()){
		solicitudes->primero(s);
		solicitudes->desencolar();
	}
	return s;
}

bool Estudiante::titulacionesVacia(){
	return solicitudes->vacia();
}

void Estudiante::mostrarEstudiante(){


	cout << "------------------------------------" << endl;
	cout << endl;
	cout << "Nombre: " << getNombre() << endl;
	cout << "Primer apellido: " << getApe1() << endl;
	cout << "Segundo apellido: "<< getApe2() << endl;
	cout << "DNI: " << getDNI() << endl;
	cout << "Nota de corte: " << getNota() << endl;
	cout << endl;
}

bool Estudiante::operator < (const Estudiante &e){
	return (nota < e.nota);
}
bool Estudiante::operator ==(const Estudiante &e){
	string nombre1, nombre2;
		nombre1 = getApe1()+getApe2()+getNombre();
		nombre2 = e.ape1+e.ape2+e.nombre;
	return (nombre1==nombre2);
}

bool Estudiante::sonElMismo(Estudiante *aux){

	bool mismaPersona = false;

	if(getDNI()==aux->getDNI()){
		mismaPersona = true;
	}

	return mismaPersona;
}

Estudiante::~Estudiante() {
	delete solicitudes;

}

