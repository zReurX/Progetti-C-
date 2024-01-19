#include "Veicolo.h"

class Bicicletta : public Veicolo
{
private:
    bool sporco;
    string suono;
public:
    Bicicletta();
    Bicicletta(bool sporco, float p, int v, string c);
    Bicicletta(Bicicletta& b);
    ~Bicicletta();
    void read();
    void print();
    void suona();
    void frena();
    void pedala();
    friend ostream& operator<<(ostream& out, Bicicletta& b);
    friend istream& operator>>(istream& in, Bicicletta& b);
};
