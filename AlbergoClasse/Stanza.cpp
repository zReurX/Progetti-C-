#include "Stanza.h"

Stanza::Stanza() {
    stato = true;
    mq = 0;
    numero = 0;
    piano = 0;

}
Stanza::~Stanza() {

}
/*SETTER*/
void Stanza::setNumero(int n) {
    numero = n;
    if (numero < 0) {
        numero = 0;
    }
}
void Stanza::setPiano(int p) {
    piano = p;
    if (piano < 0) {
        piano = 0;
    }
}
void Stanza::setMq(float m) {
    mq = m;
    if (mq < 0) {
        mq = 0;
    }
}
void Stanza::setStato(bool s) {
    stato = s;
}
void Stanza::setAll(int n, int p, float m, bool s) {
    numero = n;
    if (numero < 0) {
        numero = 0;
    }
    piano = p;
    if (piano < 0) {
        piano = 0;
    }
    mq = m;
    if (mq < 0) {
        mq = 0;
    }
    stato = s;
}
/*GETTER*/
int Stanza::getNumero() {
    return numero;
}
int Stanza::getPiano() {
    return piano;
}
float Stanza::getMq() {
    return mq;
}
bool Stanza::getStato() {
    return stato;
}
/*OVERLOADING*/
ostream &operator<<(ostream &out, const Stanza &room) {
    out << "Numero: " << room.numero << endl;
    out << "Piano: " << room.piano << endl;
    out << "Metri quadri: " << room.mq << endl;
    room.stato ? out << "Libera" : out << "Occupata";
    // out << (room.stato ? "Libera" : "Occupata");
    return out;
}
istream &operator>>(istream &in, Stanza &room) {
    cout << "Inserisci il numero: ";
    do {
        in >> room.numero;
    } while (room.numero <= 0); 
    cout << "Inserisci il piano: ";
    do {
        in >> room.piano;
    } while (room.piano <= 0);
    cout << "Inserisci i metri qudri: ";
    do {
        in >> room.mq;
    } while (room.mq <= 0); 
    cout << "La stanza e libera?: ";
    int st;
    do {
        in >> st;
    } while (st != 0 && st != 1);
    room.stato = st;
    return in;
}