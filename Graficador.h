
#ifndef GRAFICADOR_H_
#define GRAFICADOR_H_
#include "EasyBMP.h"


const unsigned int TAMANIOCASILLA = 30; //Pixeles

class  Graficador{

private:
	BMP Buscaminas;
	unsigned int filas;
	unsigned int columnas;

public:
	//Pre: Filas y Columnas deben ser mayores a 0
	//Post: Crea el Tablero en formato BMP del Buscaminas,con las filas, y las
	// columnas, el archivo se llamara "Buscaminas.bmp"
	Graficador(unsigned int filas, unsigned int columnas);
	//Pre:Esta funcion no se utilizo previamente.
	//Post: Imprime el fondo del tablero en "Buscaminas.bmp"
	void setTablero();
	//Pre: Filas y Columnas deben ser mayores a 0
	//Post: Modifica el BMP para incluir a la ultima jugada echa
	void imprimirJugada(unsigned int Fila,unsigned int Columna, char objetoAPintar);

	virtual ~Graficador();
private:
	//pre:
	//post:Pinta los limites de los casilleros en el BMP
	void pintarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int CantidadFilas,unsigned int CantidadColumnas);
	//pre:
	//post:Pinta el fondo del BMP
	void pintarFondo(BMP Buscaminas,RGBApixel Color, unsigned int CantidadFilas,unsigned int CantidadColumnas);
	//pre: Filas y columnas deben ser mayor a 0
	//post:Pinta el caracter en el lugar deseado
	void pintarCaracter(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna,char objetoAPintar);
        //Post: Pinta el casillero como "Vacio" que representa un 0, es decir que no hay minas aledañas
	void pintarVacio(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor '1' 
	void pintarUno(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor '2'
	void pintarDos(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor '3'
	void pintarTres(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor '4'
	void pintarCuatro(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor '5'
	void pintarCinco(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor '6'
	void pintarSeis(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor '7'
	void pintarSiete(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor '8'
	void pintarOcho(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor 'B', es decir una bandera
	void pintarBandera(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Limpia el casillero, dejandolo con el valor 'oculto'
	void limpiarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
	//Post: Pinta el casillero con el valor 'M', es decir, una mina, Reprensentada por un cuadrado rojo
	void pintarMina(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
};


#endif /* Graficador_H_ */
