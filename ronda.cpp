#include "Ronda.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Ronda::Ronda(vector<Jugador*>& jugadores, Carta cartaInicial)
    : jugadores(jugadores), cartaInicial(cartaInicial), ganador(nullptr) {}

void Ronda::jugarTurno() {
    vector<Carta> cartasJugadas;
    vector<Jugador*> jugadoresValidos;

    cartasJugadas.push_back(cartaInicial);
    jugadoresValidos.push_back(jugadores[0]);

    for (size_t i = 1; i < jugadores.size(); i++) {
        Jugador* jugador = jugadores[i];
        if (jugador->mano.empty()) {
            cout << jugador->nombre << " no tiene cartas y queda fuera de la ronda." << endl;
            continue;
        }

        cout << "\n" << jugador->nombre << ", tu mano:" << endl;
        for (size_t j = 0; j < jugador->mano.size(); j++) {
            cout << j << ": " << jugador->mano[j].numero 
                 << " " << jugador->mano[j].color << endl;
        }
        int id;
        cout << "Elige el índice de la carta a jugar: ";
        cin >> id;
        while(id < 0 || id >= (int)jugador->mano.size()) {
            cout << "Índice inválido. Intenta de nuevo: ";
            cin >> id;
        }
        Carta cartaJug = jugador->jugarCarta(id);
        cout << jugador->nombre << " juega: " 
             << cartaJug.numero << " " << cartaJug.color << endl;
        cartasJugadas.push_back(cartaJug);
        jugadoresValidos.push_back(jugador);
    }

    if (!cartasJugadas.empty()) {
        auto maxIt = max_element(cartasJugadas.begin(), cartasJugadas.end(),
            [](Carta a, Carta b) { return a.numero < b.numero; });
        int index = distance(cartasJugadas.begin(), maxIt);
        ganador = jugadoresValidos[index];

        ganador->acumulador += jugadores.size(); 
        cout << "\nGanador de la ronda: " << ganador->nombre << "\n" << endl;
    }
}
