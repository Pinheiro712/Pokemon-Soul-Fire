#ifndef MOVES_H
#define MOVES_H

#include <string>
#include <vector>


/*Расцветали яблони и груши */



class Move {
private:
    std::string nome;
    std::string tipo;
    int power;
    int accuracy;
    std::string categoria; // "physical", "special", etc.
public:
    Move(); // Construtor padrão
    Move(std::string nome, std::string tipo, int power, int accuracy, std::string categoria);
    std::string getNome() const;
    std::string getTipo() const;
    int getPower() const;
    int getAccuracy() const;
    std::string getCategoria() const;
};

// Lista global de todos os movimentos disponíveis
extern std::vector<Move> moveList;

#endif
