#include "Romanzo.h"

Romanzo::Romanzo() {
    autore = "Undefined";
    titolo = "Undefined";
    prezzo = 0;
}
Romanzo::Romanzo(string code, string author, string title, float price) {
    ISBN = code;
    autore = author;
    titolo = title;
    prezzo = price;
    if (prezzo < 0) {
        prezzo = 0;
    }
}
Romanzo::~Romanzo() {

}
/*SET*/
void Romanzo::setAutore(string author) {
    autore = author;
}
void Romanzo::setTitolo(string title) {
    titolo = title;
}
void Romanzo::setPrezzo(float price) {
    prezzo = price;
    if (prezzo < 0) {
        prezzo = 0;
    }
}
void Romanzo::setAll(string code, string author, string title, float price) {
    ISBN = code;
    autore = author;
    titolo = title;
    prezzo = price;
    if (prezzo < 0) {
        prezzo = 0;
    }
}
/*GET*/
string Romanzo::getAutore() {
    return autore;
}
string Romanzo::getTitolo() {
    return titolo;
}
float Romanzo::getPrezzo() {
    return prezzo;
}
void Romanzo::leggi() {
    cout << "Inserisci ISBN: ";
    do {
        cin >> ISBN;
    } while(ISBN == "");
    cout << "Inserisci autore: ";
    do {
        cin >> autore;
    } while(autore == "");
    cout << "Inserisci titolo: ";
    do {
        cin >> titolo;
    } while(titolo == "");
    cout << "Inserisci il prezzo: ";
    do {
        cin >> prezzo;
    } while (prezzo <= 0);
}
bool Romanzo::operator!=(Romanzo book) {
    if (ISBN != book.ISBN && autore != book.autore && titolo != book.titolo && prezzo != book.prezzo) {
        return true;
    } else {
        return false;
    }
}
ostream& operator<<(ostream &out, Romanzo book) {
    out << book.ISBN;
    out << book.autore;
    out << book.titolo;
    out << book.prezzo;
    return out;
}