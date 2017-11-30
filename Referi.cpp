
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

	while((this->getJugadores()->avanzarCursor()) && quedanCasillas ) {
		Jugador* jugadorDeTurno = this->getJugadores()->obtenerCursor();
		if(jugadorDeTurno->getEstaJugando()){
			
			std::cout << "Turno del jugador " << jugadorDeTurno->getIdentificador() << std::endl;
			
			Jugada* jugadaActual = NULL;
			
			bool esJugadaNormal = jugadorDeTurno->elegirJugada(buscaminas, pTablero, jugadaActual, jugadas);
			//Metodo para agregar jugada a estructura
			jugadaActual=jugadorDeTurno->getJugadaRealizada();
			
			Casilla* casilla = pTablero->obtenerCasillero(jugadaActual->getFilaDescubierta(),
								jugadaActual->getColumnaDescubierta());
			
			if(esJugadaNormal && casilla->mostrarCasilla() == MINA){

					jugadorDeTurno->cambiarJugadorAPerdido();

					std::cout << "Ha perdido el jugador " << jugadorDeTurno->getIdentificador() <<
							" !" <<std::endl;
			}
			quedanCasillas=pTablero->quedanCasillasPorDescubrir();
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



void Referi::graficarJugadaEspecial(Graficador &buscaminas, Jugador* jugadorDeTurno, Tablero* pTablero, Casilla* casilla){
	if(casilla->mostrarCasilla()== '0'){

		for(int i=0; i < pTablero->obtenerCantidadFilas();i++){
			for(int j=0; j < pTablero->obtenerCantidadColumnas();j++){

				Casilla* casillaActual= pTablero->obtenerCasillero(i,j);

				if(casillaActual->estaOculta()){
					buscaminas.imprimirJugada(i+1,j+1,'Q');
				}
			}
		}
	}
	else{
		buscaminas.imprimirJugada(jugadorDeTurno->obtenerCoordenadaYJugada()+1,
					  jugadorDeTurno->obtenerCoordenadaXJugada()+1,'Q');
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

void Referi::revertirJugada(){
	Jugador* jugadorActual = this->obtenerJugadores()->obtenerCursor;
	int identificadorActual = jugadorActual->getIdentificador();
	//Nueva posicion estaria dos antes del que jugo
	int nuevaPosicionDeCursor;
	if (identificadorActual == 1){
		nuevaPosicionDeCursor=(this->getJugadores()->contarElementos())-1;
	}
	else if (identificadorActual == 2){
		nuevaPosicionDeCursor=this->getJugadores()->contarElementos();
	}
	else{
		nuevaPosicionDelCursor = jugadorActual->getIdentificador()-2;
	}
	this->getJugadores()->iniciarCursor();
	for (int i=1 ; i<nuevaPosicionDelCursor; i++){
		this->getJugadores()->avanzarCursor();
	}
		
		

Referi::~Referi() {
	delete[]arrayJugadores;
	delete jugadores;
}
