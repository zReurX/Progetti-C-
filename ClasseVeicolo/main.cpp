#include "Bicicletta.h"

int main() {
    Veicolo *v = new Bicicletta();
    v->read();
    v->print();
    return 0;
}