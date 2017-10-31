#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(){

    estaJugando = true;
    identificadorJugador = 0;
    planillaJugador = new Planilla;
    coordenadaXDeJugada = 0;
    coordenadaYDeJugada = 0;

}

unsigned int Jugador::coordenadaXJugada(unsigned int anchoTablero, unsigned int* fila){

    unsigned int valorElegido;

    cout<<"Por favor ingresar la fila elegida para realizar la jugada"<<endl;
    cin>>valorElegido;

    valorElegido=verificarNumero(valorElegido,anchoTablero);
    (*fila) = valorElegido;
    return valorElegido;

}

unsigned int Jugador::coordenadaYJugada(unsigned int altoTablero, unsigned int* columna){

    unsigned int valorElegido;

    cout<<"Por favor ingresar la columna elegida para realizar la jugada"<<endl;
    cin>>valorElegido;

    valorElegido=verificarNumero(valorElegido,altoTablero);
    (*columna)=valorElegido;
    return valorElegido;

}

unsigned int Jugador::verificarNumero(unsigned int numeroIngresado, unsigned int tope){

    bool numeroVerificado=false;

    while (!numeroVerificado){

        if (numeroIngresado>=0 && numeroIngresado<tope)
            numeroVerificado=true;

        else{
            cout<<"El numero ingresado no es valido, por favor, ingresar nuevamente"<<endl;
            cin>>numeroIngresado;
        }
    }

    return numeroIngresado;

}

void Jugador::cambiarJugadorAPerdido(){

    estaJugando=false;

}

bool Jugador::getEstaJugando(){

    return estaJugando;

}

unsigned int Jugador::getIdentificador(){

    return identificadorJugador;

}

void Jugador::setIdentificador(unsigned int identificador) {
	this->identificadorJugador = identificador;
}

void Jugador::mostrarCasillero(Tablero* tablero, unsigned int filaElegida, unsigned int columnaElegida){
	if(tablero->coordenadasValidas(filaElegida,columnaElegida)){

		Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

		if(casillaElegida->estaOculta() && !casillaElegida->tieneBandera()){

			casillaElegida->descubrirCasillero();

			if(!casillaElegida->tieneMina() && (casillaElegida->getMinasCercanas() == 0)){

				mostrarCasillero(tablero,filaElegida+1,columnaElegida);
				mostrarCasillero(tablero,filaElegida-1,columnaElegida);
				mostrarCasillero(tablero,filaElegida,columnaElegida+1);
				mostrarCasillero(tablero,filaElegida,columnaElegida-1);
				mostrarCasillero(tablero,filaElegida+1,columnaElegida+1);
				mostrarCasillero(tablero,filaElegida+1,columnaElegida-1);
				mostrarCasillero(tablero,filaElegida-1,columnaElegida+1);
				mostrarCasillero(tablero,filaElegida-1,columnaElegida-1);

			}
		}
	}
}

void Jugador::jugada(Tablero* tablero){

    unsigned int filaElegida,columnaElegida,tipoDeJugada;
    bool eleccionValida=false;
    unsigned int filasTablero = tablero->obtenerCantidadFilas();
    unsigned int columnasTablero = tablero->obtenerCantidadColumnas();

    filaElegida=this->coordenadaXJugada(columnasTablero,&this->coordenadaXDeJugada);
    columnaElegida=this->coordenadaYJugada(filasTablero,&this->coordenadaYDeJugada);

    Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

    while (not eleccionValida){

        cout<<"Por favor ingresar el numero que corresponde a la jugada elegida"<<endl;
        cout<<"(1) Descubrir casillero"<<endl<<"(2) Colocar bandera"<<endl<<"(3) Quitar bandera"<<endl;
        cin>>tipoDeJugada;

        if (tipoDeJugada==DESCUBRIR_CASILLA){
            mostrarCasillero(tablero,filaElegida,columnaElegida);
            eleccionValida=true;
        }
        else if (tipoDeJugada==COLOCAR_BANDERA){
            casillaElegida->colocarBandera();
            eleccionValida=true;
        }
        else if (tipoDeJugada==QUITAR_BANDERA){
            casillaElegida->quitarBandera();
            eleccionValida=true;
        }
        else{
            cout<<"El tipo de jugada ingresado no es valido, por favor ingresar nuevamente"<<endl;
        }
    }

    actualizarPuntaje(casillaElegida,tipoDeJugada);

}

void Jugador::actualizarPuntaje(Casilla* casillaJugada, unsigned int jugadaElegida){

        if (jugadaElegida==DESCUBRIR_CASILLA && casillaJugada->tieneMina()){
            cambiarJugadorAPerdido();
        }

        else if (jugadaElegida==COLOCAR_BANDERA && casillaJugada->tieneMina()){
            planillaJugador->sumarPuntos(1);
        }

        else if (jugadaElegida==COLOCAR_BANDERA && not casillaJugada->tieneMina()){
            planillaJugador->sumarPuntos(-1);
        }

        else if (jugadaElegida==QUITAR_BANDERA && casillaJugada->tieneMina()){
            planillaJugador->sumarPuntos(-2);
        }

        else if (jugadaElegida==QUITAR_BANDERA && not casillaJugada->tieneMina()){
            planillaJugador->sumarPuntos(2);
        }
}

int Jugador::getPuntajeJugador(){

	return planillaJugador->obtenerPuntaje();
}
unsigned int Jugador::obtenerCoordenadaXJugada(){
	return this->coordenadaXDeJugada;
}
unsigned int Jugador::obtenerCoordenadaYJugada(){
	return this->coordenadaYDeJugada;
}
Jugador::~Jugador(){
	delete planillaJugador;
}
