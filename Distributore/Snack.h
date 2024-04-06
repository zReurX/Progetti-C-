#ifndef SNACK_H
#define SNACK_H

#include <iostream>
using namespace std;

class Snack
{
private:
    string name;
    int code;
public:
    Snack(/* args */);
    ~Snack();
    void set(string n, int c);
    void setName(string n);
    void setCode(int c);
    string getName();
    int getCode();
    Snack operator=(Snack s);
    Snack operator=(int val);
    friend ostream& operator<<(ostream& out, Snack s);
    friend istream& operator>>(istream& in, Snack s);
};


#endif