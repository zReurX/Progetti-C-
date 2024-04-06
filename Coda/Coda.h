#ifndef CODA_H
#define CODA_H

#include "node.h"

class Coda
{
private:
    Node* front;
    Node* rear;
public:
    Coda(/* args */);
    Coda(const Coda &c);
    ~Coda();
    bool insert(int element);
    bool remove();
    bool isEmpty();
    int getFront();
    int getRear();
    
};


#endif
