#ifndef MULTISTRIKE_H
#define MULTISTRIKE_H
#include "Ataques.h"
//clase para el intento de polimorfismo pero fracasó. Problemas de forward declaration muy raros

class MultiStrike : virtual public Ataque
{
public:       
        void AttackPosition(Jugador &J)
        {
            if(J.getEnemigo().tab[getX_Ataque()][getY_Ataque()] == "T") //centro
            {
                 J.getEnemigo().tab[getX_Ataque()][getY_Ataque()] = "getX_Ataque()";
                 J.getGuia().tab[getX_Ataque()][getY_Ataque()]="getX_Ataque()";
            }
            else if (J.getEnemigo().tab[getX_Ataque()][getY_Ataque()] == "0")
            {
                J.getGuia().tab[getX_Ataque()][getY_Ataque()]  = "F";
            }
            if(getY_Ataque()!=1)
            {
                if(J.getEnemigo().tab[getX_Ataque()][getY_Ataque()-1] == "T") //arriba
                {
                 J.getEnemigo().tab[getX_Ataque()][getY_Ataque()-1] = "getX_Ataque()";
                 J.getGuia().tab[getX_Ataque()][getY_Ataque()-1]="getX_Ataque()";
                }
                else if (J.getEnemigo().tab[getX_Ataque()][getY_Ataque()-1] == "0")
                {
                  J.getGuia().tab[getX_Ataque()][getY_Ataque()-1]  = "F";
                }
            }
            if(getY_Ataque()!=11)
            {
                if(J.getEnemigo().tab[getX_Ataque()][getY_Ataque()+1] == "T") //arriba
                {
                 J.getEnemigo().tab[getX_Ataque()][getY_Ataque()+1] = "getX_Ataque()";
                 J.getGuia().tab[getX_Ataque()][getY_Ataque()+1]="getX_Ataque()";
                }
                else if (J.getEnemigo().tab[getX_Ataque()][getY_Ataque()+1] == "0")
                {
                  J.getGuia().tab[getX_Ataque()][getY_Ataque()+1]  = "F";
                }
            }
            
            if(getX_Ataque()!=1)
            {
                if(J.getEnemigo().tab[getX_Ataque()-1][getY_Ataque()] == "T") //arriba
                {
                 J.getEnemigo().tab[getX_Ataque()-1][getY_Ataque()] = "getX_Ataque()";
                 J.getGuia().tab[getX_Ataque()-1][getY_Ataque()]="getX_Ataque()";
                }
                else if (J.getEnemigo().tab[getX_Ataque()-1][getY_Ataque()] == "0")
                {
                  J.getGuia().tab[getX_Ataque()-1][getY_Ataque()]  = "F";
                }
            }
            
            if(getX_Ataque()!=11)
            {
                if(J.getEnemigo().tab[getX_Ataque()+1][getY_Ataque()] == "T") //arriba
                {
                 J.getEnemigo().tab[getX_Ataque()+1][getY_Ataque()] = "getX_Ataque()";
                 J.getGuia().tab[getX_Ataque()+1][getY_Ataque()]="getX_Ataque()";
                }
                else if (J.getEnemigo().tab[getX_Ataque()+1][getY_Ataque()] == "0")
                {
                  J.getGuia().tab[getX_Ataque()+1][getY_Ataque()]  = "F";
                }
            }
        }
};

#endif