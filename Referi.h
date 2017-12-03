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
#include "Jugada.h"

const char FACIL='F';
const char MEDIA= 'M';
const char DIFICIL='D';

class Referi {
	private:
		int cantJugadores;
		Lista <Jugador*>* jugadores;
		char dificultad;
		Jugador* arrayJugadores;
	
		//se encarga de enviarle al graficador los datos para graficar la jugada
		void graficarJugadaNormal(Graficador &buscaminas, Jugador* jugadorDeTurno, Tablero* pTablero, Casilla* casilla);
	
		//Se encarga de Enviarle al graficador los datos para graficar la jugada de tipo "Deshacer"
		void graficarJugadaEspecial(Graficador &buscaminas, Jugador* jugadorDeTurno, Tablero* pTablero, Casilla* casilla);
	
	public:
		//Crea al referi, que contiene 2 jugadores por defecto y dificultad media
		Referi();
		//Crea al referi que manejara una cantidad n de jugadores.
		Referi(unsigned int cantJugadores, char dificultad);

		Lista<Jugador*>* getJugadores();
	
		/*
		 * devuelve si hay al menos un jugador que no haya perdido.
		 */
		bool hayJugadoresVivos();
		/*
		 * ejecuta una ronda de la partida, en otras palabras, le pide una jugada a
		 * cada jugador(si este no perdio aun) y la ejecuta. .
		 */
		void ejecutarRonda(Graficador &buscaminas, Tablero* pTablero, bool &quedanCasillas, LineasDeTiempo<Jugada> &jugadas);
		/*
		 * muestra por pantalla el puntaje de cada uno de los jugadores.
		 */
		void mostrarPuntajes();
		
		//Post: Luego de que se deshace un turno, actualiza los puntos correspondientes
		void revertirJugada(Tablero* tablero, Jugada jugadaADeshacer);


		//Post: Luego de que se rehace un turno, actualiza los puntos correspondientes
		void rehacerJugada(Tablero* tablero, Jugada jugadaARehacer);

		virtual ~Referi();
};

#endif /* REFERI_H_ */
