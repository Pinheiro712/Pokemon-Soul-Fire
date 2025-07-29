#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

struct stats{
    int hp;
    int defesa;
    int ataque;
    int especialataq;
    int especialdefesa; 
    int speed;

};

class Pokemon{
    private:
        string nome;
        stats stats;
    public:
        Pokemon(string n, int hp, int atk, int def, int espa, int espd, int spd);
        void mostrar();
        void Dano(int dano);

};

#endif