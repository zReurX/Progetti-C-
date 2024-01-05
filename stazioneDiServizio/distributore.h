#ifndef DISTRIBUTORE_H
#define DISTRIBUTORE_H

#include "iostream"
using namespace std;

class Distributore
{
private:
    string typeCarb;
    double prezzo;
    double litri;
    double maxLitri;

public:
    /*COSTRUTTORI*/
    Distributore();
    Distributore(string tC, double p, double l, double mL);
    /*DISTRUTTORI*/
    ~Distributore();
    /*GET*/
    string getType();
    double getPrezzo();
    double getLitri();
    double getMaxLitri();
    /*SET*/
    void setType(string tC);
    void setPrezzo(double p);
    void setLitri(double l);
    void setMaxLitri(double mL);
    void steDistributore(string tC, double p, double l, double mL);
    /*PRINT*/
    void print();
    /*READ*/
    void read();
    /*OVERLOADING MENO*/
    Distributore operator-(double euro);
};

#endif