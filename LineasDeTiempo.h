
#ifndef LINEASDETIEMPO_H_
#define LINEASDETIEMPO_H_

#include "NodoBinario.h"

/*
 * Se va a encargar de guardar los turnos jugados, para poder acceder a ellos mediante
 * el deshacer y rehacer de las jugadas.
 *
 * Raiz (t0)
 	 |
 	 t1(1) ----- t1(2) ----- t1(3) ----- t1(4)
	 |       	 |            |      	 |
 	 t2(1)       t2(2)       t2(3)       t2(4)
          	  	 |                       |
          	  	 |                     	 |
          	  	 t3(2-1)--t3(2-1)        t3(4)
 */

template<class T> class LineasDeTiempo {
private:

	NodoBinario<T>* turnoActual;
	int tamanio;

public:
	/*
	 * Post: Arma las lineas de tiempo listas para su uso.
	 */
	LineasDeTiempo();

	/*
	 * post: obtiene la jugada actual.
	 */
	T obtenerJugadaActual();

	/*
	 * post: crea un nuevo turno.
	 */
	void nuevoTurno(T dato);

	/*
	 * post: se vuelve al turno anterior, y se crea una nueva linea de tiempo para los siguientes turnos.
	 */
	void deshacerJugada();

	/*
	 * Post: Libera los recursos asociados.
	 */
	~LineasDeTiempo();

private:
	/*
	 * post: crea una nueva linea de tiempo, donde se van a jugar nuevos turnos paralelos a los de la
	 * 		 linea anterior
	 */
	void nuevaLinea();

	/*
	 * post: el nuevo turno actual sera el anterior.
	 */
	NodoBinario<T>* obtenerTurnoAnterior();

};



template<class T> LineasDeTiempo<T>::LineasDeTiempo() {
	turnoActual = NULL;
	tamanio = 0;
}


template<class T> T LineasDeTiempo<T>::obtenerJugadaActual() {
	return turnoActual->obtenerDato();
}


template<class T> void LineasDeTiempo<T>::nuevoTurno(T dato) {
	NodoBinario<T>* nuevo = new NodoBinario<T>;
	if (tamanio == 0)  {
		turnoActual = nuevo;
	}
	else {
		nuevo->cambiarAnteriorHijo(turnoActual);
		turnoActual->cambiarHijo(nuevo);
		turnoActual = nuevo;
	}
	nuevo->cambiarDato(dato);
	tamanio++;
}


template<class T> void LineasDeTiempo<T>::nuevaLinea() {
	NodoBinario<T>* nuevo = new NodoBinario<T>;
	if (tamanio == 0)  {
		turnoActual = nuevo;
	}
	else {
		nuevo->cambiarAnteriorHermano(turnoActual);
		turnoActual->cambiarHermano(nuevo);
		turnoActual = nuevo;
	}
	tamanio++;
}


template<class T> NodoBinario<T>* LineasDeTiempo<T>::obtenerTurnoAnterior() {

	//Este while esta porque, por ejemplo,
	// si hay muchas lineas de tiempo que se desprenden del turno 2, pero se quiere volver
	// al unico turno 1 que hay, hay que volver a la linea original.
	while (turnoActual->obtenerAnteriorHermano() != NULL) {
		 turnoActual = turnoActual->obtenerAnteriorHermano();
	}

	turnoActual = turnoActual->obtenerAnteriorHijo();
	return turnoActual;
}


template<class T> void LineasDeTiempo<T>::deshacerJugada() {
	turnoActual = obtenerTurnoAnterior();
	nuevaLinea();
}


template<class T> LineasDeTiempo<T>::~LineasDeTiempo() {
//TODO: destruir todos los nodos

}




#endif /* LINEASDETIEMPO_H_ */
