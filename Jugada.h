/*
 * Jugada.h
 *
 *  Created on: Nov 27, 2017
 *      Author: lubuntu
 */

#ifndef JUGADA_H_
#define JUGADA_H_

class Jugada {
private:
	int filaDescubierta;
    int columnaDescubierta;
	int jugadaDeJugadorNumero;
	char opcionElegidaParaJugar;
	char valorDeLaCasilla;


public:

	//Post: Crea la jugada con todos los datos en 0 para luego ser modificados
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
	void modificarOpcionElegidaParaJugar(char opcionElegida);

	//Pre:El 'valorActual' debe estar entre 0 y 8, o Bandera('B')
	//Post: Almacena el valor que posee la casilla moficada
	void modificarElValorDeLaCasilla(char valorActual);


	virtual ~Jugada();
};

#endif /* JUGADA_H_ */
