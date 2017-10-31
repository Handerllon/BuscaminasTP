#include "Terrorista.h"

void Terrorista::plantarBombas(Tablero* tablero, char dificultad) {
    
    int filas = tablero->obtenerCantidadFilas();
    int columnas = tablero->obtenerCantidadColumnas();
    int cantidadBombas;
    
    srand(time(0));
    
    if (dificultad == 'F')
        cantidadBombas = (filas * columnas) / 5;
    else if (dificultad == 'I')
        cantidadBombas = (filas * columnas) / 4;
    else
        cantidadBombas = (filas * columnas) / 3;
    
 
    for (int i = 0; i < cantidadBombas; i++) {
         
        unsigned int posX = rand() % filas;
        unsigned int posY = rand() % columnas;
        
        Casilla* aPlantar = tablero->obtenerCasillero(posX, posY);
        
        if(aPlantar->tieneMina())
            i--;
        
        aPlantar->colocarMina();
    }                   
}
