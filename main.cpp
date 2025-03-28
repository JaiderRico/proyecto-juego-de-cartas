#include <iostream>
#include <vector>
#include <string>
#include "Juego.h"
using namespace std;

int main() {

    vector<string> nombres;
    for (int i = 1; i <= 2; i++) {
        nombres.push_back("Jugador " + to_string(i));
    }

    Juego juego(nombres);
    juego.jugar();

    return 0;
}
