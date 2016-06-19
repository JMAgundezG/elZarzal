///============================================================================
// Name        : titulaciones.cpp
// Author 	   : José Manuel Agúndez García & Jaime Alcántara Arnela
// Version     : Curso 15/16
// Copyright   : *
// Description : Source File de la clase titulaciones
//============================================================================

#include "titulaciones.h"





titulaciones::titulaciones() {
	Titulaciones = new ListaPI<titulacion*>;
	cargarTitulacionesDesdeArchivo();
}

void titulaciones::mostrarTitulaciones(){
	titulacion *t;
	Titulaciones->moverInicio();
	while(!Titulaciones->finLista()){
		Titulaciones->consultar(t);
		t->mostrarInfo();
		Titulaciones->avanzar();
	}


}

void titulaciones::cargarTitulacionesDesdeArchivo(){

	ifstream fsal;
	string id, nombre, numEstudiantes;
	int numEstudiantesDef;

	fsal.open("titulaciones.txt");
	while(!fsal.eof()){
		getline(fsal,id,'#');
		if(!fsal.eof()){
			getline(fsal,nombre,'#');
			getline(fsal,numEstudiantes);


			numEstudiantesDef = atoi(numEstudiantes.c_str());

			titulacion *t = new titulacion(id,nombre,numEstudiantesDef); //

			Titulaciones->insertar(t);
			Titulaciones->avanzar();
			}
	}
	fsal.close();

}



void titulaciones::borrarEstudianteMat(Estudiante *e, string id){
	titulacion *t;
	Titulaciones->moverInicio();
	while(!Titulaciones->finLista()){
		Titulaciones->consultar(t);
		t->borrarEstudianteMat(e, id);

		Titulaciones->avanzar();
	}
}

void titulaciones::buscarEstudiante(string dni){

	cout <<"--------------------------"<< endl;
	cout <<"DNI buscado: "<< dni << endl;
	cout <<"--------------------------"<< endl;
	cout <<"Lista de titulaciones:"<<endl<<endl;
	titulacion *t;
	Estudiante *e;
	bool encontrado;
	int contador = 0;
	Titulaciones->moverInicio();
	while(!Titulaciones->finLista()){
		Titulaciones->consultar(t);
		encontrado = t->buscarEstudiante(dni,e);
		Titulaciones->avanzar();
		if (encontrado){
			contador++;
		}
	}
	if(contador == 0){
			cout<<"ALUMNO NO ENCONTRADO"<<endl;
		}
	else{
		cout <<"--------------------------"<< endl;
		cout <<"Información personal:"<<endl<<endl;
		cout<<"Nombre: "<<e->getNombre()<<" "<<e->getApe1()<<" "<<e->getApe2()<<endl;
		cout<<"Nota: "<<e->getNota()<<endl;
	}

}


bool titulaciones::buscarTitulacion(string id, titulacion * &t){

	bool enc = false;
	Titulaciones->moverInicio();
	while(!Titulaciones->finLista() && !enc){
		Titulaciones->consultar(t);
		if (t->getID() == id){
			enc = true;
		}
		else{
			Titulaciones->avanzar();
		}
	}
	return enc;
}

void titulaciones::cargaDeArboles(){
	Titulaciones->moverInicio();
	titulacion *t;
	while(!Titulaciones->finLista()){
		Titulaciones->consultar(t);
		t->cargaDeArboles();
		Titulaciones->avanzar();
	}

}

void titulaciones::consultarTitulacionMat(string id){
	Titulaciones->moverInicio();
	bool enc = false;
	titulacion *t;
	while(!Titulaciones->finLista() && enc==false){
		Titulaciones->consultar(t);
		if(t->getID() == id){
			enc = true;
			t->mostrarTitulacionMat();
		}
		Titulaciones->avanzar();
	}
}

void titulaciones::mostrarNotasDeCorte(){
	Titulaciones->moverInicio();
	titulacion *t;
	while(!Titulaciones->finLista()){
		Titulaciones->consultar(t);
		cout<<t->getNombre()<<": "<<t->obtenerNotaCorte()<<endl;
		Titulaciones->avanzar();
	}

}

void titulaciones::mostrarSimilares(string raiz){
	titulacion *t;
	Titulaciones->moverInicio();
	while(!Titulaciones->finLista()){
			Titulaciones->consultar(t);
			t->buscarSimilares(raiz);
			Titulaciones->avanzar();
		}
}
titulaciones::~titulaciones() {
	Titulaciones->moverInicio();
	while(!Titulaciones->finLista()){
		Titulaciones->borrar();
	}
}

