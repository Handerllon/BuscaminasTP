#ifndef CASILLA_H_
#define CASILLA_H_

#include <iostream>

char const MINA = '*';
char const CUBIERTA = ' ';
char const MARCADA = '?';

// Cada casilla individual del tablero del buscaminas.
class Casilla {
private:
	int fila;
	int columna;
	int minasCercanas;
	bool tieneMina;
	bool cubierta;
	bool marcada;

public:
	/*
	* PRE: La fila 'x' y la columna 'y' ingresada deben estar dentro del rango posible del tablero.
	* POST: Devuelve una casilla ubicada en la posicion ('x','y') del tablero.
	*       Estara cubierta, desmarcada, sin mina, y con el valor 'minasCercanas' en cero.
	*/
	Casilla(int x, int y);

	/*
	* POST: Devuelve la fila de la casilla.
	*/
	int mostrarFila();

	/*
	* POST: Devuelve la columna de la casilla.
	*/
	int mostrarColumna();

	/*
	* POST: Devuelve si la casilla esta o no cubierta.
	*/
	bool estaCubierta();

	/*
	* POST: Si la casilla esta cubierta la descubre.
	*/
	void descubrir();

	/*
	* POST: Devuelve si la casilla esta o no marcada.
	*/
	bool estaMarcada();

	/*
	* POST: Si la casilla esta marcada la desmarca.
	        Si la casilla esta desmarcada la marca.
	*/
	void marcar();

	/*
	* POST: Muestra la casilla en su estado actual. Puede ser marcada o no, descubierta o no.
	* 		Si esta descubierta, muestra el numero de minas cercanas o, si es una mina, el simbolo correspondiente.
	*/
	void mostrar();



};

#endif /* CASILLA_H_ */
