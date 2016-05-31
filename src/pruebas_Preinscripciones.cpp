#include <cstring>
#include <iostream>
#include "Preinscripciones.h"
#include "Estudiante.h"


void pr_devolverestudiante(){
	Estudiante *e = new Estudiante();
	Estudiante *e0 = new Estudiante("VARGUES-MENAU", "VALIENTE", "ALBERTO", "86363988X", 9.746);
	Preinscripciones *p = new Preinscripciones();
	p->reiniciarEstudiantes();
	p->cargarEstudiantes("pr_estudiantes.txt");
	p->devolverEstudiante(e);
	if(e->getDNI()!= e0->getDNI() && e->getNombre() != e0->getNombre() && e->getApe1() != e0->getApe1() && e->getApe2() != e0->getApe2()){
		cout<<"Error en pruebas de devolverEstudiante, Preinscripciones"<<endl;
	}
}

void pr_cargarEstudiantes(){

	Estudiante *e0 = new Estudiante("VARGUES-MENAU", "VALIENTE", "ALBERTO", "86363988X", 9.746);
	Estudiante *e = new Estudiante();

	Preinscripciones *p = new Preinscripciones();
	p->reiniciarEstudiantes();
	p->cargarEstudiantes("pr_estudiantes.txt");
	p->devolverEstudiante(e);

	if(e->getDNI()!= e0->getDNI() || e->getNombre() != e0->getNombre()  || e->getApe1() != e0->getApe1()  || e->getApe2() != e0->getApe2()){
		cout<<"Error en pruebas de cargarEstudiantes, Preinscripciones"<<endl;
	}

	if(e->getPrimeraTitulacion() != "04"){
		cout<<"Error en pruebas de cargarEstudiantes, Preinscripciones"<<endl;
	}
	if(e->getPrimeraTitulacion() != "02"){
		cout<<"Error en pruebas de cargarEstudiantes, Preinscripciones"<<endl;
	}


	e0 = new Estudiante("VAQUERO", "VALBUENA", "ALBERTO", "83448443F", 9.436);

	p->devolverEstudiante(e);
	if(e->getDNI()!= e0->getDNI() || e->getNombre() != e0->getNombre()  || e->getApe1() != e0->getApe1()  || e->getApe2() != e0->getApe2()){
		cout<<"Error en pruebas de cargarEstudiantes, Preinscripciones"<<endl;
	}
	if(e->getPrimeraTitulacion() != "01"){
		cout<<"Error en pruebas de cargarEstudiantes, Preinscripciones"<<endl;
	}
	if(e->getPrimeraTitulacion() != "02"){
		cout<<"Error en pruebas de cargarEstudiantes, Preinscripciones"<<endl;
	}
	if(e->getPrimeraTitulacion() != "03"){
		cout<<"Error en pruebas de cargarEstudiantes, Preinscripciones"<<endl;
	}

}

void pr_estaVacia(){
	Preinscripciones *p = new Preinscripciones();
	p->reiniciarEstudiantes();

	if(!p->estaVacia()){
		cout<<"Error en pruebas de estaVacia, Preinscripciones"<<endl;
	}
	p->cargarEstudiantes("pr_estudiantes.txt");
	if(p->estaVacia()){
		cout<<"Error en pruebas de estaVacia, Preinscripciones"<<endl;
	}
}

/*
int main(){
	//pr_cargarEstudiantes();
	//pr_devolverestudiante();
	//pr_estaVacia();

	return 0;
}
*/
