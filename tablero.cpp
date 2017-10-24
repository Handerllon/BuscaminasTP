#include "tablero.h"

Tablero::Tablero(unsigned int cantidadFilas, unsigned int cantidadColumnas){
	this->filas=cantidadFilas;
	this->columnas=cantidadColumnas;

	this->tablero= new Casilla* [cantidadFilas];
	for(unsigned int i=0; i<cantidadFilas; i++){
		this->tablero[i]= new Casilla[cantidadColumnas];
	}
	Casilla actual;
	for(unsigned int i=0; i<cantidadFilas; i++){
		for(unsigned int j=0; j<cantidadColumnas; j++){
			actual=this->tablero[i][j];
			actual.cambiarCoordenadas(i,j);
		}
	}
}

unsigned int Tablero::obtenerCantidadFilas(){

	return this->filas;
}

unsigned int Tablero::obtenerCantidadColumnas(){

	return this->columnas;
}

Casilla Tablero::obtenerCasillero(unsigned int filaDeseada, unsigned int columnaDeseada){

	return tablero[filaDeseada][columnaDeseada];
}

Tablero::~Tablero(){

	unsigned int totalFilas=this->obtenerCantidadFilas();
	unsigned int totalColumnas=this->obtenerCantidadColumnas();

	for(unsigned int i=0; i<totalFilas; i++){

		delete []tablero[i];
	}

	delete[]tablero;
}
