#ifndef ROMANZO_H
#define ROMANZO_H

#include "Libro.h"

class Romanzo : public Libro
{
private:
    string autore;
    string titolo;
    float prezzo;
public:
    Romanzo();
    Romanzo(string code, string author, string title, float price);
    ~Romanzo();
    /*SET*/
    void setAutore(string author);
    void setTitolo(string title);
    void setPrezzo(float price);
    void setAll(string code, string author, string title, float price);
    /*GET*/
    string getAutore();
    string getTitolo();
    float getPrezzo();
    void leggi();
    bool operator!=(Romanzo book);
    friend ostream& operator<<(ostream& out, Romanzo book);
};


#endif