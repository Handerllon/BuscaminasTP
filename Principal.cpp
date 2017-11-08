
#include <iostream>
#include <string>
#include "Referi.h"
#include "Terrorista.h"
#include "Graficador.h"
using namespace std;



int main() {
	try {
		unsigned int cantidadFilas;
		unsigned int cantidadColumnas;
		unsigned int cantJugadores;
		char dificultad;
		cout << "Ingresa la cantidad de filas: "<< endl;
		cin >> cantidadFilas;
		cout << "Ingresa la cantidad de columnas: " << endl;
		cin >> cantidadColumnas;
		cout << "Cuantos jugadores habra?: " << endl;
		cin >> cantJugadores;
		cout << "Por ultimo, cual sera la dificultad? (F - I - D):" << endl;
		cin >> dificultad;

		Referi referi(cantJugadores,dificultad);
		Tablero tablero(cantidadFilas, cantidadColumnas);
		Tablero* pTablero = &tablero;

		Terrorista terrorista;
		terrorista.plantarBombas(pTablero, dificultad);
		pTablero->calcularProximidades();
		
		//BMP
		Graficador Buscaminas(cantidadFilas,cantidadColumnas);
		Buscaminas.setTablero();
		bool gameover = false;
		referi.getJugadores()->iniciarCursor();

		while((referi.getJugadores()->avanzarCursor()) && !gameover) {
			Jugador* jugadorDeTurno = referi.getJugadores()->obtenerCursor();
			cout << "Turno del jugador " << jugadorDeTurno->getIdentificador() << endl;
			jugadorDeTurno->jugada(pTablero);
			Casilla* casilla = pTablero->obtenerCasillero(jugadorDeTurno->obtenerCoordenadaYJugada(),
								jugadorDeTurno->obtenerCoordenadaXJugada());
			if(casilla->mostrarCasilla()== '0'){
				for(int i=1, i<=cantidadFilas, i++){
					for(int j=1, j=<cantidadColumnas, j++){
						casilla=pTablero->obtenerCasillero(i,j);
						if(!casilla->estaOculta()){
							Buscaminas.imprimirJugada(i,j,casilla->mostrarCasilla());
						}
					}
			}
			else{
			Buscaminas.imprimirJugada(jugadorDeTurno->obtenerCoordenadaYJugada()+1,jugadorDeTurno->obtenerCoordenadaXJugada()+1,
						  casilla->mostrarCasilla());
			}
			if (casilla->mostrarCasilla() == MINA) {
				referi.getJugadores()->remover(jugadorDeTurno->getIdentificador());
				cout << "Ha perdido el jugador " << jugadorDeTurno->getIdentificador() << " !" <<endl;
			}

		}


	} catch (string e) {
		cout << "Error:" << e << endl;
	}
	cout<<"Gracias por jugar!"<<endl;
	return 0;
}
