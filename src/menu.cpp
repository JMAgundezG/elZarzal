//============================================================================
// Name        : user interface.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 14/15
// Copyright   : Your copyright notice
// Description : Implementación de la clase user interface
//============================================================================

#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>

#include <iostream>
#include "menu.h"

using namespace std;



string toString(int numero) {
	stringstream flujo;
	string cadena;
	flujo << numero;
	flujo >> cadena;
	return cadena;
}



//PUBLIC
Menu::Menu(){
	ejecutar();
  

}

Menu::~Menu(){
	
}

/// PRIVATE



void Menu::Leer_Alum_txt(){

	ifstream fSolicitudes,fTitulaciones;
	string numeroTitulacion,titulacion,titulaciones,apel1,apel2,nombre,dni,notaAux,solicitudesAux,numeroPlazas,numeroSolicitud;
	int numSolicitudes,numTitulacion,numTitulacionSolicitud;
	bool encontrado;

	  fSolicitudes.open ("estudiantes.txt");
	  fTitulaciones.open("titulaciones.txt");


	  if(fSolicitudes.is_open()){
	   	while(!fSolicitudes.eof()){
	   		getline(fSolicitudes,apel1,'#');
		    getline(fSolicitudes,apel2,'#');
		    getline(fSolicitudes,nombre,'#');
		    getline(fSolicitudes,dni,'#');
		    getline(fSolicitudes,notaAux,'#');
		    getline(fSolicitudes,solicitudesAux);


		    cout << endl;
		    cout << "-------------------------------------"<< endl;
		    cout << "Nombre: " << nombre<<endl;
	    	cout << "Apellidos: "<<apel1 << " " << apel2 << endl;
	    	cout << "DNI: " << dni << endl;
	    	cout << "Nota de corte: " << notaAux << endl;
	    	cout << "Titulaciones solicitadas: ";

	    	numSolicitudes = atof(solicitudesAux.c_str());



	    	while(numSolicitudes>0){

	    		getline(fSolicitudes,numeroSolicitud);

	    		numTitulacionSolicitud = atoi(numeroSolicitud.c_str());

	    		encontrado = false;

	    		fTitulaciones.seekg(0,ios::beg);
	    		//if(!fTitulaciones.fail()){ TODO Preguntar si lo tienes que poner
					while(!encontrado&&!fTitulaciones.eof()){

						getline(fTitulaciones,numeroTitulacion,'#');
						getline(fTitulaciones,titulacion,'#');
						getline(fTitulaciones,numeroPlazas);
						numTitulacion = atoi(numeroTitulacion.c_str());


						if(numTitulacion == numTitulacionSolicitud){

							cout << titulacion << endl;
							encontrado = true;
					//}

	    		}
	    		numSolicitudes--;
	    	}


			    }

	}
	  fTitulaciones.close();
	  fSolicitudes.close();
}
}

void Menu::cargarEstudiantes(){
	universidad.cargarEstudiantesEnTitulaciones();
}
 
void Menu::mostrarTitulacion(){
	string seleccion;

	cout<< "¿Qué titulación quiere que sea mostrada?"<< endl;
	cout<< "01. Grado en Ingenieria Informática en Ingeniería del Software"<< endl;
	cout<< "02. Grado en Ingenieria Informática en Ingeniería del Computadores"<< endl;
	cout<< "03. Grado en Ingenieria de Sonido e Imagen en Telecomunicacion"<< endl;
	cout<< "04. Grado en Ingenieria Civil Construcciones Civiles"<< endl;
	cout<< "05. Grado en Ingenieria Civil Hidrologia"<<endl;
	cout<< "06. Grado en Ingenieria Civil Transportes y Servicios Urbanos"<<endl;
	cout<< "07. Grado en Edificación"<<endl;
	cin >> seleccion;
	cout <<endl;

	universidad.mostrarTitulacion(seleccion);

}

void Menu::mostrarEstudiante(){
	string DNI;
	cout << "Ingrese DNI del estudiante" << endl;
	cin >> DNI;
	cout << endl;

	universidad.mostrarEstudiante(DNI);
}

void Menu::cargaDeArboles(){ //TODO CAMBIADO

	universidad.cargaDeArboles();


}

void Menu::procMatricula(){
	universidad.procesoMatricula();
}

void Menu::notascorte(){
	universidad.mostrarNotasDeCorte();
}

void Menu::consultartitulacion(){
	string raiz;
	cin >> raiz;
	universidad.consultarTitulacionMat(raiz);
}

void Menu::mostrarSimilares(){
string raiz;
cout<< "Escriba la raiz:"<< endl;
cin >> raiz;
cout << endl;

	universidad.mostrarEstudiantesSimilares(raiz);
}

void Menu::finalizar(){

}
void Menu::ejecutar() {

	int       opcion;
	bool      salir = false;

	do {
		opcion = menuPrincipal();

		switch(opcion){

		case 1:
			cargarEstudiantes();
			break;
			
		case 2:
			mostrarTitulacion();
			break;

		case 3:
		    mostrarEstudiante();
			break;
		case 4:
			cargaDeArboles();
			break;	
		case 5:
			procMatricula();

			break;
		case 6:
			consultartitulacion();
			break;
		case 7:
			mostrarSimilares();
			break;
		case 8:
			notascorte();
			break;
		case 0:
			salir=true;
			break;

		default:
			cout << "ERROR: opcion de menu no valida" << endl;
			break;
		}

	} while (!salir);
}


int Menu::menuPrincipal(){

	int opcion;


		cout << endl;
		cout << "__________________ MENU PRINCIPAL ________________" << endl << endl;
		cout << "   FASE 2"<<endl;
		cout << "   1. Asignación de estudiantes"<< endl;
		cout << "   2. Mostrar los alumnos de una titulación" << endl;
		cout << "   3. Mostrar un estudiante" <<endl;
		cout <<endl;
		cout << "   FASE 3"<<endl;
		cout << "   4. Carga de estudiantes en Arboles"<< endl;
		cout << "   5. Buscar alumnos que comienzan por: "<<endl;
		cout << "   6. Nota de corte de una titulación"<< endl;
		cout << "   7. Finalizar"<<endl;
		cout << "   0. SALIR."<< endl << endl;
		cout << "Opcion elegida:  ";cin>> opcion;
		cout<<"----------------------------------------------------------------------"<<endl;
		cin.ignore();



	return opcion;
}



