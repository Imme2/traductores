#ifndef robot_h
#define robot_h

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

union valores{
	int num;
	bool booleano;
	char caracter;
};

// Necesita una funcion que ejecute los comportamientos.

class Robot{
	int tipo;
	int activado;
	int posx;
	int posy;
	valores valor;		

	SecuenciaComportamientos* comp;

	Robot(int t,Comport* c){
		posx = 0;
		posy = 0;
		comp = (SecuenciaComportamientos*)c;
		tipo = t;
		activado = 0;
	}

	valores obtenerValor(int t){
		return valor;
	}

	

};







#endif