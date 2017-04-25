#ifndef TABLERO_JUGADOR_H
#define TABLERO_JUGADOR_H
#include <vector>
#include <iostream>
using namespace std;
#include <string>
class TableroJugador //Recibe los parametros (y,x) del tablero
{
  public:
  string tab[11][11];
  TableroJugador()
  {
  	tab[0][0]= " ";
  	
  	tab[0][1] = "A";
	tab[0][2] = "B";
	tab[0][3] = "C";
  	tab[0][4] = "D";
  	tab[0][5] = "E";
  	tab[0][6] = "F";
  	tab[0][7] = "G";
  	tab[0][8] = "H";
  	tab[0][9] = "I";
  	tab[0][10] = "J";
  	
  	tab[1][0] = "1";
  	tab[2][0] = "2";
  	tab[3][0] = "3";
  	tab[4][0] = "4";
  	tab[5][0] = "5";
  	tab[6][0] = "6";
  	tab[7][0] = "7";
  	tab[8][0] = "8";
  	tab[9][0] = "9";
  	tab[10][0] = "10";




  	for(int x=1; x<11; x++)
  	{
  		for(int y=1; y<11; y++)
  		{
  			tab[x][y]="0";
  		}
  	}
  }
  void printTab()
  {
  	for(int x=0; x<11; x++)
  	{
  		for(int y=0; y<11; y++)
  		{
  			cout<<tab[x][y]<<"\t";
  		}
  		cout<<endl;
  	}
  }
};

#endif