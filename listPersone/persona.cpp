#include "persona.h"

/*COSTRUTTORI*/
Persona::Persona() {
    nome = "Pippo";
    cognome = "Bauldo";
    nascita.today();
}
Persona::Persona(string nome, string cognome, Data nascita) {
    this->nome = nome;
    this->cognome = cognome;
    this->nascita = nascita;   
}
/*DISTRUTTORE*/
Persona::~Persona() {

}
/*GET*/
string Persona::getNome() {
    return nome;
}
string Persona::getCognome() {
    return cognome;
}
Data Persona::getNascita() {
    return nascita;
}
/*SET*/
void Persona::setNome(string nome) {
    this->nome = nome;
}
void Persona::setCognome(string cognome) {
    this->cognome  =cognome;
}
void Persona::setNascita(Data nascita) {
    this->nascita = nascita;
}
void Persona::setPersona(string nome, string cognome, Data nascita) {
    this->nome = nome;
    this->cognome = cognome;
    this->nascita = nascita;
}
/*CONFRONTO*/
bool Persona::operator==(const Persona& p) {
    bool flag = true;
    if (nome != p.nome || cognome != p.cognome || nascita != p.nascita) {
        flag = false;
    }
    return flag;
}
/*MAGGIORE*/
Persona Persona::operator>(Persona& p) {
    if (!(nascita > p.nascita)) {
        return *this;
    } else {
        return p;
    }
}
/*ASSEGNAZIONE*/
Persona Persona::operator=(const Persona& p) {
    nome = p.nome;
    cognome = p.cognome;
    nascita = p.nascita;
    return *this;
}
/*READ*/
istream& operator>>(istream& in, Persona& p) {
    cout << "Inserisci il tuo nome: ";
    in >> p.nome;
    cout << "Inserisci il tuo cognome: ";
    in >> p.cognome;
    cout << "Inserisci l'anno di nascita: " << endl;
    in >> p.nascita;
    return in;
}
/*PRINT*/
ostream& operator<<(ostream& out,  const Persona& p) {
    
    out << "Nome: " << p.nome << endl;
    out << "Cognome: " << p.cognome << endl;
    out << "Nascità: " << p.nascita << endl;
    return out;
}
/*ETA DI UNA PERSONA*/
int etaPersona(Persona& p) {
    Data d;
    return howDays(p.nascita, d) / 365;
}