#include "Medico.h"

Medico::Medico() {
    specializzazione = "Undefined";
}
Medico::Medico(string name, string surname, string spec) : Persona(name, surname) {
    specializzazione = spec;
}
Medico::~Medico() {

}
void Medico::stampa() {
    cout << "Nome: " << getNome() << endl;
    cout << "Cognome: " << getCognome() << endl;
    cout << "Specializzazione: " << specializzazione << endl;
}