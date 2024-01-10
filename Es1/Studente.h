#ifndef STUDENTE_H
#define STUDENTE_H
#include "Persona.h"

class Studente : public Persona
{
private:
    int matricola;
public:
    Studente();
    Studente(string n, string c, int m);
    ~Studente();
    void setAll(string n, string c, int m);
    void leggi(); //OVERRIDING
    void stampa(); //OVERRIDING
}; 

#endif