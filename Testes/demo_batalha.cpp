#include "batalha.h"
#include "Tipagem.cpp"
#include "pokedex.h"
#include "moves.h"
#include <iostream>
#include <memory>
#include <vector>

void mostrarPokemon(const std::shared_ptr<Pokemon>& pokemon) {
    std::cout << "Nome: " << pokemon->getNome() << "\n";
    std::cout << "Nível: " << pokemon->getLvl() << "\n";
    std::cout << "Tipos: ";
    for (size_t i = 0; i < pokemon->getTipos().size(); ++i) {
        std::cout << pokemon->getTipos()[i];
        if (i < pokemon->getTipos().size() - 1) std::cout << " / ";
    }
    std::cout << "\n";
    std::cout << "HP: " << pokemon->getHp() << "\n";
    std::cout << "Ataque: " << pokemon->getAtaque() << "\n";
    std::cout << "Defesa: " << pokemon->getDefesa() << "\n";
    std::cout << "Ataque Especial: " << pokemon->getEspecialataq() << "\n";
    std::cout << "Defesa Especial: " << pokemon->getEspecialdefesa() << "\n";
    std::cout << "Velocidade: " << pokemon->getSpeed() << "\n";
    std::cout << "------------------------\n";
}

int main() {
    std::cout << "=== DEMONSTRAÇÃO DO SISTEMA DE BATALHA POKÉMON ===\n\n";
    
    // Cria uma instância da tabela de tipos
    Typeadv tipos;
    
    // Demonstra o sistema de tipos
    std::cout << "=== TESTE DO SISTEMA DE TIPOS ===\n";
    std::vector<std::string> tiposTeste = {"Fire", "Water"};
    std::cout << "Ataque Fire vs Pokémon Water: " << tipos.calculodano("Fire", tiposTeste) << "\n";
    std::cout << "Multiplicador: " << tipos.getMultiplicador("Fire", tiposTeste) << "x\n\n";
    
    // Cria parties de exemplo
    std::vector<std::shared_ptr<Pokemon>> partyJogador;
    std::vector<std::shared_ptr<Pokemon>> partyOponente;
    
    // Adiciona Pokémon à party do jogador
    partyJogador.push_back(std::make_shared<Pokemon>(Pokedex[0])); // Bulbasaur
    partyJogador.push_back(std::make_shared<Pokemon>(Pokedex[3])); // Charmander
    partyJogador.push_back(std::make_shared<Pokemon>(Pokedex[6])); // Squirtle
    
    // Adiciona Pokémon à party do oponente
    partyOponente.push_back(std::make_shared<Pokemon>(Pokedex[9])); // Pikachu
    partyOponente.push_back(std::make_shared<Pokemon>(Pokedex[11])); // Arcanine
    partyOponente.push_back(std::make_shared<Pokemon>(Pokedex[14])); // Gengar
    
    // Mostra informações dos Pokémon antes da batalha
    std::cout << "=== POKÉMON DO JOGADOR ===\n";
    for (size_t i = 0; i < partyJogador.size(); ++i) {
        std::cout << "Pokémon " << (i + 1) << ":\n";
        mostrarPokemon(partyJogador[i]);
    }
    
    std::cout << "=== POKÉMON DO OPONENTE ===\n";
    for (size_t i = 0; i < partyOponente.size(); ++i) {
        std::cout << "Pokémon " << (i + 1) << ":\n";
        mostrarPokemon(partyOponente[i]);
    }
    
    // Cria uma instância da batalha
    Batalha batalha(tipos);
    
    // Configura as parties na batalha
    batalha.configurarPartyJogador(partyJogador);
    batalha.configurarPartyOponente(partyOponente);
    
    std::cout << "=== INICIANDO BATALHA ===\n";
    std::cout << "Pressione Enter para começar...";
    std::cin.get();
    
    // Inicia a batalha
    batalha.iniciar();
    
    std::cout << "\n=== BATALHA FINALIZADA ===\n";
    std::cout << "Obrigado por testar o sistema de batalha!\n";
    
    return 0;
}
