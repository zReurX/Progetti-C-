#ifndef VEICOLO_H
#define VEICOLO_H

#include <iostream>
using namespace std;

class Veicolo
{
private:
    float peso;
    int ruote, velocita;
    string cod;
public:
    Veicolo();
    Veicolo(float peso, int ruote, int velocita, string cod);
    Veicolo(const Veicolo& v);
    virtual ~Veicolo();
    /*SET*/
    void setAll(float peso, int ruote, int velocita, string cod);
    void setPeso(float peso);
    void setRuote(int ruote);
    void setVelocita(int velocita);
    void setCodice(string cod);
    /*GET*/
    string getCodice();
    int getRuote();
    int getVelocita();
    float getPeso();
    /*ALTRO*/
    virtual void read() = 0;
    virtual void print() = 0;
    virtual void frena() = 0;
};

#endif