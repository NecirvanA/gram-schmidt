#include "Vector.h"
#include <iostream>

int main(){
    Vector a(3);
    Vector b(3);

    a[0] = 0; a[1] = 1; a[2] = 2;
    b[0] = 2; b[1] = 1; b[2] = 0;

    std::cout << (a * 4).toString();

    return 0;
}