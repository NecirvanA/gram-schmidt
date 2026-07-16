#include "Vector.h"

template <typename T>
Vector<T>::Vector() : size{0}, elem{nullptr} {}

template <typename T>
Vector<T>::Vector(int s) : size{s}, elem{new T[s]()} {}

template <typename T>
Vector<T>::~Vector(){
    delete[] elem;
    elem = nullptr;
}

template <typename T>
Vector<T>::Vector(const Vector& a): size{a.size}, elem{new T[a.size]}{
    for(auto i = 0; i < size; i++){
        elem[i] = a.elem[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& a){
    T *p = new T[a.size];
    for(auto i = 0; i < a.size; i++){
        p[i] = a.elem[i];
    }

    delete[] elem;
    elem = p;
    size = a.size;
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector&& a): elem{a.elem}, size{a.size}{
    a.elem = nullptr;
    a.size = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& a){
    T* old = elem;

    elem = a.elem;
    size = a.size;

    a.elem = nullptr;
    a.size = 0;

    delete[] old;
    
    return *this;
}

template <typename T>
T& Vector<T>::operator[](int i){ // TODO: throw errors
    return *(elem + i);
}

template <typename T>
const T& Vector<T>::operator[](int i) const{
    return *(elem + i);
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector& b){
    // TODO: throw error if dimensions are wrong

    Vector<T> result(size);

    for(auto i = 0; i < size; i++){
        result[i] = (*this)[i] + b[i];
    }

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector& b){
    Vector<T> result(size);

    for(auto i = 0; i < size; i++){
        result[i] = (*this)[i] - b[i];
    }

    return result;
}

template <typename T>
double Vector<T>::operator*(const Vector<T>& b) const{
    T result {};

    for(auto i = 0; i < size; i++){
        result += (*this)[i] * b[i];
    }

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const double& b) const{ // TODO: fix the assumption that * works.
    Vector<T> result(size);

    for(auto i = 0; i < size; i++){
        result[i] = (*this)[i] * b;
    }

    return result;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& b){
    for(auto i = 0; i < size; i++){
        (*this)[i] += b[i];
    }

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& b){
    for(auto i = 0; i < size; i++){
        (*this)[i] -= b[i];
    }

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator*=(const double& b){
    for(auto i = 0; i < size; i++){
        (*this)[i] *= b;
    }

    return *this;
}

template <typename T>
int Vector<T>::dim() const{
    return size;
}

template <typename T>
void Vector<T>::push_back(const T& a){
    int new_size = size + 1;
    Vector<T> new_vector(new_size);

    for(int i = 0; i < size; i++){
        new_vector[i] = elem[i];
    }

    new_vector[size] = a;

    *this = std::move(new_vector);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v){
    os << '[';
    for(int i = 0; i < v.dim(); i++){
        os << v[i];
        if(i != v.dim() - 1) os << ", ";
    }
    os << ']';
    return os;
}
