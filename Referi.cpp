
#include "Referi.h"


Referi::Referi() {
	this->cantJugadores = 2;
	this->dificultad= MEDIA;
	this->jugadores = new Lista<Jugador*>;
	this->arrayJugadores=NULL;
}

Referi::Referi(unsigned int cantJugadores, char dificultad) {
	this->cantJugadores=cantJugadores;
	this->dificultad=dificultad;
	this->jugadores = new Lista<Jugador*>;

	//Se crean los jugadores y se los agrega a la lista
	this->arrayJugadores = new Jugador[cantJugadores];
	for (int i = 1; i <= cantJugadores; i++) {
		arrayJugadores[i-1].setIdentificador(i);
		jugadores->agregar(arrayJugadores + (i-1));
	}
}


Lista<Jugador*>* Referi::getJugadores() {
	return jugadores;
}

bool Referi::hayJugadoresVivos(){
	int jugadoresVivos=0;

		this->getJugadores()->iniciarCursor();
		while(this->getJugadores()->avanzarCursor()){

			Jugador* jugadorActual = this->getJugadores()->obtenerCursor();
			if(jugadorActual->getEstaJugando()){
				jugadoresVivos++;
			}

		}
		return jugadoresVivos > 0;
}

void Referi::ejecutarRonda(Graficador &buscaminas, Tablero* pTablero, bool &quedanCasillas){
	this->getJugadores()->iniciarCursor();

	while((this->getJugadores()->avanzarCursor()) && quedanCasillas ) {
		Jugador* jugadorDeTurno = this->getJugadores()->obtenerCursor();
		if(jugadorDeTurno->getEstaJugando()){
			std::cout << "Turno del jugador " << jugadorDeTurno->getIdentificador() << std::endl;
			Jugada* jugadaActual = jugadorDeTurno->jugada(pTablero);
			//Metodo para agregar jugada a estructura
			Casilla* casilla = pTablero->obtenerCasillero(jugadorDeTurno->obtenerCoordenadaYJugada(),
								jugadorDeTurno->obtenerCoordenadaXJugada());
			
			this->graficarJugadaNormal(buscaminas, jugadorDeTurno, pTablero, casilla);
			quedanCasillas=pTablero->quedanCasillasPorDescubrir();
			
			if (casilla->mostrarCasilla() == MINA) {
				jugadorDeTurno->cambiarJugadorAPerdido();
				std::cout << "Ha perdido el jugador " << jugadorDeTurno->getIdentificador() <<
						" !" <<std::endl;
			}
		}
	}
}

void Referi::graficarJugadaNormal(Graficador &buscaminas, Jugador* jugadorDeTurno, Tablero* pTablero, Casilla* casilla){
	if(casilla->mostrarCasilla()== '0'){

		for(int i=0; i < pTablero->obtenerCantidadFilas();i++){
			for(int j=0; j < pTablero->obtenerCantidadColumnas();j++){

				Casilla* casillaActual= pTablero->obtenerCasillero(i,j);

				if(!casillaActual->estaOculta()){
					buscaminas.imprimirJugada(i+1,j+1,casillaActual->mostrarCasilla());
				}
			}
		}
	}
	else{
		buscaminas.imprimirJugada(jugadorDeTurno->obtenerCoordenadaYJugada()+1,
					  jugadorDeTurno->obtenerCoordenadaXJugada()+1,
					  casilla->mostrarCasilla());
	}

}
void Referi::mostrarPuntajes(){

	std::cout<<"+++++++++++++++++++++++++++++"<<std::endl;
	std::cout<<"PUNTAJES ACTUALES:"<<std::endl<<std::endl;

	this->getJugadores()->iniciarCursor();

	while(this->getJugadores()->avanzarCursor()){
		Jugador* jugadorActual= this->getJugadores()->obtenerCursor();
		std::cout<<"Jugador "<< jugadorActual->getIdentificador() <<
				": "<< jugadorActual->getPuntajeJugador() << " puntos " << std::endl;
	}

	std::cout<<"+++++++++++++++++++++++++++++"<<std::endl;
}

Referi::~Referi() {
	delete[]arrayJugadores;
	delete jugadores;
}
