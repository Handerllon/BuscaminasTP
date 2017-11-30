/*
 * Planilla.h
 *
 *  Created on: Oct 18, 2017
 *      Author: lubuntu
 */

#ifndef PLANILLA_H_
#define PLANILLA_H_

class Planilla {

	private:

		int puntosTotales;

	public:

	//post: Crea una Planilla con los puntos del jugador iniciados en 0.
	Planilla();
	//
	//Post: Devuelve el puntaje actual del jugador.
	int obtenerPuntaje();
	//Pre: "puntosASumar" Debe estar entre -3 y 2.
	//Post: Suma los puntos que gano o perdio en su turno.
	void sumarPuntos(int puntosASumar);

	virtual ~Planilla();
};
#endif /* PLANILLA_H_ */
