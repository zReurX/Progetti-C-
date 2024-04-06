#ifndef LIST_H
#define LIST_H

#include "node.h"

class List
{
private:
    Node* head;
    void displayRec(Node* head);
public:
    List();
    List(List &lista);
    ~List();
    // Node* getHead();
    void displayHelper();
    bool isEmpty();
    void display(); //scansione della lista
    bool insertHead(Persona data);
    bool insertTail(Persona data);
    bool remove(Persona data);
    Persona giovane();
    Node* ricerca(string n, string c);
};


#endif