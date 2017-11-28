#ifndef NODOBINARIO_H_
#define NODOBINARIO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class NodoBinario {

    private:

        T dato;

        NodoBinario<T>* hermano;

        NodoBinario<T>* hijo;

    public:

        /*
         * post: el Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         */
        NodoBinario(T dato){

            this->dato = dato;
            this->hermano = NULL;
            this->hijo = NULL;
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
         * post: cambia el siguiente Nodo por nuevoSiguiente.
         */
        void cambiarSiguiente(NodoBinario<T>* nuevoHermano) {

            this->hermano = nuevoHermano;
        }

        /*
		* post: devuelve el siguiente Nodo.
		*/
		NodoBinario<T>* obtenerHijo() {

			return this->hijo;
		}

		/*
		* post: cambia el siguiente Nodo por nuevoSiguiente.
		*/
		void cambiarHijo(NodoBinario<T>* nuevoHijo) {

			 this->hermano = nuevoHijo;
		}



};


#endif /* NODOBINARIO_H_ */
