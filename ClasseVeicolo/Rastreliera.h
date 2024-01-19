#ifndef RASTRELIERA_H
#define RASTRELIERA_H

#include "Bicicletta.h"

class Rastreliera
{
private:
    static int biciMax;
    int dim;
    Bicicletta* nBici;
public:
    Rastreliera();
    Rastreliera(int dim);
    ~Rastreliera();
    void operator++();
    void operator--();
};

#endif