#include <cstring>
#include <iostream>
#include "titulacion.h"
#include "Estudiante.h"


void pr_getID(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	if( "02" != t->getID()){
		cout<<"Error en pruebas de getID, titulacion"<<endl;
	}
	titulacion *t2 = new titulacion("04", "ejemplo", 3);
	if( "04" != t2->getID()){
		cout<<"Error en pruebas de getID, titulacion"<<endl;
	}
}

void pr_getNombreT(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	if( "ejemplo" != t->getNombre()){
		cout<<"Error en pruebas de getNombre, titulacion"<<endl;
	}
	titulacion *t2 = new titulacion("02", "ejemplo2", 3);
	if( "ejemplo2" != t2->getNombre()){
		cout<<"Error en pruebas de getNombre, titulacion"<<endl;
	}
}

void pr_mostrarEstudiantes(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e2 = new Estudiante("ape1Ej", "ape2Ej", "nombreEj", "76044", 5);
	t->insertarEstudianteAdmitido(e);
	t->insertarEstudianteEnEspera(e2);
	//Debe aparecer por consola un estudiante en cada apartado (admitido y en espera)
	t->mostrarEstudiantes();
}

void pr_insertarEstudianteAdmitido(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e2 = new Estudiante("ape1Ej", "ape2Ej", "nombreEj", "76044", 5);
	Estudiante *e3 = new Estudiante("ape1Ej2", "ape2Ej2", "nombreEj2", "76044", 5);
	t->insertarEstudianteAdmitido(e);
	t->insertarEstudianteAdmitido(e2);
	t->insertarEstudianteAdmitido(e3);
	//Se comprueba visualmente, el estudiante debe estar en el apartado de admitidos
	t->mostrarEstudiantes();
}

void pr_insertarEstudianteEnEspera(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e2 = new Estudiante("ape1Ej", "ape2Ej", "nombreEj", "76044", 5);
	Estudiante *e3 = new Estudiante("ape1Ej2", "ape2Ej2", "nombreEj2", "76044", 5);
	t->insertarEstudianteEnEspera(e);
	t->insertarEstudianteEnEspera(e2);
	t->insertarEstudianteEnEspera(e3);
	//Se comprueba visualmente, el estudiante debe estar en el apartado de espera
	t->mostrarEstudiantes();
}

void pr_estaLLena(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e2 = new Estudiante("ape1Ej", "ape2Ej", "nombreEj", "76044", 5);
	Estudiante *e3 = new Estudiante("ape1Ej2", "ape2Ej2", "nombreEj2", "76044", 5);
	if(t->estaLLena()){
		cout<<"Error en pruebas de estaLLena, titulacion"<<endl;
	}
	t->insertarEstudianteAdmitido(e);
	t->insertarEstudianteAdmitido(e2);
	if(t->estaLLena()){
		cout<<"Error en pruebas de estaLLena, titulacion"<<endl;
	}
	t->insertarEstudianteAdmitido(e3);
	if(!t->estaLLena()){
		cout<<"Error en pruebas de estaLLena, titulacion"<<endl;
	}

}

void pr_obtenerAdmitidoMenorNota(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	Estudiante *e = new Estudiante();
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e2 = new Estudiante("ape1Ej", "ape2Ej", "nombreEj", "76045", 3);
	Estudiante *e3 = new Estudiante("ape1Ej2", "ape2Ej2", "nombreEj2", "76046", 7);
	t->insertarEstudianteAdmitido(e1);
	t->insertarEstudianteAdmitido(e2);
	t->insertarEstudianteAdmitido(e3);
	t->obtenerAdmitidoMenorNota(e);
	if(!(e==e2)){
		cout<<"Error en pruebas de obtenerAdmitidoMenorNota, titulacion"<<endl;
	}
}

void pr_borrarEstudianteMenorNota(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e2 = new Estudiante("ape1Ej", "ape2Ej", "nombreEj", "76045", 3);
	Estudiante *e3 = new Estudiante("ape1Ej2", "ape2Ej2", "nombreEj2", "76046", 7);
	t->insertarEstudianteAdmitido(e1);
	t->insertarEstudianteAdmitido(e2);
	t->insertarEstudianteAdmitido(e3);
	t->borrarEstudianteMenorNota();
	//Sólo deben aparecer dos estudiantes: e1 y e3
	t->mostrarEstudiantes();
}

void pr_buscarEstudiante(){
	titulacion *t = new titulacion("02", "ejemplo", 3);
	Estudiante *e = new Estudiante();
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e2 = new Estudiante("ape1Ej", "ape2Ej", "nombreEj", "76045", 3);
	Estudiante *e3 = new Estudiante("ape1Ej2", "ape2Ej2", "nombreEj2", "76046", 7);
	Estudiante *e4 = new Estudiante("ape1Ej3", "ape2E3", "nombreE3", "76047", 9);
	Estudiante *e5 = new Estudiante("ape1Ej4", "ape2Ej4", "nombreEj4", "76048", 2);
	t->insertarEstudianteAdmitido(e1);
	t->insertarEstudianteAdmitido(e4);
	t->insertarEstudianteAdmitido(e3);
	t->insertarEstudianteEnEspera(e2);
	t->insertarEstudianteEnEspera(e5);
	t->buscarEstudiante("76047",e);
	if(!(e==e4)){
		cout<<"Error en pruebas de buscarEstudiante, titulacion"<<endl;
	}
	t->buscarEstudiante("76048",e);
	if(!(e==e5)){
		cout<<"Error en pruebas de buscarEstudiante, titulacion"<<endl;
	}
}

/*
int main(){
	//pr_getID();
	//pr_getNombreT();
	//pr_insertarEstudianteAdmitido();
	//pr_insertarEstudianteEnEspera();
	//pr_mostrarEstudiantes();
	//pr_estaLLena();
	//pr_obtenerAdmitidoMenorNota();
	//pr_borrarEstudianteMenorNota();
	//pr_buscarEstudiante();

	return 0;
}
*/
