#include "data.h"
#include "time.h"
/*CONSTRUTTORI*/
Data::Data() {
    today();
}
Data::Data(int g, int m, int a) {
    setData(g, m, a);
}
Data::Data(Data& d) {
    if (d.validaData()) {
        giorno = d.giorno;
        mese = d.mese;
        anno = d.anno;
    } else {
        today();
    }
}
/*DISTRUTTORE*/
Data::~Data() {

}
/*VALIDA = TRUE 
NON VALIDA = FALSE*/
bool Data::validaData() {
    /*BIsestile vale 1 se lanno e bisestile*/
    /*Valida vale 1 se la data e accetabile*/
    int flag = true, bisestile = true, valida = true;

    /*COntrollo data*/
    if (anno < 1582 || mese < 1 || mese > 12 || giorno < 1 || giorno > 31) {
        valida = false;
    }
    /*COntrollo bisestilita*/
    if (anno % 4 != 0 || (anno % 100 == 0 && anno % 400 != 0)) {
        bisestile = false;
    }

    if (valida == false 
    || ((mese == 11 || mese == 4 || mese == 6 || mese == 9) && giorno >= 31) 
    || (mese == 2 && giorno > 29) || (bisestile == false && giorno >= 29)) {
        flag = false;
    }
    /*TRUE SE LA DATA E VALIDA*/
    return flag;
}
/*SET*/
void Data::setGiorno(int g) {
    giorno = g;
    if (giorno < 1 || giorno > 31) {
        giorno = 15;
    }
}
void Data::setMese(int m) {
    mese = m;
    if (mese < 1 || mese > 12) {
        mese = 10;
    }
}
void Data::setAnno(int a) {
    anno = a;
    if (anno < 1582) {
        anno = 1582;
    }
}
void Data::setData(int g, int m, int a) {
    giorno = g;
    mese = m;
    anno = a;
    if (!validaData()) {
        today();
    }
}
/*GET*/
int Data::getGiorno() {
    return giorno;
}
int Data::getMese() {
    return mese;
}
int Data::getAnno() {
    return anno;
}
/*PRINT*/
void Data::printData() {
    cout << giorno << "/" << mese << "/" << anno << endl;
}
ostream& operator<<(ostream& out, const Data& d) {
    const string mesi[12] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};
    out << d.giorno << " "  << mesi[d.mese - 1] << " " << d.anno << endl;
    return out;
}
/*READ*/
void Data::readData() {
    int g, m, a;
    do {
        cout << "Inserisci il giorno: " << endl; 
        cin >> g;
        cout << "Inserisci il mese: " << endl; 
        cin >> m;
        cout << "Inserisci il anno: " << endl; 
        cin >> a;
    } while (!validaData());
}
istream& operator>>(istream& in, Data& d) {
    do {
        cout << "Inserisci il giorno: " << endl; 
        in >> d.giorno;
        cout << "Inserisci il mese: " << endl; 
        in >> d.mese;
        cout << "Inserisci il anno: " << endl; 
        in >> d.anno;
    } while (!d.validaData());
    return in;
}

/*CONFRONTO DATE*/
/*0 = UGUALI, 1 = d1, 2 = d2*/
int confrontoDate(const Data& d1, const Data& d2) {
    int flag = 0;
    if (d1.anno != d2.anno) {
        if (d1.anno > d2.anno) {
            flag = 1;
        } else {
            flag = 2;
        }
    } else if (d1.mese != d2.mese) {
        if (d1.mese > d2.mese) {
            flag = 1;
        } else {
            flag = 2;
        }
    } else if (d1.giorno != d2.giorno) {
        if (d1.giorno > d2.giorno) {
            flag = 1;
        } else {
            flag = 2;
        }
    }

    // le date sono uguali
    return flag;
}
bool Data::operator>(const Data& d) {
    bool flag = true;
    if (confrontoDate(*this, d) != 1) {
        flag = false;
    }
    return flag;
}
bool Data::operator!=(const Data& d) {
    bool flag = true;
    if (confrontoDate(*this, d) != 0) {
        flag = false;
    }
    return flag;
}
/*TODAY*/
void Data::today() {
    time_t t = time(0);   // Ottiene il tempo corrente
    struct tm * now = localtime(&t);
    anno = now->tm_year + 1900;
    mese = now->tm_mon + 1;
    giorno = now->tm_mday;
}
/*HOW DAYS*/
int Data::giorniDallInizio() {
    int mesi[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Controlla se l'anno è bisestile e corregge febbraio
    if (anno % 400 == 0 || (anno % 100 != 0 && anno % 4 == 0))
        mesi[1] = 29;

    // Calcola il numero di giorni trascorsi
    int tot = anno*365 + giorno;

    for (int i=0; i<mese-1; i++)
        tot += mesi[i];

    return tot;
}
int howDays(Data& d1, Data& d2) {
    if(!d1.validaData() || !d2.validaData()) {
        std::cout << "Una o entrambe le date non sono valide." << std::endl;
        return -1;
    }
    return abs(d1.giorniDallInizio() - d2.giorniDallInizio());
}