/*
 * Preinscripciones.cpp
 *
 *  Created on: 11/4/2016
 *      Author: jmagundezg
 */

#include "Preinscripciones.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Preinscripciones::Preinscripciones() {
	estudiantes = new Pila<Estudiante*>;
	cargarEstudiantes("estudiantes.txt");


}

void Preinscripciones::reiniciarEstudiantes(){
	estudiantes = new Pila<Estudiante*>;
}

void Preinscripciones::cargarEstudiantes(string archivo){

	ifstream fsal;

	string apel1,apel2,nombre,dni,notaAux,solicitudesAux;
	float nota, numSolicitudes;
	int i;
	fsal.open(archivo.c_str());
	while(!fsal.eof()){

		getline(fsal,apel1,'#');
		if (!fsal.eof()){
			getline(fsal,apel2,'#');
			getline(fsal,nombre,'#');
			getline(fsal,dni,'#');
			getline(fsal,notaAux,'#');
			getline(fsal,solicitudesAux);

			nota = atof(notaAux.c_str());

			Estudiante *e = new  Estudiante(apel1,apel2,nombre,dni,nota);

			numSolicitudes = atof(solicitudesAux.c_str());
			for(i=0;i<numSolicitudes;i++){
				getline(fsal,solicitudesAux);
				e->nuevaSolicitud(solicitudesAux);
			}
			estudiantes->apilar(e);
		}
	}
	fsal.close();




}

bool Preinscripciones::estaVacia(){
	return estudiantes->vacia();
}

void Preinscripciones::devolverEstudiante(Estudiante * &e){
	estudiantes->cima(e);
	estudiantes->desapilar();
}

Preinscripciones::~Preinscripciones() {
	delete estudiantes;
}

