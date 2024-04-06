#ifndef NODE_H
#define NODE_H

#include "Snack.h"

class Nodo
{
private:
    Snack s;
    Nodo* next;
public:
    Nodo(/* args */);
    Nodo(Snack sn);
    Nodo(Snack sn, Nodo* n);
    ~Nodo();
    Snack getSnack();
    Nodo* getNext();
    void setSnack(Snack s);
    void setNext(Nodo* n);
    void set(Snack s, Nodo* n);
};


#endif