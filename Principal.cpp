
#include <iostream>
#include <string>
#include "Referi.h"
#include "Terrorista.h"
#include "Graficador.h"
using namespace std;



int main() {
//	try {
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
			Casilla* casilla = pTablero->obtenerCasillero(jugadorDeTurno->obtenerCoordenadaXJugada(),
								jugadorDeTurno->obtenerCoordenadaYJugada());
		//	if(casilla->getMinasCercanas()== 0){
		//		for (unsigned int i=0; i<cantidadFilas; i++){
			//		for(unsigned int j=0; i<cantidadFilas; i++){
			//			 casilla = pTablero->obtenerCasillero(i,j);
						//if(!casilla->estaOculta()){
			//				Buscaminas.imprimirJugada(i+1,j+1,casilla->mostrarCasilla());
		//				}
			//		}
			//	}

	//		else{
			Buscaminas.imprimirJugada(jugadorDeTurno->obtenerCoordenadaXJugada()+1,jugadorDeTurno->obtenerCoordenadaYJugada()+1,
						  casilla->mostrarCasilla());
		//	}
		}


	//} catch (string e) {
	//	cout << "Error:" << e << endl;
	//}
	cout<<"Gracias por jugar!"<<endl;
	return 0;
}
