#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Pokemon.h"

// esse arquivo é só pra eu testar os sprites pra ajustar tamanho, talvez eu implemente mas sla.
//(easter egg) 
//اِنَّا نَحۡنُ نُحۡیِ الۡمَوۡتٰی وَنَکۡتُبُ مَا قَدَّمُوۡا وَاٰثَارَہُمۡ ؕؑ وَکُلَّ شَیۡءٍ اَحۡصَیۡنٰہُ فِیۡۤ اِمَامٍ مُّبِیۡنٍ ﴿٪۱۳﴾

extern std::vector<Pokemon> Pokedex;

#define SPRITE_FOLDER "Sprites/"

// Enum para os diferentes tamanhos disponíveis
enum TamanhoSprite {
    NORMAL = 0,
    PEQUENO = 1,    // 2x menor
    MINIATURA = 2,   // 4x menor
    MICRO = 3        // 8x menor
};

// Enum para tipos de entidades
enum TipoEntidade {
    POKEMON = 0,
    OPONENTE = 1,
    JOGADOR = 2
};

void mostrarListaPokemons() {
    std::cout << "\n=== Lista de Pokemon Disponiveis ===\n";
    std::cout << "Digite 'lista' para ver esta lista novamente\n";
    std::cout << "Digite 'sair' para encerrar o programa\n\n";
    
    // Lista dos Pokémon com sprites disponíveis
    std::vector<std::string> pokemonsDisponiveis = {
        "Pikachu", "Charmander", "Bulbasaur", "Squirtle",
        "Raichu", "Ivysaur", "Wartortle", "Blastoise",
        "machop", "Machoke", "Machamp", "Gengar",
        "Arcanine", "Articuno", "Zapdos", "Moltres",
        "Typhlosion", "Feraligatr", "Scizor", "Umbreon", "Espeon",
        "Aerodactyl", "Haunter", "Alakazam", "Gyarados",
        "Houndoom", "Arbok", "Crobat", "Vileplume"
    };
    
    for (size_t i = 0; i < pokemonsDisponiveis.size(); i++) {
        std::cout << pokemonsDisponiveis[i];
        if ((i + 1) % 4 == 0) {
            std::cout << std::endl;
        } else {
            std::cout << "\t";
        }
    }
    std::cout << std::endl;
}

void mostrarListaOponentes() {
    std::cout << "\n=== Lista de Oponentes do Torneio ===\n";
    std::cout << "Digite 'oponentes' para ver esta lista novamente\n";
    std::cout << "Digite 'party [nome]' para ver a party de um oponente\n\n";
    
    // Lista dos oponentes baseada no Torneio.cpp
    std::vector<std::string> oponentes = {
        "Bruno", "Lyra", "Blaine", "Erika", 
        "Silver", "Agatha", "Red", "Lance", "Jogador"
    };
    
    std::cout << "=== TIER 1 (Iniciantes) ===\n";
    std::cout << "Bruno, Erika, Silver\n\n";
    
    std::cout << "=== TIER 2 (Intermediarios) ===\n";
    std::cout << "Blaine, Agatha, Red\n\n";
    
    std::cout << "=== TIER 3 (Elite) ===\n";
    std::cout << "Lance (Campeao)\n\n";
    
    std::cout << "=== ESPECIAL ===\n";
    std::cout << "Lyra, Jogador\n\n";
    
    std::cout << "=== Comandos ===\n";
    std::cout << "- Digite 'party Bruno' para ver a party do Bruno\n";
    std::cout << "- Digite 'party Lance' para ver a party do Lance\n";
    std::cout << "- E assim por diante...\n";
}

void mostrarPartyOponente(const std::string& nomeOponente) {
    std::cout << "\n=== PARTY DO OPONENTE: " << nomeOponente << " ===\n";
    
    if (nomeOponente == "Bruno") {
        std::cout << "Bruno: Machamp, Machoke, Machoke\n";
        std::cout << "Tier: 1 (Iniciante)\n";
    } else if (nomeOponente == "Agatha") {
        std::cout << "Agatha: Gengar, Haunter, Arbok\n";
        std::cout << "Tier: 2 (Intermediario)\n";
    } else if (nomeOponente == "Lance") {
        std::cout << "Lance: Dragonite, Aerodactyl, Gyarados, Charizard + Lendario\n";
        std::cout << "Tier: 3 (Campeao)\n";
    } else if (nomeOponente == "Red") {
        std::cout << "Red: Charizard, Blastoise, Venusaur, Pikachu, Raichu\n";
        std::cout << "Tier: 2 (Intermediario)\n";
    } else if (nomeOponente == "Lyra") {
        std::cout << "Lyra: Feraligatr, Blastoise, Typhlosion, Typhlosion\n";
        std::cout << "Tier: Especial\n";
    } else if (nomeOponente == "Silver") {
        std::cout << "Silver: Gyarados, Houndoom, Alakazam, Crobat\n";
        std::cout << "Tier: 1 (Iniciante)\n";
    } else if (nomeOponente == "Blaine") {
        std::cout << "Blaine: Arcanine, Charizard, Charmeleon\n";
        std::cout << "Tier: 2 (Intermediario)\n";
    } else if (nomeOponente == "Erika") {
        std::cout << "Erika: Venusaur, Bulbasaur, Vileplume\n";
        std::cout << "Tier: 1 (Iniciante)\n";
    } else if (nomeOponente == "Jogador") {
        std::cout << "Jogador: Escolha sua party!\n";
        std::cout << "Tier: Especial\n";
    } else {
        std::cout << "Oponente nao encontrado.\n";
        std::cout << "Digite 'oponentes' para ver a lista disponivel.\n";
    }
}

void mostrarComandosTamanho() {
    std::cout << "\n=== Comandos de Tamanho ===\n";
    std::cout << "- 'normal'     : Sprites no tamanho original\n";
    std::cout << "- 'pequeno'    : Sprites 2x menores\n";
    std::cout << "- 'miniatura'  : Sprites 4x menores\n";
    std::cout << "- 'micro'      : Sprites 8x menores\n";
    std::cout << "- 'tamanho'    : Ver esta lista novamente\n";
}

void exibirStatsEmBlocos(const Pokemon& pokemon) {
    std::cout << "\n=== STATS DO POKEMON ===\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    std::cout << "│ " << pokemon.getNome() << " Nv." << pokemon.getLvl() << std::string(25 - pokemon.getNome().length() - std::to_string(pokemon.getLvl()).length(), ' ') << "│\n";
    std::cout << "├─────────────────────────────────────┤\n";
    std::cout << "│ HP: " << std::setw(3) << pokemon.getHp() << "        │ Ataque: " << std::setw(3) << pokemon.getAtaque() << "      │\n";
    std::cout << "│ Defesa: " << std::setw(3) << pokemon.getDefesa() << "    │ Sp.Atk: " << std::setw(3) << pokemon.getEspecialataq() << "      │\n";
    std::cout << "│ Sp.Def: " << std::setw(3) << pokemon.getEspecialdefesa() << "    │ Speed: " << std::setw(3) << pokemon.getSpeed() << "      │\n";
    std::cout << "└─────────────────────────────────────┘\n";
    
    // Mostrar tipos
    std::cout << "\n=== TIPOS ===\n";
    std::cout << "┌─────────────────────────────────────┐\n";
    std::cout << "│ ";
    for (const auto& tipo : pokemon.getTipos()) {
        std::cout << tipo << " ";
    }
    std::cout << std::string(30 - pokemon.getTipos().size() * 6, ' ') << "│\n";
    std::cout << "└─────────────────────────────────────┘\n";
}

void exibirSpriteRedimensionado(const std::string& nomeEntidade, TamanhoSprite tamanho, TipoEntidade tipo) {
    std::string caminhoSprite = SPRITE_FOLDER + nomeEntidade + ".txt";
    std::ifstream spriteFile(caminhoSprite);
    
    if (!spriteFile.is_open()) {
        std::cerr << "Nao foi possivel encontrar o sprite de " << 
            (tipo == POKEMON ? "Pokemon" : "Oponente") << ": " << nomeEntidade << std::endl;
        return;
    }

    std::vector<std::string> linhas;
    std::string linha;
    
    // Ler todas as linhas
    while (std::getline(spriteFile, linha)) {
        linhas.push_back(linha);
    }
    spriteFile.close();

    // Determinar fator de redução baseado no tamanho
    int fatorReducao;
    std::string nomeTamanho;
    
    switch (tamanho) {
        case PEQUENO:
            fatorReducao = 2;
            nomeTamanho = "Pequeno (2x menor)";
            break;
        case MINIATURA:
            fatorReducao = 4;
            nomeTamanho = "Miniatura (4x menor)";
            break;
        case MICRO:
            fatorReducao = 8;
            nomeTamanho = "Micro (8x menor)";
            break;
        default:
            fatorReducao = 1;
            nomeTamanho = "Normal";
            break;
    }

    std::string tipoEntidade = (tipo == POKEMON) ? "Pokemon" : "Oponente";
    
    if (tamanho == NORMAL) {
        std::cout << "\n=== Sprite " << tipoEntidade << " (" << nomeTamanho << ") ===\n";
        for (const auto& l : linhas) {
            std::cout << l << std::endl;
        }
        return;
    }

    std::cout << "\n=== Sprite " << tipoEntidade << " (" << nomeTamanho << ") ===\n";
    
    // Exibir linhas reduzidas
    for (size_t i = 0; i < linhas.size(); i += fatorReducao) {
        std::string linhaReduzida = linhas[i];
        
        // Reduzir caracteres na linha
        std::string linhaFinal;
        for (size_t j = 0; j < linhaReduzida.length(); j += fatorReducao) {
            linhaFinal += linhaReduzida[j];
        }
        
        std::cout << linhaFinal << std::endl;
    }
}

TipoEntidade determinarTipoEntidade(const std::string& nome) {
    // Lista de oponentes
    std::vector<std::string> oponentes = {
        "Bruno", "Lyra", "Blaine", "Erika", "Silver", "Agatha", "Red", "Lance", "Jogador"
    };
    
    // Verificar se é um oponente
    for (const auto& oponente : oponentes) {
        if (nome == oponente) {
            return (nome == "Jogador") ? JOGADOR : OPONENTE;
        }
    }
    
    return POKEMON;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "=== Sprite Viewer Pokemon & Oponentes ===\n";
    std::cout << "Comandos disponiveis:\n";
    std::cout << "- Digite o nome de um Pokemon para ver seu sprite e stats\n";
    std::cout << "- Digite o nome de um oponente para ver seu sprite\n";
    std::cout << "- Digite 'party [nome]' para ver a party de um oponente\n";
    std::cout << "- Digite 'tamanho' para ver opcoes de tamanho\n";
    std::cout << "- Digite 'lista' para ver Pokemon disponiveis\n";
    std::cout << "- Digite 'oponentes' para ver oponentes do torneio\n";
    std::cout << "- Digite 'sair' para encerrar\n\n";
    
    mostrarListaPokemons();
    mostrarListaOponentes();
    mostrarComandosTamanho();

    std::string nomeEntidade;
    TamanhoSprite tamanhoAtual = NORMAL;
    
    while (true) {
        std::cout << "\nDigite o nome do Pokemon/Oponente (ou comando): ";
        std::getline(std::cin, nomeEntidade);
        
        // Verificar comandos especiais
        if (nomeEntidade == "sair" || nomeEntidade == "Sair" || nomeEntidade == "SAIR") {
            std::cout << "Encerrando o programa...\n";
            break;
        }
        
        if (nomeEntidade == "lista" || nomeEntidade == "Lista" || nomeEntidade == "LISTA") {
            mostrarListaPokemons();
            continue;
        }
        
        if (nomeEntidade == "oponentes" || nomeEntidade == "Oponentes" || nomeEntidade == "OPONENTES") {
            mostrarListaOponentes();
            continue;
        }

        if (nomeEntidade.substr(0, 5) == "party" && nomeEntidade.length() > 5) {
            std::string oponenteNome = nomeEntidade.substr(6);
            mostrarPartyOponente(oponenteNome);
            continue;
        }
        
        if (nomeEntidade == "tamanho" || nomeEntidade == "Tamanho" || nomeEntidade == "TAMANHO") {
            mostrarComandosTamanho();
            continue;
        }
        
        if (nomeEntidade == "normal" || nomeEntidade == "Normal" || nomeEntidade == "NORMAL") {
            tamanhoAtual = NORMAL;
            std::cout << "Tamanho definido como: NORMAL\n";
            continue;
        }
        
        if (nomeEntidade == "pequeno" || nomeEntidade == "Pequeno" || nomeEntidade == "PEQUENO") {
            tamanhoAtual = PEQUENO;
            std::cout << "Tamanho definido como: PEQUENO (2x menor)\n";
            continue;
        }
        
        if (nomeEntidade == "miniatura" || nomeEntidade == "Miniatura" || nomeEntidade == "MINIATURA") {
            tamanhoAtual = MINIATURA;
            std::cout << "Tamanho definido como: MINIATURA (4x menor)\n";
            continue;
        }
        
        if (nomeEntidade == "micro" || nomeEntidade == "Micro" || nomeEntidade == "MICRO") {
            tamanhoAtual = MICRO;
            std::cout << "Tamanho definido como: MICRO (8x menor)\n";
            continue;
        }
        
        if (nomeEntidade.empty()) {
            std::cout << "Por favor, digite um nome valido.\n";
            continue;
        }

        // Corrigir capitalização
        if (!nomeEntidade.empty()) {
            nomeEntidade[0] = std::toupper(nomeEntidade[0]);
            std::transform(nomeEntidade.begin() + 1, nomeEntidade.end(), nomeEntidade.begin() + 1, ::tolower);
        }

        // Determinar tipo de entidade
        TipoEntidade tipo = determinarTipoEntidade(nomeEntidade);
        
        if (tipo == POKEMON) {
            // Buscar o Pokemon na Pokedex
            Pokemon* selecionado = nullptr;
            for (auto& p : Pokedex) {
                if (p.getNome() == nomeEntidade) {
                    selecionado = &p;
                    break;
                }
            }

            if (!selecionado) {
                std::cerr << "Pokemon nao encontrado na Pokedex.\n";
                std::cout << "Digite 'lista' para ver os Pokemon disponiveis.\n";
                continue;
            }

            // Atribui um nível aleatório entre 80 e 100
            int nivel = rand() % 21 + 80;
            selecionado->setLvl(nivel);
            selecionado->calculostats();

            // Exibir stats em blocos organizados
            exibirStatsEmBlocos(*selecionado);
        } else {
            // É um oponente ou jogador
            std::cout << "\n=== Informacoes do " << 
                (tipo == JOGADOR ? "Jogador" : "Oponente") << " ===\n";
            std::cout << "Nome: " << nomeEntidade << std::endl;
            
            if (tipo == OPONENTE) {
                // Mostrar apenas informações básicas do oponente
                if (nomeEntidade == "Lance") {
                    std::cout << "Tier: 3 (Campeao)\n";
                    std::cout << "Digite 'party Lance' para ver sua party completa\n";
                } else if (nomeEntidade == "Red" || nomeEntidade == "Agatha" || nomeEntidade == "Blaine") {
                    std::cout << "Tier: 2 (Intermediario)\n";
                    std::cout << "Digite 'party " << nomeEntidade << "' para ver sua party\n";
                } else {
                    std::cout << "Tier: 1 (Iniciante)\n";
                    std::cout << "Digite 'party " << nomeEntidade << "' para ver sua party\n";
                }
            }
        }

        // Exibir o sprite no tamanho selecionado
        exibirSpriteRedimensionado(nomeEntidade, tamanhoAtual, tipo);
    }
    
    return 0;
}