#ifndef CASILLA_H_
#define CASILLA_H_

#include <iostream>

char const MINA = 'M';
char const OCULTA = 'X';
char const BANDERA = 'B';

// Cada casilla individual del tablero del buscaminas.
class Casilla {
private:
	int fila;
	int columna;
	int minasCercanas;
	bool tieneMina;
	bool estaOculta;
	bool tieneBandera;

public:
	/*
	* PRE: La fila y la columna ingresada deben estar entre 0 y Tablero->ObtenerFilas / Tablero->ObtenerColumnas
	* POST: Devuelve una casilla ubicada en la posicion ('x','y') del tablero.
	*       Estara cubierta, desmarcada, sin mina, y con el valor 'minasCercanas' en cero.
	*/
	Casilla(int fila, int columna);

	/*
	* POST: Devuelve la fila de la casilla.
	*/
	int ObtenerFila();

	/*
	* POST: Devuelve la columna de la casilla.
	*/
	int ObtenerColumna();

	/*
	* POST: Devuelve si la casilla esta oculta.
	*/
	bool estaCubierta();

	/*Pre: La casilla debe estar oculta.
	* POST: Descubre la casilla.
	*/
	void descubrirCasilla();

	/*
	* POST: Devuelve si la casilla esta o no marcada.
	*/
	bool tieneBandera();

	/*
	* POST: Si la casilla esta marcada la desmarca.
	        Si la casilla esta desmarcada la marca.
	*/
	void colocarBandera();

	/*
	* POST: Muestra la casilla en su estado actual. Puede ser marcada o no, descubierta o no.
	* 		Si esta descubierta, muestra el numero de minas cercanas o, si es una mina, el simbolo correspondiente.
	*/
	void mostrarCasilla();



};

#endif /* CASILLA_H_ */

