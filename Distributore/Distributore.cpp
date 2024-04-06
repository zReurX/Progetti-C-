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
Distributore::Distributore(int element){
    top = new Node(element);
}
/*
* Costruttore copia
*/
Distributore::Distributore(const Distributore& st){
    Node *pTemp = st.top;
    while (pTemp)
    {
        insertTail(pTemp->getInfo());
        pTemp = pTemp->getPtrNext();
    }
    
}
/*
* Distruttore
*/
Distributore::~Distributore(){ 
    Node *pdelete = top;
    while (pdelete) {
        top = top->getPtrNext();
        delete pdelete;
        pdelete = top;
    }
}
bool Distributore::insertTail(int data) {
    Node* pNew = new Node(data);
    if (!pNew) {
        cerr << "Allocazione fallita";
        return false;
    }
    if (isEmpty()) {
        top = pNew;
    } else {
        Node* pAux = top;
        while (pAux->getPtrNext() != nullptr) {
            pAux = pAux->getPtrNext();
        }
        pAux->setPtrNext(pNew);
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
bool Distributore::push(int element){
    Node *pNew = new Node(element);
    if(!pNew){
        cerr << "Allocazione fallita. " << endl;
        return false;
    }
    pNew->setPtrNext(top);
    top = pNew;
    return true;
}
/*
* Metodo pop
*/
bool Distributore::pop(){
    Node *pCancel = top;
    if(!isEmpty()){
        cout << endl << top->getInfo();
        top = top->getPtrNext();
        delete pCancel;
        return true;
    }
    cout << endl << "Distributore vuoto";
    return false;
}
/*
* Metodo getTop
*/
bool Distributore::getTop(){
    if (isEmpty()){
        cout << top->getInfo() << endl;
        return true;
    }
    return false;
}

void scansione(Distributore s) {
    Node *pTemp = s.top;
    while (pTemp) {
        cout << pTemp->getInfo() << endl;
        pTemp = pTemp->getPtrNext();
    }
}