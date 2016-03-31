
class MapaRobots;
class Robot;
class Espacio;

class Comport{
public:
	virtual ~Comport(){}

	virtual bool activar(Robot*,MapaRobots&,Espacio&){}
	
	virtual bool desactivar(Robot*,MapaRobots&,Espacio&){}

	virtual bool avanzar(Robot*,MapaRobots&,Espacio&){}

	virtual bool verificar(MapaDeTipos&,int){}


};
