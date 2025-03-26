#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "Carta.h"
using namespace std;

class Jugador {
public:
    string nombre;
    vector<Carta> mano;
    int acumulador = 0;


    Jugador(string nom);

    void agregarCarta(Carta carta);
    Carta jugarCarta(int indice);
};

#endif
