#include "tablero.h"

Tablero::Tablero(unsigned int cantidadFilas, unsigned int cantidadColumnas){
	this->filas=cantidadFilas;
	this->columnas=cantidadColumnas;

	this->tablero= new Casilla*[cantidadFilas];
	for (int i=0; i<cantidadFilas; i++)
		tablero[i]= new Casilla[cantidadColumnas];
	
	for (int i=0; i<cantidadFilas; i++){
		for (int j=0; j<cantidadColumnas; j++){
			Casilla actual(i,j);
			tablero[i][j]=actual;
		}
	}


}

unsigned int Tablero::obtenerCantidadFilas(){

	return this->filas;
}

unsigned int Tablero::obtenerCantidadColumnas(){

	return this->columnas;
}

Casilla* Tablero::obtenerCasillero(unsigned int filaDeseada, unsigned int columnaDeseada){
	Casilla* aObtener = &tablero[filaDeseada][columnaDeseada];
	return aObtener;
}

bool Tablero::coordenadasValidas(unsigned int fila, unsigned int columna){
	return (fila>=0) && (fila< obtenerCantidadFilas()) && (columna>=0) && (columna< obtenerCantidadColumnas());
}


void Tablero::calcularProximidades(){
	unsigned int minasEncontradas=0;
	for(int filaActual=0; filaActual<obtenerCantidadFilas(); filaActual++){
		for(int columnaActual=0; columnaActual<obtenerCantidadColumnas(); columnaActual++){

			minasEncontradas=0;
			Casilla* casilleroActual = obtenerCasillero(filaActual,columnaActual);

			if ( !casilleroActual->tieneMina()){

				for(int i= (filaActual-1); i <= (filaActual+1); i++){
					for(int j= (columnaActual-1); j <= (columnaActual+1); j++){

						Casilla* aChequear;
						if(coordenadasValidas(i,j)){
							aChequear=obtenerCasillero(i,j);
							if(aChequear->tieneMina()){
								minasEncontradas++;
							}
						}
					}
				}
			}
			casilleroActual->setMinasCercanas(minasEncontradas);
		}
	}
}

Tablero::~Tablero(){

	for(int i = 0; i < this->filas; i++){
		delete[]tablero[i];
	}
	
	delete[]tablero;
}

