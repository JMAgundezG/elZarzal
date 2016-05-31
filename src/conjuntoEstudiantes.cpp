///============================================================================
// Name        : conjuntoEstudiantes.cpp
// Author 	   : José Manuel Agúndez García & Jaime Alcántara Arnela
// Version     : Curso 15/16
// Copyright   : *
// Description : Source File de la clase conjuntoEstudiantes
//============================================================================


#include "conjuntoEstudiantes.h"

conjuntoEstudiantes::conjuntoEstudiantes() {
	estudiantes = new ListaPI<Estudiante *>;
	arbolEstudiantes = new Arbol<Estudiante *, ComparaPtrEstudiante>;

}

bool conjuntoEstudiantes::vacio(){
	return estudiantes->estaVacia();
}

bool conjuntoEstudiantes::buscar (string DNI, Estudiante *&e) {

	Estudiante *s = NULL;

	string ID;
	bool encontrado = false;




	estudiantes ->moverInicio();

	while(!estudiantes->finLista()){

		estudiantes->consultar(s);
		ID = s->getDNI();

		if(ID.find(DNI) == 0){
			e = s;
			encontrado = true;
			}

		estudiantes->avanzar();
	}
	return encontrado;
}



void conjuntoEstudiantes::borrar (string DNI) {

	string dni1;
	Estudiante *s = NULL;

	estudiantes ->moverInicio();

		while(!estudiantes->finLista()){

			estudiantes->consultar(s);
			dni1 = s->getDNI();

			if(DNI.find(dni1) == 0){
				estudiantes->borrar();

				}

			estudiantes->avanzar();
		}

}


void conjuntoEstudiantes::insertarOrdenNota (Estudiante *nuevoEstudiante) {

	Estudiante *e = NULL;
	bool encontrado=false;

	estudiantes->moverInicio();
	if(!estudiantes->estaVacia()){
		while(!estudiantes->finLista() && !encontrado){
			estudiantes->consultar(e);
			if(e->getNota() < nuevoEstudiante->getNota()){
				estudiantes->insertar(nuevoEstudiante);
				encontrado=true;

			}
			else{
				estudiantes->avanzar();
			}
		}
		if(!encontrado){
			estudiantes->insertar(nuevoEstudiante);
		}

    }
	else{
		estudiantes->insertar(nuevoEstudiante);
	}


}

void conjuntoEstudiantes::borrarMenorNota(){
	estudiantes->moverFinal();
	estudiantes->borrar();


}

void conjuntoEstudiantes::obtenerEstudianteMayorNota(Estudiante *&e){
	estudiantes->moverInicio();
	estudiantes->consultar(e);

}

void conjuntoEstudiantes::obtenerEstudianteMenorNota(Estudiante *&e){
	estudiantes->moverFinal();
	estudiantes->consultar(e);

}

void conjuntoEstudiantes::mostrarEstudiantes(){

	Estudiante *e = new Estudiante;
	estudiantes->moverInicio();
	while(!estudiantes->finLista()){
		estudiantes->consultar(e);
		e->mostrar();
		estudiantes->avanzar();

	}

	delete e;
}

void conjuntoEstudiantes::cargaDeArboles(){ // TODO CAMBIADO
	estudiantes->moverInicio();
	Estudiante *e;
	while(!estudiantes->finLista()){
		estudiantes->consultar(e);
		arbolEstudiantes->insertar(e);
		estudiantes->avanzar();
	}

}

bool conjuntoEstudiantes::buscarMat(Estudiante *e){
	return arbolEstudiantes->pertenece(e);
}

void conjuntoEstudiantes::borrarEstudianteMat(Estudiante *e){
	if(arbolEstudiantes->pertenece(e)){
		arbolEstudiantes->borrar(e);
	}
	borrar(e->getDNI());
}

void conjuntoEstudiantes::insertarEnArbol(Estudiante *e){
	arbolEstudiantes->insertar(e);
}

void conjuntoEstudiantes::mostrarEstudiantesMat(){
	inOrden(arbolEstudiantes);

}

void conjuntoEstudiantes::inOrden(Arbol<Estudiante *, ComparaPtrEstudiante> *abb){
	Arbol<Estudiante *, ComparaPtrEstudiante> *aux;

	if(!abb->vacio()){

		aux = abb->hijoIzq();
		if (aux != NULL){
			inOrden(aux);
		}
		cout << abb->raiz()->getApe1()<<" "<<abb->raiz()->getApe2()<<" "<<abb->raiz()->getNombre()<<" "<<abb->raiz()->getDNI()<<" "<<abb->raiz()->getNota()<<endl;
		aux = abb->hijoDer();
		if(aux != NULL){
			inOrden(aux);
		}

	}
}

void conjuntoEstudiantes::filtroInOrden(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel) {

	Arbol<Estudiante *, ComparaPtrEstudiante> *aux;
	string raiz;

	if (!abbu->vacio()) {
		aux = abbu->hijoIzq();
				if (aux != NULL) {
					filtroInOrden(aux,apel);

				}
				if(abbu->raiz()->getApe1().find(apel)==0){
				abbu->raiz()->mostrar();
				}

				aux = abbu->hijoDer();
				if (aux != NULL) {
					filtroInOrden(aux,apel);
				}


	}
}

void conjuntoEstudiantes::mostrarSimilares(const string &apel) {

	Arbol<Estudiante *, ComparaPtrEstudiante> *abb;

	if (!arbolEstudiantes->vacio()) {

		abb = this->similares(arbolEstudiantes, apel);
		if (abb != NULL) {
			cout << "Mostrando similares a: " << apel << endl;
			filtroInOrden(abb, apel);
		} else {
			cout << "Nadie que empiece por: " << apel << endl;
		}
	}
}

Arbol<Estudiante *, ComparaPtrEstudiante> * conjuntoEstudiantes::similares(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel) {

	Estudiante *e;
	Arbol<Estudiante *, ComparaPtrEstudiante> *izq;
	Arbol<Estudiante *, ComparaPtrEstudiante> *der;
	Arbol<Estudiante *, ComparaPtrEstudiante> *aux = NULL;
	string raiz;

	if (!abbu->vacio()) {
		e = abbu->raiz();
		raiz = e->getApe1();

		if (raiz.find(apel) == 0) {
			aux = abbu;
		} else {
			if (raiz < apel) {
				der = abbu->hijoDer();
				if (der != NULL) {
					aux = similares(der, apel);
				}
			} else {
				izq = abbu->hijoIzq();
				if (izq != NULL) {
					aux = similares(izq, apel);
				}
			}
		}
	}

	return aux;
}

conjuntoEstudiantes::~conjuntoEstudiantes() {
	estudiantes->moverInicio();
	while(!estudiantes->finLista()){
		estudiantes->borrar();
	}

}

