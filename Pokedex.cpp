#include "Pokemon.h"
#include <vector>


std::vector<Pokemon> Pokedex = {
    // Geração 1
    Pokemon("Bulbasaur", 1, 45, 49, 49, 65, 65, 45),
    Pokemon("Ivysaur", 1, 60, 62, 63, 80, 80, 60),
    Pokemon("Venusaur", 1, 80, 82, 83, 100, 100, 80),

    Pokemon("Charmander", 1, 39, 52, 43, 60, 50, 65),
    Pokemon("Charmeleon", 1, 58, 64, 58, 80, 65, 80),
    Pokemon("Charizard", 1, 78, 84, 78, 109, 85, 100),

    Pokemon("Squirtle", 1, 44, 48, 65, 50, 64, 43),
    Pokemon("Wartortle", 1, 59, 63, 80, 65, 80, 58),
    Pokemon("Blastoise", 1, 79, 83, 100, 85, 105, 78),

    Pokemon("Pikachu", 1, 35, 55, 40, 50, 50, 90),
    Pokemon("Raichu", 1, 60, 90, 55, 90, 80, 110),

    Pokemon("Machop", 1, 70, 80, 50, 35, 35, 35),
    Pokemon("Machoke", 1, 80, 100, 70, 50, 60, 45),
    Pokemon("Machamp", 1, 90, 130, 80, 65, 85, 55),

    Pokemon("Gastly", 1, 30, 35, 30, 100, 35, 80),
    Pokemon("Haunter", 1, 45, 50, 45, 115, 55, 95),
    Pokemon("Gengar", 1, 60, 65, 60, 130, 75, 110),

    Pokemon("Articuno", 1, 90, 85, 100, 95, 125, 85),
    Pokemon("Zapdos", 1, 90, 90, 85, 125, 90, 100),
    Pokemon("Moltres", 1, 90, 100, 90, 125, 85, 90),

    // Geração 2
    Pokemon("Chikorita", 1, 45, 49, 65, 49, 65, 45),
    Pokemon("Bayleef", 1, 60, 62, 80, 63, 80, 60),
    Pokemon("Meganium", 1, 80, 82, 100, 83, 100, 80),

    Pokemon("Cyndaquil", 1, 39, 52, 43, 60, 50, 65),
    Pokemon("Quilava", 1, 58, 64, 58, 80, 65, 80),
    Pokemon("Typhlosion", 1, 78, 84, 78, 109, 85, 100),

    Pokemon("Totodile", 1, 50, 65, 64, 44, 48, 43),
    Pokemon("Croconaw", 1, 65, 80, 80, 59, 63, 58),
    Pokemon("Feraligatr", 1, 85, 105, 100, 79, 83, 78),

    Pokemon("Espeon", 1, 65, 65, 60, 130, 95, 110),
    Pokemon("Umbreon", 1, 95, 65, 110, 60, 130, 65),

    // Geração 3
    Pokemon("Treecko", 1, 40, 45, 35, 65, 55, 70),
    Pokemon("Grovyle", 1, 50, 65, 45, 85, 65, 95),
    Pokemon("Sceptile", 1, 70, 85, 65, 105, 85, 120),

    Pokemon("Torchic", 1, 45, 60, 40, 70, 50, 45),
    Pokemon("Combusken", 1, 60, 85, 60, 85, 60, 55),
    Pokemon("Blaziken", 1, 80, 120, 70, 110, 70, 80),

    Pokemon("Mudkip", 1, 50, 70, 50, 50, 50, 40),
    Pokemon("Marshtomp", 1, 70, 85, 70, 60, 70, 50),
    Pokemon("Swampert", 1, 100, 110, 90, 85, 90, 60),

    Pokemon("Gardevoir", 1, 68, 65, 65, 125, 115, 80),
    Pokemon("Aggron", 1, 70, 110, 180, 60, 60, 50),

    // Geração 4
    Pokemon("Turtwig", 1, 55, 68, 64, 45, 55, 31),
    Pokemon("Grotle", 1, 75, 89, 85, 55, 65, 36),
    Pokemon("Torterra", 1, 95, 109, 105, 75, 85, 56),

    Pokemon("Chimchar", 1, 44, 58, 44, 58, 44, 61),
    Pokemon("Monferno", 1, 64, 78, 52, 78, 52, 81),
    Pokemon("Infernape", 1, 76, 104, 71, 104, 71, 108),

    Pokemon("Piplup", 1, 53, 51, 53, 61, 56, 40),
    Pokemon("Prinplup", 1, 64, 66, 68, 81, 76, 50),
    Pokemon("Empoleon", 1, 84, 86, 88, 111, 101, 60),

    // Lendários adicionais
    Pokemon("Regice", 1, 80, 50, 100, 100, 200, 50),
    Pokemon("Registeel", 1, 80, 75, 150, 75, 150, 50),

    // Geração 6
    Pokemon("Froakie", 1, 41, 56, 40, 62, 44, 71),
    Pokemon("Frogadier", 1, 54, 63, 52, 83, 56, 97),
    Pokemon("Greninja", 1, 72, 95, 67, 103, 71, 122),

    Pokemon("Sylveon", 1, 95, 65, 65, 110, 130, 60),
    Pokemon("Goodra", 1, 90, 100, 70, 110, 150, 80)
};



/* Sono il factotum della città*/