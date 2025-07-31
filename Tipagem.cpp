#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <sstream>
using namespace std;

class Typeadv {
private:
    vector<string> tipos;
    vector<vector<double>> matriz;
    unordered_map<string, int> indice;

public:
    Typeadv() {
        tipos = {"Normal", "Fire", "Water", "Electric", "Grass", "Ice", "Fight", "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost", "Dragon"};

        matriz = {
            {1,1,1,1,1,1,1,1,1,1,1,1,0.5,0,1},  // Normal - corrigido: Ghost=0, Dragon=1
            {1, 0.5, 0.5, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5}, // Fire
            {1,2,0.5,1,0.5,1,1,1,2,1,1,1,2,1,0.5}, // Water
            {1,1,2,0.5,0.5,1,1,1,0,2,1,1,1,1,0.5}, // Electric
            {1,0.5,2,1,0.5,1,1,0.5,2,0.5,1,0.5,2,1,0.5}, // Grass
            {1,0.5,0.5,1,2,0.5,1,1,2,2,1,1,1,1,2}, // Ice
            {2,1,1,1,1,2,1,0.5,1,0.5,0.5,0.5,2,0,1}, // Fight - corrigido: Ghost=0
            {1,1,1,1,2,1,1,0.5,0.5,1,1,1,0.5,0.5,1}, // Poison
            {1,2,1,2,0.5,1,1,2,1,0,1,0.5,2,1,1}, // Ground
            {1,1,1,0.5,2,1,2,1,1,1,1,2,0.5,1,1}, // Flying
            {1,1,1,1,1,1,2,2,1,1,0.5,1,1,1,1}, // Psychic
            {1,0.5,1,1,2,1,0.5,0.5,1,0.5,2,1,1,0.5,1}, // Bug
            {1,2,1,1,1,2,0.5,1,0.5,2,1,2,1,1,1}, // Rock
            {0,1,1,1,1,1,1,1,1,1,2,1,1,2,1}, // Ghost
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}  // Dragon
        };

        for (int i = 0; i < tipos.size(); i++) {
            indice[tipos[i]] = i;
        }
    }

    string calculodano(string atacante, vector<string> atingido) {
    // Verifica se o tipo atacante existe
    if (indice.find(atacante) == indice.end()) {
        return "Tipo atacante invalido!";
    }
    int i = indice[atacante];
    
    double efeito_total = 1.0;
    
    // Verifica cada tipo do pokemon atingido
    for (string tipo : atingido) {
        // Verifica se o tipo atingido existe
        if (indice.find(tipo) == indice.end()) {
            return "Tipo atingido invalido!";
        }
        int j = indice[tipo];
        efeito_total *= matriz[i][j];
    }

    // Determina a mensagem com base no efeito total
    if (efeito_total == 0.0) {
        return "O ataque nao afeta o pokemon atingido...";
    }
    else if (efeito_total < 1.0) {
        return "Nao foi muito efetivo...";
    }
    else if (efeito_total > 1.0) {
        return "Super efetivo !";
    }       
    }
};
