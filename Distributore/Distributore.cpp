#include "Distributore.h"

/*
* Costruttore di default
*/
Distributore::Distributore(){
    top = nullptr;
}
/*
* Costruttore orientato ai parametri
*/
Distributore::Distributore(Snack element){
    top = new Nodo(element);
}
/*
* Costruttore copia
*/
Distributore::Distributore(const Distributore& st){
    Nodo *pTemp = st.top;
    while (pTemp)
    {
        insertTail(pTemp->getSnack());
        pTemp = pTemp->getNext();
    }
    
}
/*
* Distruttore
*/
Distributore::~Distributore(){ 
    Nodo *pdelete = top;
    while (pdelete) {
        top = top->getNext();
        delete pdelete;
        pdelete = top;
    }
}
bool Distributore::insertTail(Snack data) {
    Nodo* pNew = new Nodo(data);
    if (!pNew) {
        cerr << "Allocazione fallita";
        return false;
    }
    if (isEmpty()) {
        top = pNew;
    } else {
        Nodo* pAux = top;
        while (pAux->getNext() != nullptr) {
            pAux = pAux->getNext();
        }
        pAux->setNext(pNew);
    }
    return true;
}
/*
* Metodo isEmpty
*/
bool Distributore::isEmpty(){
    if (top) {
        return false;
    }
    return true;
}
/*
* Metodo push
*/
bool Distributore::push(Snack element){
    Nodo *pNew = new Nodo(element);
    if(!pNew){
        cerr << "Allocazione fallita. " << endl;
        return false;
    }
    pNew->setNext(top);
    top = pNew;
    return true;
}
void rifornimento(int numSnack) {
    Snack n;
    for (int i = 0; i < numSnack; i++) {
        cin >> n;
    }
}
/*
* Metodo pop
*/
Snack Distributore::pop(){
    Snack temp;
    if(!isEmpty()){
        cout << endl << top->getSnack();
        Nodo *pCancel = top;
        top = top->getNext();
        temp = pCancel->getSnack();
        delete pCancel;
    } else {
        cout << endl << "Distributore vuoto";
    }
    return temp;
}
int Distributore::erogazione(int soldi) {
    while (!isEmpty() && soldi > 0)
    {   
        cout << pop();
        soldi--;
    }
    return soldi;
    
}
/*
* Metodo getTop
*/
bool Distributore::getTop(){
    if (isEmpty()){
        cout << top->getSnack() << endl;
        return true;
    }
    return false;
}

void scansione(Distributore s) {
    Nodo *pTemp = s.top;
    while (pTemp) {
        cout << pTemp->getSnack() << endl;
        pTemp = pTemp->getNext();
    }
}