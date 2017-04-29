#ifndef AIRSTRIKE_H
#define AIRSTRIKE_H
#include "Ataques.h"
class AirStrike: virtual public Ataque
{
    public:
    void AttackPosition(Jugador &J)
    {
        for(int x1=0;x1<11;x1++)
        {
            if(J.getEnemigo().tab[x1][getY_Ataque()] == "T")
             {
                 J.getEnemigo().tab[x1][getY_Ataque()] = "X";
                 J.getGuia().tab[x1][getY_Ataque()]="X";
            }
            else if (J.getEnemigo().tab[x1][getY_Ataque()] == "0")
            {
                J.getGuia().tab[x1][getY_Ataque()]  = "F";
            } 
        }
       
    }
};


#endif