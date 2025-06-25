#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;


vector<string> Pokedex = {
        "Bulbasaur", "Charmander", "Squirtle", "Pidgey", "Rattata", "Pikachu", "Sandshrew",
        "Nidoran", "Vulpix", "Jigglypuff", "Zubat", "Oddish", "Paras", "Venonat", "Diglett",
        "Meowth", "Psyduck", "Machop", "Magnemite", "Gastly", "Onix", "Drowzee", "Krabby",
        "Voltorb", "Exeggcute", "Cubone", "Koffing", "Rhyhorn", "Horsea", "Staryu"
    };




/*se eu for usar stats incluindo pokemons da 3 gem em diante tem que ser special attack */
struct stats{
    int hp;
    int defesa;
    int ataque;
    int especialataq;
    int especialdefesa;
    int speed;

};


class Pokemon{
private:
    string nome;
    stats stats;    

public:
    Pokemon(string n, int hp, int atk, int def, int espa, int espd, int spd){
        nome = n; 
        stats.hp = hp;
        stats.ataque = atk;
        stats.defesa = def;
        stats.especialataq = espa;
        stats.especialdefesa = espd;
        stats.speed = spd;
    }

    void mostrarpkm(){
        cout<<"Pokemon: " << nome << endl;
        cout<<"hp: " << stats.hp << endl;
        cout<<"Ataque: " << stats.ataque << endl;
        cout<<"Defesa: " << stats.defesa << endl;
        cout<<"Ataque Especial: " << stats.especialataq << endl;
        cout<<"Defesa Especial: " << stats.especialdefesa << endl;
        cout<<"Velocidade: "<< stats.speed << endl;

    };

     void tomarDano(int dano) {
        stats.hp -= dano;
        if (stats.hp < 0) stats.hp = 0;
     };

};

bool Consulta(const vector<string>& pokedex, string nome){
        transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

        for(const auto& p : pokedex){
            string  nomePokedex = p;
            transform(nomePokedex.begin(), nomePokedex.end(), nomePokedex.begin(), ::tolower);

            if (nomePokedex == nome){
                return true;
            }
        }
        return false;
     }

     
