#include "batalha.h"
#include "Tipagem.cpp"
#include "pokedex.h"
#include "moves.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
    // Cria uma instância da tabela de tipos
    Typeadv tipos;
    
    // Cria uma instância da batalha
    Batalha batalha(tipos);
    
    // Cria parties de exemplo
    std::vector<std::shared_ptr<Pokemon>> partyJogador;
    std::vector<std::shared_ptr<Pokemon>> partyOponente;
    
    // Adiciona Pokémon à party do jogador (máximo 6)
    partyJogador.push_back(std::make_shared<Pokemon>(Pokedex[0])); // Bulbasaur
    partyJogador.push_back(std::make_shared<Pokemon>(Pokedex[3])); // Charmander
    partyJogador.push_back(std::make_shared<Pokemon>(Pokedex[6])); // Squirtle
    partyJogador.push_back(std::make_shared<Pokemon>(Pokedex[9])); // Pikachu
    
    // Adiciona Pokémon à party do oponente (máximo 6)
    partyOponente.push_back(std::make_shared<Pokemon>(Pokedex[11])); // Arcanine
    partyOponente.push_back(std::make_shared<Pokemon>(Pokedex[14])); // Gengar
    partyOponente.push_back(std::make_shared<Pokemon>(Pokedex[15])); // Articuno
    partyOponente.push_back(std::make_shared<Pokemon>(Pokedex[16])); // Zapdos
    partyOponente.push_back(std::make_shared<Pokemon>(Pokedex[17])); // Moltres
    
    // Configura as parties na batalha
    batalha.configurarPartyJogador(partyJogador);
    batalha.configurarPartyOponente(partyOponente);
    
    std::cout << "=== SIMULADOR DE BATALHA POKÉMON ===\n";
    std::cout << "Este é um exemplo de como usar o sistema de batalha.\n\n";
    
    // Inicia a batalha
    batalha.iniciar();
    
    return 0;
}
