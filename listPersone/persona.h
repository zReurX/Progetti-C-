/*rogettare in UML e implementare la classe Persona, dipendente dalla classe Data
(opportunamente adattata), caratterizzata dai seguenti attributi: nome, cognome, data di nascita. 
Oltre ai costruttori, al distruttore e ai metodi per l'accesso in I/O agli attributi privati, realizzare i 
seguenti metodi: 
- overloading dell’operatore >> per la lettura in input dei dati di una persona, con validazione 
della data di nascita; 
- overloading dell’operatore << per la stampa in output dei dati di una persona, visualizzando la 
data di nascita nella forma estesa (20 gennaio 2003); 
- overloading dell’operatore == che confronta due persone e restituisce true se sono identiche; 
- overloading dell’operatore > che confronta due persone e restituisce quella con età maggiore; 
- overloading dell’operatore = che svolge il classico ruolo di assegnazione; 
- funzione friend che restituisce l'età di una persona.*/
#ifndef PERSONA_H
#define PERSONA_H
#include "data.h"
#include <iostream>
using namespace std;

class Persona {
    private:
        string nome, cognome;
        Data nascita;
    public:
        /*COSTRUTTORI*/
        Persona();
        Persona(string nome, string cognome, Data nascita);
        /*DISTRUTTORE*/
        ~Persona();
        /*GET*/
        string getNome();
        string getCognome();
        Data getNascita();
        /*SET*/
        void setNome(string nome);
        void setCognome(string cognome);
        void setNascita(Data nascita);
        void setPersona(string nome, string cognome, Data nascita);
        /*CONFRONTO*/
        bool operator==(const Persona& p);
        /*MAGGIORE*/
        Persona operator>(Persona& p);
        /*ASSEGNAZIONE*/
        Persona operator=(const Persona& p);
        /*READ*/
        friend istream& operator>>(istream& in, Persona& p);
        /*PRINT*/
        friend ostream& operator<<(ostream& out, const Persona& p);
        /*ETA DI UNA PERSONA*/
        friend int etaPersona(Persona& p);
};

#endif