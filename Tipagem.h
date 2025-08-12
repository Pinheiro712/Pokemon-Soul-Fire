#ifndef TIPAGEM_H
#define TIPAGEM_H

#include <string>
#include <vector>
#include <unordered_map>

class Typeadv {
private:
    std::vector<std::string> tipos;
    std::vector<std::vector<double>> matriz;
    std::unordered_map<std::string, int> indice;

public:
    Typeadv();
    std::string calculodano(std::string atacante, std::vector<std::string> atingido);
    double getMultiplicador(std::string atacante, std::vector<std::string> atingido);
};

#endif

