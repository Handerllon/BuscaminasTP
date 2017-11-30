
#ifndef LINEASDETIEMPO_H_
#define LINEASDETIEMPO_H_

#include "NodoBinario.h"
#include <iostream>

/*
 * Se va a encargar de guardar los turnos jugados, para poder acceder a ellos mediante
 * el deshacer y rehacer de las jugadas.
 *
 *(raiz) t1(1) ----- t1(2) ----- t1(3) ----- t1(4)
	 	 |       	 |            |      	 |
 	 	 t2(1)       t2(2)       t2(3)       t2(4)
          	  	 	 |                       |
          	  	 	 |                     	 |
          	  	 	 t3(2-1)--t3(2-1)        t3(4)
 */

template<class T> class LineasDeTiempo {
private:

	NodoBinario<T>* turnoActual;
	NodoBinario<T>* primerTurno;


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
	 * post: regresa al turno posterior.
	 */
	void rehacerJugada();

	/*
	 * Post: Libera los recursos asociados.
	 */
	~LineasDeTiempo();

private:
	/*
	 * pre: no se puede crear una nueva linea si no hay un turno de donde deshacer.
	 * post: crea una nueva linea de tiempo, donde se van a jugar nuevos turnos paralelos a los de la
	 * 		 linea anterior.
	 */
	void nuevaLinea(T dato);

	/*
	 * post: el nuevo turno actual sera el anterior.
	 */
	NodoBinario<T>* regresarUnTurno();

	/*
	 * post: borra el nodo pasado por parametro.
	 */
	void eliminar(NodoBinario<T>* aBorrar);

};



template<class T> LineasDeTiempo<T>::LineasDeTiempo() {
	turnoActual = NULL;
	primerTurno = NULL;
}


template<class T> T LineasDeTiempo<T>::obtenerJugadaActual() {
	return turnoActual->obtenerDato();
}


template<class T> void LineasDeTiempo<T>::nuevoTurno(T dato) {
	NodoBinario<T>* nuevo = new NodoBinario<T>(dato);
	if (primerTurno == NULL)  {
		turnoActual = nuevo;
		primerTurno = nuevo;
	}
	else {
		nuevo->cambiarAnteriorTurno(turnoActual);
		turnoActual->cambiarSiguienteTurno(nuevo);
		turnoActual = nuevo;
	}
	nuevo->cambiarDato(dato);

}


template<class T> void LineasDeTiempo<T>::nuevaLinea(T dato) {
	NodoBinario<T>* nuevo = new NodoBinario<T>(dato);

	//Si existe una linea de tiempo vacia no crea una nueva
	NodoBinario<T>* siguienteLinea = turnoActual->obtenerSiguienteLinea();
	if ((siguienteLinea == NULL) ||
			((siguienteLinea != NULL) && (siguienteLinea->obtenerSiguienteTurno() == NULL))) {

		nuevo->cambiarAnteriorLinea(turnoActual);
		turnoActual->cambiarSiguienteLinea(nuevo);
		turnoActual = nuevo;
	}

	else
		delete nuevo;

}


template<class T> NodoBinario<T>* LineasDeTiempo<T>::regresarUnTurno() {

	//Este while esta porque, por ejemplo,
	// si hay muchas lineas de tiempo que se desprenden del turno 2, pero se quiere volver
	// al unico turno 1 que hay, hay que volver a la linea original.
	while (turnoActual->obtenerAnteriorLinea() != NULL) {
		 turnoActual = turnoActual->obtenerAnteriorLinea();
	}

	turnoActual = turnoActual->obtenerAnteriorTurno();
	return turnoActual;
}


template<class T> void LineasDeTiempo<T>::deshacerJugada() {
	turnoActual = regresarUnTurno();
	nuevaLinea(turnoActual->obtenerDato());
}


template<class T> void LineasDeTiempo<T>::rehacerJugada() {
	int cantidadDeLineas = 0;
	int eleccionLinea = 0;
	NodoBinario<T>* iteradorLineas = turnoActual;

	//Cuenta las posibles lineas
	while (iteradorLineas->obtenerAnteriorLinea() != NULL) {
		iteradorLineas = iteradorLineas->obtenerAnteriorLinea();
		cantidadDeLineas++;
	}

	//Si hay mas de una posibilidad, se le da a elegir al usuario
	if (cantidadDeLineas >= 2) {

		std::cout << "Hay " << cantidadDeLineas << " lineas de tiempo posibles para ir. En cual desea rehacer la jugada?" << std::endl;
		std::cin >> eleccionLinea;
		while ((eleccionLinea < 1 ) && (eleccionLinea > cantidadDeLineas)) {
			std::cout << "Hay " << cantidadDeLineas << " lineas de tiempo posibles para ir. En cual desea rehacer la jugada?" << std::endl;
			std::cin >> eleccionLinea;
		}
	}

	//posiciona el cursor de turnos en la linea elegida
	while ((cantidadDeLineas-eleccionLinea) > 0) {
		turnoActual = turnoActual->obtenerAnteriorLinea();
		cantidadDeLineas--;
	}

	//rehago el turno de la linea elegida
	turnoActual = turnoActual->obtenerSiguienteTurno();

}


template<class T> void LineasDeTiempo<T>::eliminar(NodoBinario<T>* aBorrar) {

	if (aBorrar->obtenerSiguienteLinea() != NULL) {
		eliminar(aBorrar->obtenerSiguienteLinea());
	}
	if (aBorrar->obtenerSiguienteTurno() != NULL) {
		eliminar(aBorrar->obtenerSiguienteTurno());
	}
	delete aBorrar;

}


template<class T> LineasDeTiempo<T>::~LineasDeTiempo() {
	eliminar(primerTurno);
}




#endif /* LINEASDETIEMPO_H_ */
