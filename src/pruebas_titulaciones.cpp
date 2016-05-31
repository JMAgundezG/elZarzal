#include <cstring>
#include <iostream>
#include "titulaciones.h"
#include "titulacion.h"


void pr_buscarTitulacion(){
	titulaciones *T = new titulaciones();
	titulacion *t = new titulacion();
	if(!T->buscarTitulacion("01",t)){
		cout<<"Error en pruebas de buscarTitulacion, titulaciones"<<endl;
	}
	if(T->buscarTitulacion("10",t)){
		cout<<"Error en pruebas de buscarTitulacion, titulaciones"<<endl;
	}
}


void pr_cargarTitulacionesDesdeArchivo(){
	titulaciones *T = new titulaciones();
	titulacion *t = new titulacion();
	T->buscarTitulacion("01",t);
	if(t->getID() != "01" || t->getNombre() != "Grado en Ingenieria Informática en Ingeniería del Software" ){
		cout<<"Error en pruebas de cargarTitulacionesDesdeArchivo, titulaciones"<<endl;
	}
	T->buscarTitulacion("02",t);
	if(t->getID() != "02" || t->getNombre() != "Grado en Ingenieria Informática en Ingeniería del Computadores" ){
		cout<<"Error en pruebas de cargarTitulacionesDesdeArchivo, titulaciones"<<endl;
	}
	T->buscarTitulacion("03",t);
	if(t->getID() != "03" || t->getNombre() != "Grado en Ingenieria de Sonido e Imagen en Telecomunicacion" ){
		cout<<"Error en pruebas de cargarTitulacionesDesdeArchivo, titulaciones"<<endl;
	}
	T->buscarTitulacion("04",t);
	if(t->getID() != "04" || t->getNombre() != "Grado en Ingenieria Civil Construcciones Civiles" ){
		cout<<"Error en pruebas de cargarTitulacionesDesdeArchivo, titulaciones"<<endl;
	}
	T->buscarTitulacion("05",t);
	if(t->getID() != "05" || t->getNombre() != "Grado en Ingenieria Civil Hidrologia" ){
		cout<<"Error en pruebas de cargarTitulacionesDesdeArchivo, titulaciones"<<endl;
	}
	T->buscarTitulacion("06",t);
	if(t->getID() != "06" || t->getNombre() != "Grado en Ingenieria Civil Transportes y Servicios Urbanos" ){
		cout<<"Error en pruebas de cargarTitulacionesDesdeArchivo, titulaciones"<<endl;
	}
	T->buscarTitulacion("07",t);
	if(t->getID() != "07" || t->getNombre() != "Grado en Edificación" ){
		cout<<"Error en pruebas de cargarTitulacionesDesdeArchivo, titulaciones"<<endl;
	}

}



//El módulo matricula sólo llama al módulo equivalente en cada una de las titulaciones, luego las pruebas se llevan
// a cabo en pruebas_conjuntoEstudiantes.cpp


/*
int main(){
	//pr_cargarTitulacionesDesdeArchivo();
	//pr_buscarTitulacion();

	return 0;
}

*/
