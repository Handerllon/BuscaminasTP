#include "tablero.h"

Tablero::Tablero(uint filas, uint columnas) {

	this->filas = filas;
	this->columnas = columnas;

	int** tablero = new int*[filas];
	for (uint i = 0; i < filas; i++) {
		tablero[i] = new int[columnas];
		for (uint j = 0; j < columnas; j++) {
			Casilla casilla(i, j);
		}
	}
}
