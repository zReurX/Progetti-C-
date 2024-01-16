#include "Libro.h"

Libro::Libro() {
    ISBN = "Undefined";
}
Libro::Libro(string code) {
    ISBN = code; 
}
Libro::~Libro() {
    
}
void Libro::setISBN(string codice) {
    ISBN = codice;
}
string Libro::getISBN() {
    return ISBN;
}
void Libro::stampa() {
    cout << "ISBN: " << ISBN << endl;
}