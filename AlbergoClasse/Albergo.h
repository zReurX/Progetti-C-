#ifndef ALBERGO_H
#define ALBERGO_H

#include "Immobile.h"
#include "Stanza.h"

class Albergo : public Immobile
{
private:
    static float costoU;
    Stanza *s;
    int dim;
public:
    Albergo();
    ~Albergo();
    void inizializza();
    Stanza operator--();
    float operator!();
    int stanzeLibere();
    float operator*(int piano);
    friend float operator*(int piano, Albergo &a);
};

#endif