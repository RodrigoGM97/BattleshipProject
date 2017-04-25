#include <iostream>
#include <string>
#include "jugador.h"
#include "tablero_jugador.h"
#include <vector>
int main()
{
    Jugador J1;
    J1.getPropio().printTab();
    Barco bar(4,"vertical");
    bar.setXBar(5);
    bar.setYBar(6);
    
    string prueba[11][11];
    for(int y=0; y<11; y++)
    {
        for(int t=0; t<11; t++)
        {
            prueba[y][t]=
        }
    }


    return 0;
    
}