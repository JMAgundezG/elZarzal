
#include <cstring>
#include <iostream>
#include "conjuntoEstudiantes.h"
#include "elZarzal.h"




void pr_mostrarTitulacion(){

	elZarzal *z = new elZarzal();
	z->mostrarTitulacion("01");
	//La prueba es visual. Deben aparecer 45 estudiantes en admitidos y 10 en lista de espera

}

void pr_mostrarNotasDeCorte(){

	elZarzal *z = new elZarzal();
	z->cargaDeArboles();
	z->procesoMatricula();
	z->mostrarNotasDeCorte();
	//La prueba es visual

}



/*
int main(){
	pr_mostrarTitulacion();
	pr_mostrarNotasDeCorte();

	return 0;
}
*/
