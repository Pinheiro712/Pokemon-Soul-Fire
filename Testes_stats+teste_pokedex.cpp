#include "Pokemon.H"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct PokemonBase {
    string nome;
    int hp, atk, def, espa, espd, spd;
};

// Pokedex com alguns exemplos
vector<PokemonBase> pokedex = {
    {"Bulbasaur", 45, 49, 49, 65, 65, 45},
    {"Charmander", 39, 52, 43, 60, 50, 65},
    {"Squirtle", 44, 48, 65, 50, 64, 43},
    {"Pikachu", 35, 55, 40, 50, 50, 90},
    {"Gengar", 60, 65, 60, 130, 75, 110},
    {"Lucario", 70, 110, 70, 115, 70, 90}
};

int main() {
    while (true) {
        cout << "Escolha um Pokemon pelo número (ou -1 para sair):" << endl;
        for (int i = 0; i < pokedex.size(); i++) {
            cout << i << ": " << pokedex[i].nome << endl;
        }

        int escolha;
        cin >> escolha;

        if (escolha == -1) break;
        if (escolha < 0 || escolha >= pokedex.size()) {
            cout << "Escolha inválida." << endl;
            continue;
        }

        int nivel;
        cout << "Digite o nível do Pokemon (1 a 100): ";
        cin >> nivel;

        if (nivel < 1 || nivel > 100) {
            cout << "Nível inválido." << endl;
            continue;
        }

        PokemonBase base = pokedex[escolha];
        Pokemon p(base.nome, nivel, base.hp, base.atk, base.def, base.espa, base.espd, base.spd);

        p.calculostats();
        p.mostrar();

        cout << endl;
    }

    return 0;
}
