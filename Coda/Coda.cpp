#include "Coda.h"

Coda::Coda(/* args */) {
    front = rear = nullptr;
    /* COmposizione forte
        
        front = new Node();
        rear = front;
        rear->setNext(front)
    
    */
}
Coda::Coda(const Coda &c) {

}
Coda::~Coda() {

}
bool Coda::insert(int element) {
    Node* pNew = new Node(element);
    if (!pNew) {
        cerr << "Allocazione fallita" << endl;
        return false;
    }
    rear->setPtrNext(pNew);
    pNew->setPtrNext(front);
    rear = pNew;

}

bool Coda::remove() {
    if (!isEmpty()) {
        if (front == rear) {
            //C'è solo un elemento
            delete front;
            rear = nullptr;
        } else {
            //Ci sono più elementi
            rear->setPtrNext(front->getPtrNext());
            delete front;
            front = rear->getPtrNext();
        }
    }
    return false;

}

bool Coda::isEmpty() {
    //return front || rear;
    if (front || rear) {
        return false;
    }
    return true;
}
int Coda::getFront() {
    if (!isEmpty()) {
        return front->getInfo();
    }
    cerr << "Coda vuota";
    return -1;
}
int Coda::getRear() {
    if (!isEmpty()) {
        return rear->getInfo();
    }
    cerr << "Coda vuota";
    return -1;
}