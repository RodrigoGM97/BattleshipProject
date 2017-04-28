#include <iostream>
#include <string>
#include "jugador.h"
#include "tablero_jugador.h"
#include <vector>
#include <cstdlib>
void SetupJuego();
void Ataques();
Jugador J1;
Jugador J2;

int coordColumn=0, coordReng=0;
int main()
{
    //pedir Nombres
    string Coords = "ABCDEFGHIJ";
    string nom;
    string inicia_turno;
    string ori;
    bool Turno_J1=true;
    cout<<"Jugador 1: "<<endl<< "Ingrese su apodo: ";
    cin>>nom;
    J1.setNombre(nom);
    
    cout<<"Jugador 2: "<<endl<< "Ingrese su apodo: ";
    cin>>nom;
    cout<<endl;
    J2.setNombre(nom);

//    cout<<"J1: "<< J1.getNombre()<<endl<<"J2: "<<J2.getNombre()<< endl;
    cout << string(50, '\n');
    
    //pedir barcos. Los tamaños son 5, 4, 3, 3, 2
    cout << J1.getNombre() << " presiona Y para comenzar tu turno" << endl;

    cin >> inicia_turno;
    if (inicia_turno=="Y")
    {
        cout << J1.getNombre()<< " está colocando sus barcos:  "  << endl;
        //Barco 1(5 casillas)
        J1.getPropio().printTab();
        int conta=5;
        while(conta>1)
        {
            Barco bar;
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
            //cout<<coordColumn;
            //cout << "Si llega";
            if (ori=="horizontal")
            {
                bar.setHorizontal(coordColumn,coordReng);
            }
            else if (ori ==  "vertical")
            {
                bar.setVertical(coordColumn,coordReng);
            }
            J1.AddBarco(bar);
            //bar.resetPos();
            cout<<endl;
            J1.getPropio().printTab();
            conta--;
            //Barco 2(4 casillas)
        }
    }

    
    
    /*Barco bar(4,"horizontal");  //Numero de casillas del barco, orientación
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
    
    J1.AtaqueBasico(2,6);
    J2.BajoAtaque(2,6);
    cout << string(50, '\n');
    system("clear");
    J1.getPropio().printTab();   */
    
    
    //system("clear"); // se encarga de borrar los tableros. Útil para el cambio de jugador

    return 0;
    
}

