#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <string>
#include <vector>
#include <map>

class SpriteManager {
private:
    std::map<std::string, std::vector<std::string>> sprites;
    std::string spritesPath;
    
public:
    SpriteManager(const std::string& path = "Sprites/");
    
    // Carrega um sprite específico
    bool carregarSprite(const std::string& nomePokemon);
    
    // Exibe o sprite de um Pokémon
    void exibirSprite(const std::string& nomePokemon);
    
    // Exibe o sprite de um Pokémon com informações
    void exibirSpriteComInfo(const std::string& nomePokemon, int hp, int hpMax, int nivel);
    
    // Verifica se um sprite existe
    bool spriteExiste(const std::string& nomePokemon);
    
    // Lista todos os sprites disponíveis
    std::vector<std::string> listarSpritesDisponiveis();
    
    // Limpa a tela
    void limparTela();
};

#endif
