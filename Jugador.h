#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Planilla.h"
#include "Casilla.h"
#include "Tablero.h"


class Jugador{

private:

        bool estaJugando;

        Planilla* planillaJugador;

        unsigned int identificadorJugador;

        /*
        PRE: Recibe el ancho del tablero
        POST: Se encarga de obtener la posicion X de jugada
        */

        unsigned int coordenadaXJugada(unsigned int anchoTablero);

        /*
        PRE: Recibe el alto del tablero
        POST: Se encarga de obtener la posicion Y de jugada
        */

        unsigned int coordenadaYJugada(unsigned int altoTablero);

        /*
        PRE: Recibe valor para verificar si es mayor a 0
        POST: Devuelve si el numero ingresado esta entre 0 y el segundo parametro ingresado
        */

        unsigned int verificarNumero(int numeroIngresado, unsigned int tope);

public:

        /*
        PRE: Es necesario un numero para identificar al jugador, pasado como parametro
        POST: Crea un jugador con el identificador recibido
        */
        Jugador(unsigned int identificador);

        /*
        POST: Cambia getEstaJugando a falso (caso de que el jugador pierde)
        */

        void cambiarJugadorAPerdido();

        /*
        POST: Devuelve si el jugador esta jugando o no
        */

        bool getEstaJugando();

        /*
        POST: Devuelve el numero que identifica al jugador
        */

        unsigned int getIdentificador();

        /*
        POST: Realiza una jugada, haciendo que el usuario ingrese la posicion elegida, al
        igual que el tipo de jugada a realizar. Interactua con tablero y casillero
        */

        void jugada(Tablero* tablero);

        ~Jugador();


};


#endif // JUGADOR_H_
