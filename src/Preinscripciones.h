/*
 * Preinscripciones.h
 *
 *  Created on: 11/4/2016
 *      Author: jmagundezg
 */

#ifndef PREINSCRIPCIONES_H_
#define PREINSCRIPCIONES_H_

#include "pila.h"
#include "Estudiante.h"
class Preinscripciones {

	Pila <Estudiante *> *estudiantes; // Pila de estudiantes

public:
	/*
	 *Constructor por defecto
	 */
	Preinscripciones();

	/*
		 Módulo necesario para una prueba
		 */
	void reiniciarEstudiantes();

	/*
		 *Pre: {}
		 *Post:Carga los estudiantes desde el archivo
		 *Complejidad:O(n)
		 *Parámetros: archivo (string)
		 */
	void cargarEstudiantes(string archivo);

	/*
		 *Pre: Alumnos cargados en las listas
		 *Post: saca un estudiante de las preinscripciones y después lo borra
		 *Complejidad:O(1)
		 *Parámetros: *&e (Estudiante)
		 */
	void devolverEstudiante(Estudiante *&e);
	/*
		 *Pre: {}
		 *Post:Combrueba si está vacía
		 *Complejidad:O(1)
		 */
	bool estaVacia();

	~Preinscripciones();

};

#endif /* PREINSCRIPCIONES_H_ */
