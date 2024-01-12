#include <iostream>
using namespace std;

class Figura {
    public:
        Figura(){};
        virtual ~Figura(){};
        virtual void stampa() = 0;
};

class Poligono : public Figura {
    protected:
        int nLati;
    public:
        Poligono(){};
        ~Poligono(){};
        void setNumeroLati(int n) {
            nLati = n;
        }
        void stampa() = 0;
};

class Quadrato : public Poligono {
    private:
        float lato;
    public:
        Quadrato() {
            nLati = 4;
            lato = 2;
        };
        ~Quadrato(){};
        void stampa() {
            cout << "Misura lato: " << lato << endl;
        };
};

class Triangolo : public Poligono {
    protected:
        float l1, l2, l3;
    public:
        Triangolo(){
            nLati = 3;
            l1 = 2;
            l2 = 4;
            l3 = 5;
        };
        ~Triangolo(){};
        void stampa() {
            cout << "Misure lati: " << l1 << ", " << l2 << ", " << l3 << endl;
        };
};

class TriangoloEquilatero : public Triangolo {
    public:
        TriangoloEquilatero(){
            nLati = 3;
            l1 = l2 = l3 = 2;
        };
        ~TriangoloEquilatero(){};
};

int main() {
    Figura *a, *b, *c;
    a = new Quadrato();
    b = new Triangolo();
    c = new TriangoloEquilatero();
    a->stampa();
    b->stampa();
    c->stampa();
    return 0;
}