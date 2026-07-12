#include "Vector.h"
#include <iostream>
#include <cmath>

template <typename T>
Vector<T> proj(const Vector<T>& a, const Vector<T>& b){
    return b * ((a * b) / (b * b)); // TODO: fix how this only works one way round
}

template <typename T>
Vector<Vector<T>> gramSchmidt(const Vector<Vector<T>>& vectors){ // TODO: normalise vectors too
    Vector<Vector<T>> result(vectors.dim());

    for(int i = 0; i < vectors.dim(); i++){
        Vector<T> u = vectors[i];

        for(int j = 0; j < i; j++){
            u = u - proj(vectors[i], result[j]);
        }

        T normal = 0;
        for(int i = 0; i < u.dim(); i++){
            normal += u[i] * u[i];
        }

        normal = sqrt(normal);

        for(int i = 0; i < u.dim(); i++){
            u[i] /= normal;
        }

        result[i] = u;
    }

    return result;
}

int main(){
    /*
    std::cout << "Enter dimension: " << std::endl;
    
    int dim {};
    std::cin >> dim;

    Vector<Vector<double>> vectors;

    while(true){
        std::cout << "Enter vectors (enter nothing to stop): " << '\n';
    }
    */

    Vector<double> a(3);
    Vector<double> b(3);
    Vector<double> c(3);

    a[0] = 1; a[1] = 1; a[2] = 0;
    b[0] = 1; b[1] = 0; b[2] = 1;
    c[0] = 0; c[1] = 1; c[2] = 1;

    Vector<Vector<double>> sequence(3);
    sequence[0] = a; sequence[1] = b; sequence[2] = c;

    Vector<Vector<double>> result = gramSchmidt(sequence);

    for(int i = 0; i < result.dim(); i++){
        std::cout << result[i].toString() << ' ';
    }

    return 0;
}