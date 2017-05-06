#ifndef ATAQUES_H
#define ATAQUES_H
#include "jugador.h"
//clase para el intento de polimorfismo pero fracasó. Problemas de forward declaration muy raros
class Ataque
{
private:
    int x;
    int y;
public:
    Ataque()
    {
        x=1;
        y=1;
    }
    Ataque(int x, int y)
    {
        this->x=x;
        this->y=y;
    }
    void setCoords(int x1, int y1)
    {
        x=x1;
        y=y1;
    }
    int getX_Ataque()
    {
        return x;
    }
    int getY_Ataque()
    {
        return y;
    }
    virtual void AttackPosition(int x, int y, Jugador &J, Jugador &J2)
    {
        cout<<"byeeee"<<endl;
        if(J.getEnemigo().tab[x][y] == "T")
        {
            J.getEnemigo().tab[x][y] = "X";
            J.getGuia().tab[x][y]="X";
            J2.getPropio().tab[x][y]="X";
        }
        else if (J.getEnemigo().tab[x][y] == "0")
        {
            J.getGuia().tab[x][y]  = "F";
        }
    }

};

#endif