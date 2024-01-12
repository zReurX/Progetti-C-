#include <iostream>
#include <cmath>
using namespace std;

class Solido
{
protected:
    float peso;
public:
    Solido(){};
    virtual ~Solido(){};
    virtual float superficieSolido() = 0;
    virtual float Volume() = 0;
    virtual float calcolaPeso() {
        return peso * Volume();
    };
};

class Cubo : public Solido {
    private:
        float lato;
    public:
        Cubo(){
            lato = 4;
        };
        ~Cubo(){};
        float superficieSolido() {
            return 6 * pow(lato, 2);
        }
        float Volume() {
            return pow(lato, 3);
        }
};

class Sfera : public Solido {
    private:
        float raggio;
    public:
        Sfera(){
            raggio = 2;
        };
        ~Sfera(){};
        float superficieSolido() {
            return 4 * M_PI * pow(raggio, 2);
        }
};

int main()
{
    Solido *a, *b;
    a = new Cubo();
    b = new Cubo();
    cout << a->calcolaPeso() << a->superficieSolido() << a->Volume() << endl;
    cout << b->calcolaPeso() << b->superficieSolido() << b->Volume() << endl;
    return 0;
}