/*
 * Jugador.h
 *
 *  Created on: Oct 18, 2017
 *      Author: lubuntu
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Planilla.h"



class Jugador {

	private:
		int numeroDeJugador;
		bool sigueJugando;
		Planilla PlanillaJugador(int numeroDeJugador);



	public:
		//Pre: "jugadorNumero" debe ser mayor a 0.
		//Post: Se crea el jugador en el ambito del juego.
		Jugador(int jugadorNumero);
		//Pre: La jugada debe ser: D para descubir casillero
		//						   B para colocar bandera
		//						   R para recolocar la bandera de otro jugador
		//						   Q para quitar una bandera.
		//						   S para que el jugador deje de jugar.
		//Post: Se efectua la jugada solicitada.
		void Jugada(char accion);
		virtual ~Jugador();
};

#endif /* JUGADOR_H_ */
