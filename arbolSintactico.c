#ifndef arbolsint_h
#define arbolsint_h

#include "declaraciones.c"
#include "instrucciones.c"
#include <iostream>
using namespace std;

class ArbolSintactico{
public:

	Declaracion *left;
	Instruccion *right;

	ArbolSintactico(Declaracion *l, Instruccion *r): left(l),right(r){};

	bool verificar(){
		MapaDeTipos PrincMap = MapaDeTipos();

		if (left->verificar(PrincMap)){ // Verificamos las declaraciones 
			if (left->declararRobots(PrincMap)){ // Poblamos el mapa
				return right->verificar(PrincMap); // Verificamos los tipos en las instrucciones.
			}
		}
		return false;
	}

	void toString(int i){
		right->toString(i);
	}

};

#endif