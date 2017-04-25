#ifndef JUGADOR_H
#define JUGADOR_H
#include "tablero_jugador.h"
#include "Barco.h"
class Jugador
{
    private:
    TableroJugador propio;
    TableroJugador enemigo;
    int barcos_restantes;
    Barco *piezas;

    public:

    Jugador() 
    {
        barcos_restantes = 5;
        piezas = new Barco[5];
    }
    Jugador(int barcos_restantes)
    {
        this->barcos_restantes=barcos_restantes;
        piezas = new Barco[barcos_restantes];

      
    }
    TableroJugador getPropio()
    {
        return propio;
    }
    void Bomba(int x, int y) //Coordenada donde echar la bomba
    {
        if(enemigo.tab[x][y] == "B")
        {
            enemigo.tab[x][y] = "X";
        }
        
        
    }
    void setTabEnemigo(string[] tabl)
    {
        for (int i=0;i<11;i++)
        {
            for (int j=0;j<11;j++)
            {
               enemigo[x][y] = tabl[x][y];
            }
        }    
    }
    
};

#endif