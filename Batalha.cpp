#include "Batalha.h"
#include <iostream>

Batalha::Batalha(Pokemon* jogador1, Pokemon* jogador2){
    p1 = jogador1;
    p2 = jogador2;
    int turno = 1;

}


void Batalha::iniciar() {
    cout << "Batalha iniciada entre " << p1->getNome() << " e " << p2->getNome() << "!" << endl;
    status();
}



#endif