#include "Albergo.h"
float Albergo::costoU = 100;
Albergo::Albergo() {
    dim = 0;
    s = nullptr;
}
Albergo::~Albergo() {
    delete[] s;
}
void Albergo::inizializza() {
    cout << "Inserisci l'indirizzo dell'immobile: ";
    cin >> indirizzo;
    cout << "Inserisci il numero delle stanze: ";
    do {
        cin >> dim;
    } while(dim <= 0);
    delete[] s;
    s = new Stanza[dim];
    for (int i = 0; i < dim; i++) {
        cin >> s[i];
        s[i].setStato(true);
    }
}
Stanza Albergo::operator--() {
    int pos = 0;
    while (pos < dim && s[pos].getStato() != true) {
        pos++;
    }
    Stanza s1;
    if (pos < dim) {
        Stanza *temp = new Stanza[dim];
        Stanza s1 = s[pos];
        for (int i = 0; i < dim; i++) {
            temp[i] = s[i];
        }
        for (int i = pos; i < dim - 1; i++) {
            temp[i] = temp[i + 1];
        }
        delete[] s;
        s = new Stanza[--dim];
        for (int i = 0; i < dim + 1; i++) {
            s[i] = temp[i];
        }
    }
    return s1;
}
float Albergo::operator!() {
    float dimCompl = 0;
    for (int i = 0; i < dim; i++) {
        dimCompl += s[i].getMq();
    }
    return dimCompl;
}
int Albergo::stanzeLibere() {
    int libere = 0;
    for (int i = 0; i < dim; i++) {
        s[i].getStato() == true && ++libere;
    }
    return libere;
}
float Albergo::operator*(int piano) {
    int i = 0;
    while (i < dim && s[i].getPiano() != piano && s[i].getStato() != true) {
        i++;
    }
    if (i < dim) {
        s[i].setStato(false);
        return costoU;
    }
    return -1;
}
float operator*(int piano, Albergo &a) {
    int i = 0;
    while (i < a.dim && a.s[i].getPiano() != piano && a.s[i].getStato() != true) {
        i++;
    }
    if (i < a.dim) {
        a.s[i].setStato(false);
        return a.costoU;
    }
    return -1;
}