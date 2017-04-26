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
    int contadorBarcos;
    Barco *piezas;

    public:

    Jugador() 
    {
        barcos_restantes = 5;
        contadorBarcos=0;
        piezas = new Barco[5];
    }
    Jugador(int barcos_restantes)
    {
        this->barcos_restantes=barcos_restantes;
        piezas = new Barco[barcos_restantes];
        contadorBarcos=0;


      
    }
    TableroJugador getPropio()
    {
        return propio;
    }
    void Bomba(int y, int x) //Coordenada donde echar la bomba
    {
        if(enemigo.tab[x][y] == "T")
        {
            enemigo.tab[x][y] = "X";
        }
        
        
    }
    void AddBarco(Barco bar)
    {

        string lugar;
        int sigPos=0;
        piezas[contadorBarcos]=bar;
        //piezas[contadorBarcos].getXBar(0);  --> tiene un 3
        
        lugar= piezas[contadorBarcos].getOrient();
        if(lugar=="vertical")
        {
            while(sigPos<piezas[contadorBarcos].getTamBar())
            {
                propio.tab[piezas[contadorBarcos].getYBar(sigPos)][piezas[contadorBarcos].getXBar(0)] = "T"; //Nota: son y, x las coordenadas
                sigPos++;
            }
            
            
        }
         if(lugar=="horizontal")
        {
            while(sigPos<piezas[contadorBarcos].getTamBar())
            {
                propio.tab[piezas[contadorBarcos].getYBar(sigPos)][piezas[contadorBarcos].getXBar(0)] = "T"; //Nota: son y, x las coordenadas
                sigPos++;
            }
            
            
        }
        contadorBarcos++;
        
    }
   
    
};

#endif