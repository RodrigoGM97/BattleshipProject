#include <iostream>
#include <string>
#include "jugador.h"
#include "tablero_jugador.h"
#include <vector>
#include <cstdlib>
void SetupJuego();
Jugador J1;
Jugador J2;
int main()
{
    SetupJuego();
   
    J1.AtaqueBasico(2,6);
    J2.BajoAtaque(2,6);
    J1.getGuia().printTab(); //hola!
    
    
    system("clear");

    return 0;
    
}

void SetupJuego()
{
    Barco bar(4,"horizontal");  //Numero de casillas del barco, orientación
    bar.setHorizontal(3,5);
    J1.AddBarco(bar);
    bar.resetPos();
    bar.setHorizontal(2,6);
    J2.AddBarco(bar);
    Barco bar1(4,"horizontal");
    bar1.setHorizontal(2,2);
    J1.AddBarco(bar1);
    J1.setTableroEnemigo(J2);
    J2.setTableroEnemigo(J1);
}