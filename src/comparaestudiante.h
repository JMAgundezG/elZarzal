/*
 * comparausuario.h
 *
 *  Created on: 20 de abr. de 2016
 *      Author: jarico
 */

#ifndef COMPARAESTUDIANTE_H_
#define COMPARAESTUDIANTE_H_

#include "Estudiante.h"
#include <string>
using namespace std;


class ComparaPtrEstudiante {
public:
	int operator()(Estudiante *e1, Estudiante *e2) const {

		int flag = 1;
		if (e1->getDNI() == e2->getDNI())
			flag = 0;
		else {
			if (e1->getApe1() < e2->getApe1())
				flag = -1;
			else {
				if (e1->getApe1() == e2->getApe1()) {
					if (e1->getApe2() < e2->getApe2())
						flag = -1;
					else
						if (e1->getApe2() == e2->getApe2())
							if (e1->getNombre() < e2->getNombre())
								flag = -1;
				}
			}
		}
		return flag;
	}

};
#endif /* COMPARAESTUDIANTE_H_ */
