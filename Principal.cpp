
#include <iostream>
#include <string>
#include "Referi.h"
#include "Terrorista.h"
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

		//BMP
		Graficador Buscaminas(cantidadFilas,cantidadColumnas);
		Buscaminas.setTablero();

		bool gameover = false;
		referi.getJugadores()->iniciarCursor();

		while((referi.getJugadores()->avanzarCursor()) && !gameover) {
			Jugador* jugadorDeTurno = referi.getJugadores()->obtenerCursor();

			jugadorDeTurno->jugada(pTablero);
			for (unsigned int i=0; i<cantidadFilas; i++){
				for(unsigned int j=0; i<cantidadFilas; i++){
					Casilla* casilla = pTablero->obtenerCasillero(i,j);
					if(casilla->estaOculta()){
						Buscaminas.imprimirJugada(jugadorDeTurno->obtenerCoordenadaXJugada(),
								jugadorDeTurno->obtenerCoordenadaXJugada(),casilla->mostrarCasilla());
					}
				}
			}
		}


	} catch (string e) {
		cout << "Error:" << e << endl;
	}

	return 0;
}
