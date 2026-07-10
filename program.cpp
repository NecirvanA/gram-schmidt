#include "Vector.h"
#include <iostream>

int main(){
    Vector<int> a(3);
    Vector<int> b(3);

    a[0] = 0; a[1] = 1; a[2] = 2;
    b[0] = 2; b[1] = 1; b[2] = 0;

    std::cout << (a * 4).toString();
    std::cout << (a + b).toString();

    return 0;
}