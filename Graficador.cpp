
#include "EasyBMP.h"
#include "Graficador.h"
#include <string>
#include <iostream>

Graficador::Graficador(unsigned int filas, unsigned int columnas) {
	if(filas<0||columnas<0)
		throw std:: string("Tamaño del tablero es invalido");
	this->filas=filas;
	this->columnas=columnas;
	this->Buscaminas.SetSize(TAMANIOCASILLA*this->columnas+1,TAMANIOCASILLA*this->filas+1);
	this->Buscaminas.SetBitDepth(8);
	this->Buscaminas.WriteToFile("Buscaminas.bmp");
}



void Graficador:: setTablero(){
	BMP Buscaminas;
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	RGBApixel Negro = this->Buscaminas.GetPixel(1,1);
	Negro.Red = 0; Negro.Green = 0; Negro.Blue = 0; Negro.Alpha = 0;
	RGBApixel Amarillo = this->Buscaminas.GetPixel(2,2);
	Amarillo.Red = 255;Amarillo .Green = 255; Amarillo.Blue = 0 ; Amarillo.Alpha = 0;
	pintarFondo(Buscaminas,Negro,this->filas,this->columnas);
	pintarCasillero(Buscaminas,Amarillo,this->filas,this->columnas);
}

void Graficador::imprimirJugada(unsigned int Fila,unsigned int Columna, char objetoAPintar){
	if(Fila<0||Columna<0)
		throw std:: string("Graficador: Posicion Invalida");
	BMP Buscaminas;
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	RGBApixel Rojo = Buscaminas.GetPixel(0,0);
	Rojo.Red = 250; Rojo.Green = 0; Rojo.Blue = 0; Rojo.Alpha = 0;
	RGBApixel Blanco = Buscaminas.GetPixel(2,2);
	RGBApixel Negro = Buscaminas.GetPixel(1,1);
	Negro.Red = 0; Negro.Green = 0; Negro.Blue = 0; Negro.Alpha = 0;
	Blanco.Red = 255; Blanco.Green = 255; Blanco.Blue = 255; Blanco.Alpha = 0;

	if(objetoAPintar== 'M')
		pintarCaracter(Buscaminas,Rojo, Fila,Columna,objetoAPintar);
	else if (objetoAPintar == 'Q')
		pintarVacio(Buscaminas, Negro, Fila, Columna);
	else
		pintarCaracter(Buscaminas, Blanco, Fila, Columna, objetoAPintar);

}

void Graficador::pintarFondo(BMP Buscaminas,RGBApixel Color,unsigned int CantidadFilas,unsigned int CantidadColumnas){
	if(CantidadFilas<1||CantidadColumnas<1)
		throw std:: string("Tamaño del tablero es invalido");
	for(unsigned int i=0; i <=TAMANIOCASILLA*CantidadFilas; i++){
				for(unsigned int j=0; j <= TAMANIOCASILLA*CantidadColumnas; j++){
						Buscaminas.SetPixel(j,i,Color);
				}
			}
			Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int CantidadFilas,unsigned int CantidadColumnas){
	if(CantidadFilas<1||CantidadColumnas<1)
		throw std:: string("Cantidad de Filas y/o Columnas es menor a 1");
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	unsigned int CantidadMayor;
	if(CantidadFilas>CantidadColumnas)
		CantidadMayor=CantidadFilas;
	 else
		 CantidadMayor=CantidadColumnas;
	for(unsigned int k=0; k <=CantidadMayor; k++){
		for(unsigned int i=0; i <=TAMANIOCASILLA*CantidadFilas; i++){
			for(unsigned int j=0; j <= TAMANIOCASILLA*CantidadColumnas; j++){
				if(i==0 || i== TAMANIOCASILLA*CantidadFilas ||j== 0 ||j== TAMANIOCASILLA*CantidadColumnas|| i==k*TAMANIOCASILLA
					|| j==k*TAMANIOCASILLA){
					Buscaminas.SetPixel(j,i,Color);
				}
			}
		}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarVacio(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
		Buscaminas.ReadFromFile("Buscaminas.bmp");
		for( int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+5; j <= TAMANIOCASILLA*Columna-5; j++){
				for( int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i <= TAMANIOCASILLA*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarUno(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
			for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
					for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
						if( j<= (TAMANIOCASILLA*Columna)-20 && j>= (TAMANIOCASILLA*Columna)-21){
							Buscaminas.SetPixel(j,i,Color);
						}
					}
			}
			Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarDos(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
		for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
			if( j<= (TAMANIOCASILLA*Columna)-10 && j>= (TAMANIOCASILLA*Columna)-11 && i<= TAMANIOCASILLA*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(j<= (TAMANIOCASILLA*Columna)-20 && j>= (TAMANIOCASILLA*Columna)-21 && i>= TAMANIOCASILLA*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-6 && i>= TAMANIOCASILLA*Fila-7 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-24 && i>= TAMANIOCASILLA*Fila-25 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-15 && i>= TAMANIOCASILLA*Fila-16 ){
				Buscaminas.SetPixel(j,i,Color);
								}
		}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarTres(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
		for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
			if( (j<= (TAMANIOCASILLA*Columna)-10 && j>= (TAMANIOCASILLA*Columna)-11)){
					Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-6 && i>= TAMANIOCASILLA*Fila-7 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-24 && i>= TAMANIOCASILLA*Fila-25 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-15 && i>= TAMANIOCASILLA*Fila-16 ){
				Buscaminas.SetPixel(j,i,Color);
			}
		}
	}
			Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarCuatro(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
			for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
				if( j<= (TAMANIOCASILLA*Columna)-10 && j>= (TAMANIOCASILLA*Columna)-11){
					Buscaminas.SetPixel(j,i,Color);
				}
				if(j<= (TAMANIOCASILLA*Columna)-20 && j>= (TAMANIOCASILLA*Columna)-21 && i<= TAMANIOCASILLA*Fila-15){
					Buscaminas.SetPixel(j,i,Color);
				}
				if(i<= TAMANIOCASILLA*Fila-15 && i>= TAMANIOCASILLA*Fila-16 ){
					Buscaminas.SetPixel(j,i,Color);
									}
			}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
}


void Graficador::pintarCinco(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
		for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
			if( j<= (TAMANIOCASILLA*Columna)-10 && j>= (TAMANIOCASILLA*Columna)-11 && i>= TAMANIOCASILLA*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(j<= (TAMANIOCASILLA*Columna)-20 && j>= (TAMANIOCASILLA*Columna)-21 && i<= TAMANIOCASILLA*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-6 && i>= TAMANIOCASILLA*Fila-7 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-24 && i>= TAMANIOCASILLA*Fila-25 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-15 && i>= TAMANIOCASILLA*Fila-16 ){
				Buscaminas.SetPixel(j,i,Color);
								}
		}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarSeis(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
		for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
			if( j<= (TAMANIOCASILLA*Columna)-10 && j>= (TAMANIOCASILLA*Columna)-11 && i>= TAMANIOCASILLA*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(j<= (TAMANIOCASILLA*Columna)-20 && j>= (TAMANIOCASILLA*Columna)-21  ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-6 && i>= TAMANIOCASILLA*Fila-7 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-24 && i>= TAMANIOCASILLA*Fila-25 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLA*Fila-15 && i>= TAMANIOCASILLA*Fila-16 ){
				Buscaminas.SetPixel(j,i,Color);
								}
		}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarSiete(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
				for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
					if( j<= (TAMANIOCASILLA*Columna)-10 && j>= (TAMANIOCASILLA*Columna)-11){
						Buscaminas.SetPixel(j,i,Color);
					}
					if(i<= TAMANIOCASILLA*Fila-24 && i>= TAMANIOCASILLA*Fila-25 ){
						Buscaminas.SetPixel(j,i,Color);
					}
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
	}

void Graficador::pintarOcho(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
				for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
					if( (j<= (TAMANIOCASILLA*Columna)-10 && j>= (TAMANIOCASILLA*Columna)-11)
						||
						(j<= (TAMANIOCASILLA*Columna)-20 && j>= (TAMANIOCASILLA*Columna)-21)){
						Buscaminas.SetPixel(j,i,Color);
					}
					if(i<= TAMANIOCASILLA*Fila-6 && i>= TAMANIOCASILLA*Fila-7 ){
						Buscaminas.SetPixel(j,i,Color);
					}
					if(i<= TAMANIOCASILLA*Fila-24 && i>= TAMANIOCASILLA*Fila-25 ){
						Buscaminas.SetPixel(j,i,Color);
					}
					if(i<= TAMANIOCASILLA*Fila-15 && i>= TAMANIOCASILLA*Fila-16 ){
						Buscaminas.SetPixel(j,i,Color);
					}
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
	}


void Graficador::pintarBandera(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+5; j < TAMANIOCASILLA*Columna-5; j++){
			for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
				if(	(j<= (TAMANIOCASILLA*Columna)-21 && j>= (TAMANIOCASILLA*Columna)-22)
					||
					(i <= TAMANIOCASILLA*Fila-15 && j>= (TAMANIOCASILLA*Columna)-21)	){
					Buscaminas.SetPixel(j,i,Color);
				}
			}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::limpiarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
		Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+5; j < TAMANIOCASILLA*Columna-5; j++){
				for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarMina(BMP Buscaminas,RGBApixel Color,unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+5; j < TAMANIOCASILLA*Columna-5; j++){
				for(int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
}

void Graficador::pintarCaracter(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna,char objetoAPintar){
	if(Fila<0||Columna<0)
		throw std:: string("Posicion invalida");

	if(objetoAPintar == '0')
		pintarVacio(Buscaminas,Color,Fila,Columna);
	else if(objetoAPintar == '1')
		pintarUno(Buscaminas,Color,Fila,Columna);
	else if(objetoAPintar == '2')
		pintarDos(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == '3')
		pintarTres(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == '4')
		pintarCuatro(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == '5')
		pintarCinco(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == '6')
		pintarSeis(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == '7')
		pintarSiete(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == '8')
		pintarOcho(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == 'B')
		pintarBandera(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == 'Q')
		limpiarCasillero(Buscaminas,Color,Fila,Columna);
	else if (objetoAPintar == 'M')
		pintarMina(Buscaminas,Color,Fila,Columna);
	else
		std::cout<<" Graficador: imprimirTablero: No recibio un caracter valido";
}


Graficador::~Graficador() {
	// TODO Auto-generated destructor stub
}

