#include "Tablero.h"
#include "Casilla.h"

const int filasMinimas=15;
const int columnasMinimas=15;

Tablero::Tablero() {
	int* tablero = new Casila [filasMinimas][columnasMinimas];

Tablero::Tablero(unsigned int filas, unsigned int columnas) {
	if(filas < filasMinimas || columnas < columnasMinimas){
		throw std:: string("El tablero debe ser de un minimo de 15")
	}
	this->filas = filas;
	this->columnas = columnas;

	int* tablero = new Casila [filas][columnas];
}

unsigned int Tablero:: ObtenerFilas(){
	return this->filas;
}

unsigned int Tablero:: ObtenerColumnas(){
	return this->columnas;
}
Tablero:: ~Tablero(){
	delete tablero[];
}

