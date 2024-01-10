#include "Persona.h"

Persona::Persona()
{
    nome = "Ponzio";
    cognome = "Pelato";
    cout << "Prova construttore" << endl;
}

Persona::Persona(string n, string c)
{
    nome = n;
    cognome = c;
    cout << "Prova construttore con parametri" << endl;
}

Persona::~Persona()
{
    cout << "Prova distruttore" << endl;
}

void Persona::setAll(string n, string c)
{
    nome = n;
    cognome = c;
}

void Persona::leggi()
{
    cout << "Inserisci nome e cognome" << endl;
    do
    {
        cin >> nome;
        cin >> cognome;
    } while (nome == "" || cognome == "");
}

void Persona::stampa()
{
    cout << "Nome: " << nome << endl << "Cognome: " << cognome << endl;
}