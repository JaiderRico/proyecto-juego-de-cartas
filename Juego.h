#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <string>
#include "Jugador.h"
#include "Carta.h"
using namespace std;

class Juego {
public:
    vector<Jugador> jugadores; 
    vector<Carta> mazo;

    Juego(vector<string> nombres);

    void generarMazo();
    void repartirCartas();
    void jugar();
    void determinarGanador();
};

#endif
