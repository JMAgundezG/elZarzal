//============================================================================
// Name        : user uifiles.h
// Author      : Profesores de la asignatura EDI
// Version     : Curso 15/16
// Copyright   : Your copyright notice
// Description : Definición de la clase user interface
//============================================================================

#ifndef MENU_H_
#define MENU_H_
#include <fstream>
#include "elZarzal.h"
/**
 * Clase de manejo de un menú de operaciones básicas con ficheros de texto y datos
 */

class Menu{
private:

	elZarzal universidad;

	//===========================================================================
		/*
		 * Pre: Instancia inicializada
		 * Post: Devuelve la opción elegida en el menú
		 * Complejidad:O(1)
		 * Parámetros:
		 */
	int  menuPrincipal();

	//===========================================================================
		/*
		 * Pre: Instancia inicializada
		 * Post: Carga el módulo pedido por el usuario en menuPrincipal();
		 * Complejidad:O(n)
		 * Parámetros:
		 */
	void ejecutar ();


	//===========================================================================
		/*
		 * Pre: Titulaciones cargadas
		 * Post: Muestra la titulación que se le pide por consola
		 * Complejidad:O(1)
		 */
	void mostrarTitulacion();

	//===========================================================================
		/*
		 * Pre: Estudiantes cargados en las titulaciones
		 * Post: Muestra el alumno que se le pide por consola ingresando su DNI
		 * Complejidad:O(1)
		 */
	void mostrarEstudiante();

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
//////                           FASE 3 DEL PROYECTO                                 //////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////


	//===========================================================================
		/*
		 * Pre: Estudiantes y titulaciones cargadas
		 * Post: Comienza el proceso de carga de los estudiantes a los árboles
		 * Complejidad:O(1)
		 */
	void cargaDeArboles();

	//===========================================================================
		/*
		 * Pre: Estudiantes matriculados
		 * Post: Crea las titulaciones con los parámetros que vienen en el archivo
		 * Complejidad:O(n)
		 * Parámetros:
		 */
	void mostrarSimilares();
	void cargarEstudiantes();
	void procMatricula();
	void notascorte();
	void consultartitulacion();
	void finalizar();

public:
   
	 Menu();
	 
	 ~Menu();
	 
};

#endif /* UIFILES_H_ */
