#include "MazzodiCarte.h"

MazzodiCarte::MazzodiCarte() {
    dim = 1;
    c = new Carta[dim];
}
MazzodiCarte::~MazzodiCarte(){
    delete[] c;
}