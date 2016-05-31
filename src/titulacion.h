/*
 * Archivo:titulacion.h
 *
 * Autores: José Manuel Agúndez García y Jaime Alcántara Arnela
 *
 * Clase: Titulación
 *
 */
#ifndef TITULACION_H
#define TITULACION_H

#include "conjuntoEstudiantes.h"
#include <string>
#include <fstream>
#include <iostream>


class titulacion{

private:

	string identificador;                      // Número que identifica a cada titulación (Entero)
	int admitidosPosibles;					// Cantidad máxima de alumnos que pueden entrar a una titulación
	int numAdmitidos;						// Número de admitidos en ese momento en la titulación
	string nombreTitulacion;				// Nombre de la titulación
	conjuntoEstudiantes *admitidos;			// Conjunto de estudiantes que han sido admitidos en la titulación
	conjuntoEstudiantes *enEspera;			// Conjunto de estudiantes que están en la lista de espera
	int notaCorte;



public:


	/*
	 * Constructor por defecto
	 * Pre: {}
	 * Post:Crea o inicializa una instancia de la clase
	 * Complejidad: O(1)
	 */
	titulacion ();

	/*
	 * Constructor parametrizado
	 * Pre: Valores para los parámetros de la instancia
	 * Post:Crea o inicializa una instancia de la clase según los parámetros asignados
	 * Complejidad: O(1)
	 *
	 * Parámetros
	 * ID:(Entero) Número identificador de la titulación
	 * nombre:(Cadena) Nombre de la titulación
	 * admitidosPosibles:(Entero) Número máximo de alumnos que puede admitir la titulación
	 */
	titulacion(string id, string nombre, int admitidosPosibles);

	/*
	 * Getter del identificador:
	 * Pre: {}
	 * Post:Devuelve el identificador de la titulación (String)
	 * Complejidad: O(1)
	 */
	string getID();


	/*
	 * Getter del nombre:
	 * Pre: {}
	 * Post:Devuelve el nombre de la titulación (String)
	 * Complejidad: O(1)
	 */
	string getNombre();


	/*
	 * Pre: Una instancia inicializada
	 * Post:Estudiante insertado en la titulación en la lista de admitidos
	 * Complejidad: O(n)
	 *
	 * Descripción: Inserta un estudiante en la lista de admitidos.
	 */
	void insertarEstudianteAdmitido(Estudiante *e);
	//===============================================================================
	/*
	 * Pre: Una instancia inicializada
	 * Post:Estudiante insertado en la titulación y además comprueba si ha sido admitido
	 * Complejidad: O(n)
	 *
	 * Descripción: Inserta un estudiante en la lista de admitidos. En el caso en el que fuera
	 */

	void insertarEstudianteEnEspera(Estudiante *e);

	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en las listas de los conjuntos de estudiantes de
	 * 		la titulación
	 *
	 * Post:Muestra por pantalla los estudiantes de la titulación
	 * Complejidad: O(1)
	 *
	 * Descripción: Muestra todos los estudiantes de la titulación
	 */
	void mostrarEstudiantes();

	//===============================================================================
	/*
	 * Pre:
	 * Post:Comprueba si la lista de admitidos está llena
	 * Complejidad: O(1)
	 */
	bool estaLLena();

	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en las listas
	 * Post:Devuelve el estudiante de menor nota
	 * Complejidad: O(n)
	 * Parámetros: *&e (Estudiante)
	 */
	void obtenerAdmitidoMenorNota(Estudiante *&e);
	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en las listas
	 * Post:Estudiante con el DNI que le damos por el parámetro
	 * Complejidad: O(1)
	 * Parámetros: dni (string), *&e (Estudiante);
	 */
	void buscarEstudiante(string dni, Estudiante * &e);

	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en las listas
	 * Post:Borra el estudiante con menor nota de la lista de estudiantes admitidos
	 * Complejidad: O(1)
	 */
	void borrarEstudianteMenorNota();

	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en las listas
	 * Post: Llena los árboles copiando los estudiantes de las listas
	 * Complejidad: O(1)
	 */
	void cargaDeArboles();
	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en listas y árboles y pasar el procedimiento de
	 * 		matriculación
	 * Post:Busca al estudiante en el árbol e indica si está
	 * Complejidad: O(1)
	 * Parámetros: *e (Estudiante)
	 */
	bool buscarMat(Estudiante *e);
	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en listas y árboles y pasar el procedimiento de
	 * 		matriculación
	 * Post: Borra a un estudiante del conjunto de estudiantes en el que esté
	 * Complejidad: O(1)
	 */
	void borrarEstudianteMat(Estudiante *e, string id);

	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en listas y árboles y pasar el procedimiento de
	 * 		matriculación
	 * Post: Devuelve al estudiante con mayor nota en la lista de espera
	 * Complejidad: O(1)
	 * Parámetros:
	 */
	void obtenerEnEsperaMayorNota(Estudiante *&e);

	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en listas
	 * Post: Inserta en el árbol al estudiante
	 * Complejidad: O(1)
	 * Parámetros: *&e (Estudiante)
	 */
	void insertarEnArbol(Estudiante *&e);
	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en listas y árboles y pasar el procedimiento de
	 * 		matriculación
	 * Post: Muestra los estudiantes de la titulación tras la matriculación
	 * Complejidad: O(1)
	 */
	void mostrarTitulacionMat();

	//===============================================================================
	/*
	 * setter de la nota
	 * Complejidad O(1)
	 * Parámetros: nota (float)
	 */
	void setNota(float nota);

	//===============================================================================
	/*
	 * Getter de la nota
	 * Complejidad: O(1)
	 */
	float obtenerNotaCorte();

	//===============================================================================
	/*
	 * Pre: Instancia inicializada
	 * Post: Comprueba si la lista de espera está vacía
	 * Complejidad: O(1)
	 */
	bool listaEsperaVacia();

	//===============================================================================
	/*
	 * Pre: Estudiantes cargados en listas y árboles y pasar el procedimiento de
	 * 		matriculación
	 * Post: Busca a los estudiantes con una raíz parecida y los muestra por pantalla
	 * Complejidad: O(1)
	 * Parámetros: raiz (string)
	 */

	void buscarSimilares(string raiz);
	//===============================================================================
	~titulacion ();

};

#endif // TITULACION_H
