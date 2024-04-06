#include "stack.h"

/*
* Costruttore di default
*/
Stack::Stack(){
    top = nullptr;
}
/*
* Costruttore orientato ai parametri
*/
Stack::Stack(int element){
    top = new Node(element);
}
/*
* Costruttore copia
*/
Stack::Stack(const Stack& st){
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
Stack::~Stack(){ 
    Node *pdelete = top;
    while (pdelete) {
        top = top->getPtrNext();
        delete pdelete;
        pdelete = top;
    }
}
bool Stack::insertTail(int data) {
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
bool Stack::isEmpty(){
    if (top) {
        return false;
    }
    return true;
}
/*
* Metodo push
*/
bool Stack::push(int element){
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
bool Stack::pop(){
    Node *pCancel = top;
    if(!isEmpty()){
        cout << endl << top->getInfo();
        top = top->getPtrNext();
        delete pCancel;
        return true;
    }
    cout << endl << "Stack vuoto";
    return false;
}
/*
* Metodo getTop
*/
bool Stack::getTop(){
    if (isEmpty()){
        cout << top->getInfo() << endl;
        return true;
    }
    return false;
}

void scansione(Stack s) {
    Node *pTemp = s.top;
    while (pTemp) {
        cout << pTemp->getInfo() << endl;
        pTemp = pTemp->getPtrNext();
    }
}