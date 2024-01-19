#include "Rastreliera.h"

int Rastreliera::biciMax = 100;

Rastreliera::Rastreliera() {
    dim = 0;
    nBici = nullptr;
}
Rastreliera::Rastreliera(int dim) {
    this->dim = (dim < 0 || dim > biciMax) ? 0 : dim;
    dim != 0 ? nBici = new Bicicletta[dim] : nBici = nullptr;
}
Rastreliera::~Rastreliera() {
    delete[] nBici;
}
void Rastreliera::operator++() {
    Bicicletta *temp = new Bicicletta[dim];
    for (int i = 0; i < dim; i++) {
        temp[i] = nBici[i];
    }
    delete[] nBici;
    nBici = new Bicicletta[++dim];
    for (int i = 0; i < dim - 1; i++) {
        nBici[i] = temp[i];
    }
    cin >> nBici[dim - 1];
}
void Rastreliera::operator--() {
    Bicicletta *temp = new Bicicletta[dim];
    for (int i = 0; i < dim; i++) {
        temp[i] = nBici[i];
    }
    delete[] nBici;
    nBici = new Bicicletta[--dim];
    for (int i = 0; i < dim; i++) {
        nBici[i] = temp[i];
    }
}