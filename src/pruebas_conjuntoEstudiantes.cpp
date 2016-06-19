
#include <cstring>
#include <iostream>
#include "conjuntoEstudiantes.h"
#include "Estudiante.h"


void pr_insertarOrdenNota(){
	Estudiante *e0 = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "76044", 4);
	Estudiante *e2 = new Estudiante("ape1", "ape2", "nombre", "76044", 7);
	Estudiante *e3 = new Estudiante("ape1", "ape2", "nombre", "76044", 2);

	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarOrdenNota(e0);
	CEprueba->insertarOrdenNota(e1);
	CEprueba->insertarOrdenNota(e2);
	CEprueba->insertarOrdenNota(e3);

	//El resultado esperado se debe comprobar visualmente
	CEprueba->mostrarEstudiantes();

}

void pr_buscar(){
	Estudiante *e = new Estudiante();
	Estudiante *e0 = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "73044", 4);
	Estudiante *e2 = new Estudiante("ape1", "ape2", "nombre", "76074", 7);
	Estudiante *e3 = new Estudiante("ape1", "ape2", "nombre", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarOrdenNota(e0);
	CEprueba->insertarOrdenNota(e1);
	CEprueba->insertarOrdenNota(e2);
	CEprueba->insertarOrdenNota(e3);

	if(!CEprueba->buscar("76044", e)){
		cout<<"Error en pruebas de buscar, conjuntoEstudiantes"<<endl;
	}

	if(!(e == e0)){
		cout<<"Error en pruebas de buscar, conjuntoEstudiantes"<<endl;
	}


	if(CEprueba->buscar("3333",e)){
		cout<<"Error en pruebas de buscar, conjuntoEstudiantes"<<endl;
	}


}

void pr_borrar(){
	Estudiante *e0 = new Estudiante("ape1", "ape2", "nombre", "76044", 5);
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "73044", 4);
	Estudiante *e2 = new Estudiante("ape1", "ape2", "nombre", "76074", 7);
	Estudiante *e3 = new Estudiante("ape1", "ape2", "nombre", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarOrdenNota(e0);
	CEprueba->insertarOrdenNota(e1);
	CEprueba->insertarOrdenNota(e2);
	CEprueba->insertarOrdenNota(e3);

	CEprueba->borrar("76074");
	CEprueba->borrar("76044");

	//Se deben mostrar por pantalla 2 estudiantes, con los datos de e1 y e3
	CEprueba->mostrarEstudiantes();
}
void pr_borrarMenorNota(){
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "73044", 4);
	Estudiante *e2 = new Estudiante("ape1", "ape2", "nombre", "76074", 7);
	Estudiante *e3 = new Estudiante("ape1", "ape2", "nombre", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarOrdenNota(e1);
	CEprueba->insertarOrdenNota(e2);
	CEprueba->insertarOrdenNota(e3);

	CEprueba->borrarMenorNota();
	//Se deben mostrar por pantalla 2 estudiantes, habiendose borrado el de menor nota (e3)
	CEprueba->mostrarEstudiantes();
}

void pr_obtenerEstudianteMenorNota(){
	Estudiante *e = new Estudiante();
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "73044", 4);
	Estudiante *e2 = new Estudiante("ape1", "ape2", "nombre", "76074", 7);
	Estudiante *e3 = new Estudiante("ape1", "ape2", "nombre", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarOrdenNota(e1);
	CEprueba->insertarOrdenNota(e2);
	CEprueba->insertarOrdenNota(e3);

	CEprueba->obtenerEstudianteMenorNota(e);
	if(!(e == e3)){
		cout<<"Error en pruebas de obtenerEstudianteMenorNota, conjuntoEstudiantes"<<endl;
	}
}

void pr_obtenerEstudianteMayorNota(){
	Estudiante *e = new Estudiante();
	Estudiante *e1 = new Estudiante("ape1", "ape2", "nombre", "73044", 4);
	Estudiante *e2 = new Estudiante("ape1", "ape2", "nombre", "76074", 7);
	Estudiante *e3 = new Estudiante("ape1", "ape2", "nombre", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarOrdenNota(e1);
	CEprueba->insertarOrdenNota(e2);
	CEprueba->insertarOrdenNota(e3);

	CEprueba->obtenerEstudianteMayorNota(e);
	if(!(e == e2)){
		cout<<"Error en pruebas de obtenerEstudianteMayorNota, conjuntoEstudiantes"<<endl;
	}
}

void pr_cargaDeArboles(){
	Estudiante *e1 = new Estudiante("a", "ape2", "nombre", "73044", 4);
	Estudiante *e2 = new Estudiante("c", "ape2", "nombre", "76074", 7);
	Estudiante *e3 = new Estudiante("b", "ape2", "nombre", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarOrdenNota(e1);
	CEprueba->insertarOrdenNota(e2);
	CEprueba->insertarOrdenNota(e3);
	CEprueba->cargaDeArboles();
	CEprueba->mostrarEstudiantesMat();
	//Deben mostrarse por pantalla los tres estudiantes, pues se está mostrando el arbol
}

void pr_borrarEstudianteMat(){
	Estudiante *e1 = new Estudiante("a", "ape2", "nombre", "73044", 4);
	Estudiante *e2 = new Estudiante("c", "ape2", "nombre", "76074", 7);
	Estudiante *e3 = new Estudiante("b", "ape2", "nombre", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarOrdenNota(e1);
	CEprueba->insertarOrdenNota(e2);
	CEprueba->insertarOrdenNota(e3);
	CEprueba->cargaDeArboles();
	cout<<"Alumnos iniciales:"<<endl;
	CEprueba->mostrarEstudiantesMat();
	CEprueba->borrarEstudianteMat(e1);
	cout<<"Alumnos tras borrado:"<<endl;
	CEprueba->mostrarEstudiantesMat();
	//Deben aparecer por pantalla los estudiantes 2 y 3

}

void pr_insertarEnArbol(){
	Estudiante *e1 = new Estudiante("a", "ape2", "nombre", "73044", 4);
	Estudiante *e2 = new Estudiante("c", "ape2", "nombre", "76074", 7);
	Estudiante *e3 = new Estudiante("b", "ape2", "nombre", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarEnArbol(e1);
	CEprueba->insertarEnArbol(e3);
	CEprueba->insertarEnArbol(e2);
	CEprueba->mostrarEstudiantesMat();
	//Deben aparecer por pantalla los 3 alumnos, que se han incluido en el CE utilizando el módulo que se prueba
}

void pr_mostrarSimilares(){
	Estudiante *e1 = new Estudiante("VARGUES", "VALIENTE", "ALBERTO", "73044", 4);
	Estudiante *e2 = new Estudiante("RODRIGUEZ", "RAMOS", "CÁNDIDO", "76074", 7);
	Estudiante *e3 = new Estudiante("VAQUERO", "VALBUENA", "JAVIER", "76244", 2);
	conjuntoEstudiantes *CEprueba = new conjuntoEstudiantes();
	CEprueba->insertarEnArbol(e1);
	CEprueba->insertarEnArbol(e3);
	CEprueba->insertarEnArbol(e2);
	CEprueba->mostrarSimilares("VA");
	//Debe mostrar dos estudiantes, excluyendo al e2

}

/*
int main(){
	//pr_insertarOrdenNota();
	//pr_buscar();
	//pr_borrar();
	//pr_borrarMenorNota();
	//pr_obtenerEstudianteMenorNota();
	//pr_obtenerEstudianteMayorNota();
	//pr_cargaDeArboles();
	//pr_borrarEstudianteMat();
	//pr_insertarEnArbol();
	//pr_mostrarSimilares();

	return 0;
}
*/
