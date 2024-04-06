#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class Data {
    private:
        int giorno, mese, anno;
    public:
        /*CONSTRUTTORI*/
        Data();
        Data(int g, int m, int a);
        Data(Data& d);
        /*DISTRUTTORE*/
        ~Data();
        /*VALIDA DATA*/
        bool validaData();
        /*SET*/
        void setGiorno(int g);
        void setMese(int m);
        void setAnno(int a);
        void setData(int g, int m, int a);
        /*GET*/
        int getGiorno();
        int getMese();
        int getAnno();
        /*PRINT*/
        void printData();
        friend ostream& operator<<(ostream& out, const Data& d);
        /*READ*/
        void readData();
        friend istream& operator>>(istream& in, Data& d);
        /*CONFRONTO DATE*/
        friend int confrontoDate(const Data& d1, const Data& d2);
        // bool operator==(const Data& d);
        bool operator>(const Data& d);
        // bool operator>=(const Data& d);
        // bool operator<(const Data& d);
        // bool operator<=(const Data& d);
        bool operator!=(const Data& d);
        /*TODAY*/
        void today();
        /*HOW DAYS*/
        /*GIORNI DALL'INIZIO*/
        int giorniDallInizio();
        friend int howDays(Data& d1, Data& d2);
};

#endif
