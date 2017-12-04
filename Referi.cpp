
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

void Referi::ejecutarRonda(Graficador &buscaminas, Tablero* pTablero, bool &quedanCasillas, LineasDeTiempo<Jugada> &jugadas){
	this->getJugadores()->iniciarCursor();

	while((this->getJugadores()->avanzarCursor()) && quedanCasillas) {
		Jugador* jugadorDeTurno = this->getJugadores()->obtenerCursor();

		if(jugadorDeTurno->getEstaJugando()){

			std::cout << "Turno del jugador " << jugadorDeTurno->getIdentificador() << std::endl;

			Jugada* jugadaActual = NULL;
			Jugada jugadaEspecial;

			char tipoDeJugadaElegida= jugadorDeTurno->elegirJugada(buscaminas, pTablero, jugadaActual,jugadas, jugadaEspecial);

			jugadaActual=jugadorDeTurno->getJugadaRealizada();

			Casilla* casilla = pTablero->obtenerCasillero(jugadaActual->getFilaDescubierta(),
								jugadaActual->getColumnaDescubierta());

			if( (tipoDeJugadaElegida == JUGADA_NORMAL) && casilla->mostrarCasilla() == MINA){

				jugadorDeTurno->cambiarJugadorAPerdido();

				std::cout << "Ha perdido el jugador " << jugadorDeTurno->getIdentificador() <<
					" !" <<std::endl;
			}
			else if(tipoDeJugadaElegida == JUGADA_DESHACER){
				revertirJugada(pTablero, jugadaEspecial);
			}
			else if(tipoDeJugadaElegida == JUGADA_REHACER){
				rehacerJugada(pTablero, jugadaEspecial);
			}
			quedanCasillas=pTablero->quedanCasillasPorDescubrir();
		}
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

//Agarra el jugador actual y busca al anterior, actualiza los puntos de ese jugador
void Referi::revertirJugada(Tablero* tablero, Jugada jugadaADeshacer){

	int numeroJugadorAModificar = jugadaADeshacer.getJugadorDeLaJugada();
	Jugador* jugadorAModificar = &arrayJugadores[numeroJugadorAModificar -1];

	Casilla* casillaAfectada = tablero->obtenerCasillero(jugadaADeshacer.getFilaDescubierta(),
								jugadaADeshacer.getColumnaDescubierta());

	int jugadaRealizada = jugadaADeshacer.getTipoDeJugada();

	if(jugadaRealizada == DESCUBRIR_CASILLA && !casillaAfectada->tieneMina()){
		jugadorAModificar->cambiarPuntaje(-1);
	}
	else if(jugadaRealizada == COLOCAR_BANDERA){
		jugadorAModificar->actualizarPuntaje(casillaAfectada,QUITAR_BANDERA);
	}
	else {
		jugadorAModificar->actualizarPuntaje(casillaAfectada,COLOCAR_BANDERA);
	}
}

void Referi::rehacerJugada(Tablero* tablero, Jugada jugadaARehacer){

	int numeroJugadorAModificar = jugadaARehacer.getJugadorDeLaJugada();
	Jugador* jugadorAModificar = &arrayJugadores[numeroJugadorAModificar-1];

	Casilla* casillaAfectada = tablero->obtenerCasillero(jugadaARehacer.getFilaDescubierta(),
								jugadaARehacer.getColumnaDescubierta());

	int jugadaRealizada = jugadaARehacer.getTipoDeJugada();

	jugadorAModificar->actualizarPuntaje(casillaAfectada,jugadaRealizada);

}
Referi::~Referi() {
	delete[]arrayJugadores;
	delete jugadores;
}
