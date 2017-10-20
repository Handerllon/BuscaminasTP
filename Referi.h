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

namespace Referi {
const char FACIL='F';
const char MEDIA= 'M';
const char DIFICIL='D';

class Referi {
	private:
		int jugadores;
		Lista <Jugador*>* Jugadores;
		char dificultad;
	public:
		//Crea al referi, que contiene 2 jugadores por defecto y dificultad media
		Referi();
		//Crea al referi que manejara una cantidad n de jugadores.
		Referi(unsigned int jugadores, char dificultad);

		virtual ~Referi();
};

} /* namespace Referi */

#endif /* REFERI_H_ */
