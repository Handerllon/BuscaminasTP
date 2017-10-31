#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Planilla.h"
#include "casilla.h"
#include "tablero.h"

const int DESCUBRIR_CASILLA=1;
const int COLOCAR_BANDERA=2;
const int QUITAR_BANDERA=3;

class Jugador{

private:

        bool estaJugando;

        Planilla* planillaJugador;

        unsigned int identificadorJugador;
        
        unsigned int coordenadaXDeJugada;

        unsigned int coordenadaYDeJugada;

        /*
        PRE: Recibe valor para verificar si es mayor a 0
        POST: Devuelve si el numero ingresado esta entre 0 y el segundo parametro ingresado
        */

        unsigned int verificarNumero(unsigned int numeroIngresado, unsigned int tope);
        
        /*
        PRE: Recibe la fila y columna del casillero que se quiere abrir
        POST: En el caso de que el casillero tenga el numero 0, descubre los casilleros de alrededor
        */

        void mostrarCasillero(Tablero tablero, unsigned int filaElegida, unsigned int columnaElegida);

public:
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
        PRE: Es necesario un numero para identificar al jugador, pasado como parametro
        POST: Crea un jugador con el identificador recibido
        */
        Jugador();

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
         * Pre: identificador es valido
         * Post: asigna un identificador al jugador
         */
        void setIdentificador(unsigned int identificador);

        /*
        POST: Realiza una jugada, haciendo que el usuario ingrese la posicion elegida, al
        igual que el tipo de jugada a realizar. Interactua con tablero y casillero
        */


        void jugada(Tablero tablero);

        /*
        PRE: Requiere que el jugador haya sido inicializado "puntosASumar" debe estar entre -1 y 2
        POST: Le agrega o resta puntos al jugador
        */

        /*
        PRE: Es necesario que haya ocurrido una jugada
        POST: Actualiza la planilla del jugador, tomando datos de la jugada y el tablero
        */
        void actualizarPuntaje(Casilla* casillaJugada, unsigned int jugadaElegida);


        /*
         * PRE:-
         * POST:devuelve el puntaje
         */
        int getPuntajeJugador();
        
        //pre: el jugador debio hacer una jugada primero
        //post: devuelve la coordenada x de la jugada
        unsigned int obtenerCoordenadaXJugada();

        //pre: el jugador debio hacer una jugada primero
        //post: devuelve la coordenada y de la jugada
        unsigned int obtenerCoordenadaYJugada();
        ~Jugador();


};


#endif // JUGADOR_H_
