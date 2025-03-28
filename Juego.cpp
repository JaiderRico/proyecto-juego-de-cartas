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
    for(int i = 0; i < 9; i++ ){
       for(int j = 0; j < 4; j++){
        mazo.push_back(Carta(i,colores[j]));
        } 
    }
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
    int turno = 0; 

    while (!jugadores[0].mano.empty() && !jugadores[1].mano.empty()) {
        cout << "===== Nueva Ronda =====" << endl;

        Jugador* jugadorActual = &jugadores[turno]; 
        Jugador* segundoJugador = &jugadores[1 - turno]; 

        cout << "\n" << jugadorActual->nombre << ", es tu turno." << endl;
        cout << "Tu mano:" << endl;
        for (size_t j = 0; j < jugadorActual->mano.size(); j++) {
            cout << j << ": " << jugadorActual->mano[j].numero << " " 
                 << jugadorActual->mano[j].color << endl;
        }

        int id;
        cout << "Elige el índice de la carta a jugar: ";
        cin >> id;
        while (id < 0 || id >= (int)jugadorActual->mano.size()) {
            cout << "Índice inválido. Intenta de nuevo: ";
            cin >> id;
        }

        Carta cartaInicial = jugadorActual->jugarCarta(id);

        cout << "\n" << segundoJugador->nombre << ", es tu turno." << endl;
        cout << "Tu mano:" << endl;
        for (size_t j = 0; j < segundoJugador->mano.size(); j++) {
            cout << j << ": " << segundoJugador->mano[j].numero << " " 
                 << segundoJugador->mano[j].color << endl;
        }

        cout << "Elige el índice de la carta a jugar: ";
        cin >> id;
        while (id < 0 || id >= (int)segundoJugador->mano.size()) {
            cout << "Índice inválido. Intenta de nuevo: ";
            cin >> id;
        }

        Carta cartaSegunda = segundoJugador->jugarCarta(id);

        if (cartaInicial.color != cartaSegunda.color) {
            jugadorActual->acumulador += 2;
        } else { 
            if (cartaInicial.numero > cartaSegunda.numero) {
                jugadorActual->acumulador += 2;
            } else {
                segundoJugador->acumulador += 2;
            }
        }

        turno = 1 - turno;
    }

    determinarGanador();
}

void Juego::determinarGanador() {
    Jugador* ganador = &jugadores[0];
    
    for (size_t i = 1; i < jugadores.size(); i++) {
        if (jugadores[i].acumulador > ganador->acumulador) {
            ganador = &jugadores[i];
        }
    }

    cout << "===== Ganador final: " << ganador->nombre << " con " 
         << ganador->acumulador << " puntos! =====" << endl;
}

