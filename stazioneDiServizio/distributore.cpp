#include "distributore.h"

/*COSTRUTTORI*/
Distributore::Distributore()
{
    typeCarb = "";
    prezzo = 0;
    litri = 0;
    maxLitri = 0;
}
Distributore::Distributore(string tC, double p, double l, double mL)
{
    typeCarb = tC;
    prezzo = p;
    litri = l;
    maxLitri = mL;
    if (prezzo <= 0)
    {
        prezzo = 0;
    }
    if (litri <= 0)
    {
        litri = 0;
    }
    if (maxLitri <= 0 || maxLitri < litri)
    {
        maxLitri = litri;
    }
}
/*DISTRUTTORI*/
Distributore::~Distributore()
{
}
/*GET*/
string Distributore::getType()
{
    return typeCarb;
}
double Distributore::getPrezzo()
{
    return prezzo;
}
double Distributore::getLitri()
{
    return litri;
}
double Distributore::getMaxLitri()
{
    return maxLitri;
}
/*SET*/
void Distributore::setType(string tC)
{
    typeCarb = tC;
}
void Distributore::setPrezzo(double p)
{
    prezzo = p;
    if (prezzo <= 0)
    {
        prezzo = 0;
    }
}
void Distributore::setLitri(double l)
{
    litri = l;
    if (litri <= 0)
    {
        litri = 0;
    }
}
void Distributore::setMaxLitri(double mL)
{
    maxLitri = mL;
    if (maxLitri <= 0 || maxLitri < litri)
    {
        maxLitri = litri;
    }
}
void Distributore::steDistributore(string tC, double p, double l, double mL)
{
    typeCarb = tC;
    prezzo = p;
    litri = l;
    maxLitri = mL;
    if (prezzo <= 0)
    {
        prezzo = 0;
    }
    if (litri <= 0)
    {
        litri = 0;
    }
    if (maxLitri <= 0 || maxLitri < litri)
    {
        maxLitri = litri;
    }
}
/*PRINT*/
void Distributore::print()
{
    cout << "TIPO DI CARBURANTE: " << typeCarb << endl;
    cout << "PREZZO DEL CARBURANTE: " << prezzo << endl;
    cout << "LITRI DI CARBURANTE: " << litri << endl;
    cout << "CAPACITA MASSIMA DI CARBURANTE: " << maxLitri << endl;
}
/*READ*/
void Distributore::read()
{
    cout << "INSERISCI IL TIPO DI CARBURANTE: ";
    cin >> typeCarb;

    cout << "INSERISCI IL PREZZO: ";
    do {
        cin >> prezzo;
    } while (prezzo <= 0);

    cout << "INSERISCI I LITRI: ";
    do {
        cin >> litri;
    } while (litri <= 0);

    cout << "INSERISCI LA CAPIENZA DEL DISTRIBUTORE: ";
    do {
        cin >> maxLitri;
    } while (maxLitri <  litri);
}
/*OVERLOADING MENO*/
Distributore Distributore::operator-(double euro)
{
    double litriComprati = euro / prezzo;
    if (litri - litriComprati >= 0 ) {
        litri -= litriComprati;
        cout << "LITRI TOT COMPRATI: " << litriComprati << " A " << euro << "$" << endl;
    } else {
        cout << "CARBURANTE INSUFICIENTE. LE VERRANO RIMBORSATI: " << abs((litri - litriComprati) * prezzo) << "$" << endl;
        litri = 0;
    }
    return *this;
}