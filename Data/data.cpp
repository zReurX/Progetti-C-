#include "data.h"
#include <iostream>
using namespace std;

Data::Data() {
    giorno = 15;
    mese = 10;
    anno = 1582;
}
Data::Data(int g, int m, int a) {
    giorno = g;
    mese = m;
    anno = a;
    if (validaData()) {
        giorno = 15;
        mese = 10;
        anno = 1582;
    }
}
Data::~Data() {

}
/*valida data*/
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

    return flag;
}

/*set*/
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
    if (validaData()) {
        giorno = 15;
        mese = 10;
        anno = 1582;
    }
}
/*get*/
int Data::getGiorno() {
    return giorno;
}
int Data::getMese() {
    return mese;
}
int Data::getAnno() {
    return anno;
}
/*print*/
void Data::printData() {
    cout << giorno << "/" << mese << "/" << anno << endl;
}
/*Read*/
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

/*Confronto Date*/
int confrontoDate(Data d1, Data d2) {
    int flag = 0;
    if (d1.anno != d2.anno) {
        if (d1.anno > d2.anno) {
            flag = 1;
        } else {
            flag = 2;
        }
    }

    if (d1.mese != d2.mese) {
        if (d1.mese > d2.mese) {
            flag = 1;
        } else {
            flag = 2;
        }
    }

    if (d1.giorno != d2.giorno) {
        if (d1.giorno > d2.giorno) {
            flag = 1;
        } else {
            flag = 2;
        }
    }

    // le date sono uguali
    return flag;
}