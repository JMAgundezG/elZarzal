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

void Menu::cargarEstudiantes(){
	universidad.cargarEstudiantesEnTitulaciones();
}

void Menu::mostrarTitulacion(){
	string seleccion;

	cout<< "¿Qué titulación quiere que sea mostrada?"<< endl;
	universidad.mostrarInfoTitulaciones();
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

void Menu::cargaDeArboles(){
	universidad.cargaDeArboles();
}

void Menu::procMatricula(){
	universidad.procesoMatricula();
}

void Menu::notascorte(){
	universidad.mostrarNotasDeCorte();
}

void Menu::consultartitulacion(){
	string seleccion;
	cout<< "¿Qué titulación quiere que sea mostrada?"<< endl;
	universidad.mostrarInfoTitulaciones();
	cin >> seleccion;
	cout <<endl;
	universidad.consultarTitulacionMat(seleccion);
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
		case 9:
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
	cout << "   FASE 1"<<endl;
	cout << "   1. Asignación de estudiantes"<< endl;
	cout << "   2. Consulta de una titulación" << endl;
	cout << "   3. Consulta de un estudiante" <<endl;
	cout <<endl;
	cout << "   FASE 2"<<endl;
	cout << "   4. Matrícula"<< endl;
	cout << "   5. Proceso de Matrícula "<<endl;
	cout << "   6. Consultar titulación"<< endl;
	cout << "   7. Consulta por raíz"<<endl;
	cout << "   8. Nota de corte"<<endl;
	cout << "   9. Finalizar"<< endl << endl;
	cout << "Opcion elegida:  ";cin>> opcion;
	cout<<"----------------------------------------------------------------------"<<endl;
	cin.ignore();
	return opcion;
}
