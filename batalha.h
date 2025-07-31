#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <sstream>
using namespace std;


class Batalha{

    #pragma once
    #include "Poke-clase.cpp"
    #include "Moves.cpp"
    #include "Tipagem.cpp"
    private:
        Pokemon* p1;
        Pokemon* p2;
        int turno_;
    public:
        Batalha(Pokemon* jogador1, Pokemon* jogador2);
        void iniciar();
        void turno(int moveP1);
        void terminou();
        void status();
        Pokemon* getVencedor();

};