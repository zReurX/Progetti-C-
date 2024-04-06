#ifndef DISTRIBUTORE_H
#define DISTRIBUTORE_H

#include "Nodo.h"

class Distributore {
    private:
        Nodo *top; //Puntatore al top (testa) dello stack
        bool insertTail(Snack data);
    public:
        Distributore();
        Distributore(Snack element);
        Distributore(const Distributore& st);
        ~Distributore();
        bool push(Snack element);
        void rifornimento(Snack numSnack);
        Snack pop();
        int erogazione(int soldi);
        bool getTop();
        bool isEmpty();
    friend void scansione(Distributore s); 
};

#endif