
#ifndef TERRORISTA_H
#define TERRORISTA_H

#include "tablero.h"
#include <stdlib.h>  
#include <time.h>    

class Terrorista {
    
    
public:
    /* Post: inserta en el tablero una cantidad de minas proporcional a la dificultad.
     */
    int plantarBombas(Tablero* tablero, char dificultad);
};



#endif /* TERRORISTA_H */

