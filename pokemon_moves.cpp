#include "pokemon.h"
#include "moves.h"
#include <iostream>

// Função para configurar ataques específicos para cada Pokémon
//os mais populares tem ataques mais padrão 
void configurarAtaquesPokemon(Pokemon& pokemon) {
    std::string nome = pokemon.getNome();
    
    // Configura ataques baseados no nome do Pokémon
    if (nome == "Pikachu") {
        pokemon.adicionarAtaque(moveList[18]); // Thunder Shock
        pokemon.adicionarAtaque(moveList[19]); // Thunderbolt
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[2]);  // Quick Attack
    }
    else if (nome == "Charmander") {
        pokemon.adicionarAtaque(moveList[6]);  // Ember
        pokemon.adicionarAtaque(moveList[7]);  // Flamethrower
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[1]);  // Scratch
    }
    else if (nome == "Bulbasaur") {
        pokemon.adicionarAtaque(moveList[23]); // Vine Whip
        pokemon.adicionarAtaque(moveList[24]); // Razor Leaf
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[30]); // Sleep Powder
    }
    else if (nome == "Squirtle") {
        pokemon.adicionarAtaque(moveList[12]); // Water Gun
        pokemon.adicionarAtaque(moveList[13]); // Bubble Beam
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[1]);  // Scratch
    }
    else if (nome == "machop") {
        pokemon.adicionarAtaque(moveList[45]); // Karate Chop
        pokemon.adicionarAtaque(moveList[44]); // Double Kick
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[1]);  // Scratch
    }
    else if (nome == "Gengar") {
        pokemon.adicionarAtaque(moveList[35]); // Lick
        pokemon.adicionarAtaque(moveList[36]); // Shadow Ball
        pokemon.adicionarAtaque(moveList[37]); // Shadow Claw
        pokemon.adicionarAtaque(moveList[38]); // Night Shade
    }
    else if (nome == "Arcanine") {
        pokemon.adicionarAtaque(moveList[6]);  // Ember
        pokemon.adicionarAtaque(moveList[7]);  // Flamethrower
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[2]);  // Quick Attack
    }
    else if (nome == "Articuno") {
        pokemon.adicionarAtaque(moveList[42]); // Ice Beam
        pokemon.adicionarAtaque(moveList[43]); // Blizzard
        pokemon.adicionarAtaque(moveList[47]); // Peck
        pokemon.adicionarAtaque(moveList[48]); // Wing Attack
    }
    else if (nome == "Zapdos") {
        pokemon.adicionarAtaque(moveList[18]); // Thunder Shock
        pokemon.adicionarAtaque(moveList[19]); // Thunderbolt
        pokemon.adicionarAtaque(moveList[47]); // Peck
        pokemon.adicionarAtaque(moveList[48]); // Wing Attack
    }
    else if (nome == "Moltres") {
        pokemon.adicionarAtaque(moveList[6]);  // Ember
        pokemon.adicionarAtaque(moveList[7]);  // Flamethrower
        pokemon.adicionarAtaque(moveList[47]); // Peck
        pokemon.adicionarAtaque(moveList[48]); // Wing Attack
    }
    else if (nome == "Raichu") {
        pokemon.adicionarAtaque(moveList[18]); // Thunder Shock
        pokemon.adicionarAtaque(moveList[19]); // Thunderbolt
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[2]);  // Quick Attack
    }
    else if (nome == "Ivysaur") {
        pokemon.adicionarAtaque(moveList[23]); // Vine Whip
        pokemon.adicionarAtaque(moveList[24]); // Razor Leaf
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[30]); // Sleep Powder
    }
    else if (nome == "Wartortle") {
        pokemon.adicionarAtaque(moveList[12]); // Water Gun
        pokemon.adicionarAtaque(moveList[13]); // Bubble Beam
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
        pokemon.adicionarAtaque(moveList[1]);  // Scratch
    }
    else if (nome == "Blastoise") {
        pokemon.adicionarAtaque(moveList[12]); // Water Gun
        pokemon.adicionarAtaque(moveList[13]); // Bubble Beam
        pokemon.adicionarAtaque(moveList[14]); // Surf
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
    }
    else if (nome == "Machoke") {
        pokemon.adicionarAtaque(moveList[45]); // Karate Chop
        pokemon.adicionarAtaque(moveList[44]); // Double Kick
        pokemon.adicionarAtaque(moveList[47]); // Brick Break
        pokemon.adicionarAtaque(moveList[0]);  // Tackle
    }
    else if (nome == "Machamp") {
        pokemon.adicionarAtaque(moveList[45]); // Karate Chop
        pokemon.adicionarAtaque(moveList[44]); // Double Kick
        pokemon.adicionarAtaque(moveList[47]); // Brick Break
        pokemon.adicionarAtaque(moveList[48]); // Close Combat
    }
    else {
        // Para Pokémon não configurados, adiciona ataques básicos baseados no tipo
        std::vector<std::string> tipos = pokemon.getTipos();
        
        for (const auto& move : moveList) {
            for (const auto& tipo : tipos) {
                if (move.getTipo() == tipo && pokemon.getAtaques().size() < 4) {
                    pokemon.adicionarAtaque(move);
                    break;
                }
            }
        }
        
        // Se não tiver ataques suficientes, adiciona ataques normais
        while (pokemon.getAtaques().size() < 4) {
            for (const auto& move : moveList) {
                if (move.getTipo() == "Normal" && !pokemon.temAtaque(move.getNome())) {
                    pokemon.adicionarAtaque(move);
                    break;
                }
            }
        }
    }
}
