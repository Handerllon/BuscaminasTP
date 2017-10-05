#ifndef TABLERO_H_
#define TABLERO_H_

typedef unsigned int uint;
#include "casilla.h"

class Tablero {
private:
	uint filas;
	uint columnas;
public:
	/*
	* PRE: Las filas y las columnas deben ser valores mayores a cero.
	* POST: Crea un tablero con determinadas filas y columnas. Dentro de cada espacio del tablero habra una
	* 		Casilla, con su respectivo estado.
	*/
	Tablero(uint filas, uint columnas);
};


#endif /* TABLERO_H_ */
