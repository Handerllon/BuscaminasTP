#ifndef INICIALIZADOR_H_
#define INICIALIZADOR_H_

class Inicializador{

    private:

        int tamanioAncho;

        int tamanioAlto;

        int numeroJugadores;

        char dificultad;

    public:

        //Pre:
        //Post: Crea un inicializador, con valores en 0, para luego consultar los mismos valores al usuario
        Inicializador();
        //
        //Pre: Recibe un dato inicial, el cual sera validado
        //Post: Devuelve un dato valido, funciona para alto, ancho y numero de jugadores;
        int validarDato(int datoInicial);
        //
        //Pre: El valor ingresado debe ser mayor a 0
        //Post: Fija el ancho del tablero que se usara en el juego
        void setAncho();
        //
        //Pre: El valor ingresado debe ser mayor a 0
        //Post: Fija el alto del tablero que se usara en el juego
        void setAlto();
        //
        //Pre: El valor ingresado debe ser mayor a 0
        //Post: Fija la cantidad de jugadores que participaran en el juego
        void setCantJugadores();
        //
        //Pre: Las letras ingresadas deben ser F/I/D
        //Post: Fija la dificultad del juego
        void setDificultad();
        //
        //Pre:
        //Post: Devuelve el ancho del tablero (x)
        int obtenerAncho();
        //
        //Pre:
        //Post: Devuelve el alto del tablero (y)
        int obtenerAlto();
        //
        //Pre:
        //Post: Devuelve la cantidad de jugadores elegida para jugar
        int obtenerCantJugadores();
        //
        //Pre:
        //Post: Devuelve la dificultad
        char obtenerDificultad();

        ~Inicializador();

};

#endif // INICIALIZADOR_H_
