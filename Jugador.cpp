#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(unsigned int identificador){

    estaJugando=true;

    identificadorJugador=identificador;

}

void Jugador::verificarJugada(int posX, int posY, unsigned int anchoTablero, unsigned int altoTablero){

    bool jugadaValida=false;
    
    if ((0<posX<=anchoTablero) && (0<posY<=altoTablero)){
        jugadaValida=true;
    }
    
    return jugadaValida;
    
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

    bool eleccionValida=false;
    
    cout<<"Por favor ingresar la fila elegida para jugar"<<endl;
    cin>>filaElegida;

    cout<<"Por favor ingresar la columna elegida para jugar"<<endl;
    cin>>columnaElegida;
        
    while (not jugadaValida(filaElegida,columnaElegida,filasTablero,columnasTablero){

        cout>>"Jugada no valida, por favor ingresar nuevamente la fila y columna elegida en ese orden">>endl;
        cout>>"(Una a la vez)">>endl;
        cin<<filaElegida;
        cin<<columnaElegida;
        
    }

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
