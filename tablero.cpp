#include "tablero.h"

Tablero::Tablero(unsigned int cantidadFilas, unsigned int cantidadColumnas){
	this->filas=cantidadFilas;
	this->columnas=cantidadColumnas;

	this->tablero= new Casilla* [cantidadFilas];
	for(unsigned int i=0; i<cantidadFilas; i++){
		this->tablero[i]= new Casilla[cantidadColumnas];
	}
	Casilla* actual;
	for(unsigned int i=0; i<cantidadFilas; i++){
		for(unsigned int j=0; j<cantidadColumnas; j++){
			actual=this->obtenerCasillero(i,j);
			actual->cambiarCoordenadas(i,j);
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
	
	return fila>=0 && fila< obtenerCantidadFilas() && columna>=0 && columna< obtenerCantidadColumnas();
}

void calcularProximidades(){

	for(unsigned int i=0; i<cantidadFilas; i++){
		for(unsigned int j=0; j<cantidadColumnas; j++){

			int minasEncontradas=0

			Casillero* casilleroActual = obtenerCasillero(i,j);

			if (not casilleroActual->tieneMina()){

				if (obtenerCasillero(i+1,j)->tieneMina())
					minasEncontradas++;

				if (obtenerCasillero(i-1,j)->tieneMina())
					minasEncontradas++;

				if (obtenerCasillero(i,j+1)->tieneMina())
					minasEncontradas++;

				if (obtenerCasillero(i,j-1)->tieneMina())
					minasEncontradas++;
			
				if (obtenerCasillero(i+1,j+1)->tieneMina())
					minasEncontradas++;

				if (obtenerCasillero(i+1,j-1)->tieneMina())
					minasEncontradas++;

				if (obtenerCasillero(i-1,j+1)->tieneMina())
					minasEncontradas++;

				if (obtenerCasillero(i-1,j-1)->tieneMina())
					minasEncontradas++;
			}

			casilleroActual->setMinasCercanas(minasEncontradas);

		}
	}
}

Tablero::~Tablero(){

	unsigned int totalFilas=this->obtenerCantidadFilas();

	for(unsigned int i=0; i<totalFilas; i++){

		delete []tablero[i];
	}

	delete[]tablero;
}


