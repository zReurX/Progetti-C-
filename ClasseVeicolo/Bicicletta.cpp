#include "Bicicletta.h"

Bicicletta::Bicicletta() {
    sporco = false;
    suono = "ding-dong";
}

Bicicletta::Bicicletta(bool sporco, float p, int v, string c) : Veicolo(p, 2, v, c) {
    this->sporco = sporco;
    suono = "ding-dong";
}
Bicicletta::Bicicletta(Bicicletta& b) {
    setAll(b.getPeso(), b.getRuote(), b.getVelocita(), b.getCodice());
    sporco = b.sporco;
    suono = b.suono;
}
Bicicletta::~Bicicletta() {

}
void Bicicletta::read() {
    cin >> (*this);
}
void Bicicletta::print() {
    cout << (*this);
}
void Bicicletta::suona() {
    cout << "Stai suonando il capanello: " << suono << endl;
}
void Bicicletta::frena() {
    cout << "Stai frenando" << endl;
    setVelocita(getVelocita() - 10);
}
void Bicicletta::pedala() {
    cout << "Stai pedalando" << endl;
    setVelocita(getVelocita() + 10);
}

ostream& operator<<(ostream& out, Bicicletta& b) {
    out << "Ruote: " << b.getRuote() << endl;
    out << "Velocita: " << b.getVelocita() << endl;
    out << "Peso: " << b.getPeso() << endl;
    out << "Codice: " << b.getCodice() << endl;
    out << (b.sporco ? "Sporca" : "Non sporca") << endl;
    return out;
}
istream& operator>>(istream& in, Bicicletta& b) {
    b.setRuote(2);
    string temp;
    float p;
    int v;
    cout << "Insersci il peso: ";
    do {
        in >> p;
    } while (p <= 0);
    b.setPeso(p);
    cout << "Insersci la velocita: ";
    do {
        in >> v;
    } while (v <= 0);
    b.setVelocita(v);
    cout << "Inserisci il codice: ";
    in >> temp;
    b.setCodice(temp);
    cout << "La bici e sporca?: ";
    do {
        in >> b.sporco;
    } while(b.sporco != 0 && b.sporco != 1);
    return in;
}