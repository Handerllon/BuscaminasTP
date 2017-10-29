

#include "EasyBMP.h"
#include "Graficador.h"
#include "Inicializador.h"
namespace Graficador{

Graficador::Graficador(unsigned int filas, unsigned int columnas) {

	this->filas=filas;
	this->columnas=columnas;
	this->Buscaminas.SetSize(TAMANIOCASILLERO*this->columnas+1,TAMANIOCASILLERO*this->filas+1);
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
	this->pintarFondo(Buscaminas,Negro,this->filas,this->columnas);
	this->pintarCasillero(Buscaminas,Amarillo,this->filas,this->columnas);
}

void Graficador::imprimirJugada(unsigned int Fila,unsigned int Columna, char objetoAPintar){
	BMP Buscaminas;
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	RGBApixel Rojo = Buscaminas.GetPixel(0,0);
	Rojo.Red = 250; Rojo.Green = 0; Rojo.Blue = 0; Rojo.Alpha = 0;
	RGBApixel Blanco = Buscaminas.GetPixel(2,2);
	Blanco.Red = 255; Blanco.Green = 255; Blanco.Blue = 255; Blanco.Alpha = 0;

	if(objetoAPintar== 'M')
	pintarCaracter(Buscaminas,Rojo, Fila,Columna,objetoAPintar);
	else
	pintarCaracter(Buscaminas,Blanco, Fila,Columna,objetoAPintar);

}

void pintarFondo(BMP Buscaminas,RGBApixel Color,unsigned int CantidadFilas,unsigned int CantidadColumnas){
	for(unsigned int i=0; i <=TAMANIOCASILLERO*CantidadFilas; i++){
				for(unsigned int j=0; j <= TAMANIOCASILLERO*CantidadColumnas; j++){
						Buscaminas.SetPixel(j,i,Color);
				}
			}
			Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int CantidadFilas,unsigned int CantidadColumnas){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	unsigned int CantidadMayor;
	if(CantidadFilas>CantidadColumnas)
		CantidadMayor=CantidadFilas;
	 else
		 CantidadMayor=CantidadColumnas;
	for(unsigned int k=0; k <=CantidadMayor; k++){
		for(unsigned int i=0; i <=TAMANIOCASILLERO*CantidadFilas; i++){
			for(unsigned int j=0; j <= TAMANIOCASILLERO*CantidadColumnas; j++){
				if(i==0 || i== TAMANIOCASILLERO*CantidadFilas ||j== 0 ||j== TAMANIOCASILLERO*CantidadColumnas|| i==k*TAMANIOCASILLERO
					|| j==k*TAMANIOCASILLERO){
					Buscaminas.SetPixel(j,i,Color);
				}
			}
		}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarVacio(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
		Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+5; j < TAMANIOCASILLERO*Columna-5; j++){
				for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarUno(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
			for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+9; j < TAMANIOCASILLERO*Columna-9; j++){
					for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
						if( j<= (TAMANIOCASILLERO*Columna)-20 && j>= (TAMANIOCASILLERO*Columna)-21){
							Buscaminas.SetPixel(j,i,Color);
						}
					}
			}
			Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarDos(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+9; j < TAMANIOCASILLERO*Columna-9; j++){
		for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
			if( j<= (TAMANIOCASILLERO*Columna)-10 && j>= (TAMANIOCASILLERO*Columna)-11 && i<= TAMANIOCASILLERO*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(j<= (TAMANIOCASILLERO*Columna)-20 && j>= (TAMANIOCASILLERO*Columna)-21 && i>= TAMANIOCASILLERO*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-6 && i>= TAMANIOCASILLERO*Fila-7 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-24 && i>= TAMANIOCASILLERO*Fila-25 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-15 && i>= TAMANIOCASILLERO*Fila-16 ){
				Buscaminas.SetPixel(j,i,Color);
								}
		}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarTres(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+9; j < TAMANIOCASILLERO*Columna-9; j++){
		for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
			if( (j<= (TAMANIOCASILLERO*Columna)-10 && j>= (TAMANIOCASILLERO*Columna)-11)){
					Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-6 && i>= TAMANIOCASILLERO*Fila-7 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-24 && i>= TAMANIOCASILLERO*Fila-25 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-15 && i>= TAMANIOCASILLERO*Fila-16 ){
				Buscaminas.SetPixel(j,i,Color);
			}
		}
	}
			Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarCuatro(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+9; j < TAMANIOCASILLERO*Columna-9; j++){
			for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
				if( j<= (TAMANIOCASILLERO*Columna)-10 && j>= (TAMANIOCASILLERO*Columna)-11){
					Buscaminas.SetPixel(j,i,Color);
				}
				if(j<= (TAMANIOCASILLERO*Columna)-20 && j>= (TAMANIOCASILLERO*Columna)-21 && i<= TAMANIOCASILLERO*Fila-15){
					Buscaminas.SetPixel(j,i,Color);
				}
				if(i<= TAMANIOCASILLERO*Fila-15 && i>= TAMANIOCASILLERO*Fila-16 ){
					Buscaminas.SetPixel(j,i,Color);
									}
			}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
}


void pintarCinco(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+9; j < TAMANIOCASILLERO*Columna-9; j++){
		for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
			if( j<= (TAMANIOCASILLERO*Columna)-10 && j>= (TAMANIOCASILLERO*Columna)-11 && i>= TAMANIOCASILLERO*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(j<= (TAMANIOCASILLERO*Columna)-20 && j>= (TAMANIOCASILLERO*Columna)-21 && i<= TAMANIOCASILLERO*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-6 && i>= TAMANIOCASILLERO*Fila-7 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-24 && i>= TAMANIOCASILLERO*Fila-25 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-15 && i>= TAMANIOCASILLERO*Fila-16 ){
				Buscaminas.SetPixel(j,i,Color);
								}
		}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarSeis(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+9; j < TAMANIOCASILLERO*Columna-9; j++){
		for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
			if( j<= (TAMANIOCASILLERO*Columna)-10 && j>= (TAMANIOCASILLERO*Columna)-11 && i>= TAMANIOCASILLERO*Fila-15){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(j<= (TAMANIOCASILLERO*Columna)-20 && j>= (TAMANIOCASILLERO*Columna)-21  ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-6 && i>= TAMANIOCASILLERO*Fila-7 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-24 && i>= TAMANIOCASILLERO*Fila-25 ){
				Buscaminas.SetPixel(j,i,Color);
			}
			if(i<= TAMANIOCASILLERO*Fila-15 && i>= TAMANIOCASILLERO*Fila-16 ){
				Buscaminas.SetPixel(j,i,Color);
								}
		}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarSiete(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+9; j < TAMANIOCASILLERO*Columna-9; j++){
				for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
					if( j<= (TAMANIOCASILLERO*Columna)-10 && j>= (TAMANIOCASILLERO*Columna)-11){
						Buscaminas.SetPixel(j,i,Color);
					}
					if(i<= TAMANIOCASILLERO*Fila-24 && i>= TAMANIOCASILLERO*Fila-25 ){
						Buscaminas.SetPixel(j,i,Color);
					}
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
	}

void pintarOcho(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+9; j < TAMANIOCASILLERO*Columna-9; j++){
				for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
					if( (j<= (TAMANIOCASILLERO*Columna)-10 && j>= (TAMANIOCASILLERO*Columna)-11)
						||
						(j<= (TAMANIOCASILLERO*Columna)-20 && j>= (TAMANIOCASILLERO*Columna)-21)){
						Buscaminas.SetPixel(j,i,Color);
					}
					if(i<= TAMANIOCASILLERO*Fila-6 && i>= TAMANIOCASILLERO*Fila-7 ){
						Buscaminas.SetPixel(j,i,Color);
					}
					if(i<= TAMANIOCASILLERO*Fila-24 && i>= TAMANIOCASILLERO*Fila-25 ){
						Buscaminas.SetPixel(j,i,Color);
					}
					if(i<= TAMANIOCASILLERO*Fila-15 && i>= TAMANIOCASILLERO*Fila-16 ){
						Buscaminas.SetPixel(j,i,Color);
					}
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
	}


void pintarBandera(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
	for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+5; j < TAMANIOCASILLERO*Columna-5; j++){
			for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
				if(	(j<= (TAMANIOCASILLERO*Columna)-21 && j>= (TAMANIOCASILLERO*Columna)-22)
					||
					(i <= TAMANIOCASILLERO*Fila-15 && j>= (TAMANIOCASILLERO*Columna)-21)	){
					Buscaminas.SetPixel(j,i,Color);
				}
			}
	}
	Buscaminas.WriteToFile("Buscaminas.bmp");
}

void limpiarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
		Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+5; j < TAMANIOCASILLERO*Columna-5; j++){
				for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarMina(BMP Buscaminas,RGBApixel Color,unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Buscaminas.bmp");
		for(unsigned int j=TAMANIOCASILLERO*Columna-TAMANIOCASILLERO+5; j < TAMANIOCASILLERO*Columna-5; j++){
				for(unsigned int i=TAMANIOCASILLERO*Fila-TAMANIOCASILLERO+5; i < TAMANIOCASILLERO*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Buscaminas.bmp");
}

void pintarCaracter(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna,char objetoAPintar){
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
}


Graficador::~Graficador() {
	// TODO Auto-generated destructor stub
}

} /* namespace Graficador */
