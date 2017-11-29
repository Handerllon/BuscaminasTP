#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(){

    estaJugando = true;
    identificadorJugador = 0;
    planillaJugador = new Planilla;
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

void Jugador::mostrarCasillero(Tablero* tablero, unsigned int filaElegida, unsigned int columnaElegida){
	if(tablero->coordenadasValidas(filaElegida,columnaElegida)){

		Casilla* casillaElegida= tablero->obtenerCasillero(filaElegida, columnaElegida);

		if(casillaElegida->estaOculta() && !casillaElegida->tieneBandera()){

			casillaElegida->descubrirCasillero();

			if(!casillaElegida->tieneMina()){
				tablero->cambiarCasillasPorDescubrir(1);

				if(casillaElegida->getMinasCercanas()==0){

					mostrarCasillero(tablero,filaElegida+1,columnaElegida);
					mostrarCasillero(tablero,filaElegida-1,columnaElegida);
					mostrarCasillero(tablero,filaElegida,columnaElegida+1);
					mostrarCasillero(tablero,filaElegida,columnaElegida-1);
					mostrarCasillero(tablero,filaElegida+1,columnaElegida+1);
					mostrarCasillero(tablero,filaElegida+1,columnaElegida-1);
					mostrarCasillero(tablero,filaElegida-1,columnaElegida+1);
					mostrarCasillero(tablero,filaElegida-1,columnaElegida-1);
				}
			}
		}
	}
}

int Jugador::verificarJugada(unsigned int filaElegida, unsigned int columnaElegida, Casilla* casillaElegida){

	bool eleccionValida=false;
	unsigned int tipoDeJugada;


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

void Jugador::elegirJugada(Tablero* tablero){

	bool jugadaValida = false;
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
		jugada(tablero);
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
			//Pasan cosas
		}
		else{
			//Pasan mas cosas
		}

		planillaJugador->sumarPuntos(-3);
		
	}
}

Jugada* Jugador::jugada(Tablero* tablero){

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

    unsigned int tipoDeJugada=verificarJugada(filaElegida,columnaElegida, casillaElegida);

    if (tipoDeJugada==DESCUBRIR_CASILLA){
        mostrarCasillero(tablero,filaElegida,columnaElegida);
    }
    else if (tipoDeJugada==COLOCAR_BANDERA){
        casillaElegida->colocarBandera();
    }
    else if (tipoDeJugada==QUITAR_BANDERA){
        casillaElegida->quitarBandera();
    }

    actualizarPuntaje(casillaElegida,tipoDeJugada);
	//No se porque el indentado me lo manda para aca
	Jugada* jugadaRealizada(casillaElegida,getIdentificador(),tipoDeJugada);
	
	return jugadaRealizada;

}

void Jugador::actualizarPuntaje(Casilla* casillaJugada, unsigned int jugadaElegida){

        if (jugadaElegida==DESCUBRIR_CASILLA && casillaJugada->tieneMina()){
            cambiarJugadorAPerdido();
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
}
