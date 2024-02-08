#include "List.h"

int main() {
    List l1;
    // l1.insertHead(5);
    l1.insertTail(10);
    l1.insertTail(5);
    List l2(l1);
    l2.displayHelper();
    return 0;
}