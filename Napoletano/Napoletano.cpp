#include "Napoletano.h"
#include <ctime>


Napoletano::Napoletano() {
    inizializza();
}
Napoletano::Napoletano(const Napoletano &n) {

}
Napoletano::~Napoletano() {}
void Napoletano::inizializza() {
    string nomi[] = {"Asso", "2", "3", "4", "5", "6", "7", "Fante", "Cavallo", "Re"};
    int punteggi[] = {11, 0, 10, 0, 0, 0, 0, 2, 3, 4};
    delete[] c;
    dim = 40;
    c = new Carta[dim];
    for (int i = 0; i < dim; i++) {
        int pos = i % 10;
        if (i < 10) {
            c[i].setCarta("spade", nomi[pos], pos + 1, punteggi[pos]);
        } else if (i < 20) {
            c[i].setCarta("bastoni", nomi[pos], pos + 1, punteggi[pos]);
        } else if (i < 30) {
            c[i].setCarta("denari", nomi[pos], pos + 1, punteggi[pos]);
        } else {
            c[i].setCarta("coppe", nomi[pos], pos + 1, punteggi[pos]);
        }
    }
}
Carta Napoletano::operator--() {
    srand(time(NULL));
    int pos = rand() % dim;
    Carta estratta = c[pos];
    Carta* temp = new Carta[dim];
    for (int i = 0; i < dim; i++) {
        temp[i] = c[i];
    }
    for (int i = pos; i < dim - 1; i++) {
        temp[i] = temp[i + 1];
    }
    delete[] c;
    c = new Carta[--dim];
    for (int i = 0; i < dim + 1; i++) {
        c[i] =  temp[i];
    }

    return estratta;
}
int Napoletano::numeroCarte() {
    return dim;
}