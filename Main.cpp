/*#include "Graficador.h"
#include <iostream>
#include <fstream>
using namespace std;


void pintarFondo(BMP Buscaminas,RGBApixel Color,unsigned int CantidadFilas,unsigned int CantidadColumnas){
	for(unsigned int i=0; i <=TAMANIOCASILLA*CantidadFilas; i++){
				for(unsigned int j=0; j <= TAMANIOCASILLA*CantidadColumnas; j++){
						Buscaminas.SetPixel(j,i,Color);
				}
			}
			Buscaminas.WriteToFile("Test.bmp");
}

void pintarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int CantidadFilas,unsigned int CantidadColumnas){
	Buscaminas.ReadFromFile("Test.bmp");
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
	Buscaminas.WriteToFile("Test.bmp");
}

void pintarVacio(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
		Buscaminas.ReadFromFile("Test.bmp");
		for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+5; j < TAMANIOCASILLA*Columna-5; j++){
				for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Test.bmp");
}

void pintarUno(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
			for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+9; j < TAMANIOCASILLA*Columna-9; j++){
					for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
						if( j<= (TAMANIOCASILLA*Columna)-20 && j>= (TAMANIOCASILLA*Columna)-21){
							Buscaminas.SetPixel(j,i,Color);
						}
					}
			}
			Buscaminas.WriteToFile("Test.bmp");
}

void pintarDos(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
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
	Buscaminas.WriteToFile("Test.bmp");
}

void pintarTres(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
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
			Buscaminas.WriteToFile("Test.bmp");
}

void pintarCuatro(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
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
		Buscaminas.WriteToFile("Test.bmp");
}


void pintarCinco(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
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
	Buscaminas.WriteToFile("Test.bmp");
}

void pintarSeis(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
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
	Buscaminas.WriteToFile("Test.bmp");
}

void pintarOcho(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
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
		Buscaminas.WriteToFile("Test.bmp");
	}

void pintarSiete(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
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
		Buscaminas.WriteToFile("Test.bmp");
	}

void pintarBandera(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
	for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+5; j < TAMANIOCASILLA*Columna-5; j++){
			for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
				if(	(j<= (TAMANIOCASILLA*Columna)-21 && j>= (TAMANIOCASILLA*Columna)-22)
					||
					(i <= TAMANIOCASILLA*Fila-15 && j>= (TAMANIOCASILLA*Columna)-21)	){
					Buscaminas.SetPixel(j,i,Color);
				}
			}
	}
	Buscaminas.WriteToFile("Test.bmp");
}

void limpiarCasillero(BMP Buscaminas,RGBApixel Color, unsigned int Fila,unsigned int Columna){
		Buscaminas.ReadFromFile("Test.bmp");
		for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+5; j < TAMANIOCASILLA*Columna-5; j++){
				for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Test.bmp");
}

void pintarMina(BMP Buscaminas,RGBApixel Color,unsigned int Fila,unsigned int Columna){
	Buscaminas.ReadFromFile("Test.bmp");
		for(unsigned int j=TAMANIOCASILLA*Columna-TAMANIOCASILLA+5; j < TAMANIOCASILLA*Columna-5; j++){
				for(unsigned int i=TAMANIOCASILLA*Fila-TAMANIOCASILLA+5; i < TAMANIOCASILLA*Fila-5; i++){
					Buscaminas.SetPixel(j,i,Color);
				}
		}
		Buscaminas.WriteToFile("Test.bmp");
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


int main(){
		unsigned int CantidadFilas;
			    cout<<"Ingresa la cantidad de fil papu"<<endl;
			    cin>>CantidadFilas;
		unsigned int CantidadColumnas;
				cout<<"Ingresa la cantidad de col papu"<<endl;
			   	cin>>CantidadColumnas;
		BMP Buscaminas;
		Buscaminas.SetBitDepth(8);
		Buscaminas.SetSize(TAMANIOCASILLA*CantidadColumnas+1,TAMANIOCASILLA*CantidadFilas+1);
		Buscaminas.WriteToFile("Test.bmp");
		Buscaminas.ReadFromFile("Test.bmp");
		RGBApixel Rojo = Buscaminas.GetPixel(0,0);
		Rojo.Red = 250; Rojo.Green = 0; Rojo.Blue = 0; Rojo.Alpha = 0;
		RGBApixel Negro = Buscaminas.GetPixel(1,1);
		Negro.Red = 0; Negro.Green = 0; Negro.Blue = 0; Negro.Alpha = 0;
		RGBApixel Blanco = Buscaminas.GetPixel(2,2);
		Blanco.Red = 255; Blanco.Green = 255; Blanco.Blue = 255; Blanco.Alpha = 0;
		RGBApixel ColorX = Buscaminas.GetPixel(2,2);
		ColorX.Red = 255;ColorX .Green = 255; ColorX.Blue = 0 ; ColorX.Alpha = 0;

		pintarFondo(Buscaminas,Negro,CantidadFilas,CantidadColumnas);
		pintarCasillero(Buscaminas,ColorX,CantidadFilas,CantidadColumnas);
		pintarCaracter(Buscaminas,Blanco,1,1,'0');
		pintarCaracter(Buscaminas,Blanco,1,2,'1');
		pintarCaracter(Buscaminas,Blanco,1,3,'2');
		pintarCaracter(Buscaminas,Blanco,1,4,'3');
		pintarCaracter(Buscaminas,Blanco,1,5,'4');
		pintarCaracter(Buscaminas,Blanco,2,1,'5');
		pintarCaracter(Buscaminas,Blanco,2,2,'6');
		pintarCaracter(Buscaminas,Blanco,2,3,'7');
		pintarCaracter(Buscaminas,Blanco,2,4,'8');
		pintarCaracter(Buscaminas,Blanco,2,5,'B');
		pintarCaracter(Buscaminas,Negro,3,1,'Q');
		pintarCaracter(Buscaminas,Rojo,3,2,'M');
		cout<<"Finished"<<endl;

//		cout << "colors: " << Buscaminas.TellNumberOfColors() << endl;
//		DisplayBitmapInfo("Test.bmp");


		return 0;
}
*/

