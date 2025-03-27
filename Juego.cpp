#include "Juego.h"
#include "Ronda.h"
#include "Carta.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

Juego::Juego(vector<string> nombres) {
    for (size_t i = 0; i < nombres.size(); i++) {
        jugadores.push_back(nombres[i]);
    }
    generarMazo();
    repartirCartas();
}

void Juego::generarMazo() {
    vector<string> colores = {"Rojo", "Azul", "Verde", "Amarillo"};
    srand(time(0));
    for(int i = 0; i < 8; i++ ){
       for(int j = 0; j < 4; j++){
        mazo.push_back(Carta(i,colores[j]));
        }; 
    };
    random_shuffle(mazo.begin(), mazo.end());
}

void Juego::repartirCartas() {
    int numJugadores = jugadores.size();
    int cartasPorJugador = mazo.size() / numJugadores;
    for (int i = 0; i < cartasPorJugador * numJugadores; i++) {
        jugadores[i % numJugadores].agregarCarta(mazo[i]);
    }
}

void Juego::jugar() {

    int rondas = mazo.size() / jugadores.size();
    for (int i = 0; i < rondas; i++) {
        cout << "===== Ronda " << i + 1 << " =====" << endl;
        Jugador* jugadorInicio = &jugadores[i % jugadores.size()];
        Carta cartaInicial;
        if (!jugadorInicio->mano.empty()) {
            cout << "\n" << jugadorInicio->nombre << ", es tu turno para iniciar la ronda." << endl;
            cout << "Tu mano:" << endl;
            for (int j = 0; j < jugadorInicio->mano.size(); j++) {
                cout << j << ": " << jugadorInicio->mano[j].numero << " " 
                     << jugadorInicio->mano[j].color << endl;
            }
            int id;
            cout << "Elige el índice de la carta a jugar como carta inicial: ";
            cin >> id;
            while(id < 0 || id >= (int)jugadorInicio->mano.size()) { // esto "||" funciona como un operador logico or 
                cout << "Índice inválido. Intenta de nuevo: ";
                cin >> id;
            }
            cartaInicial = jugadorInicio->jugarCarta(id);
        }
        vector<Jugador*> jugadoresPtr;
        int total = jugadores.size();
        for (int j = 0; j < total; j++) {
            jugadoresPtr.push_back(&jugadores[j]);
        }

        Ronda ronda(jugadoresPtr, cartaInicial);
        ronda.jugarTurno();
    }
    determinarGanador();
}

void Juego::determinarGanador() {
    auto it = max_element(jugadores.begin(), jugadores.end(),
        [](Jugador a, Jugador b) { return a.acumulador < b.acumulador; });
    cout << "===== Ganador final: " << it->nombre << " con " 
         << it->acumulador << " cartas acumuladas! =====" << endl;
}
