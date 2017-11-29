/*
 * Jugada.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: lubuntu
 */

#include "Jugada.h"

Jugada::Jugada(Casilla* casilla, int identificador, int opcion){
	    this-> casillaDeJugada = casilla;
		this-> jugadaDeJugadorNumero = identificador;
		this-> opcionElegidaParaJugar = opcion;
		this-> valorDeLaCasilla = 0 ;

}
/*
void Jugada:: modificarFilaDeJugada(int filaJugada){
	this->filaDescubierta = filaJugada;
}

void Jugada:: modificarColumnaDeJugada(int columnaJugada){
	this->columnaDescubierta = columnaJugada;
}
*/

void Jugada:: modificarJugadorDeLaJugada(int jugadorNumero){
	this->jugadaDeJugadorNumero = jugadorNumero;
}

void Jugada:: modificarOpcionElegidaParaJugar(char opcionElegida){
	this->opcionElegidaParaJugar = opcionElegida;
}
/*
void Jugada:: modificarElValorDeLaCasilla(char valorActual){
	this->valorDeLaCasilla = valorActual;
}

int Jugada::getFilaDescubierta(){

	return this->filaDescubierta;
}

int Jugada::getColumnaDescubierta(){

	return this->columnaDescubierta;
}
*/
int Jugada::getJugadorDeLaJugada(){

	return this->jugadaDeJugadorNumero;
}

char Jugada::getTipoDeJugada(){

	return this->opcionElegidaParaJugar;
}
	
Casilla* Jugada::getCasilla(){
	
	return this->casillaDeJugada;
}

Jugada::~Jugada() {
	// TODO Auto-generated destructor stub
}

