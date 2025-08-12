#include "Pokemon.h"
#include <vector>


//Sono il factotum della citta,
//tem uns 60 pokemons classificados por tipos e seus stats base (calculados depois)
//stats base sendo em ordem: hp, ataque fisico, defesa fisica, ataque especial, defesa especial, velocidade
//dei os moldes e pedi pro chat encher de pokemons aos poucos para que ainda haja controle de versão
//stats calculados não envolvem IVs, EVs, Naturezas ou habilidades (eu iria ficar maluco)
//inffelizmente tive que tirar os sprites dos pokemons acima da gen 2 por limitações visuais do terminal

std::vector<Pokemon> Pokedex = {
    //gen1
    Pokemon("Bulbasaur", 1, 45, 49, 49, 65, 65, 45, {"Grass", "Poison"}),
    Pokemon("Ivysaur", 1, 60, 62, 63, 80, 80, 60, {"Grass", "Poison"}),
    Pokemon("Venusaur", 1, 80, 82, 83, 100, 100, 80, {"Grass", "Poison"}),
    Pokemon("Charmander", 1, 39, 52, 43, 60, 50, 65, {"Fire"}),
    Pokemon("Charmeleon", 1, 58, 64, 58, 80, 65, 80, {"Fire"}),
    Pokemon("Charizard", 1, 78, 84, 78, 109, 85, 100, {"Fire", "Flying"}),
    Pokemon("Squirtle", 1, 44, 48, 65, 50, 64, 43, {"Water"}),
    Pokemon("Wartortle", 1, 59, 63, 80, 65, 80, 58, {"Water"}),
    Pokemon("Blastoise", 1, 79, 83, 100, 85, 105, 78, {"Water"}),
    Pokemon("Pikachu", 1, 35, 55, 40, 50, 50, 90, {"Electric"}),
    Pokemon("Raichu", 1, 60, 90, 55, 90, 80, 110, {"Electric"}),
    Pokemon("Arcanine", 1, 90, 110, 80, 100, 80, 95, {"Fire"}), // melhor pokemon 
    Pokemon("Machoke", 1, 80, 100, 70, 50, 60, 45, {"Fighting"}),
    Pokemon("Machamp", 1, 90, 130, 80, 65, 85, 55, {"Fighting"}),
    Pokemon("Gengar", 1, 60, 65, 60, 130, 75, 110, {"Ghost", "Poison"}),
    Pokemon("Haunter", 1, 45, 50, 45, 115, 55, 95, {"Ghost", "Poison"}),
    Pokemon("Arbok", 1, 60, 95, 69, 65, 79, 80, {"Poison"}),
    Pokemon("Dragonite", 1, 91, 134, 95, 100, 100, 80, {"Dragon", "Flying"}),
    Pokemon("Aerodactyl", 1, 80, 105, 65, 60, 75, 130, {"Rock", "Flying"}),
    Pokemon("Gyarados", 1, 95, 125, 79, 60, 100, 81, {"Water", "Flying"}),
    Pokemon("Vileplume", 1, 75, 80, 85, 110, 90, 50, {"Grass", "Poison"}),
    Pokemon("Alakazam", 1, 55, 50, 45, 135, 95, 120, {"Psychic"}),
    Pokemon("Jolteon", 1, 65, 65, 60, 110, 95, 130, {"Electric"}),
    Pokemon("Flareon", 1, 65, 130, 60, 95, 110, 65, {"Fire"}),
    Pokemon("Vaporeon", 1, 130, 65, 60, 110, 95, 65, {"Water"}),
    Pokemon("Snorlax", 1, 160, 110, 65, 65, 110, 30, {"Normal"}),
    Pokemon("Lapras", 1, 130, 85, 80, 85, 95, 60, {"Water", "Ice"}),
    
    // gen2
    Pokemon("Typhlosion", 1, 78, 84, 78, 109, 85, 100, {"Fire"}),
    Pokemon("Totodile", 1, 50, 65, 64, 44, 48, 43, {"Water"}),
    Pokemon("Feraligatr", 1, 85, 105, 100, 79, 83, 78, {"Water"}),
    Pokemon("Espeon", 1, 65, 65, 60, 130, 95, 110, {"Psychic"}),
    Pokemon("Umbreon", 1, 95, 65, 110, 60, 130, 65, {"Dark"}),
    Pokemon("Scizor", 1, 70, 130, 100, 55, 80, 65, {"Bug", "Steel"}),
    Pokemon("Houndoom", 1, 75, 90, 50, 110, 80, 95, {"Dark", "Fire"}),
    Pokemon("Crobat", 1, 85, 90, 80, 70, 80, 130, {"Poison", "Flying"}),
    Pokemon("Kingdra", 1, 75, 95, 95, 95, 95, 85, {"Water", "Dragon"}),
    Pokemon("Heracross", 1, 80, 125, 75, 40, 95, 85, {"Bug", "Fighting"}),


  
    /*lendarios*/
    Pokemon("Lugia", 1, 106, 90, 130, 90, 154, 110, {"Psychic", "Flying"}),
    Pokemon("Ho-Oh", 1, 106, 130, 90, 110, 154, 90, {"Fire", "Flying"}),
    Pokemon("Articuno", 1, 90, 85, 100, 95, 125, 85, {"Ice", "Flying"}),
    Pokemon("Zapdos", 1, 90, 90, 85, 125, 90, 100, {"Electric", "Flying"}),
    Pokemon("Moltres", 1, 90, 100, 90, 125, 85, 90, {"Fire", "Flying"}),
    Pokemon("Mewtwo", 1, 106, 110, 90, 154, 90, 130, {"Psychic"}),
    Pokemon("Entei", 1, 115, 115, 85, 90, 75, 100, {"Fire"}),
    Pokemon("Raikou", 1, 90, 85, 75, 115, 100, 115, {"Electric"}),
    Pokemon("Suicune", 1, 100, 75, 115, 90, 115, 85, {"Water"}),

};