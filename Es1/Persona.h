#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;


class Persona
{
private:
    string nome, cognome;
public:
    Persona();
    Persona(string n, string c);
    ~Persona();
    void setAll(string n, string c);
    void leggi();
    void stampa();
};




#endif