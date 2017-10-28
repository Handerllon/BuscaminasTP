#include "Terrorista.h"

void Terrorista::plantarBombas(Tablero* tablero, Inicializador* init) {
    
    int filas = tablero->obtenerCantidadFilas();
    int columnas = tablero->obtenerCantidadColumnas();
    int cantidadBombas;
    
    srand(time(0));
    
    if (init->obtenerDificultad() == 'F')
        cantidadBombas = (filas * columnas) / 5;
    if (init->obtenerDificultad() == 'I')
        cantidadBombas = (filas * columnas) / 4;
    else
        cantidadBombas = (filas * columnas) / 3;
    
 
    for (int i = 0; i < cantBombas; i++) {
         
        unsigned int posX = rand() % filas;
        unsigned int posY = rand() % columnas;
        
        Casilla* aPlantar = tablero->obtenerCasillero(posX, posY);  
        
        if(aPlantar->tieneMina())
            i--;
        
        aPlantar->colocarMina();
    }                   
}