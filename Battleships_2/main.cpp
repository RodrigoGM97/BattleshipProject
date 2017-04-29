#include <iostream>
#include <string>
#include "jugador.h"
#include "tablero_jugador.h"
#include "Ataques.h"
#include "AirStrike.h"
#include "Multistrike.h"
#include <vector>
#include <cstdlib>

void SetupBarcos(Jugador &);
void SetupUniversal(Jugador &J, Jugador &J2);
void Turnos(bool t, Jugador &J, Jugador &J2);
void Ataques();
void check_end(Jugador &J, Jugador &J1);

Barco bar;
string ori;
string Coords = "ABCDEFGHIJ";
int coordColumn=0, coordReng=0;
char col;
bool turno = true;
bool end_game=false;

int main()
{

    Jugador J;
    Jugador J2;
    //pedir Nombres
    SetupUniversal(J, J2);
    
    while(end_game==false)
    {
        //Turnos(turno, J, J2);
        if(turno==true)
        {
            cout<<J.getNombre()<<" está atacando..."<<endl;
            cout<<"Ingresa coordenadas a ataque: ";
            cin>>col;
            cin>>coordReng;
            for(coordColumn; Coords[coordColumn]!=col;coordColumn++);
            coordColumn++;
            
            //J2.getPropio().printTab();
            J.AtaqueBasico(coordColumn, coordReng);
            cout<<"Guía de ataques: "<<endl;
            J.getGuia().printTab();
            cout<<"---------------------------------------------------------------"<<endl;
            cout<<"Tu tablero: "<<endl;
            J.getPropio().printTab();
            cout<<endl<<"Presiona una tecla y enter para terminar tu turno"<<endl;
            cin>>col;
            
            system("clear");
            turno = false;
           // J2.getPropio().printTab();
        }
        else
        {
            cout<<J2.getNombre()<<" está atacando..."<<endl;
            cout<<"Ingresa coordenadas a ataque: ";
            cin>>col;
            cin>>coordReng;
            for(coordColumn; Coords[coordColumn]!=col;coordColumn++);
            coordColumn++;
            
            //J2.getPropio().printTab();
            J2.AtaqueBasico(coordColumn, coordReng);
            cout<<"Guía de ataques: "<<endl;
            J2.getGuia().printTab();
            cout<<"---------------------------------------------------------------"<<endl;
            cout<<"Tu tablero: "<<endl;
            J2.getPropio().printTab();
            cout<<endl<<"Presiona una tecla y enter para terminar tu turno"<<endl;
            cin>>col;
            
            system("clear");
            turno=true;
           // J2.getPropio().printTab();
            check_end(J, J2);
        }
    }
    
    /*Barco barq(4,"vertical");
    Barco barq2(3,"vertical");
    barq.setVertical(2,3);
    barq2.setVertical(4,5);
    J.AddBarco(barq);
    J2.AddBarco(barq2);
    J.setTableroEnemigo(J2);
    J2.setTableroEnemigo(J);
    J.getEnemigo().printTab();*/
    
    
    
    return 0;
    
}
void Turnos(bool turno, Jugador &J, Jugador &J2)
{
    
}
void SetupUniversal(Jugador &J, Jugador &J2)
{
    string nom;
    string inicia_turno;
    
    cout<<"Jugador 1: "<<endl<< "Ingrese su apodo: ";
    cin>>nom;
    J.setNombre(nom);
    
    cout<<"Jugador 2: "<<endl<< "Ingrese su apodo: ";
    cin>>nom;
    cout<<endl;
    J2.setNombre(nom);

//    
    cout << endl;
    
    //pedir barcos. Los tamaños son 5, 4, 3, 3, 2
    cout << J.getNombre() << " presiona Y para comenzar tu turno" << endl;

    cin >> inicia_turno;
    if (inicia_turno=="Y")
    {
        SetupBarcos(J);
        cout << endl<< J.getNombre() << " Ingresa cualquier tecla y Enter terminar tu turno" << endl;
        cin>>inicia_turno;
        
        system("clear");
        cout <<endl<< J2.getNombre() << " presiona Y para comenzar tu turno" << endl;
        cin>>inicia_turno;

            
        SetupBarcos(J2);
        
        cout << endl<< J2.getNombre() << " presiona X para terminar tu turno" << endl;
        cin>>inicia_turno;
        J.setTableroEnemigo(J2);
        J2.setTableroEnemigo(J);

        
    }
}
void SetupBarcos(Jugador & J)
{
    cout << J.getNombre()<< " está colocando sus barcos:  "  << endl;
        //Barco 1(5 casillas)
        J.getPropio().printTab();
        int conta=5;
        while(conta>0)
        {
            coordColumn = 0;
            if(conta>=3)
                cout << "Ingresa la orientacion que quieras tener para tu barco (su tamaño es de "<< conta<<" casillas)"<< endl << "horizontal" <<endl <<"vertical"<<endl;
            else
                cout << "Ingresa la orientacion que quieras tener para tu barco (su tamaño es de "<< conta+1<<" casillas)"<< endl << "horizontal" <<endl <<"vertical"<<endl;

            cin >>ori;
            
            if(conta>=3)
                bar.setTamBar(conta);
            else
                bar.setTamBar(conta+1);
            bar.setOrient(ori);
            cout<<"Ingresa la coordenada en la quieras tener el inicio de tu barco: " << endl;
            cin >> col;
            cin >> coordReng;
            for(coordColumn; Coords[coordColumn]!=col;coordColumn++);
            coordColumn++;
            if (ori=="horizontal")
            {
                bar.setHorizontal(coordColumn,coordReng);
            }
            else if (ori ==  "vertical")
            {
                bar.setVertical(coordColumn,coordReng);
            }
            J.AddBarco(bar);
            bar.resetPos();
            cout<<endl;
            J.getPropio().printTab();
            conta--;
            //Barco 2(4 casillas)
        }
}

void check_end(Jugador &J, Jugador &J1)
{
    for(int x=0; x<11; x++)
    {  
      for(int y=0; y<11; y++)
      {
        if (J.getPropio().tab[x][y] == "T" || J1.getPropio().tab[x][y] == "T")
        {
          end_game = false;
        }
        else
        end_game = true;
      }
    }
}