#ifndef arbolsint_h
#define arbolsint_h

#include "valores.c"
#include "MapaRobots.c"
#include "mapa.c"
#include "Robot.c"
#include "Espacio.c"
#include "declaraciones.c"
#include "instrucciones.c"
#include <iostream>

using namespace std;

class ArbolSintactico{
public:

	Declaracion *left;
	Instruccion *right;
	int lineNo;


	ArbolSintactico(Declaracion *l, Instruccion *r,int line): left(l),right(r){
		lineNo = line;
	};

	bool ejecutar(){
		Espacio Matriz = Espacio();
		MapaRobots mapa = MapaRobots();
		if (left->ejecutar(mapa)){
			return right->ejecutar(Matriz,mapa);
		}
	}


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