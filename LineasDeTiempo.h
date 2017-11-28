
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
	NodoBinario<T>* raiz;

public:
	/*
	 * Post: Arma las lineas de tiempo listas para su uso.
	 */
	LineasDeTiempo();

	void nuevaLinea(T dato);

	void nuevoTurno(T dato);


	/*
	 * Post: Libera los recursos asociados.
	 */
	~LineasDeTiempo();

private:

	void nuevaLinea(T dato, NodoBinario<T>* nuevaLinea);

	void nuevoTurno(T dato, NodoBinario<T>* nuevoTurno);

};



template<class T> LineasDeTiempo<T>::LineasDeTiempo() {
	raiz = NULL;
}

template<class T> void LineasDeTiempo<T>::nuevoTurno(T dato) {
	if (raiz != NULL)
		nuevoTurno(dato, raiz);
	else {
		raiz = new NodoBinario<T>;
		raiz->cambiarDato(dato);

	}
}

template<class T> void LineasDeTiempo<T>::nuevaLinea(T dato) {
	if (raiz != NULL)
		nuevaLinea(dato, raiz);
	else {
		raiz = new NodoBinario<T>;
		raiz->cambiarDato(dato);
	}
}


template<class T> LineasDeTiempo<T>::~LineasDeTiempo() {

}


template<class T> void LineasDeTiempo<T>::nuevoTurno(T dato, NodoBinario<T>* nuevoTurno) {
	NodoBinario<T>* turno = nuevoTurno->obtenerHijo();
	if (turno != NULL)
		nuevoTurno(dato, turno);

	else {
		turno = new NodoBinario<T>;
		turno->cambiarDato(dato);
	}
}

template<class T> void LineasDeTiempo<T>::nuevaLinea(T dato, NodoBinario<T>* nuevaLinea) {
	NodoBinario<T>* turno = nuevaLinea->obtenerHermano();
	if (turno != NULL)
		nuevoTurno(dato, turno);

	else {
		turno = new NodoBinario<T>;
		turno->cambiarDato(dato);
	}
}



#endif /* LINEASDETIEMPO_H_ */
