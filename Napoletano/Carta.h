#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;


class Carta
{
private:
    string seme;
    string nome;
    int numero;
    int punteggio;
public:
    /*COSTRUTTORI*/
    Carta();
    Carta(string s, string nom, int num, int p);
    /*DISTRUTTORI*/
    ~Carta();
    /*SETTER*/
    void setSeme(string s);
    void setNome(string n);
    void setNumero(int n);
    void setPunteggio(int p);
    void setCarta(string s, string nom, int num, int p);
    /*CONFRONTA*/
    int confronta(Carta c2, Carta briscola);
    /*OVERLOADING*/
    int operator+(Carta c2);
    friend istream& operator>>(istream& in, Carta c1);
    friend ostream& operator<<(ostream& out, Carta c1);
};


#endif