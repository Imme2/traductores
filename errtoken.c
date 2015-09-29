#include <sstream>
#include <string>

using namespace std;

class errToken{

	string content;
	int posFila;
	int posColu;

public:

	errToken(string c, int fila, int colu){
		content = c;
		posFila = fila;
		posColu = colu;
	}

	string toString(){
		ostringstream result;

		result << "Error: Caracter inesperado \"";
		result << content;
		result << "\" en la fila " << posFila;
		result << ", columna " << posColu;
		return result.str();
	}

};