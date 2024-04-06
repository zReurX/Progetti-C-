#include "Nodo.h"

Nodo::Nodo(/* args */) {
    next = nullptr;
}
Nodo::Nodo(Snack sn) {
    s = sn;
    next = nullptr;
}
Nodo::Nodo(Snack sn, Nodo* n) {
    next = n;
    s = sn;
}
Nodo::~Nodo() {
    delete[] next;
}
Snack Nodo::getSnack() {
    return s;
}
Nodo* Nodo::getNext() {
    return next;
}   
void Nodo::setSnack(Snack sn) {
    s = sn;
}
void Nodo::setNext(Nodo* n) {
    next = n;
}
void Nodo::set(Snack sn, Nodo* n) {
    next = n;
    s = sn;
}