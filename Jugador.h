#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Planilla.h"
#include "casilla.h"
#include "tablero.h"
#include "Jugada.h"
#include "LineasDeTiempo.h"

const int DESCUBRIR_CASILLA=1;
const int COLOCAR_BANDERA=2;
const int QUITAR_BANDERA=3;

const char JUGADA_NORMAL = 'N';
const char JUGADA_DESHACER = 'D';
const char JUGADA_REHACER = 'R';

class Jugador{

private:

        bool estaJugando;

        Planilla* planillaJugador;
        
        Jugada* jugadaRealizada;

        unsigned int identificadorJugador;
        
        unsigned int coordenadaXDeJugada;

        unsigned int coordenadaYDeJugada;

        /*
        PRE: Recibe valor para verificar si es mayor a 0
        POST: Devuelve si el numero ingresado esta entre 0 y el segundo parametro ingresado
        */

        unsigned int verificarNumero(unsigned int numeroIngresado, unsigned int tope);
        
        /*
        PRE: Recibe el tablero, el graficador, la fila y columna del casillero que se quiere abrir
        POST: En el caso de que el casillero tenga el numero 0, descubre los casilleros de alrededor
        */

        void mostrarCasillero(Graficador &buscaminas, Tablero* tablero, unsigned int filaElegida,
                                                                        unsigned int columnaElegida);
        
        /*
         * PRE:Recibe el tablero, el graficador, la fila y columna del casillero que se quiere ocultar
         * POST:oculta la casilla deseada y, en caso de que tenga el numero 0,
         *  	tambien oculta los casilleros de alrededor
         */
        void ocultarCasilleros(Graficador &buscaminas, Tablero* tablero, unsigned int filaElegida,
        								unsigned int columnaElegida);
        
        //Pre: Necesita recibir la coordenada de la jugada que quiere realizar el jugador actual
        //Post: Devuelve la jugada elegida, verificando que esta sea valida (Por ej, no se puede poner bandera donde ya hay una)
        int verificarJugada(unsigned int filaElegida, unsigned int columnaElegida, Casilla* casillaElegida);
        
         /*
        POST: Realiza una jugada, haciendo que el usuario ingrese la posicion elegida, al
        igual que el tipo de jugada a realizar. Interactua con el graficador, el tablero y casillero
        */
        
        Jugada* jugada(Graficador &buscaminas, Tablero* tablero);

public:
        /*
        PRE: Recibe el ancho del tablero
        POST: Se encarga de obtener la posicion X de jugada
        */

        unsigned int coordenadaXJugada(unsigned int anchoTablero, unsigned int* fila);

        /*
        PRE: Recibe el alto del tablero
        POST: Se encarga de obtener la posicion Y de jugada
        */

        unsigned int coordenadaYJugada(unsigned int altoTablero, unsigned int* columna);

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
         * PRE: recibe el tablero, el graficador y la jugada que se debe deshacer.
         * POST: se encarga de deshacer la jugada recibida.
         */
        void revertirJugada(Graficador &buscaminas, Tablero* tablero, Jugada jugadaRealizada);
        
        /*
         * PRE:recibe el tablero, el graficador y la jugada que se debe rehacer.
         * POST:se encarga de rehacer la jugada recibida.
         */
        void restaurarJugada(Graficador &buscaminas, Tablero* tablero, Jugada jugadaRealizada);

        /*
        Pre: Debe tener el tablero para poder funcionar
        Post: Consulta al jugador los diferentes tipos de jugadas a hacer y las realiza, si la jugada
                es de tipo normal, jugadaRealizada queda cargado con los datos de la jugada. Si es especial
                jugadaEspecial queda cargado con los datos de la jugada especial.
        */
        
        char elegirJugada(Graficador &buscaminas, Tablero* tablero, Jugada* jugadaRealizada,
                                        LineasDeTiempo<Jugada> &jugadas, Jugada &jugadaEspecial);

        /*
        PRE: Es necesario que haya ocurrido una jugada
        POST: Actualiza la planilla del jugador, tomando datos de la jugada y el tablero
        */
        void actualizarPuntaje(Casilla* casillaJugada, unsigned int jugadaElegida);
        
        /*
         * recibe los puntos a cambiar del jugador y los suma a su planilla.
         */
        void cambiarPuntaje(int puntos);

        /*
         * PRE:-
         * POST:devuelve el puntaje
         */
        int getPuntajeJugador();
        
        //Pre: Se debe haber jugado al menos un turno
        //POST: Devuelve la jugada realizada, de tipo Jugada
        Jugada* getJugadaRealizada();
        
        //pre: el jugador debio hacer una jugada primero
        //post: devuelve la coordenada x de la jugada
        unsigned int obtenerCoordenadaXJugada();

        //pre: el jugador debio hacer una jugada primero
        //post: devuelve la coordenada y de la jugada
        unsigned int obtenerCoordenadaYJugada();

        //Post: libera los recursos asociados
        ~Jugador();


};


#endif // JUGADOR_H_
