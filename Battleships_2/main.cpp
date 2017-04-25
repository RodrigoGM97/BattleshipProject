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
    J1.AddBarco(bar); //agrega el 3,5, 
        J1.getPropio().printTab();
    cout<<"gola";
    


    return 0;
    
}