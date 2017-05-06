#ifndef AIRSTRIKE_H
#define AIRSTRIKE_H
#include "Ataques.h"
//clase para el intento de polimorfismo pero fracasó. Problemas de forward declaration muy raros

class AirStrike:public Ataque
{
    public:
    void AttackPosition(int x, int y, Jugador &J, Jugador &J2)
    {
        cout<<"hola!!!"<<endl;
        for(int x1=0;x1<11;x1++)
        {
            if(J.getEnemigo().tab[x1][y] == "T")
             {
                 J.getEnemigo().tab[x1][y] = "X";
                 J.getGuia().tab[x1][y]="X";
                 J2.getPropio().tab[x1][y]="X";
            }
            else if (J.getEnemigo().tab[x1][y] == "0")
            {
                J.getGuia().tab[x1][y]  = "F";
            } 
        }
       
    }
};


#endif