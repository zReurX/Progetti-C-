#ifndef PAZIENTE_H
#define PAZIENTE_H

#include "Persona.h"
#include "data.h"

class Paziente : public Persona
{
private:
    Data nascita;
    string cf;
public:
    Paziente();
    Paziente(Data birthdate, string code);
    ~Paziente();
    string getCodFiscale();
    void leggi();
    void stampa();
};

#endif