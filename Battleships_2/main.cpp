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
int main()
{
    string nom;
    //pedir barcos. Los tamaños son 5, 4, 3, 3, 2
    cout<<"Jugador 1: "<<endl<< "Ingrese su apodo: ";
    cin>>nom;
    J1.setNombre(nom);
    system("clear");
    cout<<"Jugador 2: "<<endl<< "Ingrese su apodo: ";
    cin>>nom;
    J2.setNombre(nom);
    cout << endl;
    system("clear");
    

    cout<<"J1: "<< J1.getNombre()<<endl<<"J2: "<<J2.getNombre()<< endl;


    
    
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
    J1.getPropio().printTab();   */
    
    //system("clear"); // se encarga de borrar los tableros. Útil para el cambio de jugador

    return 0;
    
}

