#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vetor>
#include <queue>
#include <string>
#include "TipoTablero.h"
#include "barcos.h"
#include "ImprimirConsola.h"

class Tablero {
  public:
    static int const tamañoTablero = 10;

    const std::vector<Barco::InfoBarco> BarcosTipos = {{"Portaaviones", 5},
      {"Barco de batalla", 4},
      {"Destructor", 3},
      {"Submarino", 3},
      {"Barco patrulla", 2}
    };

    typedef enum {PORTAVIONES, BARCO, DESTRUCTOR, SUB, PATRULLA} barco_t;
}
