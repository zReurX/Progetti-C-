#include "Paziente.h"

Paziente::Paziente() {
    cf = "Undefined";
}
Paziente::Paziente(Data birthdate, string code) {
    nascita = birthdate;
    cf = code;
}
Paziente::~Paziente() {

}
string Paziente::getCodFiscale() {
    return cf;
}
void Paziente::leggi() {
    nascita.readData();
    cout << "Inserisci il codice fiscale: ";
    cin >> cf;
}
void Paziente::stampa() {
    nascita.printData();
    cout << "Codice fiscale: " << cf << endl;
}