#ifndef MEDICO_H
#define MEDICO_H

#include "Persona.h"

class Medico : public Persona
{
protected:
    string specializzazione;
public:
    Medico();
    Medico(string name, string surname, string spec);
    virtual ~Medico();
    /*Deve essere puro o no?*/
    // O posso non scriverlo?
    virtual void leggi() = 0;
    virtual void stampa();
};

#endif