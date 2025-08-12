#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "moves.h"
using namespace std;

//al mio comando tutto qui sta
//joguei os stats num struct pra organizar bonitinho
struct Stats {
    int lvl;
    int hp;
    int ataque;
    int defesa;
    int especialataq;
    int especialdefesa;
    int speed;
};

// Classe Pokémon em sí
class Pokemon {
private:
    string nome;
    int lvl;
    Stats stats;
    vector<string> tipos;
    vector<Move> ataques; // Lista de ataques do Pokémon

public:
    // Construtor com tipos
    Pokemon(string n, int level, int hp, int atk, int def, int espa, int espd, int spd, vector<string> t);

    // Mostra os stats calculados
    void mostrar();

    // Calcula os stats com base no nível (sem IV/EV)
    void calculostats();

    // Gerenciamento de ataques
    void adicionarAtaque(const Move& ataque);
    void removerAtaque(int index);
    const vector<Move>& getAtaques() const;
    bool temAtaque(const string& nomeAtaque) const;

    // Getters
    string getNome() const { return nome; }
    int getLvl() const { return lvl; }
    vector<string> getTipos() const { return tipos; }
    
    // Getters para stats individuais
    int getHp() const { return stats.hp; }
    int getHpMax() const { return stats.hp; } // HP máximo é o mesmo que HP atual (sem sistema de HP base)
    int getAtaque() const { return stats.ataque; }
    int getDefesa() const { return stats.defesa; }
    int getEspecialataq() const { return stats.especialataq; }
    int getEspecialdefesa() const { return stats.especialdefesa; }  
    int getSpeed() const { return stats.speed; }

    // Setters
    void setLvl(int l) { lvl = l; }
    void setHp(int hp) { stats.hp = hp; }
};

#endif
