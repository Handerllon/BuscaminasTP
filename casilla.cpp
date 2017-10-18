#include "Casilla.h"
using namespace std;

Casilla::Casilla(int fila, int columna) {
	this->fila = fila;
	this->columna = columna;
	this->minasCercanas = 0;
	this->tieneMina = false;
	this->estaOculta = true;
	this->TieneBandera = false;
}

int Casilla::obtenerFila() {
	return this->fila;
}


int Casilla::obtenerColumna() {
	return this->columna;
}


bool Casilla::estaOculta() {
	return this->estaOculta;
}


void Casilla::descubrirCasilla() {
	if(this->EstaOculta){
		this->estaOculta = false;
	}
	else{
		throw std:: string("La casilla ya esta Descubierta");
	}
}


bool Casilla::tieneBandera() {
	return this->tieneBandera;
}


void Casilla::colocarBandera() {
	if(!this->tieneBandera)
		this->tieneBandera = true;
	else
		this->tieneBandera = false;
}


void Casilla::mostrarCasilla() {
	if(this->estaOculta) {
		if(this->tieneBandera)
			cout << BANDERA;
		else
			cout << OCULTA;
	}
	else {
		if(this->tieneMina)
			cout << MINA;
		else
			cout << this->minasCercanas;
	}
}





