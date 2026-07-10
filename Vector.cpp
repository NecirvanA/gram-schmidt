#include "Vector.h"

template <typename T>
Vector<T>::Vector() : size{0}, elem{nullptr} {}

template <typename T>
Vector<T>::Vector(int s) : size{s}, elem{new T[s]} {}

template <typename T>
Vector<T>::~Vector(){
    delete[] elem;
    elem = nullptr;
}

template <typename T>
Vector<T>::Vector(const Vector& a): elem{new T[a.size]}, size{a.size}{
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
    delete[] elem;

    elem = a.elem;
    size = a.size;

    a.elem = nullptr;
    a.size = 0;

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
double Vector<T>::operator*(const Vector<T>& b){
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
Vector<T> Vector<T>::operator*(const double& b){ // TODO: fix the assumption that * works.
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
int Vector<T>::dim(){
    return size;
}

template <typename T>
int Vector<T>::dim() const{
    return size;
}

template <typename T>
std::string Vector<T>::toString(){
    std::string s {};
    
    s += '[';

    for(auto i = 0; i < size - 1; i++){
        s += std::to_string((*this)[i]);
        s += ", ";
    }

    s += std::to_string((*this)[size - 1]);
    s += "]";

    return s;
}