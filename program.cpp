#include "Vector.h"
#include <iostream>
#include <cmath>

template <typename T>
Vector<T> proj(const Vector<T>& a, const Vector<T>& b){
    return b * ((a * b) / (b * b)); // TODO: fix how this only works one way round
}

template <typename T>
Vector<Vector<T>> gramSchmidt(const Vector<Vector<T>>& vectors){
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

        if (normal < 1e-10) {
            // vector is linearly dependent
            continue;
        }

        for(int i = 0; i < u.dim(); i++){
            u[i] /= normal;
        }

        result[i] = u;
    }

    return result;
}

int main() {
    int dim;
    std::cout << "Enter vector dimension: ";
    std::cin >> dim;

    Vector<Vector<double>> sequence;

    while (true) {
        Vector<double> v(dim);

        std::cout << "\nEnter " << dim << " components:\n";
        for (int i = 0; i < dim; i++) {
            std::cin >> v[i];
        }

        sequence.push_back(v);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string again;
        std::cout << "Add another vector? (Y/n): ";
        std::getline(std::cin, again);

        if (!again.empty() && (again[0] == 'n' || again[0] == 'N'))
            break;
    }

    if (sequence.dim() == 0) {
        std::cout << "No vectors entered.\n";
        return 0;
    }

    auto result = gramSchmidt(sequence);

    std::cout << "\nOrthonormal basis:\n";
    for (int i = 0; i < result.dim(); i++) {
        std::cout << "u" << i + 1 << " = " << result[i].toString() << '\n';
    }

    return 0;
}