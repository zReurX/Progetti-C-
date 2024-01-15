#ifndef NAPOLETANO_H
#define NAPOLETANO_H

#include "MazzodiCarte.h"

class Napoletano : public MazzodiCarte
{
public:
    Napoletano();
    Napoletano(const Napoletano &n);
    ~Napoletano();
    void inizializza();
    Carta operator--();
    int numeroCarte();
};


#endif