#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;



/*programando ouvindo 钢铁洪流进行曲  */
class moves {
    private:
    string nome;
    string tipo;
    int danobase;/*sem modificadores como tipo e ataque do pkm*/
    int pp;/*vezes que ele pode usar*/
    int accuracy;/*precisao 0-100*/
    string category;/* status, fisico ou especial*/


    public:
    /*construtor*/
    moves(string n , string t, int db, int pp, int a, string c)
       : nome(n), tipo(t), danobase(db), accuracy(a), category(c), pp(pp){}

       /*getters*/
       string getNome() const { return nome; }
       string getTipo() const { return tipo; }
       int getDanoBase() const { return danobase; }
       int getPP() const { return pp; }
       int getAccuracy() const { return accuracy; }
       string getCategory() const { return category; }

    void use() { pp--; } // Reduz PP ao usar o movimento
};

