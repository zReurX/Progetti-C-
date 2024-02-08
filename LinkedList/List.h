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
    bool insertHead(int data);
    bool insertTail(int data);
    bool remove(int data);
};


#endif