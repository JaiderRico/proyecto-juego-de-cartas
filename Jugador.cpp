#include "Jugador.h"

Jugador::Jugador(string nom) : nombre(nom) {}

Carta Jugador::jugarCarta(int indice) {
    Carta carta = mano[indice];
    mano.erase(mano.begin() + indice);
    return carta;
}
void Jugador::agregarCarta(Carta carta) {
    mano.push_back(carta);
}