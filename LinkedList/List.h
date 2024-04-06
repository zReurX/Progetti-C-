#ifndef LIST_H
#define LIST_H

#include "node.h"

class List
{
private:
    Node* head;
    void displayRec(Node* head);
    void swap(Node* pi, Node* pj);
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
    void ordina();
    /*Serve il costruttore copia
    List& operator+(List l1);*/
    /*Si puo modifica l'elemento*/
    List& operator+(List& l1);
    /*Non si puo modifica la lista
    List& operator+(List& l1);*/
    friend istream& operator>>(istream& in, List* l1);
    /*Fusione - merge*/
    friend List megaOrdinamento(List& l1, List& l2);
};


#endif