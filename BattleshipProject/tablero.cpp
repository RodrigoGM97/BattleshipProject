#include <iostream>
#include <string>
#include <cdtlib>
#include <list>
#include <ctime>
#include "coordenadas.h"
#include "tablero.h"
#include "BarcosTipos.h"

using namespace std;

string const casillaBarc = "      Casilla para Barco    ";
string const CasillaAtaque = "    Casilla de Ataque     ";
string const SuperiorTab = " |A|B|C|D|E|F|G|H|I|J| ";
string const filas[tablero::tableroSize] = {
    " 1|",
    " 2|",
    " 3|",
    " 4|",
    " 5|",
    " 6|",
    " 7|",
    " 8|",
    " 9|",
    "10|"
};

string const BarcoNoTocado = "0";
string const BarcoTocado = "@";
string const TableroNoTocado = "";
string const TableroTocado = "X";

string const indicador = "--indicador-- \n0 Ningún barco tocado    \n@ Barco Tocado   \nX ataque fallido";


const int
