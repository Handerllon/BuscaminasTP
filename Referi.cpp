/*
 * Referi.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: lubuntu
 */

#include "Referi.h"

namespace Referi {

Referi::Referi() {
	this->cantJugadores = 2;
	this->dificultad= MEDIA;
	this->jugadores = new Lista<Jugador*>;
}
	
Referi::Referi(unsigned int cantJugadores, char dificultad) {
	//jugadores es enviado por metodo de inicializador
	this->cantJugadores=cantJugadores;
	this->dificultad=dificultad;			
	this->jugadores = new Lista<Jugador*>;
	
	//Se crean los jugadores y se los agrega a la lista circular
	Jugador* arrayJugadores = new Jugador[cantJugadores];
	for (int i = 0; i < cantJugadores; i++) {
		jugadores.agregar(arrayJugadores[i]);
	}
	
}

Referi::~Referi() {
	// TODO Auto-generated destructor stub
}

} /* namespace Referi */
