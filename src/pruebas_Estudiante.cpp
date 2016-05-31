#include <cstring>
#include <iostream>
#include "Estudiante.h"


void pr_getApellido1(){
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 7);
	if( "ape1" != e->getApe1()){
		cout<<"Error en pruebas de getApellido1, estudiante"<<endl;
	}
	Estudiante *e2 = new Estudiante("apel1", "ape2", "nombre", "76044", 7);
	if( "apel1" != e2->getApe1()){
		cout<<"Error en pruebas de getApellido1, estudiante"<<endl;
	}
}

void pr_getApellido2(){
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 7);
	if( "ape2" != e->getApe2()){
		cout<<"Error en pruebas de getApellido2, estudiante"<<endl;
	}
	Estudiante *e2 = new Estudiante("ape1", "apel2", "nombre", "76044", 7);
	if( "apel2" != e2->getApe2()){
		cout<<"Error en pruebas de getApellido2, estudiante"<<endl;
	}
}

void pr_getNombre(){
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 7);
	if( "nombre" != e->getNombre()){
		cout<<"Error en pruebas de getNombre, estudiante"<<endl;
	}
	Estudiante *e2 = new Estudiante("ape1", "ape2", "nombre1", "76044", 7);
	if( "nombre1" != e2->getNombre()){
		cout<<"Error en pruebas de getNombre, estudiante"<<endl;
	}
}

void pr_getDNI(){
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 7);
	if( "76044" != e->getDNI()){
		cout<<"Error en pruebas de getDNI, estudiante"<<endl;
	}
	Estudiante *e2 = new Estudiante("ape1", "ape2", "nombre", "76045", 7);
	if( "76045" != e2->getDNI()){
		cout<<"Error en pruebas de getDNI, estudiante"<<endl;
	}
}

void pr_mostrarEstudiante(){
	Estudiante *e = new Estudiante("ape1", "ape2", "nombre", "76044", 7);
	e->mostrarEstudiante();
	//Debe aparecer por pantalla la información del estudiante indicada en el constructor

}


void pr_nuevaSolicitud(){
	Estudiante *e = new Estudiante();
	string solicitud;
	e->nuevaSolicitud("03");
	//Comprobamos también el funcionamiento de getPrimeraTitulacion
	solicitud = e->getPrimeraTitulacion();
	if(solicitud != "03"){
		cout<<"Error en pruebas de nuevaSolicitud, estudiante"<<endl;
	}

}

void pr_titulacionesVacia(){
	Estudiante *e = new Estudiante();
	if(!e->titulacionesVacia()){
		cout<<"Error en pruebas de titulacionesVacia, estudiante"<<endl;
	}
	e->nuevaSolicitud("03");
	if(e->titulacionesVacia()){
		cout<<"Error en pruebas de titulacionesVacia, estudiante"<<endl;
	}


}

/*
int main(){
	//pr_getApellido1();
	//pr_getApellido2();
	//pr_getNombre();
	//pr_getDNI();
	//pr_mostrarEstudiante();
	//pr_nuevaSolicitud();
	//pr_titulacionesVacia();

	return 0;
}
*/








