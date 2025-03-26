#include <iostream>
#include <vector>
#include <string>
#include "Juego.h"
using namespace std;

int main() {
    int numJugadores;

    do {
        cout << "Ingrese el número de jugadores (entre 2 y 4): ";
        cin >> numJugadores;
    } while(numJugadores < 2 || numJugadores > 4);

    vector<string> nombres;
    for (int i = 1; i <= numJugadores; i++) {
        nombres.push_back("Jugador " + to_string(i));
    }

    Juego juego(nombres);
    juego.jugar();

    return 0;
}
