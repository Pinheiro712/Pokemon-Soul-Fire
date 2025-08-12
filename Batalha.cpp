#include "batalha.h"
#include "pokedex.h"
#include "moves.h"
#include "Tipagem.cpp"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include <limits>
#include <random>
#include <iomanip>

using namespace std;
//arquivo principal para as batalhas, aqui é onde a magia acontece
// Расцветали яблони и груши
//eu criei uma classe Party para gerenciar as parties de pokemons, e uma classe Batalha que gerencia a batalha em si
Party::Party() {
    pokemons.clear();
}
bool Party::adicionarPokemon(std::shared_ptr<Pokemon> pokemon) {
    if (pokemons.size() < MAX_PARTY_SIZE) {
        pokemons.push_back(pokemon);
        return true;
    }
    return false;
}

void Party::removerPokemon(int index) {
    if (index >= 0 && index < static_cast<int>(pokemons.size())) {
        pokemons.erase(pokemons.begin() + index);
    }
}

std::shared_ptr<Pokemon> Party::getPokemonAtivo() const {
    if (!pokemons.empty()) {
        return pokemons[0];
    }
    return nullptr;
}

const std::vector<std::shared_ptr<Pokemon>>& Party::getPokemons() const {
    return pokemons;
}

bool Party::estaVazia() const {
    return pokemons.empty();
}

size_t Party::getTamanho() const {
    return pokemons.size();
}

void Party::trocarPosicao(int pos1, int pos2) {
    if (pos1 >= 0 && pos1 < static_cast<int>(pokemons.size()) &&
        pos2 >= 0 && pos2 < static_cast<int>(pokemons.size())) {
        std::swap(pokemons[pos1], pokemons[pos2]);
    }
}

void Party::removerPokemonEspecifico(std::shared_ptr<Pokemon> pokemon) {
    auto it = std::find(pokemons.begin(), pokemons.end(), pokemon);
    if (it != pokemons.end()) {
        pokemons.erase(it);
    }
}

// ==================== IMPLEMENTAÇÃO DA CLASSE BATALHA ====================

Batalha::Batalha(Typeadv& typeChart) : typeChart(typeChart), rng(std::chrono::steady_clock::now().time_since_epoch().count()) {
    pokemonAtivoJogador = nullptr;
    pokemonAtivoOponente = nullptr;
}

void Batalha::configurarPartyJogador(const std::vector<std::shared_ptr<Pokemon>> &pokemons) {
    partyJogador = Party();
    for (const auto& pokemon : pokemons) {
        partyJogador.adicionarPokemon(pokemon);
    }
    pokemonAtivoJogador = partyJogador.getPokemonAtivo();
}

void Batalha::configurarPartyOponente(const std::vector<std::shared_ptr<Pokemon>> &pokemons) {
    partyOponente = Party();
    for (const auto& pokemon : pokemons) {
        partyOponente.adicionarPokemon(pokemon);
    }
    pokemonAtivoOponente = partyOponente.getPokemonAtivo();
}

void Batalha::iniciar() {
    if (partyJogador.estaVazia() || partyOponente.estaVazia()) {
        cout << "Erro: Uma das parties esta vazia!" << endl;
        return;
    }

    pokemonAtivoJogador = partyJogador.getPokemonAtivo();
    pokemonAtivoOponente = partyOponente.getPokemonAtivo();

    cout << "=== BATALHA POKEMON INICIADA ===" << endl;
    cout << "Jogador vs " << pokemonAtivoOponente->getNome() << endl << endl;

    while (!verificarFimBatalha()) {
        turno();
    }

    // Determinar vencedor
    bool jogadorSemPokemon = true;
    for (const auto& pokemon : partyJogador.getPokemons()) {
        if (pokemon->getHp() > 0) {
            jogadorSemPokemon = false;
            break;
        }
    }

    bool oponenteSemPokemon = true;
    for (const auto& pokemon : partyOponente.getPokemons()) {
        if (pokemon->getHp() > 0) {
            oponenteSemPokemon = false;
            break;
        }
    }

    if (jogadorSemPokemon) {
        cout << "\n=== VOCE PERDEU! ===" << endl;
    } else if (oponenteSemPokemon) {
        cout << "\n=== VOCE VENCEU! ===" << endl;
    } else {
        cout << "\n=== EMPATE! ===" << endl;
    }
}

void Batalha::turno() {
    limparTela();
    mostrarStatusBatalha();

    // Verificar se algum Pokémon desmaiou
    if (pokemonAtivoJogador->getHp() <= 0) {
        cout << "\n" << pokemonAtivoJogador->getNome() << " desmaiou!" << endl;
        cout << "Pressione ENTER para trocar Pokemon...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        trocarPokemonJogador();
        if (!pokemonAtivoJogador) return;
        limparTela();
        mostrarStatusBatalha();
    }

    if (pokemonAtivoOponente->getHp() <= 0) {
        cout << "\n" << pokemonAtivoOponente->getNome() << " desmaiou!" << endl;
        trocarPokemonOponente();
        if (!pokemonAtivoOponente) return;
        limparTela();
        mostrarStatusBatalha();
    }

    // Determinar quem ataca primeiro (baseado na velocidade)
    bool jogadorPrimeiro = pokemonAtivoJogador->getSpeed() >= pokemonAtivoOponente->getSpeed();

    cout << "\n=== TURNO INICIADO ===" << endl;
    cout << "Velocidade do " << pokemonAtivoJogador->getNome() << ": " << pokemonAtivoJogador->getSpeed() << endl;
    cout << "Velocidade do " << pokemonAtivoOponente->getNome() << ": " << pokemonAtivoOponente->getSpeed() << endl;
    
    if (jogadorPrimeiro) {
        cout << pokemonAtivoJogador->getNome() << " ataca primeiro!" << endl;
    } else {
        cout << pokemonAtivoOponente->getNome() << " ataca primeiro!" << endl;
    }
    cout << "=====================" << endl;

    // Mostrar menu de ataques apenas uma vez no início do turno
    if (jogadorPrimeiro) {
        cout << "\nEscolha seu ataque:" << endl;
        mostrarMenuAtaques(*pokemonAtivoJogador);
    }

    if (jogadorPrimeiro) {
        // Jogador ataca primeiro
        executarAtaque(pokemonAtivoJogador, pokemonAtivoOponente, true);

        // Verificar se o oponente ainda está vivo antes de contra-atacar
        if (pokemonAtivoOponente->getHp() > 0) {
            // Oponente contra-ataca
            executarAtaque(pokemonAtivoOponente, pokemonAtivoJogador, false);
        }
    } else {
        // Oponente ataca primeiro
        executarAtaque(pokemonAtivoOponente, pokemonAtivoJogador, false);

        // Verificar se o jogador ainda está vivo antes de contra-atacar
        if (pokemonAtivoJogador->getHp() > 0) {
            // Mostrar menu de ataques para o jogador
            cout << "\nEscolha seu ataque:" << endl;
            mostrarMenuAtaques(*pokemonAtivoJogador);
            // Jogador contra-ataca
            executarAtaque(pokemonAtivoJogador, pokemonAtivoOponente, true);
        }
    }

    // Mostrar o que aconteceu no turno
    cout << "\n=== RESUMO DO TURNO ===" << endl;
    cout << pokemonAtivoJogador->getNome() << " HP: " << pokemonAtivoJogador->getHp() << "/" << pokemonAtivoJogador->getHpMax() << endl;
    cout << pokemonAtivoOponente->getNome() << " HP: " << pokemonAtivoOponente->getHp() << "/" << pokemonAtivoOponente->getHpMax() << endl;
    cout << "=========================" << endl;
    
    cout << "Pressione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool Batalha::acertou(const Move &move) {
    std::uniform_int_distribution<int> dist(1, 100);
    return dist(rng) <= move.getAccuracy();
}

bool Batalha::critico() {
    std::uniform_int_distribution<int> dist(1, 100);
    return dist(rng) <= 6; // 6% de chance de crítico
}

double Batalha::fatorAleatorio() {
    std::uniform_real_distribution<double> dist(0.85, 1.0);
    return dist(rng);
}
// Multiplicador de tipo baseado na tabela de tipos
// Retorna o multiplicador de dano baseado no tipo do ataque e nos tipos do defensor
double Batalha::multiplicadorTipo(const Move &move, const Pokemon &defensor) {
    return typeChart.getMultiplicador(move.getTipo(), defensor.getTipos());
}

int Batalha::calcularDano(const Pokemon &atacante, const Pokemon &defensor, const Move &move) {
    int poder = move.getPower();
    if (poder == 0) return 0; // Movimentos de status

    int ataque, defesa;
    if (move.getCategoria() == "Fisico") {
        ataque = atacante.getAtaque();
        defesa = defensor.getDefesa();
    } else {
        ataque = atacante.getEspecialataq();
        defesa = defensor.getEspecialdefesa();
    }

    double multiplicador = multiplicadorTipo(move, defensor);
    double fatorCritico = critico() ? 1.5 : 1.0;
    double fatorAleatorio = this->fatorAleatorio();

    int dano = static_cast<int>(((2 * atacante.getLvl() / 5.0 + 2) * poder * ataque / defesa) / 50.0 + 2);
    dano = static_cast<int>(dano * multiplicador * fatorCritico * fatorAleatorio);

    return max(1, dano); // Mínimo de 1 de dano
}

Move Batalha::selecionarAtaqueAleatorio(const Pokemon &pokemon) {
    const vector<Move>& ataques = pokemon.getAtaques();
    if (ataques.empty()) {
        return Move("Struggle", "Normal", 50, 100, "Fisico");
    }

    std::uniform_int_distribution<int> dist(0, ataques.size() - 1);
    return ataques[dist(rng)];
}

Move Batalha::selecionarAtaqueJogador(const Pokemon &pokemon) {
    mostrarMenuAtaques(pokemon);
    
    const vector<Move>& ataques = pokemon.getAtaques();
    int escolha;
    
    do {
        cout << "Escolha seu ataque (1-" << ataques.size() << "): ";
        cin >> escolha;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            escolha = 0;
        }
    } while (escolha < 1 || escolha > static_cast<int>(ataques.size()));

    return ataques[escolha - 1];
}

Move Batalha::selecionarAtaqueJogadorSemMenu(const Pokemon &pokemon) {
    const vector<Move>& ataques = pokemon.getAtaques();
    int escolha;
    
    do {
        cout << "Escolha seu ataque (1-" << ataques.size() << "): ";
        cin >> escolha;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            escolha = 0;
        }
    } while (escolha < 1 || escolha > static_cast<int>(ataques.size()));

    return ataques[escolha - 1];
}

void Batalha::executarAtaque(std::shared_ptr<Pokemon> atacante, std::shared_ptr<Pokemon> defensor, bool jogadorAtacando) {
    Move ataque;
    
    if (jogadorAtacando) {
        ataque = selecionarAtaqueJogadorSemMenu(*atacante);
    } else {
        ataque = selecionarAtaqueAleatorio(*atacante);
    }
    
    // Mostrar quem está atacando
    string atacanteNome = atacante->getNome();
    string defensorNome = defensor->getNome();
    
    // Calcular HP antes do ataque para calcular porcentagem
    int hpAntes = defensor->getHp();
    
    // Mostrar o ataque sendo usado
    if (jogadorAtacando) {
        cout << atacanteNome << " usou " << ataque.getNome() << "!" << endl;
    } else {
        cout << atacanteNome << " usou " << ataque.getNome() << "!" << endl;
    }
    
    // Verificar se acertou
    if (!acertou(ataque)) {
        cout << "O ataque errou!" << endl;
        return;
    }

    // Calcular e aplicar dano
    int dano = calcularDano(*atacante, *defensor, ataque);
    defensor->setHp(defensor->getHp() - dano);
    
    if (defensor->getHp() < 0) defensor->setHp(0);
    
    // Calcular porcentagem de HP perdida
    double porcentagemPerdida = (double)dano / hpAntes * 100.0;
    
    // Mostrar eficácia do tipo
    string eficacia = typeChart.calculodano(ataque.getTipo(), defensor->getTipos());
    
    // Mostrar feedback narrativo
    if (jogadorAtacando) {
        cout << eficacia << " contra o " << defensorNome << endl;
        cout << defensorNome << " perdeu " << fixed << setprecision(0) << porcentagemPerdida << "% de HP!" << endl;
    } else {
        cout << eficacia << " contra " << defensorNome << "!" << endl;
        cout << "Seu " << defensorNome << " perdeu " << fixed << setprecision(0) << porcentagemPerdida << "% de HP!" << endl;
    }
    
    // Verificar se o defensor desmaiou
    if (defensor->getHp() <= 0) {
        if (jogadorAtacando) {
            cout << defensorNome << " desmaiou!" << endl;
        } else {
            cout << "Seu " << defensorNome << " desmaiou!" << endl;
        }
    }
    
    cout << endl;
}

bool Batalha::verificarFimBatalha() {
    // Verificar se todos os Pokémon do jogador desmaiaram
    bool jogadorSemPokemon = true;
    for (const auto& pokemon : partyJogador.getPokemons()) {
        if (pokemon->getHp() > 0) {
            jogadorSemPokemon = false;
            break;
        }
    }

    // Verificar se todos os Pokémon do oponente desmaiaram
    bool oponenteSemPokemon = true;
    for (const auto& pokemon : partyOponente.getPokemons()) {
        if (pokemon->getHp() > 0) {
            oponenteSemPokemon = false;
            break;
        }
    }

    return jogadorSemPokemon || oponenteSemPokemon;
}

void Batalha::trocarPokemonJogador() {
    cout << "Escolha um novo Pokemon:" << endl;
    mostrarPartyJogador();
    
    int escolha;
    do {
        cout << "Escolha (1-" << partyJogador.getTamanho() << "): ";
        cin >> escolha;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            escolha = 0;
        }
    } while (escolha < 1 || escolha > static_cast<int>(partyJogador.getTamanho()));

    // Trocar posição do Pokémon escolhido para a primeira posição
    partyJogador.trocarPosicao(0, escolha - 1);
    pokemonAtivoJogador = partyJogador.getPokemonAtivo();
    
    cout << "Voce enviou " << pokemonAtivoJogador->getNome() << "!" << endl;
}

void Batalha::trocarPokemonOponente() {
    // Oponente escolhe automaticamente o próximo Pokémon com HP > 0
    for (size_t i = 0; i < partyOponente.getTamanho(); i++) {
        if (partyOponente.getPokemons()[i]->getHp() > 0) {
            partyOponente.trocarPosicao(0, i);
            pokemonAtivoOponente = partyOponente.getPokemonAtivo();
            cout << "Oponente enviou " << pokemonAtivoOponente->getNome() << "!" << endl;
            return;
        }
    }
}

void Batalha::mostrarStatusBatalha() {
    cout << "=== STATUS DA BATALHA ===" << endl;
    cout << "JOGADOR: " << pokemonAtivoJogador->getNome() << " HP: " << pokemonAtivoJogador->getHp() << "/" << pokemonAtivoJogador->getHpMax() << endl;
    cout << "ELITE 4: " << pokemonAtivoOponente->getNome() << " HP: " << pokemonAtivoOponente->getHp() << "/" << pokemonAtivoOponente->getHpMax() << endl;
    cout << "=========================" << endl << endl;
}

void Batalha::mostrarPartyJogador() {
    const auto& pokemons = partyJogador.getPokemons();
    for (size_t i = 0; i < pokemons.size(); i++) {
        cout << (i + 1) << ". " << pokemons[i]->getNome();
        if (pokemons[i]->getHp() <= 0) {
            cout << " (DESMAIADO)";
        } else {
            cout << " HP: " << pokemons[i]->getHp();
        }
        cout << endl;
    }
}

void Batalha::mostrarMenuAtaques(const Pokemon &pokemon) {
    cout << "\n=== ATAQUES DISPONIVEIS ===" << endl;
    const vector<Move>& ataques = pokemon.getAtaques();
    for (size_t i = 0; i < ataques.size(); i++) {
        cout << (i + 1) << ". " << ataques[i].getNome() 
             << " (" << ataques[i].getTipo() << ") "
             << "Poder: " << ataques[i].getPower() 
             << " Precisao: " << ataques[i].getAccuracy() << "%" << endl;
    }
    cout << "===========================" << endl;
}

void Batalha::limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Outras coisas importantes pro jogo

std::vector<Move> obterMovesPorTipo(const std::vector<std::string>& tipos) {
    std::vector<Move> movesCompativeis;
    //eu montei pokemons com ataques em mente mas caso o jogador pegue pokemons específicos ele nao fica sem o ataque
    for (const auto& move : moveList) {
        for (const auto& tipo : tipos) {
            if (move.getTipo() == tipo) {
                movesCompativeis.push_back(move);
                break;
            }
        }
    }
    
    // Se não encontrar moves do tipo, adicionar moves normais (todo pokemon usa)
    if (movesCompativeis.empty()) {
        for (const auto& move : moveList) {
            if (move.getTipo() == "Normal") {
                movesCompativeis.push_back(move);
            }
        }
    }
    
    return movesCompativeis;
}

std::shared_ptr<Pokemon> criarPokemonComMoves(const Pokemon& base) {
    auto pokemon = std::make_shared<Pokemon>(base);
    
    // Obter moves compativeis com os tipos do Pokémon
    std::vector<Move> movesCompativeis = obterMovesPorTipo(pokemon->getTipos());
    
    // Selecionar 4 moves aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    
    if (movesCompativeis.size() > 4) {
        std::shuffle(movesCompativeis.begin(), movesCompativeis.end(), gen);
        movesCompativeis.resize(4);
    }
    
    // Adicionar os moves ao Pokémon
    for (const auto& move : movesCompativeis) {
        pokemon->adicionarAtaque(move);
    }
    
    // Calcular stats baseado no nível
    pokemon->calculostats();
    
    return pokemon;
}

std::vector<std::shared_ptr<Pokemon>> criarPartyOponente(const std::string& nomeOponente) {
    std::vector<std::shared_ptr<Pokemon>> party;
    
    // Função para gerar nível aleatório entre 80-100   
    auto gerarNivelAleatorio = []() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(80, 100);
        return dist(gen);
    };
    
    // Definir parties específicas para cada oponente
    if (nomeOponente == "Bruno") {
        //bruno lutador
        auto pokemon1 = criarPokemonComMoves(Pokedex[13]); // Machamp
        auto pokemon2 = criarPokemonComMoves(Pokedex[12]); // Machoke
        auto pokemon3 = criarPokemonComMoves(Pokedex[30]); // Heracross
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3};
    }
    else if (nomeOponente == "Agatha") {
        //agatha veneno
        auto pokemon1 = criarPokemonComMoves(Pokedex[14]); // Gengar
        auto pokemon2 = criarPokemonComMoves(Pokedex[15]); // Haunter
        auto pokemon3 = criarPokemonComMoves(Pokedex[16]); // Arbok
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3};
    }
    else if (nomeOponente == "Lance") {
        //lance campeão dragão
        auto pokemon1 = criarPokemonComMoves(Pokedex[17]); // Dragonite
        auto pokemon2 = criarPokemonComMoves(Pokedex[18]); // Aerodactyl
        auto pokemon3 = criarPokemonComMoves(Pokedex[19]); // Gyarados
        auto pokemon4 = criarPokemonComMoves(Pokedex[5]);  // Charizard
        
        // Adicionar um lendário aleatório
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(40, 48); // Índices dos lendários
        auto lendario = criarPokemonComMoves(Pokedex[dist(gen)]);
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        pokemon4->setLvl(gerarNivelAleatorio()); pokemon4->calculostats();
        lendario->setLvl(gerarNivelAleatorio()); lendario->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3, pokemon4, lendario};
    }
    else if (nomeOponente == "Red") {
        //Campeão anterior com pokemons mais fortes
        auto pokemon1 = criarPokemonComMoves(Pokedex[5]);  // Charizard
        auto pokemon2 = criarPokemonComMoves(Pokedex[8]);  // Blastoise
        auto pokemon3 = criarPokemonComMoves(Pokedex[2]);  // Venusaur
        auto pokemon4 = criarPokemonComMoves(Pokedex[9]);  // Pikachu
        auto pokemon5 = criarPokemonComMoves(Pokedex[33]); // Espeon
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        pokemon4->setLvl(gerarNivelAleatorio()); pokemon4->calculostats();
        pokemon5->setLvl(gerarNivelAleatorio()); pokemon5->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3, pokemon4, pokemon5};
    }
    else if (nomeOponente == "Lyra") {
        //água + steel
        auto pokemon1 = criarPokemonComMoves(Pokedex[32]); // Feraligatr
        auto pokemon2 = criarPokemonComMoves(Pokedex[8]);  // Blastoise
        auto pokemon3 = criarPokemonComMoves(Pokedex[35]); // Scizor
        auto pokemon4 = criarPokemonComMoves(Pokedex[29]); // Typhlosion
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        pokemon4->setLvl(gerarNivelAleatorio()); pokemon4->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3, pokemon4};
    }
    else if (nomeOponente == "Silver") {
        //Rival de Johto
        auto pokemon1 = criarPokemonComMoves(Pokedex[19]); // Gyarados
        auto pokemon2 = criarPokemonComMoves(Pokedex[34]); // Houndoom
        auto pokemon3 = criarPokemonComMoves(Pokedex[22]); // Alakazam
        auto pokemon4 = criarPokemonComMoves(Pokedex[36]); // Crobat
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        pokemon4->setLvl(gerarNivelAleatorio()); pokemon4->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3, pokemon4};
    }
    else if (nomeOponente == "Blaine") {
        //lider de fogo
        auto pokemon1 = criarPokemonComMoves(Pokedex[11]); // Arcanine
        auto pokemon2 = criarPokemonComMoves(Pokedex[29]); // Typhlosion
        auto pokemon3 = criarPokemonComMoves(Pokedex[4]);  // Charmeleon
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3};
    }
    else if (nomeOponente == "Erika") {
        //Planta
        auto pokemon1 = criarPokemonComMoves(Pokedex[2]);  // Venusaur
        auto pokemon2 = criarPokemonComMoves(Pokedex[0]);  // Bulbasaur
        auto pokemon3 = criarPokemonComMoves(Pokedex[21]); // Vileplume
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3};
    }
    else {
        // Party padrão se o nome não for reconhecido (party Básica mas efetiva)
        auto pokemon1 = criarPokemonComMoves(Pokedex[0]);  // Bulbasaur
        auto pokemon2 = criarPokemonComMoves(Pokedex[3]);  // Charmander
        auto pokemon3 = criarPokemonComMoves(Pokedex[6]);  // Squirtle
        
        pokemon1->setLvl(gerarNivelAleatorio()); pokemon1->calculostats();
        pokemon2->setLvl(gerarNivelAleatorio()); pokemon2->calculostats();
        pokemon3->setLvl(gerarNivelAleatorio()); pokemon3->calculostats();
        
        party = {pokemon1, pokemon2, pokemon3};
    }
    
    return party;
}
