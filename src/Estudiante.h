///============================================================================
// Name        : Estudiante.cpp
// Author      : Profesores de la asignatura
// Version     : Curso 15/16
// Copyright   : UEx
// Description : definición de la clase estudiante
//============================================================================


#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include <cstring>
#include <iostream>
#include "cola.h"
using namespace std;

class Estudiante {
	string ape1;				//Primer apellido
	string ape2;				//Segundo apellido
	string nombre;				//Nombre
	string dni;					//DNI
	float nota;					//Nota
	Cola <string> *solicitudes; //Cola de solicitudes


public:
	/*
	 * Constructor por defecto
	 */
	Estudiante();

	/*
	 * Constructor parametrizado
	 */
	Estudiante(string ape1, string ape2, string nombre, string dni, float nota);

	/*
	 *Pre: instancia inicializada
	 *Post:añade una nueva solicitud
	 *Complejidad:O(1)
	 *Parámetros: n (string)
	 */
	void nuevaSolicitud(string n);

	/*
		 *Pre: instancia inicializada
		 *Post:Muestra al estudiante
		 *Complejidad:O(1)*/
	void   mostrar();

	/*
	 * getter de Ape1
	 */
	string getApe1();

	/*
	 * getter de ape2
	 */
	string getApe2();

	/*
	 * getter de nota
	 */
	float  getNota();

	/*
	 * getter de DNI
	 */
	string getDNI();

	/*
	 * getter del nombre
	 */
	string getNombre();

	/*
	 * getter de la primera titulación de la lista
	 */
	string getPrimeraTitulacion();

	/*
	 *Pre: instancia inicializada
		 *Post:comprueba si la lista de titulaciones está vacía
		 *Complejidad:O(1)
		 */
	bool titulacionesVacia();

	/*
		 *Pre: {}
		 *Post:comprueba según su DNI si dos estudiantes son el mismo
		 *Complejidad:O(1)
		 *Parámetros: *aux (Estudiante)
		 */
	bool sonElMismo(Estudiante *aux);

	/*
		 *Pre: Instancia inicializada
		 *Post:Muestra al alumno por terminal
		 *Complejidad:O(1)*/
	void mostrarEstudiante();


	bool   operator <  (const Estudiante &e);
	bool   operator == (const Estudiante &e);

	~Estudiante();


};


#endif /* ESTUDIANTE_H_ */
