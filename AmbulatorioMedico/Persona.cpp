#include "Persona.h"

Persona::Persona() {
    nome = "Undefined";
    cognome = "Undefined";
}
Persona::Persona(string name, string surname) {
    nome = name;
    cognome = surname;
}
Persona::~Persona() {

}
void Persona::setNome(string name) {
    nome = name;
}
void Persona::setCognome(string surname) {
    cognome = surname;
}
string Persona::getNome() {
    return nome;
}
string Persona::getCognome() {
    return cognome;
}