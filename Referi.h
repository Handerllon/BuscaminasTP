/*
 * Referi.h
 *
 *  Created on: Oct 20, 2017
 *      Author: lubuntu
 */

#ifndef REFERI_H_
#define REFERI_H_
#include "ListaCircular.h"
#include "Jugador.h"

const char FACIL='F';
const char MEDIA= 'M';
const char DIFICIL='D';

class Referi {
	private:
		int cantJugadores;
		Lista <Jugador*>* jugadores;
		char dificultad;
	public:
		//Crea al referi, que contiene 2 jugadores por defecto y dificultad media
		Referi();
		//Crea al referi que manejara una cantidad n de jugadores.
		Referi(unsigned int cantJugadores, char dificultad);

		virtual ~Referi();
};

#endif /* REFERI_H_ */
