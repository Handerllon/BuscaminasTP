#ifndef NODOBINARIO_H_
#define NODOBINARIO_H_

#ifndef NULL
#define NULL 0
#endif

//Nodo con punteros al siguiente y al anterior turno. Y las siguiente
// y anterior lineas de tiempo.
template<class T> class NodoBinario {

    private:

        T dato;

        NodoBinario<T>* siguienteLinea;
        NodoBinario<T>* anteriorLinea;

        NodoBinario<T>* siguienteTurno;
        NodoBinario<T>* anteriorTurno;

    public:

        /*
         * post: el Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         */
        NodoBinario(T dato){

            this->dato = dato;
            this->siguienteLinea = NULL;
            this->siguienteTurno = NULL;
            this->anteriorLinea = NULL;
            this->anteriorTurno = NULL;
        }

        /*
         * post: devuelve el valor del dato.
         */
        T obtenerDato() {

            return this->dato;
        }

        /*
         * post: cambia el valor del dato.
         */
        void cambiarDato(T nuevoDato) {

            this->dato = nuevoDato;
        }

        /*
         * post: devuelve la siguiente linea.
         */
        NodoBinario<T>* obtenerSiguienteLinea() {

            return this->siguienteLinea;
        }

        /*
         * post: cambia el la siguiente linea por nuevaLinea.
         */
        void cambiarSiguienteLinea(NodoBinario<T>* nuevaLinea) {

            this->siguienteLinea = nuevaLinea;
        }

        /*
		* post: devuelve el siguiente turno.
		*/
		NodoBinario<T>* obtenerSiguienteTurno() {

			return this->siguienteTurno;
		}

		/*
		* post: cambia el siguiente turno por nuevoTurno.
		*/
		void cambiarSiguienteTurno(NodoBinario<T>* nuevoTurno) {

			 this->siguienteTurno = nuevoTurno;
		}


		/*
		 *post: cambia la anteriorLinea.
		 */
		void cambiarAnteriorLinea(NodoBinario<T>* anteriorLinea) {

			this->anteriorLinea = anteriorLinea;

		}

		/*
		 * post: cambia el anteriorTurno.
		 */
		void cambiarAnteriorTurno(NodoBinario<T>* anteriorTurno) {

			this->anteriorTurno = anteriorTurno;
		}

		/*
		 * Post: devuelve la linea anterior.
		 */
		NodoBinario<T>* obtenerAnteriorLinea()  {
			return anteriorLinea;
		}

		/*
		 * post: devuelve el turno anterior.
		 */
		NodoBinario<T>* obtenerAnteriorTurno() {
			return anteriorTurno;
		}
};


#endif /* NODOBINARIO_H_ */
