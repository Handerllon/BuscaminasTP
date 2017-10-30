#ifndef TABLERO_H_
#define TABLERO_H_

#include "casilla.h"
#include "Graficador.h"
const unsigned int filasMinimas=10;
const unsigned int columnasMinimas=10;

class Tablero{

private:

	unsigned int filas;

	unsigned int columnas;

	Casilla** tablero;

public:

	/*
	 * POST:crea el tablero con la cantidad de filas y de columnas recibida.
	 */
	Tablero(unsigned int cantidadFilas, unsigned int cantidadColumnas);

	/*
	 * POST: devuelve la cantidad de filas que posee el tablero.
	 */
	unsigned int obtenerCantidadFilas();

	/*
	 * POST:devuelve la cantidad de columnas que posee el tablero.
	 */
	unsigned int obtenerCantidadColumnas();

	/*
	 * PRE: recibe la fila y columna de la casilla que se quiere obtener
	 * POST: devuelve la casilla de la posicion filaDeseada y columnaDeseada.
	 */
	Casilla* obtenerCasillero(unsigned int filaDeseada, unsigned int columnaDeseada);


	/*
	 * Libera los recursos asociados a la clase.
	 */
	~Tablero();
};



#endif /* TABLERO_H_ */
