#include <sstream>
#include <string>

using namespace std;


//Esta es una simple clase de tokens de error
// se recibe un string (que siempre va a ser un caracter)
// y hasta ahora su unica funcion es imprimir los errores 

class errToken{

	string content;
	int posFila;
	int posColu;

public:

	// funcion constructora

	errToken(string c, int fila, int colu){
		content = c;
		posFila = fila;
		posColu = colu;
	}

	// funcion que retorna un string con la descripcion
	// del error

	string toString(){
		ostringstream result; // Para crear el error se usa un stringstream
							  // Al que simplemente se le van agregando las partes.
		result << "Error: Caracter inesperado \"";
		result << content;
		result << "\" en la fila " << posFila;
		result << ", columna " << posColu;
		return result.str();
	}

};