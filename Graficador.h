
#ifndef GRAFICADOR_H_
#define GRAFICADOR_H_
#include "EasyBMP.h"


const unsigned int TAMANIOCASILLERO = 30;//Pixeles
namespace Graficador{

class  Graficador{

private:
	BMP Buscaminas;
	unsigned int filas;
	unsigned int columnas;

public:
	//Pre: Filas y Columnas deben ser mayores a 0
	//Post: Crea el Tablero en formato BMP del Buscaminas,con tableroObtener como filas, y Tableroobtener
	//como columnas, el archivo se llamara "Buscaminas.bmp"
	Graficador(unsigned int filas, unsigned int columnas);
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

	void pintarVacio(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarUno(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarDos(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarTres(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarCuatro(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarCinco(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarSeis(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarSiete(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarOcho(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarBandera(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void limpiarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);

	void pintarMina(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna);
};


} /* namespace Graficador */

#endif /* Graficador_H_ */
