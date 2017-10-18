#include "Tablero.h"
#include "Casilla.h"

const int filasMinimas=15;
const int columnasMinimas=15;

Tablero::Tablero(uint filas, uint columnas) {
	if(filas < filasMinimas || columnas < columnasMinimas){
		throw std:: string("El tablero debe ser de un minimo de 15")
	}
	this->filas = filas;
	this->columnas = columnas;

	int* tablero = new Casila [filas][columnas];
}
