#ifndef DISTRIBUTORE_H
#define DISTRIBUTORE_H

#include "node.h"

class Distributore {
    private:
        Node *top; //Puntatore al top (testa) dello stack
        bool insertTail(int data);
    public:
        /*
        * Costruttore di default
        * ------------------------------------------------------------
        * Crea uno stack vuoto: il puntatore al top viene settato
        * a nullptr.
        */
        Distributore();
        /*
        * Costruttore orientato i parametri
        * ------------------------------------------------------------
        * Crea uno stack con un solo nodo, quello al top, e puntatore
        * al nodo successivo a nullptr.
        * Se l'allocazione fallisce viene visualizzato un messaggio di
        * errore.
        */
        Distributore(int element);
        /*
        * Costruttore copia
        * ------------------------------------------------------------
        * Crea un’istanza di Stack con valori uguali e nello stesso
        * ordine di un’altra istanza.
        */
        Distributore(const Distributore& st);
        /*
        * Distruttore
        * --------------------------------------------------------------
        * Distruttore dell'istanza di un oggetto di tipo Stack.
        */
        ~Distributore();
        /*
        * Metodo: push
        * --------------------------------------------------------------
        * Esegue l'inserimento di un nuovo nodo in testa allo stack.
        * Richiede come parametro l’informazione, di tipo intero, da
        * memorizzare nel nuovo nodo e ritorna true se l'inserimento è
        * avvenuto correttamente, false altrimenti.
        */
        bool push(int element);
        /*
        * Metodo: pop
        * --------------------------------------------------------------
        * Esegue l'eliminazione del nodo in testa allo stack.
        * Restituisce true se la cancellazione è avvenuta correttamente,
        * false altrimenti.
        */
        bool pop();
        /*
        * Metodo: getTop
        * -----------------------------------------------------------
        * Visualizza il contenuto informativo del nodo alla testa dello
        * stack, se non è vuoto. In tal caso restituisce true,
        * false altrimenti
        */
        bool getTop();
        /*
        * Metodo: isEmpty
        * -----------------------------------------------------------
        * Restituisce true se lo stack è vuoto, false altrimenti
        */
        bool isEmpty();
    friend void scansione(Distributore s); 
};


#endif