#include "Pokemon.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Pokemon::Pokemon(string n, int level, int hp, int atk, int def, int espa, int espd, int spd, vector<string> t) {
    nome = n; 
    lvl = level;
    stats.hp = hp;
    stats.ataque = atk;
    stats.defesa = def;
    stats.especialataq = espa;
    stats.especialdefesa = espd;
    stats.speed = spd;
    tipos = t;
}

void Pokemon::mostrar() {
    cout << "Pokemon: " << nome << endl;

    cout << "Tipos: ";
    for (size_t i = 0; i < tipos.size(); ++i) {
        cout << tipos[i];
        if (i < tipos.size() - 1) cout << " / ";
    }
    cout << endl;

    cout << "HP: " << stats.hp << endl;
    cout << "Ataque: " << stats.ataque << endl;
    cout << "Defesa: " << stats.defesa << endl;
    cout << "Ataque Especial: " << stats.especialataq << endl;
    cout << "Defesa Especial: " << stats.especialdefesa << endl;
    cout << "Velocidade: " << stats.speed << endl;
    
    // Mostra os ataques disponíveis
    if (!ataques.empty()) {
        cout << "Ataques: ";
        for (size_t i = 0; i < ataques.size(); ++i) {
            cout << ataques[i].getNome();
            if (i < ataques.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}

void Pokemon::calculostats() {
    //desconsiderando IVs, EVs, Naturezas e Habilidades (talvez implemente depois)
    stats.hp = (2 * stats.hp * lvl) / 100 + lvl + 10;
    stats.ataque = (2 * stats.ataque * lvl) / 100 + 5;
    stats.defesa = (2 * stats.defesa * lvl) / 100 + 5;
    stats.especialataq = (2 * stats.especialataq * lvl) / 100 + 5;
    stats.especialdefesa = (2 * stats.especialdefesa * lvl) / 100 + 5;
    stats.speed = (2 * stats.speed * lvl) / 100 + 5;
}

// Métodos de gerenciamento de ataques
void Pokemon::adicionarAtaque(const Move& ataque) {
    // Verifica se o Pokémon já tem esse ataque
    if (!temAtaque(ataque.getNome())) {
        ataques.push_back(ataque);
    }
}

void Pokemon::removerAtaque(int index) {
    if (index >= 0 && index < static_cast<int>(ataques.size())) {
        ataques.erase(ataques.begin() + index);
    }
}

const vector<Move>& Pokemon::getAtaques() const {
    return ataques;
}

bool Pokemon::temAtaque(const string& nomeAtaque) const {
    for (const auto& ataque : ataques) {
        if (ataque.getNome() == nomeAtaque) {
            return true;
        }
    }
    return false;
}


