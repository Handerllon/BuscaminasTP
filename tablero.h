#ifndef TABLERO_H_
#define TABLERO_H_

typedef unsigned int uint;
#include "casilla.h"

class Tablero {
private:
	unsigned int filas;
	unsigned int columnas;
public:
	
	//Post: Crea un tablero de filasMinimas x columnasMinimas
	Tablero();
	/*
	* PRE: Las filas y las columnas deben ser valores mayores a filasMinimas y columnasMinimas.
	* POST: Crea un tablero con determinadas filas y columnas. Dentro de cada espacio del tablero habra una
	* 		Casilla, con su respectivo estado.
	*/
	Tablero(unsigned int filas, unsigned int columnas);
	//Post: Devuelve la cantidad de filas totales.
	unsigned int ObtenerFilas();
	//Post: Devuelve la cantidad de filas totales.
	unsigned int ObtenerColumnas();
	//Post: Libera la memoria tomada.
	~Tablero();
};


#endif /* TABLERO_H_ */
