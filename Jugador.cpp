#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(unsigned int identificador){

    estaJugando=true;

    identificadorJugador=identificador;

}

unsigned int Jugador::coordenadaXJugada(unsigned int anchoTablero){

    int valorElegido;

    cout<<"Por favor ingresar la fila elegida para realizar la jugada"<<endl;
    cin>>valorElegido;

    valorElegido=verificarNumero(valorElegido,anchoTablero);

    return valorElegido;

}

unsigned int Jugador::coordenadaYJugada(unsigned int altoTablero){

    int valorElegido;

    cout<<"Por favor ingresar la columna elegida para realizar la jugada"<<endl;
    cin>>valorElegido;

    valorElegido=verificarNumero(valorElegido,altoTablero);

    return valorElegido;

}

unsigned int Jugador::verificarNumero(int numeroIngresado, unsigned int tope){

    bool numeroVerificado=false;

    while (not numeroVerificado){

        if (0<numeroIngresado<=tope)
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

void Jugador::jugada(Tablero* tablero){

    int filaElegida,columnaElegida,tipoDeJugada;

    unsigned int filasTablero = tablero->obtenerCantidadFilas();
    unsigned int columnasTablero = tablero->obtenerCantidadColumnas();

    filaElegida=coordenadaXJugada(anchoTablero);
    columnaElegida=coordenadaYJugada(altoTablero);

    Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

    while (not eleccionValida){

        cout>>"Por favor ingresar el numero que corresponde a la jugada elegida"<<endl;
        cout>>"(1) Descubrir casillero">>endl>>"(2) Colocar bandera">>endl>>"(3) Quitar bandera">>endl;
        cin<<tipoDeJugada;

        if (tipoDeJugada==1){
            casillaElegida->descubrirCasillero();
            eleccionValida=true;
        }
        else if (tipoDeJugada==2){
            casillaElegida->colocarBandera();
            eleccionValida=true;
        }
        else if (tipoDeJugada==3){
            casillaElegida->quitarBandera();
            eleccionValida=true;
        }
        else{
            cout>>"El tipo de jugada ingresado no es valido, por favor ingresar nuevamente">>endl;
        }
    }
}

Jugador::~Jugador(){}
