#ifndef STANZA_H
#define STANZA_H

#include <iostream>
using namespace std;

class Stanza
{
private:
    int numero, piano;
    float mq;
    bool stato;
public:
    Stanza();
    ~Stanza();
    /*SETTER*/
    void setNumero(int n);
    void setPiano(int p);
    void setMq(float m);
    void setStato(bool s);
    void setAll(int n, int p, float m, bool s);
    /*GETTER*/
    int getNumero();
    int getPiano();
    float getMq();
    bool getStato();
    /*OVERLOADING*/
    friend ostream& operator<<(ostream& out, const Stanza& s);
    friend istream& operator>>(istream& in, Stanza& s);
};

#endif