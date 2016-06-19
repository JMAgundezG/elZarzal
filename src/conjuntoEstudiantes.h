/*
 * conjuntoEstudiantes.h
 *
 *  Created on: 12/4/2016
 *      Author: jmagundezg
 */

#ifndef CONJUNTOESTUDIANTES_H_
///============================================================================
// Name        : ConjuntoEstudiantes.h
// Author 	   : José Manuel Agúndez García & Jaime Alcántara Arnela
// Version     : Curso 15/16
// Copyright   : *
// Description : Header File de la clase elZarzal
//============================================================================
#define CONJUNTOESTUDIANTES_H_

#include "listapi.h"
#include "Estudiante.h"
#include "arbol.h"
#include "comparaestudiante.h"

class conjuntoEstudiantes {

private:
	ListaPI <Estudiante *> *estudiantes;
	Arbol<Estudiante *, ComparaPtrEstudiante> *arbolEstudiantes;

	/*
	 *Pre: Estudiantes cargados en árboles
	 *Post:Devuelve al estudiante
	 *Complejidad:O(log n)
	 *Parámetros: apellido1, apellido2, nombre (string) *abbu (árbol de estudiantes)
	 */
	bool buscarEstudianteArbol(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu,Estudiante *&e,string apellido1, string apellido2, string nombre);

	//=================================================================
	/*
	 *Pre: Alumnos matriculados
	 *Post:Devuelve Arbol con raices similares
	 *Complejidad:O(log n)
	 *Parámetros: const &apel (string)
	 */
	Arbol<Estudiante *, ComparaPtrEstudiante> * similares(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel);


	//=================================================================
		/*
		 *Pre:
		 *Post:Devuelve un valor comparando un estudiante y la información de otro estudiante
		 *Complejidad:O(n)
		 *Parámetros: Estudiante *e, string apellido1, string apellido2, string nombre
		 */
	int comparadorDeEstudiantes(Estudiante *e, string apellido1, string apellido2, string nombre);
public:
	/*
	 * Constructor
	 */
	conjuntoEstudiantes();

	/*
	 *Pre: Instancia creada y cargada con estudiantes
	 *Post:Devuelve al estudiante y avisa si lo ha encontrado
	 *Complejidad:O(n)
	 *Parámetros: DNI (string) *&e (estudiante)
	 */
	bool buscar(string DNI, Estudiante *&e);
	//==================================================
	/*
	 *Pre: Instancia creada y cargada con estudiantes
	 *Post:Borra el estudiante con el DNI que se le da por parámetro
	 *Complejidad:O(n)
	 *Parámetros: DNI (string)
	 */
	void borrar(string DNI);
	//=============================================================================
	/*
	 *Pre: Instancia creada y cargada con estudiantes
	 *Post:Borra al estudiante con menor nota
	 *Complejidad:O(1)
	 */
	void borrarMenorNota();
	//=============================================================================
	/*
	 *Pre: Instancia creada
	 *Post:comprueba si la lista está vacía
	 *Complejidad:O(1)
	 */
	bool vacio();
	//===============================================
	/*
	 *Pre: Instancia creada y cargada con estudiantes
	 *Post:Devuelve al estudiante con mayor nota
	 *Complejidad:O(1)
	 *Parámetros: *&e (estudiante)
	 */
	void obtenerEstudianteMayorNota(Estudiante *&e);
	//==============================================
	/*
	 *Pre: Instancia creada y cargada con estudiantes
	 *Post:Devuelve al estudiante con menor nota
	 *Complejidad:O(1)
	 *Parámetros:*&e (estudiante)
	 */
	void obtenerEstudianteMenorNota(Estudiante *&e);
	//==============================================
	/*
	 *Pre: Instancia creada
	 *Post:inserta al estudiante
	 *Complejidad:O(n)
	 *Parámetros: *nuevoEstudiante (Estudiante)
	 */
	void insertarOrdenNota (Estudiante *nuevoEstudiante);
	//===============================================
	/*
	 *Pre: Instancia creada y cargada con estudiantes
	 *Post:Muestra a los estudiantes por terminal
	 *Complejidad:O(n)
	 */
	void mostrarEstudiantes();
	//===============================================
	/*
	 *Pre: Instancia creada y cargada con estudiantes
	 *Post:Carga en los árboles los estudiantes de las listas
	 *Complejidad:O(n)
	 */
	void cargaDeArboles();
	//===============================================
	/*
	 *Pre: Alumnos matriculados
	 *Post:Devuelve al estudiante y avisa si lo ha encontrado
	 *Complejidad:O(1)
	 *Parámetros: *e (estudiante)
	 */
	bool buscarMat(Estudiante *e);
	//===============================================
	/*
	 *Pre: AlumnosMatriculados
	 *Post:Borra un estudiante matriculado
	 *Complejidad:O(1)
	 *Parámetros: *e (estudiante)
	 */
	void borrarEstudianteMat(Estudiante *e);
	//===============================================
	/*
	 *Pre: Instancia creada y cargada con estudiantes
	 *Post:Inserta a un estudiante en el arbol
	 *Complejidad:O(1)
	 *Parámetros: *e (estudiante)
	 */
	void insertarEnArbol(Estudiante *e);
	//==============================================
	/*
	 *Pre: Alumnos matriculados
	 *Post:Muestra a los alumnos por terminal
	 *Complejidad:O(1)
	 */
	void mostrarEstudiantesMat();
	//==============================================
	/*
	 *Pre: Alumnos matriculados
	 *Post:Muestra a los alumnos recorriendo el árbol
	 *Complejidad:O(log n)
	 *Parámetros: *abb (Arbol<Estudiante *, ComparaPtrEstudiante>)
	 */
	void inOrden(Arbol<Estudiante *, ComparaPtrEstudiante> *abb);
	//=================================================================
	/*
	 *Pre: Alumnos matriculados
	 *Post:Muestra a los alumnos recorriendo el árbol que contengan la cadena apel
	 *Complejidad:O(log n)
	 *Parámetros: *abbu (Arbol<Estudiante *, ComparaPtrEstudiante>), const &apel (string)
	 */
	void filtroInOrden(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel);
	//=================================================================
	/*
	 *Pre: Alumnos matriculados
	 *Post:Muestra a los alumnos que contengan la raíz apel
	 *Complejidad:O(log n)
	 *Parámetros: const &apel (string)
	 */
	void mostrarSimilares(const string &apel);


	bool buscarEstudianteEnArbol(Estudiante *&e, string apellido1, string apellido2, string nombre);

	~conjuntoEstudiantes();
};

#endif /* CONJUNTOESTUDIANTES_H_ */
