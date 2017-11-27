// Para el git

//En header

void ocultarCasilleros(Tablero* tablero, unsigned int filaElegida, unsigned int columnaElegida);

//En cpp

//Como es una jugada ya realizada, se le quitan las verificaciones de coordenadas validas
void Algo::ocultarCasilleros(Tablero* tablero, unsigned int filaElegida, unsigned int columnaElegida){

	Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);
	//Ocultar Casillero seria un metodo de casilla, que lo cambia a oculto
	casillaElegida->ocultarCasillero();

	if(!casillaElegida->tieneMina()){
		//Se cambio a un -1, ya que debe agregar casillas a casillas por descubrir
		tablero->cambiarCasillasPorDescubrir(-1);

		if(casillaElegida->getMinasCercanas()==0){

			ocultarCasilleros(tablero,filaElegida+1,columnaElegida);
			ocultarCasilleros(tablero,filaElegida-1,columnaElegida);
			ocultarCasilleros(tablero,filaElegida,columnaElegida+1);
			ocultarCasilleros(tablero,filaElegida,columnaElegida-1);
			ocultarCasilleros(tablero,filaElegida+1,columnaElegida+1);
			ocultarCasilleros(tablero,filaElegida+1,columnaElegida-1);
			ocultarCasilleros(tablero,filaElegida-1,columnaElegida+1);
			ocultarCasilleros(tablero,filaElegida-1,columnaElegida-1);
		}
	}
}
	
