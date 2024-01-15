#include "Carta.h"
/*COSTRUTTORI*/
Carta::Carta() {
    seme = "Undefined";
    nome = "Undefined";
    numero = -1;
    punteggio = -1;
}
Carta::Carta(string s, string nom, int num, int p) {
    seme = s;
    if (seme != "bastoni" && seme != "denari" && seme != "spade" && seme != "coppe") {
        seme = "Undefined";
    }
    nome = nom;
    if (nome != "Asso" && nome != "Fante" && nome != "Cavallo" && nome != "Re" && (nome < "2" || nome > "7")) {
        nome = "Undefined";
    }
    numero = num; 
    if (numero < 1 || numero > 10) {
        numero = -1;
    }
    punteggio = p;
    if (punteggio != 11 && punteggio != 10 && (punteggio < 2 || punteggio > 4) && punteggio != 0) {
        punteggio = -1;
    }
}
/*DISTRUTTORI*/
Carta::~Carta() {

}
/*SETTER*/
void Carta::setSeme(string s) {
    seme = s;
    if (seme != "bastoni" && seme != "denari" && seme != "spade" && seme != "coppe") {
        seme = "Undefined";
    }
}
void Carta::setNome(string n) {
    nome = n;
    if (nome != "Asso" && nome != "Fante" && nome != "Cavallo" && nome != "Re") {
        nome = "Undefined";
    }
}
void Carta::setNumero(int n) {
    numero = n; 
    if (numero < 1 || numero > 10) {
        numero = -1;
    }
}
void Carta::setPunteggio(int p) {
    punteggio = p;
    if (punteggio != 11 && punteggio != 10 && (punteggio < 2 || punteggio > 4) && punteggio != 0) {
        punteggio = -1;
    }
}
void Carta::setCarta(string s, string nom, int num, int p) {
    seme = s;
    if (seme != "bastoni" && seme != "denari" && seme != "spade" && seme != "coppe") {
        seme = "Undefined";
    }
    nome = nom;
    if (nome != "Asso" && nome != "Fante" && nome != "Cavallo" && nome != "Re" && (nome < "2" || nome > "7")) {
        nome = "Undefined";
    }
    numero = num; 
    if (numero < 1 || numero > 10) {
        numero = -1;
    }
    punteggio = p;
    if (punteggio != 11 && punteggio != 10 && (punteggio < 2 || punteggio > 4) && punteggio != 0) {
        punteggio = -1;
    }
}
/*CONFRONTA*/
int Carta::confronta(Carta c2, Carta briscola) {
    if (seme == c2.seme) {
        if (punteggio == c2.punteggio) {
            if (numero > c2.numero) {
                return 1;
            } else {
                return 2;
            }
        } else if (punteggio > c2.punteggio) {
            return 1;
        } else {

            return 2;
        }
    } else {
        if (seme == briscola.seme) {
            return 1;
        } else if (c2.seme == briscola.seme) {
            return 2;
        }
        return 1;
    }
}
/*OVERLOADING*/
int Carta::operator+(Carta c2) {
    return numero + c2.numero;
}
istream &operator>>(istream &in, Carta c1) {
    cout << "Inserisci il seme: ";
    do {
        in >> c1.seme;
    } while (c1.seme != "bastoni" && c1.seme != "denari" && c1.seme != "spade" && c1.seme != "coppe");
    return in;
}
ostream &operator<<(ostream &out, Carta c1) {
    out << "Seme: " << c1.seme << endl;
    out << "Nome: " << c1.nome << endl;
    out << "Numero: " << c1.numero << endl;
    out << "Punteggio: " << c1.punteggio << endl;
    return out;
}