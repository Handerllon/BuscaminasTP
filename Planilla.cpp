/*
 * Planilla.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: lubuntu
 */

#include "Planilla.h"
#include <string>


Planilla::Planilla() {
	this->puntosTotales = 0;
}

int Planilla:: obtenerPuntaje(){
	return this->puntosTotales;
}

void Planilla:: sumarPuntos(int puntosASumar){
	if(puntosASumar <-3 || puntosASumar >2){
		throw std::string("puntosASumar debe estar entre -3 y 2");
	}

	this->puntosTotales+= puntosASumar;
}

Planilla::~Planilla() {

}
