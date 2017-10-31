#ifndef TABLERO_H_
#define TABLERO_H_

#include "casilla.h"
#include "Graficador.h"


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
	 * PRE: recibe la fila y columna de la casilla que se quiere obtener, estos valores tienen que estar
	 * 		entre 0 y obtenerCantidadFilas() / obtenerCantidadColumnas().
	 * POST: devuelve la casilla de la posicion filaDeseada y columnaDeseada.
	 */
	Casilla* obtenerCasillero(unsigned int filaDeseada, unsigned int columnaDeseada);
	
	/*
	 *POST:devuelve true si las coordenadas recibidas estan dentro del rango del tablero.
	 */
	bool coordenadasValidas(unsigned int fila, unsigned int columna);
	
	/*
	PRE: Es necesario que el tablero este incicializado, ya con las minas puestas en cada una de las casillas
	POST: Asigna las minas cercanas a cada uno de los casilleros dentro del tablero
	*/
	void calcularProximidades();

	/*
	 * Libera los recursos asociados a la clase.
	 */
	~Tablero();
};



#endif /* TABLERO_H_ */
