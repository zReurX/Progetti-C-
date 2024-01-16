#include "Libreria.h"

int Libreria::capienzaMax = 100;

Libreria::Libreria() {
    dim = 0;
    books = nullptr;
}
Libreria::~Libreria() {
    delete[] books;
}
void Libreria::leggi() {
    for (int i = 0; i < dim; i++) {
        books[i].leggi();
    }
}
int Libreria::ricerca(Romanzo book) {
    int i = 0;
    while (i < dim && books[i].getISBN() != book.getISBN()) {
        i++;
    }
    if (i < dim) {
        return i;
    } else {
        return -1;
    }
}
Libreria &Libreria::operator+(Romanzo book) {
    if (ricerca(book) != -1) {
        Romanzo *temp = new Romanzo[dim];
        for (int i = 0; i < dim; i++) {
            temp[i] = books[i];
        }
        delete[] books;
        books = new Romanzo[++dim];
        for (int i = 0; i < dim -1; i++) {
            books[i] = temp[i];
        }
        books[dim - 1] = book;
    }
    return *this;
}
Libreria &Libreria::operator--(int) {

}
Libreria &Libreria::operator!() {

}
ostream &operator<<(ostream &out, Romanzo book) {

}