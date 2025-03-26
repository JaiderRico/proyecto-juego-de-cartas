#ifndef RONDA_H
#define RONDA_H

#include <vector>
#include "Jugador.h"
#include "Carta.h"
using namespace std;

class Ronda {
public:
    vector<Jugador*> jugadores;
    Carta cartaInicial;
    Jugador* ganador;

    Ronda(vector<Jugador*>& jugadores, Carta cartaInicial);
    void jugarTurno();
};

#endif
