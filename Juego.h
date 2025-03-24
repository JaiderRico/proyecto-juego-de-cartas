#include <vector>
#include "carta.h"
#include "jugador.h"

class Juego{
    public:
        vector<Jugador> Jugadores;
        vector<Carta> mazo;
    
        Juego(vector<string> nombres);

        void generarmazo();
        void repartir();
        void genganador();
}