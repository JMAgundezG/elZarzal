/*
 * titulaciones.h
 *
 *  Created on: 19/4/2016
 *      Author: jmagundezg
 */

#ifndef TITULACIONES_H_
#define TITULACIONES_H_

#include "titulacion.h"
#include "listapi.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class titulaciones {
private:

	ListaPI<titulacion*> *Titulaciones;

public:
	titulaciones();

	//===========================================================================
	/*
	 * Pre: Archivo "titulaciones.txt"
	 * Post: Crea las titulaciones con los parámetros que vienen en el archivo
	 * Complejidad:O(n)
	 * Parámetros:
	 */
	void cargarTitulacionesDesdeArchivo();
	//===========================================================================
	/*
	 * Pre: Titulaciones cargadas
	 * Post:Devuelve si una titulación existe y la propia titulación buscándola
	 * 		mediante el identificador
	 * Complejidad:
	 * Parámetros:
	 */
	bool buscarTitulacion(string id, titulacion * &t);
	//===========================================================================
	/*
	 * Pre: Estudiantes cargados en las titulaciones
	 * Post:Muestra por pantalla al estudiante que coincida con el DNI de ingresado por parámetro
	 * Complejidad:O(n)
	 * Parámetros:dni (string)
	 */
	void buscarEstudiante(string dni);
	//===========================================================================
	/*TODO REVISAR / CAMBIADO
	 * Pre: Listas de las titulaciones cargadas con los alumnos
	 * Post:Comienza el proceso de matriculación en todas las titulaciones
	 * Complejidad:O(n)
	 */
	void cargaDeArboles();
	//===========================================================================
	/*TODO TIENE QUE HACERLO JAIME
	 * Pre:
	 * Post:
	 * Complejidad:
	 * Parámetros:
	 */
	void buscarMat(Estudiante *e, string op, string id);
	//===========================================================================
	/*
	 * Pre:
	 * Post:
	 * Complejidad:
	 * Parámetros:
	 */
	void borrarEstudianteMat(Estudiante *e, string id);
	//===========================================================================
	/*
	 * Pre:
	 * Post:
	 * Complejidad:
	 * Parámetros:
	 */
	void consultarTitulacionMat(string id);
	//===========================================================================
	/*
	 * Pre: Titulaciones cargadas
	 * Post: Muestra por pantalla todas las notas de corte de las titulaciones
	 * Complejidad: O(n)
	 */
	void mostrarNotasDeCorte();

	//===========================================================================
	/*
	 * Pre: Haber realizado el proceso de matriculación
	 * Post:Muestra por pantalla todos alumnos que contengan en su apellido una raíz similar
	 * 		a la ingresada por parámetro
	 * Complejidad:O(n)
	 * Parámetros:raiz (string)
	 */
	void mostrarSimilares(string raiz);

	~titulaciones();
};


#endif /* TITULACIONES_H_ */
