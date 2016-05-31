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

			titulacion *t = new titulacion(id,nombre,numEstudiantesDef); // TODO ID es un string, cambiado por idDef

			Titulaciones->insertar(t);
			}
	}
	fsal.close();

}

void titulaciones::buscarMat(Estudiante *e, string op, string id){
	titulacion *t;
	ofstream salida;
	bool enc = false;
	Titulaciones->moverInicio();
	while(!Titulaciones->finLista() && enc == false){
		Titulaciones->consultar(t);
		if(t->getID()==id){
			enc = true;
			if(t->buscarMat(e)){
				if(op == "MAT"){
					string nombre;
					nombre = t->getID() + ".txt";
					ofstream salida(nombre.c_str(), ios::out | ios::app);
					salida<<e->getApe1()<<" "<<e->getApe2()<<" "<<e->getNombre()<<" "<<e->getDNI()<<endl;
					salida.close();
					borrarEstudianteMat(e, t->getID());
				}
				else{
					borrarEstudianteMat(e,t->getID());
					if(!t->listaEsperaVacia()){
						t->obtenerEnEsperaMayorNota(e);
						t->insertarEstudianteAdmitido(e);
						t->insertarEnArbol(e);
					}
				}

			}
		}

		Titulaciones->avanzar();
	}

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
	Titulaciones->moverInicio();
	while(!Titulaciones->finLista()){
		Titulaciones->consultar(t);
		t->buscarEstudiante(dni,e);
		Titulaciones->avanzar();
	}
	cout <<"--------------------------"<< endl;
	cout <<"Información personal:"<<endl<<endl;
	cout<<"Nombre: "<<e->getNombre()<<" "<<e->getApe1()<<" "<<e->getApe2()<<endl;
	cout<<"Nota: "<<e->getNota()<<endl;

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

void titulaciones::cargaDeArboles(){ //TODO CAMBIADO
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

