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
        PRE: Recibe el ancho y el alto del tablero
        POST: Verifica si la posicion ingresada por el jugador es valida para ser usada
        */
        
        void verificarJugada(int posX, int posY, unsigned int anchoTablero, unsigned int altoTablero); 

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
