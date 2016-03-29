



// Alternativa de mapa pero que va a un robot en lugar de un tipo, las funciones deberian ser parecidas.


class MapaRobots{
public:
	vector< map<string, Robot> > listMapas;
	int nivel;
	int currsize;
	MapaDeTipos(){
		nivel = 1;
		currsize = 16; // Tama;o inicial
		listMapas.resize(currsize);
	}


}