#include <iostream>
#include <string>
#include "jugador.h"
#include "tablero_jugador.h"
#include <vector>
#include <cstdlib>
void SetupBarcos(Jugador);
void SetupUniversal();
void Ataques();
Jugador J;
Jugador J2;
Jugador jugadores[2];
Barco bar;
string ori;
string Coords = "ABCDEFGHIJ";
int coordColumn=0, coordReng=0;

int main()
{
    //pedir Nombres
    SetupUniversal();
    
    return 0;
    
}
void SetupUniversal()
{
    string nom;
    string inicia_turno;
    
    bool turno = false;
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
        
        if (turno==true)
        {
            cout << J.getNombre() << "Es tu turno de atacar: " << endl;
            cout << "Dame la columna y el renglón que quieres atacar: " << endl;
            
        }

        
    }
}
void SetupBarcos(Jugador J1)
{
    cout << J1.getNombre()<< " está colocando sus barcos:  "  << endl;
        //Barco 1(5 casillas)
        J1.getPropio().printTab();
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
            cout<<"Ingresa la columna en la quieras tener el inicio de tu barco: " << endl;
            char col;
            cin >> col;
            cout << "Ahora ingresa el renglón: " << endl;
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
            J1.AddBarco(bar);
            bar.resetPos();
            cout<<endl;
            J1.getPropio().printTab();
            conta--;
            //Barco 2(4 casillas)
        }
}
