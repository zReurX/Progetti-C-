#ifndef DATA_H
#define DATA_H

class Data {
    private:
        int giorno, mese, anno;
    public:
        /*construttori*/
        Data();
        Data(int g, int m, int a);
        ~Data();
        bool validaData();
        /*set*/
        void setGiorno(int g);
        void setMese(int m);
        void setAnno(int a);
        void setData(int g, int m, int a);
        /*get*/
        int getGiorno();
        int getMese();
        int getAnno();
        /*print*/
        void printData();
        /*Read*/
        void readData();
        /*Confronto Date*/
        friend int confrontoDate(Data d1, Data d2);
};

#endif
