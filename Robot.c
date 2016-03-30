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
	string nombre; // Solo para errores. (Nota: se puede apostar que los voy a usar para algo mas)
	SecuenciaComportamientos* comp;

	Robot(int t,Comport* c, string s){
		nombre = s;
		posx = 0;
		posy = 0;
		comp = (SecuenciaComportamientos*)c;
		tipo = t;
		activado = 0;
	}

	valores obtenerValor(int t){
		return valor;
	}

	bool estaActivo(){
		return (activado == 1); // Se ve mas bonito esto que castear a booleano :D.
	}

	bool desactivar(Espacio& space, MapaRobots& mapa){
		; // Aqui hay que poner que haga lo de desactivar.
	}

	bool activar(Espacio& space, MapaRobots& mapa){
		;
	}

	bool avanzar(Espacio& space, MapaRobots& mapa){
		;
	}

};




#endif