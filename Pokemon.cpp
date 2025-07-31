#include "Pokemon.H"
#include <iostream>
#include <string>

using namespace std;

Pokemon::Pokemon(string n, int hp, int atk, int def, int espa, int espd, int spd ) {
    nome = n; 
    stats.hp = hp;
    stats.ataque = atk;
    stats.defesa = def;
    stats.especialataq = espa;
    stats.especialdefesa = espd;
    stats.speed = spd;
}

void Pokemon::mostrar (){
    cout<<"Pokemon: " << nome << endl;
    cout<<"hp: " << stats.hp << endl;
    cout<<"Ataque: " << stats.ataque << endl;
    cout<<"Defesa: " << stats.defesa << endl;
    cout<<"Ataque Especial: " << stats.especialataq << endl;
    cout<<"Defesa Especial: " << stats.especialdefesa << endl;
    cout<<"Velocidade: "<< stats.speed << endl;
}

void