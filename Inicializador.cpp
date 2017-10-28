#include "Inicializador.h"
#include <iostream>

Inicializador::Inicializador(){
    tamanioAncho=0;
    tamanioAlto=0;
    numeroJugadores=0;
    dificultad='N';
}

int Inicializador::validarDato(int datoInicial){
    bool valorValido=false;
    while (not valorValido){
        if (datoInicial>0){
            valorValido=true;
        }
        else{
            std::cout<<"Valor no valido, por favor ingresar nuevamente, recuerde que el ancho debe ser mayor a 0"<<std::endl;
            std::cin>>datoInicial;
        }
    }
    return datoInicial;
}

void Inicializador::setAncho(){
    int anchoElegido;
    std::cout<<"Por favor ingresar el ancho deseado de tablero"<<std::endl;
    std::cin>>anchoElegido;
    tamanioAncho=validarDato(anchoElegido);
}

void Inicializador::setAlto(){
    int altoElegido;
    std::cout<<"Por favor ingresar el alto deseado de tablero"<<std::endl;
    std::cin>>altoElegido;
    tamanioAlto=validarDato(altoElegido);
}

void Inicializador::setCantJugadores(){
    int cantidadElegida;
    std::cout<<"Por favor ingrese la cantidad de jugadores que jugaran esta ronda"<<std::endl;
    std::cin>>cantidadElegida;
    numeroJugadores=validarDato(cantidadElegida);
}

void Inicializador::setDificultad(){
    bool caracterValido=false;
    char dificultadElegida;
    std::cout<<"Por favor ingresar el caracter de la dificultad en la que quiere jugar"<<std::endl;
    std::cout<<"Puede elegir entre Facil, Intermedio o Dificil (F/I/D respectivamente)"<<std::endl;
    std::cin>>dificultadElegida;
    while (not caracterValido){
        if ((dificultadElegida=='F') || (dificultadElegida=='I') || (dificultadElegida=='D')){
            caracterValido=true;
            dificultad=dificultadElegida;
        }
        else{
            std::cout<<"El caracter ingresado no es valido, recuerde que debe elegir entre"<<std::endl;
            std::cout<<"Facil, intermedio o dificil (F/I/D respectivamente)"<<std::endl;
            std::cin>>dificultadElegida;
        }
    }
}

int Inicializador::obtenerAlto(){
    return tamanioAlto;
}

int Inicializador::obtenerAncho(){
    return tamanioAncho;
}

int Inicializador::obtenerCantJugadores(){
    return numeroJugadores;
}

char Inicializador::obtenerDificultad(){
    return dificultad;
}

Inicializador::~Inicializador(){

}
