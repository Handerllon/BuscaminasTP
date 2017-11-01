
#ifndef CASILLA_H_
#define CASILLA_H_


char const MINA = 'M';
char const OCULTA = 'X';
char const BANDERA = 'B';

class Casilla{


private:
	unsigned int fila;

	unsigned int columna;

	unsigned int minasCercanas;

	bool estaMinado;

	bool estaConBandera;

	bool estaEscondido;

public:
	
	/*
	 * PRE: La fila y la columna ingresada deben estar entre 0 y Tablero->ObtenerFilas / Tablero->ObtenerColumnas
	 * POST: Devuelve una casilla ubicada en la posicion ('x','y') del tablero.
	 *       Estara cubierta, desmarcada, sin mina, y con el valor 'minasCercanas' en cero.
	 */
	Casilla(unsigned int filaActual, unsigned int columnaActual);


	/*
	 * PRE: La nueva fila y nueva columna estan entre 0 y tablero->obtenerFilas / obtenerColumnas
	 * POST:cambia el valor de la fila a 'nuevaFila' y el valor de la columna a 'nuevaColumna'
	 */
	void cambiarCoordenadas(unsigned int nuevaFila, unsigned int nuevaColumna);

	/*
	PRE: Es necesario que el casillero este inicializado
	POST: Modifica minasCercanas para que sea igual a "minasEncontradas"
	*/
	void setMinasCercanas(unsigned int minasEncontradas);

	/*
	 * devuelve TRUE si la casilla esta Minada o FALSE en caso contrario.
	 */
	bool tieneMina();


	/*
	 * devuelve TRUE si la casilla posee una Bandera o FALSE en caso contrario.
	 */
	bool tieneBandera();


	/*
	 * devuelve TRUE si la casilla esta oculta o FALSE si no lo esta.
	 */
	bool estaOculta();


	/*
	 * PRE: la casilla esta oculta y no posee una bandera.
	 * POST: descubre la casilla.
	 */
	void descubrirCasillero();


	/*
	 * PRE: la casilla no posee una bandera y esta oculta.
	 * POST: coloca una bandera en la casilla.
	 */
	void colocarBandera();


	/*
	 * PRE:se coloco una bandera en la casilla previamente.
	 * POST: se quita la bandera de la casilla.
	 */
	void quitarBandera();


	/*
	 * PRE: la casilla no esta minada y esta oculta.
	 * POST: coloca una mina en la casilla
	 */

	void colocarMina();


	/*
	 * POST:devuelve la fila de la casilla.
	 */
	unsigned int obtenerFila();


	/*
	 * POST: devuelve la columna de la casilla.
	 */
	unsigned int obtenerColumna();

	/*
	 *PRE:-
	 *POST:devuelve el valor de minasCercanas.(cuantos casilleros a su alrededor tienen una mina plantada.)
	 */
	unsigned int getMinasCercanas();
	
	/*
	 * POST: devuelve el estado actual de la casilla. Puede ser marcada o no, descubierta o no.
	 * 	Si esta descubierta, muestra el numero de minas cercanas o, si es una mina, el simbolo correspondiente.
	 */
	char mostrarCasilla();

};



#endif /* CASILLA_H_ */
