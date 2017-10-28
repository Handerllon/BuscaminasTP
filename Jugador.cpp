#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(unsigned int identificador){

    estaJugando=true;

    identificadorJugador=identificador;

}

Jugador::cambiarJugadorAPerdido(){

    estaJugando=false;

}

Jugador::getEstaJugando(){

    return estaJugando;

}

Jugador::getIdentificador(){

    return identificadorJugador;

}

Jugador::jugada(Tablero* tablero){

    unsigned int filaElegida,columnaElegida,tipoDeJugada;

    bool jugadaValida=false

    cout<<"Por favor ingresar la fila elegida para jugar"<<endl;
    cin>>filaElegida;

    cout<<"Por favor ingresar la columna elegida para jugar"<<endl;
    cin>>columnaElegida;

    Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

    while (not jugadaValida){

        cout>>"Por favor ingresar el numero que corresponde a la jugada elegida"<<endl;
        cout>>"(1) Descubrir casillero">>endl>>"(2) Colocar bandera">>endl>>"(3) Quitar bandera">>endl;
        cin<<tipoDeJugada;

        if (tipoDeJugada==1){
            casillaElegida.descubrirCasillero;
            jugadaValida=true;
        }
        else if (tipoDeJugada==2){
            casillaElegida.colocarBandera;
            jugadaValida=true;
        }
        else if (tipoDeJugada==3){
            casillaElegida.quitarBandera;
            jugadaValida=true;
        }
        else{
            cout>>"El tipo de jugada ingresado no es valido, por favor ingresar nuevamente">>endl;
        }
    }
}
