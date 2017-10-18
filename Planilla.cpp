/*
 * Planilla.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: lubuntu
 */

#include "Planilla.h"
#include <string>


Planilla::Planilla(int jugador) {
	if(jugador<1){
		 throw std::string("No puede existir un jugador menor al 1");
	}
	else{
		this->NumeroJugador= jugador;
		this->puntosTotales= 0;
	}
}

int Planilla:: obtenerPuntaje(){
	return this->puntosTotales;
}

void Planilla:: sumarPuntos(int puntosASumar){
	if(puntosASumar <-1 || puntosASumar >2){
		throw std::string("puntosASumar debe estar entre -1 y 2");
	}

	this->puntosTotales+= puntosASumar;
}

Planilla::~Planilla() {

}
