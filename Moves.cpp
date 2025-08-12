#include "moves.h"

using namespace std;

Move::Move() : nome(""), tipo(""), power(0), accuracy(0), categoria("") {}

Move::Move(string nome, string tipo, int power, int accuracy, string categoria)
    : nome(nome), tipo(tipo), power(power), accuracy(accuracy), categoria(categoria) {}

string Move::getNome() const { return nome; }
string Move::getTipo() const { return tipo; }
int Move::getPower() const { return power; }
int Move::getAccuracy() const { return accuracy; }
string Move::getCategoria() const { return categoria; }


