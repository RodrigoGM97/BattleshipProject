#ifndef JUGADOR_H
#define JUGADOR_H
#include "tablero_jugador.h"
#include "Barco.h"
class Jugador
{
    private:
    string nombre;
    TableroJugador propio;
    TableroJugador enemigo;
    TableroJugador guia_de_ataque;
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
    void setNombre(string n)
    {
        nombre = n;
    }
    string getNombre()
    {
        return nombre;
    }
    TableroJugador getPropio()
    {
        return propio;
    }
    TableroJugador getEnemigo()
    {
        return enemigo;
    }
    TableroJugador getGuia()
    {
        return guia_de_ataque;
    }
    
    void setTableroEnemigo(Jugador J2)
    {
        this->enemigo = J2.getPropio();
    }
    void BajoAtaque(int y, int x)
    {
         if(propio.tab[x][y] == "T")
        {
            propio.tab[x][y] = "X";
            
        }
    }
    void AtaqueBasico(int y, int x) //Coordenada donde vas a atacar al otro
    {
        if(enemigo.tab[x][y] == "T")
        {
            enemigo.tab[x][y] = "X";
            guia_de_ataque.tab[x][y]="X";
        }
        else if (enemigo.tab[x][y] == "0")
        {
            guia_de_ataque.tab[x][y]  = "F";
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
                propio.tab[piezas[contadorBarcos].getYBar(0)][piezas[contadorBarcos].getXBar(sigPos)] = "T"; //Nota: son y, x las coordenadas
                sigPos++;
            }
            
            
        }
        contadorBarcos++;
        
    }
   
    
};

#endif