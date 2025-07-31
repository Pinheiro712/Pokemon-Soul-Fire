#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

struct stats{
    int lvl;
    int hp;
    int defesa;
    int ataque;
    int especialataq;
    int especialdefesa; 
    int speed;
    string moves; 
};

class Pokemon{
    private:
        string nome;
        stats stats;
        int lvl;
        int status;
    public:
        Pokemon(string n, int lvl,  int hp, int atk, int def, int espa, int espd, int spd);
        void mostrar();
        void Dano(int dano);
        void calculostats();
        void defstatus();

};

#endif