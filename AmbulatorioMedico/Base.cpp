#include "Base.h"

int Base::nrMax = 500;

Base::Base() {
    dim = 0;
    p = nullptr;
}
Base::Base(const Base &b) {
    p = new Paziente[b.dim];
    for (int i = 0; i < b.dim; i++) {
        p[i] = b.p[i];
    }
}
Base::~Base() {
    delete[] p;
}
void Base::leggi() {
    string temp;
    cout << "Inserisci il nome: ";
    do {
        cin >> temp;
    } while (temp == "");
    setNome(temp);
    cout << "Inserisci il cognome: ";
    do {
        cin >> temp;
    } while (temp == "");
    setCognome(temp);
    cout << "Insersci la specializzazione: ";
    do {
        cin >> specializzazione;
    } while (specializzazione == "");
    cout << "Inserisci il numero di pazienti: ";
    do {
        cin >> dim;
    } while (dim <= 0 || dim > nrMax);
    delete[] p;
    p = new Paziente[dim];
    for (int i = 0; i < dim; i++) {
        p[i].leggi();
    }
}
void Base::stampa() {
    cout << "Nome: " << getNome() << endl;
    cout << "Cognome: " << getCognome() << endl;
    cout << "Specializzazione: " << specializzazione << endl;
    if (dim == 0) {
        cout << "Non ha pazienti";
    }
    for (int i = 0; i < dim; i++) {
        cout << "Paziente n" << i + 1 << ":" << endl;
        p[i].stampa();
    }
}
Base &Base::operator++() {
    Paziente *temp = new Paziente[dim];
    for (int i = 0; i < dim; i++) {
        temp[i] = p[i];
    }
    delete[] p;
    p = new Paziente[++dim];
    for (int i = 0; i < dim - 1; i++) {
        p[i] = temp[i];
    }
    p[dim - 1].leggi();
    return *this;
}
Base& Base::operator-(Paziente &paz) {
    int i = 0;
    while (i < dim && p[i].getCodFiscale() != paz.getCodFiscale()) {
        i++;
    }
    if (i < dim) {
        Paziente *temp = new Paziente[dim];
        for (int i = 0; i < dim; i++) {
            temp[i] = p[i];
        }
        for (int i = dim; i < dim - 1; i++) {
            temp[i] = temp[i + 1]; 
        }
        delete[] p;
        p = new Paziente[--dim];
        for (int i = 0; i < dim + 1; i++) {
            p[i] = temp[i];
        }
    }
    return *this;
}