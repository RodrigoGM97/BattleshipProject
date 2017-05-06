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
void check_end(Jugador &J, Jugador &J1);

Barco bar;
string ori;
string Coords= "ABCDEFGHIJ";
int coordColumn=0, coordReng=0;
char col;
int AirRestJ=1, AirRestJ2=1;
int MultrestJ=1, MultrestJ2=1;
bool turno= true;
bool end_game =false;
Jugador J;
Jugador J2;
void debugSetup() {
    Barco b1(5,"vertical");
    Barco b2(4,"vertical");
    Barco b3(3,"vertical");
    Barco b4(3,"vertical");
    Barco b5(2,"vertical");
    
    b1.setVertical(1,1);
    b2.setVertical(2,1);
    b2.setVertical(3,1);
    b3.setVertical(4,1);
    b4.setVertical(5,1);
    J.AddBarco(b1);
    J.AddBarco(b2);
    J.AddBarco(b3);
    J.AddBarco(b4);
    J.AddBarco(b5);
    b1.resetPos();
    b2.resetPos();
    b3.resetPos();
    b4.resetPos();
    b5.resetPos();
    b1.setVertical(3,1);
    b2.setVertical(4,1);
    b2.setVertical(8,1);
    b3.setVertical(7,1);
    b4.setVertical(6,1);
    J2.AddBarco(b1);
    J2.AddBarco(b2);
    J2.AddBarco(b3);
    J2.AddBarco(b4);
    J2.AddBarco(b5);
     J.setTableroEnemigo(J2);
        J2.setTableroEnemigo(J);
}

int main()
{
    //pedir Nombres
    SetupUniversal(J, J2);
    //debugSetup();
    AirStrike airstrike;
    Ataque B;
    Ataque *A;
    char tipoAtaque;
    /*B.setCoords(5,6);
    A=&B;
    A-> AttackPosition(4,5, J);
    A=&airstrike;
    A->AttackPosition(3,4,J);
    airstrike.AttackPosition(4,5,J);*/
    while(end_game==false)
    {
        coordColumn=0;
        //Turnos(turno, J, J2);
        if(turno==true)
        {
            cout<<J.getNombre()<<" está atacando..."<<endl;
            cout<<"Ingresa tipo de ataque. Tienes: "<<endl<<"B) Ataque básico"<<endl<<"A) Airstrike (" << AirRestJ <<  " restantes)"<<endl<<"M) MultiStrike ("<<MultrestJ<<" restantes)"<<endl;
            cin>>tipoAtaque;
            cout<<"Ingresa las coordenadas para atacar: ";
            cin>>col;
            cin>>coordReng;
            for(coordColumn; Coords[coordColumn]!=col;coordColumn++);
            coordColumn++;
            switch(tipoAtaque)
            {
                case 'B':
                J.AtaqueBasico(coordColumn, coordReng, J2);
                break;
                case 'A':
                if(AirRestJ>0)
                {
                    J.AirStrike(coordColumn, J2);
                    AirRestJ--;
                }
                else
                {
                    cout<<"No te quedan Air Strikes. Realizando ataque básico..."<<endl;
                    J.AtaqueBasico(coordColumn, coordReng, J2);                    
                }
                break;
                case 'M':
                if(MultrestJ>0)
                {
                    J.MultiStrike(coordColumn, coordReng, J2);
                    MultrestJ--;
                }
                else
                {
                    cout<<"No te quedan MultiStrikes. Realizando ataque básico..."<<endl;
                    J.AtaqueBasico(coordColumn, coordReng, J2);
                }
                break;
                
            }
            
            //J2.getPropio().printTab();
            
            //J.Attack=&airstrike;
            //J.Attack->AttackPosition(coordColumn, coordReng, J, J2);
            
            //J.setAttack(airstrike);
            //J.getAttack().AttackPosition(J);
           
           // J.Attack = &airstrike;
            //J.Attack->setCoords(coordColumn, coordReng);
            //J.getAttack()->AttackPosition(J.getAttack->getX_Ataque(), J.getAttack->getY_Ataque(),J);
            cout<<"Guía de ataques: "<<endl;
            J.getGuia().printTab();
            cout<<"---------------------------------------------------------------"<<endl;
            cout<<"Tu tablero: "<<endl;
            J.getPropio().printTab();
            cout<<endl<<"Presiona una tecla y enter para terminar tu turno"<<endl;
            cin>>col;
            cout << "-------------------------------------------------------------"<< endl;
            
            system("clear");
            turno= false;
            // J2.getPropio().printTab();
            end_game=J2.check_end();
        }
        else
        {
            cout<<J2.getNombre()<<" está atacando..."<<endl;
            cout<<"Ingresa tipo de ataque. Tienes: "<<endl<<"B) Ataque básico"<<endl<<"A) Airstrike (" << AirRestJ2 <<  " restantes)"<<endl<<"M) MultiStrike ("<<MultrestJ<<" restantes)"<<endl;
            cin>>tipoAtaque;
            cout<<"Ingresa las coordenadas para atacar: ";
            cin>>col;
            cin>>coordReng;
            for(coordColumn; Coords[coordColumn]!=col;coordColumn++);
            coordColumn++;
            switch(tipoAtaque)
            {
                case 'B':
                J2.AtaqueBasico(coordColumn, coordReng, J);
                break;
                case 'A':
                if(AirRestJ2>0)
                {
                    J2.AirStrike(coordColumn, J);
                    AirRestJ2--;
                }
                else
                {
                    cout<<"No te quedan Air Strikes. Realizando ataque básico..."<<endl;
                    J2.AtaqueBasico(coordColumn, coordReng, J);                    
                }
                break;
                case 'M':
                if(MultrestJ2>0)
                {
                    J2.MultiStrike(coordColumn, coordReng, J);
                    MultrestJ2--;
                }
                else
                {
                    cout<<"No te quedan MultiStrikes. Realizando ataque básico..."<<endl;
                    J2.AtaqueBasico(coordColumn, coordReng, J);
                }
                break;
                
            }
            
            //J2.getPropio().printTab();
            cout<<"Guía de ataques: "<<endl;
            J2.getGuia().printTab();
            cout<<"---------------------------------------------------------------"<<endl;
            cout<<"Tu tablero: "<<endl;
            J2.getPropio().printTab();
            cout<<endl<<"Presiona una tecla y enter para terminar tu turno"<<endl;
            cin>>col;
            cout << "-------------------------------------------------------------"<< endl;
            
            system("clear");
            turno=true;
            // J2.getPropio().printTab();
            end_game=J.check_end();
        }
    }

    return 0;
    
}

void SetupUniversal(Jugador &J, Jugador &J2)
{
    string nom;
    string inicia_turno;
    
    cout << "Jugador 1: "<< endl << "Ingrese su apodo: ";
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
    if (inicia_turno!="")
    {
        SetupBarcos(J);
        cout << endl<< J.getNombre() << " Ingresa cualquier tecla y Enter terminar tu turno" << endl;
        cin>>inicia_turno;
        
        system("clear");
        cout <<endl<< J2.getNombre() << " presiona Y para comenzar tu turno" << endl;
        cin>>inicia_turno;
        
        SetupBarcos(J2);
        
        cout << endl<< J2.getNombre() << " Ingresa cualquier tecla y Enter terminar tu turno" << endl;
        cin>>inicia_turno;
        J.setTableroEnemigo(J2);
        J2.setTableroEnemigo(J);
    }
}
void SetupBarcos(Jugador & J)
{
    cout << J.getNombre()<< " está colocando sus barcos: "  << endl;
    //Barco 1(5 casillas)
    J.getPropio().printTab();
    int conta=5;
    while(conta>0)
    {
        coordColumn= 0;
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
        else if (ori==  "vertical")
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

