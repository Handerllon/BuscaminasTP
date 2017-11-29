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
	
	//Pre: Debe recibir los datos de la jugada que ocurrio para ser creado
	//Post: Crea la jugada con todos los datos de la jugada que fue realizada
	Jugada(int fila, int columna, int identificador, int opcion, int valor);

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
	
	//Post: devuelve el valor de la fila en la que se realizo la jugada
	int getFilaDescubierta();

	//Post: devuelve el valor de la columna en la que se realizo la jugada
	int getColumnaDescubierta();

	//Post: devuelve el identificador del jugadorq ue realizo la jugada
	int getJugadorDeLaJugada();

	//Post: devuelve el tipo de jugada que decidio hacer el jugador
	char getTipoDeJugada();


	virtual ~Jugada();
};

#endif /* JUGADA_H_ */
