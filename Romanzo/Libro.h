#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
using namespace std;

class Libro
{
protected:
    string ISBN;
public:
    Libro();
    Libro(string code);
    virtual ~Libro();
    void setISBN(string codice);
    string getISBN();
    virtual void leggi() = 0;
    virtual void stampa();
};


#endif