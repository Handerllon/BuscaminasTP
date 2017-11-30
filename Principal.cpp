#include <iostream>
#include <string>
#include "Referi.h"
#include "Terrorista.h"
#include "Graficador.h"
#include "LineasDeTiempo.h"
using namespace std;



int main() {
	try {
		unsigned int cantidadFilas;
		unsigned int cantidadColumnas;
		unsigned int cantJugadores;
		int cantidadDeBombas;
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
		cantidadDeBombas=terrorista.plantarBombas(pTablero, dificultad);
		tablero.cambiarCasillasPorDescubrir(cantidadDeBombas);
		pTablero->calcularProximidades();
		
		LineasDeTiempo<Jugada> jugadas;
		Jugada jugadaInicial;
		jugadas.nuevoTurno(jugadaInicial);

		//BMP
		Graficador Buscaminas(cantidadFilas,cantidadColumnas);
		Buscaminas.setTablero();

		bool quedanCasillas = true;


		while(referi.hayJugadoresVivos() && quedanCasillas){
			referi.ejecutarRonda(Buscaminas, pTablero, quedanCasillas, jugadas);
			referi.mostrarPuntajes();
		}

	} catch (string e) {
		cout << "Error:" << e << endl;
	}
	cout<<"Gracias por jugar!"<<endl;
	return 0;
}

