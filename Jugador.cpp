/*
 * Jugador.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: lubuntu
 */

#include "Jugador.h"
#include <string>

Jugador::Jugador(int jugadorNumero) {
	if(jugadorNumero < 1){
		throw std:: string("jugadorNumero debe ser mayor a 0");
	}
	else{
		this->numeroDeJugador= jugadorNumero;
		this->sigueJugando= true;
	}
}

void Jugador:: Jugada(char accion){
	if(accion == 'D' || accion == 'd'){

	}
	else if(accion == 'B' || accion == 'b'){

	}
	else if(accion == 'R' || accion == 'r'){

		}
	else if(accion == 'Q' || accion == 'q'){

		}
	else if(accion == 'S' || accion == 's'){

		}
	else{
		throw std:: string("Jugada invalida");
	}
}

Jugador::~Jugador() {
	// TODO Auto-generated destructor stub
}

