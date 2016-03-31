#ifndef robot_h
#define robot_h

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "valores.c"
#include "declaraciones.c"
#include "Robot.h"

using namespace std;

// Necesita una funcion que ejecute los comportamientos.

class Robot{
public:
	int tipo;
	int activado;
	int posx;
	int posy;
	Valores valor;		
	string nombre;
	SecuenciaComportamiento* comp;

	Robot(int t,Comport* c, string s){
		nombre = s;
		posx = 0;
		posy = 0;
		comp = (SecuenciaComportamiento*)c;
		tipo = t;
		activado = 0;
	}

	Valores obtenerValor(int t){
		return valor;
	}

	bool estaActivo(){
		return (activado == 1); // Se ve mas bonito esto que castear a booleano :D.
	}

	bool desactivar(Espacio& space, MapaRobots& mapa){
		if (activado){
			activado = 0;
			comp->desactivar(this,space,mapa);
		}
		else{

		}
	}

	bool activar(Espacio& space, MapaRobots& mapa){
		if (!activado){
			activado = 1;
			comp->activar(this,space,mapa);
		}
		else{
			cout << "El robot " << nombre << " se intento activar cuando ya estaba activo." << endl;
			exit(0);
		}
	}

	bool avanzar(Espacio& space, MapaRobots& mapa){
		if (activado){
			comp->avanzar(this,space,mapa);
		}
		else{
			cout << "Error: El robot " << nombre << " se intento avanzar sin estar activo." << endl;
			exit(0);
		}
	}

};




#endif