#include "Studente.h"

Studente::Studente()
{
    matricola = 0;
    cout << "Costuttore studente" << endl;
}

Studente::Studente(string n, string c, int m) : Persona(n, c)
{
    // Persona::setAll(n, c);
    
    matricola = m;
    if (matricola <= 0)
    {
        matricola = 0;
    }
    cout << "Costuttore con parametri studente" << endl;
}

Studente::~Studente()
{
    cout << "Distruttore studente" << endl;
}

void Studente::setAll(string n, string c, int m)
{
    Persona::setAll(n, c);
    matricola = m;
    if (matricola <= 0)
    {
        matricola = 0;
    }
}

void Studente::leggi()
{
    Persona::leggi();
    cout << "Inserisci la matricola: ";
    do
    {
        cin >> matricola;
    } while (matricola <= 0);
}

void Studente::stampa()
{
    Persona::stampa();
    cout << "Matricola: " << matricola << endl;
}