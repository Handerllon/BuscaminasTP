/*
 * Referi.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: lubuntu
 */

#include "Referi.h"

namespace Referi {

Referi::Referi() {
	this->jugadores = 2;
	this->dificultad= MEDIA;
	//Se crea la lista con 2 jugadores

}
Referi::Referi(unsigned int jugadores, char dificultad) {
	//jugadores es enviado por metodo de inicializador
	this->jugadores=jugadores;
	this->dificultad=dificultad;
	//se crea la lista ocn cantidad de 'jugadores'
}

Referi::~Referi() {
	// TODO Auto-generated destructor stub
}

} /* namespace Referi */
