
#ifndef TERRORISTA_H
#define TERRORISTA_H

#include "tablero.h"
#include <stdlib.h>  
#include <time.h>    

class Terrorista {
    
    
public:
    /* Post: inserta en el tablero una cantidad de minas proporcional a la dificultad.
     */
    void plantarBombas(Tablero* tablero, Inicializador* init);
};



#endif /* TERRORISTA_H */

