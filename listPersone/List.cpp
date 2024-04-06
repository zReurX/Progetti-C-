#include "List.h"

List::List() {
    head = nullptr;
}
List::List(List &lista) {
    head = nullptr;
    Node* pAux = lista.head;
    while (pAux != nullptr) {
        insertTail(pAux->getInfo());
        pAux = pAux->getPtrNext();
    }
}
List::~List() {
    Node* pCancel = head;
    while (head != nullptr) {
        head = head->getPtrNext();
        delete pCancel;
        pCancel = head;
    }

    /*non va bene consiglio di patrire da head*/
    // while (pCancel != nullptr) {
    //     pCancel = pCancel->getPtrNext();
    //     delete head;
    //     head = pCancel;
    // }
}
bool List::isEmpty() {
    return !head ? true : false;
}
void List::display() {
    Node* pAux = head;
    if (isEmpty()) {
        cout << "Lista vuota" << endl;
    } else {
        while (pAux != nullptr) {
            cout << pAux->getInfo();
            pAux = pAux->getPtrNext();
        }
    }
    
} //scansione della list
bool List::insertHead(Persona data) {
    Node* pNew = new Node(data, head);
    if (!pNew) {
        cerr << "Allocazione fallita";
        return false;
    }
    head = pNew;
    return true;
}

bool List::insertTail(Persona data) {
    Node* pNew = new Node(data);
    if (!pNew) {
        cerr << "Allocazione fallita";
        return false;
    }
    if (isEmpty()) {
        head = pNew;
    } else {
        Node* pAux = head;
        while (pAux->getPtrNext() != nullptr) {
            pAux = pAux->getPtrNext();
        }
        pAux->setPtrNext(pNew);
    }
    return true;
}

void List::displayRec(Node* head) {
    if (head != nullptr) {
        //Passo
        cout << " " << head->getInfo();
        displayRec(head->getPtrNext());
    }
    //Base: lista vuota
}

void List::displayHelper() {
    displayRec(head);
}

// Node* List::getHead() {
//     return head;
// }

bool List::remove(Persona data) {
    bool flag = false;
    if (!isEmpty()) {
        Node* pCancel;
        if (data == head->getInfo()) {
            pCancel = head;
            head = head->getPtrNext();
            delete pCancel;
            flag = true;
        } else {
            Node* pCurrent;
            pCancel = head->getPtrNext();
            pCurrent = head;
            while (pCancel != nullptr && pCurrent->getInfo() != data) {
                pCancel = pCancel->getPtrNext();
                pCurrent = pCurrent->getPtrNext();
            }
            if (pCancel != nullptr) {
                pCurrent->setPtrNext(pCancel->getPtrNext());
                delete pCancel;
                flag = true;
            }
        }
    }
    return flag;
}

Persona List::giovane() {
    Persona temp;
    if (!isEmpty()) {
        Node* pMin = head;
        Node* pAux = head->getPtrNext();
        while (pAux != nullptr) {
            if (pMin->getInfo().p() > pAux->getInfo().getNascita()) {
                pMin = pAux;
            }
            pAux = pAux->getPtrNext();
        }
        temp = pMin->getInfo();
    } else {
        cout << "Lista vuote";
    }
    return temp;
}

Node* List::ricerca(string n, string c) {
    Node* pAux;
    while (pAux != nullptr && (pAux->getInfo().getNome() != n || pAux->getInfo().getCognome() != c)) {
        pAux = pAux->getPtrNext();
    }
    return pAux;
}