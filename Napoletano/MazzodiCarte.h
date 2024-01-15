#ifndef MAZZODICARTE_H
#define MAZZODICARTE_H

#include "Carta.h"

class MazzodiCarte
{
protected:
    Carta *c;
    int dim;
public:
    MazzodiCarte();
    virtual ~MazzodiCarte();
    virtual void inizializza() = 0;
};


#endif
