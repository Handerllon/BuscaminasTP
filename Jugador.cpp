#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(){

	estaJugando = true;
	identificadorJugador = 0;
	planillaJugador = new Planilla;
	jugadaRealizada = new Jugada;
	coordenadaXDeJugada = 0;
	coordenadaYDeJugada = 0;

}

unsigned int Jugador::coordenadaXJugada(unsigned int anchoTablero, unsigned int* fila){

    unsigned int valorElegido;

    cout<<"Por favor ingresar la columna elegida para realizar la jugada"<<endl;
    cin>>valorElegido;

    valorElegido=verificarNumero(valorElegido,anchoTablero);
    (*fila) = valorElegido;
    return valorElegido;

}

unsigned int Jugador::coordenadaYJugada(unsigned int altoTablero, unsigned int* columna){

    unsigned int valorElegido;

    cout<<"Por favor ingresar la fila elegida para realizar la jugada"<<endl;
    cin>>valorElegido;

    valorElegido=verificarNumero(valorElegido,altoTablero);
    (*columna)=valorElegido;
    return valorElegido;

}

unsigned int Jugador::verificarNumero(unsigned int numeroIngresado, unsigned int tope){

    bool numeroVerificado=false;

    while (!numeroVerificado){

        if ((numeroIngresado>=0) && (numeroIngresado<tope))
            numeroVerificado=true;

        else{
            cout<<"El numero ingresado no es valido, por favor, ingresar nuevamente"<<endl;
            cin>>numeroIngresado;
        }
    }

    return numeroIngresado;

}

void Jugador::cambiarJugadorAPerdido(){

    estaJugando=false;

}

bool Jugador::getEstaJugando(){

    return estaJugando;

}

unsigned int Jugador::getIdentificador(){

    return identificadorJugador;

}

void Jugador::setIdentificador(unsigned int identificador) {
	this->identificadorJugador = identificador;
}

void Jugador::mostrarCasillero(Graficador &buscaminas,Tablero* tablero, unsigned int filaElegida,
									unsigned int columnaElegida){

	if(tablero->coordenadasValidas(filaElegida,columnaElegida)){

		Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

		if(casillaElegida->estaOculta() && !casillaElegida->tieneBandera()){

			casillaElegida->descubrirCasillero();

			buscaminas.imprimirJugada(filaElegida+1,columnaElegida+1,casillaElegida->mostrarCasilla());

			if(!casillaElegida->tieneMina()){
				tablero->cambiarCasillasPorDescubrir(1);

				if(casillaElegida->getMinasCercanas()==0){

					mostrarCasillero(buscaminas, tablero,filaElegida+1,columnaElegida);
					mostrarCasillero(buscaminas, tablero,filaElegida-1,columnaElegida);
					mostrarCasillero(buscaminas, tablero,filaElegida,columnaElegida+1);
					mostrarCasillero(buscaminas, tablero,filaElegida,columnaElegida-1);
					mostrarCasillero(buscaminas, tablero,filaElegida+1,columnaElegida+1);
					mostrarCasillero(buscaminas, tablero,filaElegida+1,columnaElegida-1);
					mostrarCasillero(buscaminas, tablero,filaElegida-1,columnaElegida+1);
					mostrarCasillero(buscaminas, tablero,filaElegida-1,columnaElegida-1);
				}
			}
		}
	}
}

void Jugador::ocultarCasilleros(Graficador &buscaminas, Tablero* tablero, unsigned int filaElegida,
									unsigned int columnaElegida){

	if(tablero->coordenadasValidas(filaElegida,columnaElegida)){
		Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

		if( !casillaElegida->estaOculta() ){

			casillaElegida->ocultarCasillero();

			buscaminas.imprimirJugada(filaElegida+1,columnaElegida+1,casillaElegida->mostrarCasilla());

			if(!casillaElegida->tieneMina()){
				//Se cambio a un -1, ya que debe agregar casillas a casillas por descubrir
				tablero->cambiarCasillasPorDescubrir(-1);

				if(casillaElegida->getMinasCercanas()==0){

					ocultarCasilleros(buscaminas, tablero,filaElegida+1,columnaElegida);
					ocultarCasilleros(buscaminas, tablero,filaElegida-1,columnaElegida);
					ocultarCasilleros(buscaminas, tablero,filaElegida,columnaElegida+1);
					ocultarCasilleros(buscaminas, tablero,filaElegida,columnaElegida-1);
					ocultarCasilleros(buscaminas, tablero,filaElegida+1,columnaElegida+1);
					ocultarCasilleros(buscaminas, tablero,filaElegida+1,columnaElegida-1);
					ocultarCasilleros(buscaminas, tablero,filaElegida-1,columnaElegida+1);
					ocultarCasilleros(buscaminas, tablero,filaElegida-1,columnaElegida-1);
				}
			}
		}
	}
}

int Jugador::verificarJugada(unsigned int filaElegida, unsigned int columnaElegida, Casilla* casillaElegida){

	bool eleccionValida=false;
	int tipoDeJugada;


	while (not eleccionValida){

        cout<<"Por favor ingresar el numero que corresponde a la jugada elegida"<<endl;
        cout<<"(1) Descubrir casillero"<<endl<<"(2) Colocar bandera"<<endl<<"(3) Quitar bandera"<<endl;
        cin>>tipoDeJugada;

        //Puse como verificacion que si se quiere descubrir, que no haya bandera, ya que de hacerlo de otra manera interfiere con
        //El conteo de puntos
        if (tipoDeJugada==DESCUBRIR_CASILLA){
        	if (not casillaElegida->tieneBandera())
        		eleccionValida=true;
        	else
        		cout<<"No se puede descubrir un casillero en donde se encuentra una bandera, por favor quitarla primero"<<endl;
        }

        else if (tipoDeJugada==COLOCAR_BANDERA){
        	if (not casillaElegida->tieneBandera())
        		eleccionValida=true;
        	else
        		cout<<"No se puede ingresar una bandera en un casillero que ya tiene bandera"<<endl;	
        }

        else if (tipoDeJugada==QUITAR_BANDERA){
        	if (casillaElegida->tieneBandera())
        		eleccionValida=true;
        	else
        		cout<<"No se puede quitar una bandera de un casillero que no tiene bandera"<<endl;	
        }

        else
        	cout<<"El tipo de jugada ingresado no es valido, por favor ingresar nuevamente"<<endl;
    	

	}

	return tipoDeJugada;
}

void Jugador::revertirJugada(Graficador &buscaminas, Tablero* tablero, Jugada jugadaRealizada){

	Casilla* casillaAfectada= tablero->obtenerCasillero(jugadaRealizada.getFilaDescubierta(),
							jugadaRealizada.getColumnaDescubierta());

	int tipoJugada=jugadaRealizada.getTipoDeJugada();

	if(tipoJugada==DESCUBRIR_CASILLA){
		ocultarCasilleros(buscaminas, tablero, casillaAfectada->obtenerFila(), casillaAfectada->obtenerColumna());

	}
	else if(tipoJugada==COLOCAR_BANDERA){
		casillaAfectada->quitarBandera();

		buscaminas.imprimirJugada(casillaAfectada->obtenerFila()+1,casillaAfectada->obtenerColumna()+1,
										casillaAfectada->mostrarCasilla());

	}
	else if(tipoJugada==QUITAR_BANDERA){
		casillaAfectada->colocarBandera();

		buscaminas.imprimirJugada(casillaAfectada->obtenerFila()+1,casillaAfectada->obtenerColumna()+1,
										casillaAfectada->mostrarCasilla());

	}
}

void Jugador::restaurarJugada(Graficador &buscaminas, Tablero* tablero, Jugada jugadaRealizada){

	Casilla* casillaAfectada= tablero->obtenerCasillero(jugadaRealizada.getFilaDescubierta(),
							jugadaRealizada.getColumnaDescubierta());

	int tipoJugada=jugadaRealizada.getTipoDeJugada();

	if(tipoJugada==DESCUBRIR_CASILLA){
		mostrarCasillero(buscaminas, tablero, casillaAfectada->obtenerFila(), casillaAfectada->obtenerColumna());
	}
	else if(tipoJugada==COLOCAR_BANDERA){
		casillaAfectada->colocarBandera();

		buscaminas.imprimirJugada(casillaAfectada->obtenerFila()+1,casillaAfectada->obtenerColumna()+1,
										casillaAfectada->mostrarCasilla());
	}
	else if(tipoJugada==QUITAR_BANDERA){
		casillaAfectada->quitarBandera();

		buscaminas.imprimirJugada(casillaAfectada->obtenerFila()+1,casillaAfectada->obtenerColumna()+1,
										casillaAfectada->mostrarCasilla());
	}
}

char Jugador::elegirJugada(Graficador &buscaminas, Tablero* tablero, Jugada* jugadaRealizada,
					LineasDeTiempo<Jugada> &jugadas, Jugada &jugadaEspecial){

	bool jugadaValida = false;
	char tipoDeJugada;
	unsigned int jugadaElegida;

	while (!jugadaValida){
		cout<<"Por favor, elegir la jugada ingresando el numero correspondiente"<<endl;
		cout<<"(1) Jugada normal (Descubrir casillero, colocar/sacar bandera)"<<endl;
		cout<<"(2) Ingresar en la maquina del tiempo"<<endl;
		cin>>jugadaElegida;

		if ( jugadaElegida==1){
			jugadaValida = true;
		}

		else if (jugadaElegida==2 && getPuntajeJugador()>=3){
			jugadaValida = true;
		}

		else{
			cout<<"La jugada ingresada no fue valida, recuerde que, en caso de querer"<<endl;
			cout<<"volver en el tiempo, debe tener como minimo 3 puntos"<<endl;
		}
	}

	if (jugadaElegida==1){
		jugadaRealizada = jugada(buscaminas, tablero);
		jugadaRealizada= this->getJugadaRealizada();
		jugadas.nuevoTurno( (*jugadaRealizada) );
		tipoDeJugada = JUGADA_NORMAL;
	}

	else{

		jugadaValida=false;

		while (!jugadaValida){
			cout<<"Por favor, elegir la jugada ingresando el numero correspondiente"<<endl;
			cout<<"(1) Volver un turno atras"<<endl;
			cout<<"(2) Volver al turno siguiente"<<endl;
			cin>>jugadaElegida;

			if (jugadaElegida==1 || jugadaElegida==2){
				jugadaValida=true;
			}
			else
				cout<<"El numero de jugada ingresado no fue valido"<<endl;
		}

		if (jugadaElegida==1){
			jugadaEspecial=jugadas.obtenerJugadaActual();
			jugadas.deshacerJugada();
			revertirJugada(buscaminas, tablero, jugadaEspecial);
			tipoDeJugada = JUGADA_DESHACER;
		}
		else{
			jugadas.rehacerJugada();
			jugadaEspecial=jugadas.obtenerJugadaActual();
			restaurarJugada(buscaminas, tablero, jugadaEspecial);
			tipoDeJugada = JUGADA_REHACER;
		}

		planillaJugador->sumarPuntos(-3);
		
	}
	return tipoDeJugada;
}

Jugada* Jugador::jugada(Graficador &buscaminas, Tablero* tablero){

    unsigned int filaElegida,columnaElegida;
    bool casilleroValido = false;
    unsigned int filasTablero = tablero->obtenerCantidadFilas();
    unsigned int columnasTablero = tablero->obtenerCantidadColumnas();

    Casilla* casillaElegida;

    while (not casilleroValido){
    	filaElegida=this->coordenadaYJugada(filasTablero,&this->coordenadaYDeJugada);
    	columnaElegida=this->coordenadaXJugada(columnasTablero,&this->coordenadaXDeJugada);
    	casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);
    	if (casillaElegida->estaOculta()){
    		casilleroValido=true;
    	}
		else{
    		cout<<"el casillero elegido no es valido, elija otro"<<endl;
    	}	    
    }	

    int tipoDeJugada=verificarJugada(filaElegida,columnaElegida, casillaElegida);

    if (tipoDeJugada==DESCUBRIR_CASILLA){
        mostrarCasillero(buscaminas, tablero,filaElegida,columnaElegida);
    }
    else if (tipoDeJugada==COLOCAR_BANDERA){
	casillaElegida->colocarBandera();
	    
	buscaminas.imprimirJugada(filaElegida+1,columnaElegida+1,casillaElegida->mostrarCasilla());
    }
    else if (tipoDeJugada==QUITAR_BANDERA){
	casillaElegida->quitarBandera();
	    
	buscaminas.imprimirJugada(filaElegida+1,columnaElegida+1,casillaElegida->mostrarCasilla());
    }

    actualizarPuntaje(casillaElegida,tipoDeJugada);

	jugadaRealizada->modificarFilaDeJugada(filaElegida);
	jugadaRealizada->modificarColumnaDeJugada(columnaElegida);
	jugadaRealizada->modificarJugadorDeLaJugada(getIdentificador());
	jugadaRealizada->modificarOpcionElegidaParaJugar(tipoDeJugada);

    return jugadaRealizada;

}

Jugada* Jugador::getJugadaRealizada(){
	return jugadaRealizada;
}

void Jugador::actualizarPuntaje(Casilla* casillaJugada, unsigned int jugadaElegida){

        if (jugadaElegida==DESCUBRIR_CASILLA && casillaJugada->tieneMina()){
            cambiarJugadorAPerdido();
        }
	
	else if(jugadaElegida==DESCUBRIR_CASILLA && !casillaJugada->tieneMina()){
        	planillaJugador->sumarPuntos(1);
        }

        else if (jugadaElegida==COLOCAR_BANDERA && casillaJugada->tieneMina()){
            planillaJugador->sumarPuntos(1);
        }

        else if (jugadaElegida==COLOCAR_BANDERA && !casillaJugada->tieneMina()){
            planillaJugador->sumarPuntos(-1);
        }

        else if (jugadaElegida==QUITAR_BANDERA && casillaJugada->tieneMina()){
            planillaJugador->sumarPuntos(-2);
        }

        else if (jugadaElegida==QUITAR_BANDERA && !casillaJugada->tieneMina()){
            planillaJugador->sumarPuntos(2);
        }
}

void Jugador::cambiarPuntaje(int puntos){
	planillaJugador->sumarPuntos(puntos);
}

int Jugador::getPuntajeJugador(){

	return planillaJugador->obtenerPuntaje();
}
unsigned int Jugador::obtenerCoordenadaXJugada(){
	return this->coordenadaXDeJugada;
}
unsigned int Jugador::obtenerCoordenadaYJugada(){
	return this->coordenadaYDeJugada;
}
Jugador::~Jugador(){
	delete planillaJugador;
	delete jugadaRealizada;
}
