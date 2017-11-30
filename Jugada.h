/*
 * Jugada.h
 *
 *  Created on: Nov 27, 2017
 *      Author: lubuntu
 */

#ifndef JUGADA_H_
#define JUGADA_H_
#include "casilla.h"

class Jugada {
private:
	int filaDescubierta;
	int columnaDescubierta;
	int jugadaDeJugadorNumero;
	int opcionElegidaParaJugar;


public:
	
	//Pre: Debe recibir los datos de la jugada que ocurrio para ser creado
	//Post: Crea la jugada con todos los datos de la jugada que fue realizada
	Jugada();

	//Pre: 'filaJugada' debe estar entre 0 y tablero->ObtenerFilas()
	//Post: Almacena la fila que se realizo en la jugada
	void modificarFilaDeJugada(int filaJugada);

	//Pre: 'columnaJugada' debe estar entre 0 y tablero->ObtenerFilas()
	//Post: Almacena la columna que se hizo en la jugada
	void modificarColumnaDeJugada(int columnaJugada);

	//Pre: 'jugadaDeJugadorNumero' debe estar entre 0 y referi->obtenerCantidadDeJugadores()
	//Post: Modifica el numero del jugador que realizo la jugada
	void modificarJugadorDeLaJugada(int jugadorNumero);

	//Pre: 'opcionElegida' debe ser o una bandera, o descubir un casillero, o quitar bandera
	//Post: modifica la opcion de la jugada a un valor valido
	void modificarOpcionElegidaParaJugar(int opcionElegida);
	
	//Post: devuelve el valor de la fila en la que se realizo la jugada
	int getFilaDescubierta();

	//Post: devuelve el valor de la columna en la que se realizo la jugada
	int getColumnaDescubierta();

	//Post: devuelve el identificador del jugadorq ue realizo la jugada
	int getJugadorDeLaJugada();

	//Post: devuelve el tipo de jugada que decidio hacer el jugador
	int getTipoDeJugada();

	virtual ~Jugada();
};

#endif /* JUGADA_H_ */
