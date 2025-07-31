#include "Pokemon.H"
#include <iostream>
#include <string>

using namespace std;

Pokemon::Pokemon(string n, int level, int hp, int atk, int def, int espa, int espd, int spd ) {
    nome = n; 
    lvl = level; // Default 
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

void Pokemon::calculostats(){
    //define os status de um pokemon de acordo com o level selecionado aleatóriamente (range 80-100 )
    stats.hp = (2 * stats.hp * lvl) / 100 + lvl + 10;
    stats.ataque = (2 * stats.ataque * lvl) / 100 + 5;
    stats.defesa = (2 * stats.defesa * lvl) / 100 + 5;
    stats.especialataq = (2 * stats.especialataq * lvl) / 100 + 5;
    stats.especialdefesa = (2 * stats.especialdefesa * lvl) / 100 + 5;
    stats.speed = (2 * stats.speed * lvl) / 100 + 5;


}
