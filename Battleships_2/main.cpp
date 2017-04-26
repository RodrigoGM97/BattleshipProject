#include <iostream>
#include <string>
#include "jugador.h"
#include "tablero_jugador.h"
#include <vector>
int main()
{
    Jugador J1;
    Barco bar(4,"vertical");
    bar.setVertical(3,5);
    J1.AddBarco(bar);
    J1.Bomba(3,5);
    J1.getPropio().printTab(); //hola!

    return 0;
    
}