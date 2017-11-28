#ifndef NODOBINARIO_H_
#define NODOBINARIO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class NodoBinario {

    private:

        T dato;

        NodoBinario<T>* hermano;
        NodoBinario<T>* anteriorHermano;

        NodoBinario<T>* hijo;
        NodoBinario<T>* anteriorHijo;

    public:

        /*
         * post: el Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         */
        NodoBinario(T dato){

            this->dato = dato;
            this->hermano = NULL;
            this->hijo = NULL;
            this->anteriorHermano = NULL;
            this->anteriorHijo = NULL;
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
         * post: devuelve el siguiente Nodo.
         */
        NodoBinario<T>* obtenerHermano() {

            return this->hermano;
        }

        /*
         * post: cambia el nodo hermano por nuevoHermano.
         */
        void cambiarHermano(NodoBinario<T>* nuevoHermano) {

            this->hermano = nuevoHermano;
        }

        /*
		* post: devuelve el siguiente Nodo.
		*/
		NodoBinario<T>* obtenerHijo() {

			return this->hijo;
		}

		/*
		* post: cambia el nodo hijo por nuevoHijo.
		*/
		void cambiarHijo(NodoBinario<T>* nuevoHijo) {

			 this->hermano = nuevoHijo;
		}


		/*
		 *post: cambia el anteriorHermano.
		 */
		void cambiarAnteriorHermano(NodoBinario<T>* anteriorHermano) {

			this->anteriorHermano = anteriorHermano;

		}

		/*
		 * post: cambia el anteriorHijo.
		 */
		void cambiarAnteriorHijo(NodoBinario<T>* anteriorHijo) {

			this->anteriorHijo = anteriorHijo;
		}

		/*
		 * Post: devuelve el hermano anterior.
		 */
		NodoBinario<T>* obtenerAnteriorHermano()  {
			return anteriorHermano;
		}

		/*
		 * post: devuelve el hijo anterior.
		 */
		NodoBinario<T>* obtenerAnteriorHijo() {
			return anteriorHijo;
		}
};


#endif /* NODOBINARIO_H_ */

#endif /* NODOBINARIO_H_ */
