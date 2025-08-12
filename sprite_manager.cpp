#include "sprite_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

SpriteManager::SpriteManager(const std::string& path) : spritesPath(path) {
    // Carrega todos os sprites disponíveis na inicialização
    auto spritesDisponiveis = listarSpritesDisponiveis();
    for (const auto& sprite : spritesDisponiveis) {
        carregarSprite(sprite);
    }
}

bool SpriteManager::carregarSprite(const std::string& nomePokemon) {
    // Tenta diferentes variações do nome do arquivo
    std::vector<std::string> possiveisNomes = {
        spritesPath + nomePokemon + ".txt",
        spritesPath + nomePokemon + ".txt.txt",
        spritesPath + nomePokemon + ".txt"
    };
    
    // Para nomes que podem ter variações de capitalização
    std::string nomeLower = nomePokemon;
    std::transform(nomeLower.begin(), nomeLower.end(), nomeLower.begin(), ::tolower);
    if (nomeLower != nomePokemon) {
        possiveisNomes.push_back(spritesPath + nomeLower + ".txt");
    }
    
    for (const auto& nomeArquivo : possiveisNomes) {
        std::ifstream arquivo(nomeArquivo);
        
        if (arquivo.is_open()) {
            std::vector<std::string> linhas;
            std::string linha;
            
            while (std::getline(arquivo, linha)) {
                linhas.push_back(linha);
            }
            
            arquivo.close();
            
            if (!linhas.empty()) {
                sprites[nomePokemon] = linhas;
                return true;
            }
        }
    }
    
    return false;
}

void SpriteManager::exibirSprite(const std::string& nomePokemon) {
    auto it = sprites.find(nomePokemon);
    if (it != sprites.end()) {
        for (const auto& linha : it->second) {
            std::cout << linha << std::endl;
        }
    } else {
        std::cout << "Sprite não encontrado para " << nomePokemon << std::endl;
    }
}

void SpriteManager::exibirSpriteComInfo(const std::string& nomePokemon, int hp, int hpMax, int nivel) {
    auto it = sprites.find(nomePokemon);
    if (it != sprites.end()) {
        // Exibe o sprite
        for (const auto& linha : it->second) {
            std::cout << linha << std::endl;
        }
        
        // Exibe informações do Pokémon
        std::cout << "\n" << nomePokemon << " Nv." << nivel << std::endl;
        std::cout << "HP: " << hp << "/" << hpMax << std::endl;
        
        // Barra de HP visual
        int barraLength = 20;
        int hpPercent = (hpMax > 0) ? (hp * barraLength) / hpMax : 0;
        
        std::cout << "[";
        for (int i = 0; i < barraLength; i++) {
            if (i < hpPercent) {
                std::cout << "█";
            } else {
                std::cout << "░";
            }
        }
        std::cout << "]" << std::endl;
    } else {
        std::cout << "Sprite não encontrado para " << nomePokemon << std::endl;
    }
}

bool SpriteManager::spriteExiste(const std::string& nomePokemon) {
    return sprites.find(nomePokemon) != sprites.end();
}

std::vector<std::string> SpriteManager::listarSpritesDisponiveis() {
    std::vector<std::string> nomes;
    
    // Lista dos Pokémon com sprites disponíveis na pasta Sprites
    nomes = {
        "Pikachu", "Charmander", "Bulbasaur", "Squirtle",
        "Raichu", "Ivysaur", "Wartortle", "Blastoise",
        "machop", "Machoke", "Machamp", "Gengar",
        "Arcanine", "Articuno", "Zapdos", "Moltres",
        "Typhlosion", "Feraligatr", "Sceptile", "Blaziken",
        "Swampert", "Aggron", "Empoleon", "Infernape",
        "Torterra", "Regirock", "Regice", "Rayquaza",
        "Lugia", "Ho-Oh", "Goodra", "Sylveon",
        "Greninja", "Scizor", "Umbreon", "Espeon"
    };
    
    return nomes;
}

void SpriteManager::limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
