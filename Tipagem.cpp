#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <unordered_map>
using namespace std;

/* função que vai definir os tipos de cada pokemon e que vai puxar a tabela de tipos do jogo*/
/*bora fazer os negocio de poo, ja que tamo sem oq fazer*/

class Typeadv{
private:
    vector<string> tipos;
    vector<vector<double>> matriz;
    unordered_map<string, int> indice;


public:
    Typeadv(){
         tipos = {"Normal", "Fire", "Water", "Electric", "Grass", "Ice", "Fight", "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost", "Dragon"};
    }
    vector<vector<double>> matriz_ef = {
    {1,1,1,1,1,1,1,1,1,1,1,0.5,0,1},/*normal*/ 
    {1, 0.5, 0.5, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5},/*fogo*/ 
    {1,2,0.5,1,0.5,1,1,1,2,1,1,1,2,1,0.5},/*agua*/ 
    {1,1,2,0.5,0.5,1,1,1,0,2,1,1,1,1,0.5},/*eletrico*/ 
    {1,0.5,2,1,0.5,1,1,0.5,2,0.5,1,0.5,2,1,0.5},/*grama*/ 
    {1,0.5,0.5,1,2,0.5,1,1,2,2,1,1,1,1,2},/*gelo*/ 
    {2,1,1,1,1,2,1,0.5,1,0.5,0.5,2,0,1}, /*luta*/ 
    {1,1,1,1,2,1,1,0.5,0.5,1,1,1,0.5,0.5,1},/*Veneno*/
    {1,2,1,2,0.5,1,1,2,1,0,1,0.5,2,1,1},/*ground*/
    {1,1,1,0.5,2,1,2,1,1,1,1,2,0.5,1,1},/*voador*/
    {1,1,1,1,1,1,2,2,1,1,0.5,1,1,1,1},/*Psychic*/
    {1,0.5,1,1,2,1,0.5,0.5,1,0.5,2,1,1,0.5,1},/*Bug*/
    {1,2,1,1,1,2,0.5,1,0.5,2,1,2,1,1,1},/*rock*/
    {0,1,1,1,1,1,1,1,1,1,2,1,1,2,1},/*ghost*/
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},/*Dragon*/
    };
    for (int i = 0 ; i < tipos.size(); i++){
        indice[tipos[i]] = i;
        }
    };

};

int mian