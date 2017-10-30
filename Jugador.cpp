#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(unsigned int identificador){

    estaJugando=true;

    identificadorJugador=identificador;

    planillaJugador= new Planilla(this->getIdentificador());

}

unsigned int Jugador::coordenadaXJugada(unsigned int anchoTablero){

    unsigned int valorElegido;

    cout<<"Por favor ingresar la fila elegida para realizar la jugada"<<endl;
    cin>>valorElegido;

    valorElegido=verificarNumero(valorElegido,anchoTablero);

    return valorElegido;

}

unsigned int Jugador::coordenadaYJugada(unsigned int altoTablero){

    unsigned int valorElegido;

    cout<<"Por favor ingresar la columna elegida para realizar la jugada"<<endl;
    cin>>valorElegido;

    valorElegido=verificarNumero(valorElegido,altoTablero);

    return valorElegido;

}

unsigned int Jugador::verificarNumero(unsigned int numeroIngresado, unsigned int tope){

    bool numeroVerificado=false;

    while (not numeroVerificado){

        if (numeroIngresado>=0 && numeroIngresado<=tope)
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

void mostrarCasillero(Tablero* tablero, unsigned int filaElegida, unsigned int columnaElegida){

    Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

    casillaElegida->descubrirCasillero();

    if (casillaElegida->tieneMina() || (casillaElegida->mostrarCasilla())!=0)
        return;

    mostrarCasillero(tablero,filaElegida+1,columnaElegida);
    mostrarCasillero(tablero,filaElegida-1,columnaElegida);
    mostrarCasillero(tablero,filaElegida,columnaElegida+1);
    mostrarCasillero(tablero,filaElegida,columnaElegida-1);
    mostrarCasillero(tablero,filaElegida+1,columnaElegida+1);
    mostrarCasillero(tablero,filaElegida+1,columnaElegida-1);
    mostrarCasillero(tablero,filaElegida-1,columnaElegida+1);
    mostrarCasillero(tablero,filaElegida-1,columnaElegida-1);

}

void Jugador::jugada(Tablero* tablero){

    unsigned int filaElegida,columnaElegida,tipoDeJugada;
    bool eleccionValida=false;
    unsigned int filasTablero = tablero->obtenerCantidadFilas();
    unsigned int columnasTablero = tablero->obtenerCantidadColumnas();

    filaElegida=this->coordenadaXJugada(columnasTablero);
    columnaElegida=this->coordenadaYJugada(filasTablero);

    Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

    while (not eleccionValida){

        cout<<"Por favor ingresar el numero que corresponde a la jugada elegida"<<endl;
        cout<<"(1) Descubrir casillero"<<endl<<"(2) Colocar bandera"<<endl<<"(3) Quitar bandera"<<endl;
        cin>>tipoDeJugada;

        if (tipoDeJugada==DESCUBRIR_CASILLA){
            mostrarCasillero(tablero,filaElegida,coulmnaElegida);
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

Jugador::~Jugador(){
	delete planillaJugador;
}
