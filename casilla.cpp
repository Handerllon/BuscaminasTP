#include "casilla.h"
using namespace std;

Casilla::Casilla(int x, int y) {
	this->fila = x;
	this->columna = y;
	this->minasCercanas = 0;
	this->tieneMina = false;
	this->cubierta = true;
	this->marcada = false;
}

int Casilla::mostrarFila() {
	return this->fila;
}


int Casilla::mostrarColumna() {
	return this->columna;
}


bool Casilla::estaCubierta() {
	return (this->cubierta == true);
}


void Casilla::descubrir() {
	if(this->cubierta)
		this->cubierta = false;
}


bool Casilla::estaMarcada() {
	return (this->marcada == true);
}


void Casilla::marcar() {
	if(!this->marcada)
		this->marcada = true;
	else
		this->marcada = false;
}


void Casilla::mostrar() {
	if(this->cubierta) {
		if(this->marcada)
			cout << MARCADA;
		else
			cout << CUBIERTA;
	}
	else {
		if(this->tieneMina)
			cout << MINA;
		else
			cout << this->minasCercanas;
	}
}





