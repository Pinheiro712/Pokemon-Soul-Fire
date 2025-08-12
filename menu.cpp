#include "batalha.h"
#include "pokedex.h"
#include "Tipagem.cpp"
#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <algorithm>

using namespace std;

class MenuJogo {
private:
    Typeadv typeChart;
    Party partyJogador;
    vector<string> oponentesDisponiveis = {
        "Bruno", "Agatha", "Lance", "Red", "Lyra", "Silver", "Blaine", "Erika"
    };

    void limparTela() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void mostrarMenuPrincipal() {
        cout << "=====================================" << endl;
        cout << "         POKEMON BATTLE GAME" << endl;
        cout << "=====================================" << endl;
        cout << "1. Montar Party" << endl;
        cout << "2. Ver Party Atual" << endl;
        cout << "3. Iniciar Liga Pokemon" << endl;
        cout << "4. Sair" << endl;
        cout << "=====================================" << endl;
        cout << "Escolha uma opcao: ";
    }

    void mostrarListaPokemon() {
        cout << "\n=== POKEMON DISPONiVEIS ===" << endl;
        cout << "Escolha até 6 Pokemon para sua party:" << endl;
        cout << endl;
        
        for (size_t i = 0; i < Pokedex.size(); i++) {
            cout << (i + 1) << ". " << Pokedex[i].getNome() 
                 << " (Nv." << Pokedex[i].getLvl() << ") "
                 << "Tipos: ";
            
            const auto& tipos = Pokedex[i].getTipos();
            for (size_t j = 0; j < tipos.size(); j++) {
                cout << tipos[j];
                if (j < tipos.size() - 1) cout << "/";
            }
            cout << endl;
        }
        cout << "0. Voltar" << endl;
        cout << "===========================" << endl;
    }

    void montarParty() {
        limparTela();
        partyJogador = Party(); // Limpar party atual
        
        cout << "=== MONTAR PARTY ===" << endl;
        cout << "Você pode escolher ate 6 Pokemon." << endl;
        cout << "Digite 0 para parar de adicionar Pokemon." << endl << endl;

        while (partyJogador.getTamanho() < 6) {
            mostrarListaPokemon();
            cout << "\nParty atual (" << partyJogador.getTamanho() << "/6):" << endl;
            if (partyJogador.getTamanho() == 0) {
                cout << "Vazia" << endl;
            } else {
                const auto& pokemons = partyJogador.getPokemons();
                for (size_t i = 0; i < pokemons.size(); i++) {
                    cout << (i + 1) << ". " << pokemons[i]->getNome() << endl;
                }
            }
            
            cout << "\nEscolha um Pokemon (0-" << Pokedex.size() << "): ";
            int escolha;
            cin >> escolha;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida!" << endl;
                continue;
            }
            
            if (escolha == 0) {
                if (partyJogador.getTamanho() == 0) {
                    cout << "Voce precisa ter pelo menos 1 Pokemon na party!" << endl;
                    continue;
                }
                break;
            }
            
            if (escolha < 1 || escolha > static_cast<int>(Pokedex.size())) {
                cout << "Opcao inválida!" << endl;
                continue;
            }
            
            // Criar Pokemon com moves
            auto pokemon = criarPokemonComMoves(Pokedex[escolha - 1]);
            
            // Definir nível aleatório entre 80-100
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(80, 100);
            int nivel = dist(gen);
            pokemon->setLvl(nivel);
            pokemon->calculostats();
            
            if (partyJogador.adicionarPokemon(pokemon)) {
                cout << pokemon->getNome() << " foi adicionado a party!" << endl;
            } else {
                cout << "Party cheia!" << endl;
                break;
            }
            
            cout << "Pressione ENTER para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            limparTela();
        }
        
        cout << "Party montada com sucesso!" << endl;
        cout << "Pressione ENTER para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    void verPartyAtual() {
        limparTela();
        cout << "=== SUA PARTY ATUAL ===" << endl;
        
        if (partyJogador.estaVazia()) {
            cout << "Sua party esta vazia!" << endl;
        } else {
            const auto& pokemons = partyJogador.getPokemons();
            for (size_t i = 0; i < pokemons.size(); i++) {
                cout << (i + 1) << ". " << pokemons[i]->getNome() << endl;
                cout << "   Nivel: " << pokemons[i]->getLvl() << endl;
                cout << "   HP: " << pokemons[i]->getHp() << "/" << pokemons[i]->getHpMax() << endl;
                cout << "   Tipos: ";
                const auto& tipos = pokemons[i]->getTipos();
                for (size_t j = 0; j < tipos.size(); j++) {
                    cout << tipos[j];
                    if (j < tipos.size() - 1) cout << "/";
                }
                cout << endl;
                cout << "   Ataques: ";
                const auto& ataques = pokemons[i]->getAtaques();
                for (size_t j = 0; j < ataques.size(); j++) {
                    cout << ataques[j].getNome();
                    if (j < ataques.size() - 1) cout << ", ";
                }
                cout << endl << endl;
            }
        }
        
        cout << "Pressione ENTER para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    void iniciarBatalha() {
        if (partyJogador.estaVazia()) {
            cout << "Você precisa montar uma party primeiro!" << endl;
            cout << "Pressione ENTER para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        }

        limparTela();
        cout << "=== LIGA POKEMON ===" << endl;
        cout << "Voce deve enfrentar 4 oponentes" << endl;
        cout << "antes de desafiar o Campeao Lance!" << endl;
        cout << "Pressione ENTER para começar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        // Lista de oponentes (excluindo Lance)
        vector<string> oponentesPreliminares = {
            "Bruno", "Agatha", "Red", "Lyra", "Silver", "Blaine", "Erika"
        };

        // Embaralhar oponentes preliminares
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(oponentesPreliminares.begin(), oponentesPreliminares.end(), gen);

        // Selecionar 4 oponentes aleatórios
        vector<string> oponentesSelecionados;
        for (int i = 0; i < 4 && i < static_cast<int>(oponentesPreliminares.size()); i++) {
            oponentesSelecionados.push_back(oponentesPreliminares[i]);
        }

        // Batalhar contra os 4 oponentes preliminares
        for (size_t i = 0; i < oponentesSelecionados.size(); i++) {
            limparTela();
            cout << "=== BATALHA " << (i + 1) << "/4 ===" << endl;
            cout << "Oponente: " << oponentesSelecionados[i] << endl;
            cout << "Pressione ENTER para iniciar a batalha...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();

            // Criar party do oponente
            auto partyOponente = criarPartyOponente(oponentesSelecionados[i]);
            
            // Criar e configurar batalha
            Batalha batalha(typeChart);
            batalha.configurarPartyJogador(partyJogador.getPokemons());
            batalha.configurarPartyOponente(partyOponente);
            
            // Iniciar batalha
            limparTela();
            batalha.iniciar();
            
            // Verificar se o jogador perdeu
            if (batalha.getPartyJogador().estaVazia()) {
                cout << "\nVoce perdeu! Game Over!" << endl;
                cout << "Pressione ENTER para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                return;
            }
            else{
            cout << "\nVitória! Pressione ENTER para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            }
        }

        // Batalha final contra Lance
        limparTela();
        cout << "=== BATALHA FINAL ===" << endl;
        cout << "Voce chegou ao campeao!" << endl;
        cout << "Oponente: Lance, O barao dos dragoes" << endl;
        cout << "Pressione ENTER para iniciar a batalha final...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        // Criar party do Lance
        auto partyLance = criarPartyOponente("Lance");
        
        // Criar e configurar batalha final
        Batalha batalhaFinal(typeChart);
        batalhaFinal.configurarPartyJogador(partyJogador.getPokemons());
        batalhaFinal.configurarPartyOponente(partyLance);
        
        // Iniciar batalha final
        limparTela();
        batalhaFinal.iniciar();
        
        // Verificar resultado final
        if (batalhaFinal.getPartyJogador().estaVazia()) {
            cout << "\nVoce perdeu para Lance! Game Over!" << endl;
        } else {
            cout << "\nPARABENS! Voce venceu Lance e se tornou o novo campeao do mundo!" << endl;
        }
        
        cout << "Pressione ENTER para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

public:
    MenuJogo() : typeChart() {}

    void executar() {
        int opcao;
        
        do {
            limparTela();
            mostrarMenuPrincipal();
            cin >> opcao;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                opcao = 0;
            }
            
            switch (opcao) {
                case 1:
                    montarParty();
                    break;
                case 2:
                    verPartyAtual();
                    break;
                case 3:
                    iniciarBatalha();
                    break;
                case 4:
                    cout << "Obrigado por jogar!" << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                    cout << "Pressione ENTER para continuar...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
            }
        } while (opcao != 4);
    }
};

int main() {
    MenuJogo menu;
    menu.executar();
    return 0;
}
