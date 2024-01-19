#include "Albergo.h"

int main() {
    Albergo a1;
    a1.inizializza();
    --a1;
    !a1;
    a1.stanzeLibere();
    float p = a1 * 3;
    p = 3 * a1;
    return 0;
}