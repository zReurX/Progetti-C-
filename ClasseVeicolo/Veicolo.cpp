#include "Veicolo.h"

Veicolo::Veicolo() {
    peso = 0;
    velocita = 0;
    ruote = 0;
    cod = "";
    
}
Veicolo::Veicolo(float peso, int ruote, int velocita, string cod) {
    this->peso = peso < 0 ? 0 : peso;
    this->ruote = ruote < 0 ? 0 : ruote;
    this->velocita = velocita < 0 ? 0 : velocita;
    this->cod = cod;
}
Veicolo::Veicolo(const Veicolo &v) {
    peso = v.peso;
    ruote = v.ruote;
    velocita = v.velocita;
    cod = v.cod;
}
Veicolo::~Veicolo() {

}
/*SET*/
void Veicolo::setAll(float peso, int ruote, int velocita, string cod) {
    this->peso = peso < 0 ? 0 : peso;
    this->ruote = ruote < 0 ? 0 : ruote;
    this->velocita = velocita < 0 ? 0 : velocita;
    this->cod = cod;
}
void Veicolo::setPeso(float peso) {
    this->peso = peso < 0 ? 0 : peso;
}
void Veicolo::setRuote(int ruote) {
    this->ruote = ruote < 0 ? 0 : ruote;
}
void Veicolo::setVelocita(int velocita) {
    this->velocita = velocita < 0 ? 0 : velocita;
}
void Veicolo::setCodice(string cod) {
    this->cod = cod;
}
/*GET*/
string Veicolo::getCodice() {
    return cod;
}
int Veicolo::getRuote() {
    return ruote;
}
int Veicolo::getVelocita() {
    return velocita;
}
float Veicolo::getPeso() {
    return peso;
}