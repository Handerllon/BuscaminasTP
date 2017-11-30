#include "casilla.h"

Casilla::Casilla(){
	this->fila=0;
	this->columna=0;
	this->minasCercanas=0;
	this->estaMinado= false;
	this->estaConBandera= false;
	this-> estaEscondido= true;
}

Casilla::Casilla(unsigned int filaActual, unsigned int columnaActual){

	this->fila=filaActual;
	this->columna=columnaActual;
	this->minasCercanas=0;
	this->estaMinado=false;
	this->estaConBandera=false;
	this->estaEscondido=true;
}

void Casilla::cambiarCoordenadas(unsigned int nuevaFila, unsigned int nuevaColumna){
	if(this->estaOculta()){
		this->fila=nuevaFila;
		this->columna=nuevaColumna;
	}
}

void Casilla::setMinasCercanas(unsigned int minasEncontradas){
	minasCercanas=minasEncontradas;
}

bool Casilla::tieneMina(){

	return this->estaMinado;
}

bool Casilla::tieneBandera(){

	return this->estaConBandera;
}

bool Casilla::estaOculta(){

	return this->estaEscondido;
}

void Casilla::descubrirCasillero(){

	if(this->estaOculta() && !this->tieneBandera()){
		this->estaEscondido=false;
	}
}

void Casilla::ocultarCasillero(){
	if(!this->estaOculta()){
		this->estaEscondido=true;
	}
}

void Casilla::colocarBandera(){

	if(!this->tieneBandera() && this->estaOculta()){
		this->estaConBandera=true;
	}
}

void Casilla::quitarBandera(){

	if(this->tieneBandera() && this->estaOculta()){
		this->estaConBandera=false;
	}
}

void Casilla::colocarMina(){

	if(!this->tieneMina() && this->estaOculta()){
		this->estaMinado=true;
	}
}

unsigned int Casilla::obtenerFila(){

	return this->fila;
}

unsigned int Casilla::obtenerColumna(){

	return this->columna;
}

unsigned int Casilla::getMinasCercanas(){

	return this->minasCercanas;
}

char Casilla::mostrarCasilla(){
	char estadoActual;
	if(this->estaOculta()){

		if(this->tieneBandera()){
			estadoActual= BANDERA;
		}
		else {
			estadoActual=OCULTA;
		}
	}
	else{
		if(this->tieneMina()){
			estadoActual=MINA;
		}
		else{
			/*como la funcion devuelve un char, casteo minasCercanas a char
			 *y le sumo 48, porque a partir del 48 estan los numeros
			 *en la tabla ASCI.
			 */
			estadoActual=(char)this->minasCercanas + 48;
		}
	}
	return estadoActual;
}


