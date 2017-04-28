#ifndef BARCO_H
#define BARCO_H
#include <vector>
class Barco
{
private:
    int tamano;
    int *coordenadaX;
    int *coordenadaY;
    int contadorX;
    int contadorY;
    string orientacion;
public: 
    Barco() {
        contadorX=0;
        contadorY=0;
        orientacion = "vertical";
    }
    Barco(int tamano, string orientacion)
    {
       this->orientacion=orientacion;
       this->tamano=tamano; 
       coordenadaX = new int[tamano];
       coordenadaY = new int[tamano];
       contadorX=0;
       contadorY=0;
    }
    void setTamBar(int tam)
    {
        tamano=tam;
        coordenadaX = new int[tamano];
        coordenadaY = new int[tamano];
        
    }
   
    void setOrient(string x)
    {
        orientacion = x;
    }
    
    string getOrient()
    {
        return orientacion;
    }
    int getTamBar()
    {
        return tamano;
    }
    int getXBar(int pox)
    {
        return coordenadaX[pox];
    }
    int getYBar(int poy)
    {
        return coordenadaY[poy];

    }
    void resetPos()
    {
        contadorX=0;
        contadorY=0;
    }
    void setHorizontal(int x, int y)
    {
        if(orientacion=="horizontal")
        {
            while( contadorY <5)
            {
              coordenadaY[contadorY] = y;
              contadorY++;
            }
            if(x + tamano >=11)
            {
                do
                {
                    x--;
                }
                while(x+tamano>=11);
            }
            while(contadorX<tamano)
            {
                coordenadaX[contadorX]=x;
                x++;
                contadorX++;
            }
        }
    }
    void setVertical(int x, int y)
    {
       if(orientacion=="vertical")
        {
            while( contadorX <5)
            {
              coordenadaX[contadorX] = x;
              contadorX++;
            }
            if(y + tamano >=11)
            {
                do
                {
                    y--;
                }
                while(y+tamano>=11);
            }
            while(contadorY<tamano)
            {
                coordenadaY[contadorY]=y;
                y++;
                contadorY++;
            }
        }
       
        
    }
    
};
#endif