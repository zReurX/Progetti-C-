#include "Snack.h"

Snack::Snack(/* args */) {
    name = "undefined";
    code = -1;
}
Snack::~Snack() {

}
void Snack::set(string n, int c) {
    name = n;
    code = c;
}
void Snack::setName(string n) {
    name = n;
}
void Snack::setCode(int c) {
    code = c;
}
string Snack::getName() {
    return name;
}
int Snack::getCode() {
    return code;
}
Snack Snack::operator=(Snack s) {
    name = s.name;
    code = s.code;
}
Snack Snack::operator=(int val) {
    code = val;
}
ostream& operator<<(ostream& out, Snack s) {
    out << s.name << s.code;
}
istream& operator>>(istream& in, Snack s) {
    cout << "Inserisci il codice: " << endl;
    in >> s.code;
    cout << "Inserisci il nome del prodotto: " << endl;
    in >> s.name;
}