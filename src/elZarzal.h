///============================================================================
// Name        : elZarzal.h
// Author 	   : José Manuel Agúndez García & Jaime Alcántara Arnela
// Version     : Curso 15/16
// Copyright   : *
// Description : Header File de la clase elZarzal
//============================================================================
#include "titulaciones.h"
#include "Preinscripciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifndef ELZARZAL_H_
#define ELZARZAL_H_

class elZarzal {
private:

	Preinscripciones *preinscripciones; //Las preinscripciones de todos los estudiantes que han pedido alguna
	//entrar en alguna titulación de esta universidad

	titulaciones *Titulaciones;			//El conjunto de titulaciones existentes en El Zarzal



public:

	/*
	 * Constructor por defecto;
	 *
	 */
	elZarzal();

	/*
	 * Pre:
	 * Post:
	 * Complejidad:
	 * Descripción: Vacía la pila de estudiantes de las preinscripciones y organiza a los
	 * 				estudiantes entre las distintas titulaciones.
	 */
	void cargarEstudiantesEnTitulaciones();

	/*
	 * Pre:
	 * Post:
	 * Complejidad:
	 * Descripción: Muestra la lista de admitidos y la lista de espera de la titulación que le pidamos
	 */
	void mostrarTitulacion(string id);

	/*
	 *Pre: Estudiantes cargados
	 *Post:Pasa los estudiantes de listas a árboles
	 *Complejidad:O(1)
	 */
	void cargaDeArboles();
	/*
	 *Pre: Alumnos en árboles
	 *Post:Matricula a los alumnos según el archivo matyrenuncias.txt
	 *Complejidad:O(n)
	 */
	void procesoMatricula();

	/*
	 *Pre: Alumnos cargados
	 *Post:Muestra a un estudiante
	 *Complejidad:O(1)
	 *Parámetros: DNI (string)
	 */
	void mostrarEstudiante(string dni);

	/*
	 *Pre: Alumnos matriculados
	 *Post:Muestra a los alumnos de una titulación
	 *Complejidad:O(1)
	 *Parámetros: id (string)
	 */
	void consultarTitulacionMat(string id);

	/*
	 *Pre: Alumnos matriculados
	 *Post:Muestra las notas de corte
	 *Complejidad: O(1)
	 */
	void mostrarNotasDeCorte();

	/*
	 *Pre: Alumnos matriculados
	 *Post:Muestra a los alumnos que contengan la misma raíz
	 *Complejidad:O(1)
	 *Parámetros: raiz (string)
	 */
	void mostrarEstudiantesSimilares(string raiz);



	/*
	 *Pre: Titulaciones cargadas
	 *Post:Muestra los datos de todas las titulaciones
	 *Complejidad:O(1)
	 *Parámetros:
	 */
	void mostrarInfoTitulaciones();

	/*
	 * Destructor;
	 */
	~elZarzal();
};
#endif /* ELZARZAL_H_ */

