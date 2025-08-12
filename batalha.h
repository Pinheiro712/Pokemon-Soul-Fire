#ifndef BATALHA_H
#define BATALHA_H

#include "pokemon.h"
#include "moves.h"
#include <vector>
#include <memory>
#include <random>
#include <string>

class Typeadv;

// Classe para gerenciar uma party de Pokémon
//melhor do que controlar pokemons individualmente
//a party é uma lista de pokemons, e o jogador pode ter até 6 pokemons na party

class Party {
private:
    std::vector<std::shared_ptr<Pokemon>> pokemons;
    static const int MAX_PARTY_SIZE = 6;

public:
    Party();
    bool adicionarPokemon(std::shared_ptr<Pokemon> pokemon);
    void removerPokemon(int index);
    std::shared_ptr<Pokemon> getPokemonAtivo() const;
    const std::vector<std::shared_ptr<Pokemon>>& getPokemons() const;
    bool estaVazia() const;
    size_t getTamanho() const;
    void trocarPosicao(int pos1, int pos2);
    void removerPokemonEspecifico(std::shared_ptr<Pokemon> pokemon);
};

// Classe principal de batalha
class Batalha {
private:
    Party partyJogador;
    Party partyOponente;
    std::shared_ptr<Pokemon> pokemonAtivoJogador;
    std::shared_ptr<Pokemon> pokemonAtivoOponente;
    Typeadv& typeChart;
    std::mt19937 rng;
    
    // Funções auxiliares
    bool acertou(const Move &move);
    bool critico();
    double fatorAleatorio();
    double multiplicadorTipo(const Move &move, const Pokemon &defensor);
    int calcularDano(const Pokemon &atacante, const Pokemon &defensor, const Move &move);
    
    // Seleção de ataques
    Move selecionarAtaqueAleatorio(const Pokemon &pokemon);
    Move selecionarAtaqueJogador(const Pokemon &pokemon);
    Move selecionarAtaqueJogadorSemMenu(const Pokemon &pokemon);
    
    // Lógica de batalha
    void executarAtaque(std::shared_ptr<Pokemon> atacante, std::shared_ptr<Pokemon> defensor, bool jogadorAtacando);
    bool verificarFimBatalha();
    void trocarPokemonJogador();
    void trocarPokemonOponente();
    
    // Interface do usuário
    void mostrarStatusBatalha();
    void mostrarPartyJogador();
    void mostrarMenuAtaques(const Pokemon &pokemon);
    void limparTela();

public:
    Batalha(Typeadv& typeChart);
    
    // Configuração das parties
    void configurarPartyJogador(const std::vector<std::shared_ptr<Pokemon>> &pokemons);
    void configurarPartyOponente(const std::vector<std::shared_ptr<Pokemon>> &pokemons);
    
    // Execução da batalha
    void iniciar();
    void turno();
    
    // Getters
    const Party& getPartyJogador() const { return partyJogador; }
    const Party& getPartyOponente() const { return partyOponente; }
};

// Funções auxiliares para criação de parties
std::vector<Move> obterMovesPorTipo(const std::vector<std::string>& tipos);
std::shared_ptr<Pokemon> criarPokemonComMoves(const Pokemon& base);
std::vector<std::shared_ptr<Pokemon>> criarPartyOponente(const std::string& nomeOponente);

#endif 