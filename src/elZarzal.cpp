///============================================================================
// Name        : elZarzal.h
// Author 	   : José Manuel Agúndez García & Jaime Alcántara Arnela
// Version     : Curso 15/16
// Copyright   : *
// Description : Source File de la clase elZarzal
//============================================================================

#include <iostream>
#include "elZarzal.h"
using namespace std;

elZarzal::elZarzal() {
	preinscripciones = new Preinscripciones;
	Titulaciones = new titulaciones;

}


void elZarzal::cargarEstudiantesEnTitulaciones(){
	Estudiante *e1 = NULL;
	Estudiante *e2 = NULL;
	string t1;
	titulacion *t = NULL;
	bool admitido;
	while(!preinscripciones->estaVacia()){
		admitido = false;
		preinscripciones->devolverEstudiante(e1);
		while(!admitido && !e1->titulacionesVacia()){
			t1 = e1->getPrimeraTitulacion();
			Titulaciones->buscarTitulacion(t1, t);
			if(!t->estaLLena()){
				t->insertarEstudianteAdmitido(e1);
				admitido = true;
			}
			else{
				t->obtenerAdmitidoMenorNota(e2);
				if(e1->getNota() > e2->getNota()){
					t->insertarEstudianteAdmitido(e1);
					t->borrarEstudianteMenorNota();
					t->insertarEstudianteEnEspera(e2);
					e1 = e2;
				}
				else{
					t->insertarEstudianteEnEspera(e1);
				}
			}
		}
	}
}

void elZarzal::mostrarTitulacion(string id){
	titulacion *t = NULL;
	if(Titulaciones->buscarTitulacion(id, t)){
		cout<<t->getNombre()<<endl;
		t->mostrarEstudiantes();
	}
	else{
		cout<<"Titulación no encontrada."<<endl;
	}

}

void elZarzal::mostrarEstudiante(string dni){
	Titulaciones->buscarEstudiante(dni);
}

void elZarzal::cargaDeArboles(){ // TODO CAMBIADO
	Titulaciones->cargaDeArboles();

}

void elZarzal::procesoMatricula(){
	ifstream fsal;
	titulacion *t;
	string operacion, id, ape1, ape2, nombre, DNI;
	fsal.open("matyrenuncias.txt");
	while(!fsal.eof()){
		getline(fsal,operacion,'#');
		if (!fsal.eof()){
			getline(fsal,id,'#');
			getline(fsal,ape1,'#');
			getline(fsal,ape2,'#');
			getline(fsal,nombre,'#');
			getline(fsal,DNI);

			Estudiante *e;
			Titulaciones->buscarTitulacion(id,t);

			if(t->buscarEstudianteEnArboles(e,ape1,ape2,nombre)){
				if(operacion == "MAT"){
					string nombre;
					nombre = t->getID() + ".txt";
					ofstream salida(nombre.c_str(), ios::out | ios::app);
					salida<<e->getApe1()<<" "<<e->getApe2()<<" "<<e->getNombre()<<" "<<e->getDNI()<<" "<<e->getNota()<<endl;
					salida.close();
					t->borrarEstudianteMat(e, t->getID());
				}
				else{
					t->borrarEstudianteMat(e,t->getID());
					if(!t->listaEsperaVacia()){
						t->obtenerEnEsperaMayorNota(e);
						t->insertarEstudianteAdmitido(e);
						t->insertarEnArbol(e);
					}
				}

			}
		}
	}
	fsal.close();

}

void elZarzal::consultarTitulacionMat(string id){
	Titulaciones->consultarTitulacionMat(id);

}

void elZarzal::mostrarNotasDeCorte(){
	Titulaciones->mostrarNotasDeCorte();
}

void elZarzal::mostrarEstudiantesSimilares(string raiz){
	Titulaciones->mostrarSimilares(raiz);
}

void elZarzal::mostrarInfoTitulaciones(){
	Titulaciones->mostrarTitulaciones();
}
elZarzal::~elZarzal() {
	delete preinscripciones;
	delete Titulaciones;
}

