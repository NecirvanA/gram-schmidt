#include "Vector.h"

Vector::Vector(int s) : size{s}, elem{new double [s]} {};

Vector::~Vector(){
    delete[] elem;
    elem = nullptr;
}

Vector::Vector(const Vector& a): elem{new double[a.size]}, size{a.size}{
    for(int i = 0; i < size; i++){
        elem[i] = a.elem[i];
    }
}

Vector& Vector::operator=(const Vector& a){
    double *p = new double[a.size];
    for(int i = 0; i < a.size; i++){
        p[i] = a.elem[i];
    }

    delete[] elem;
    elem = p;
    size = a.size;
    return *this;
}

Vector::Vector(Vector&& a): elem{a.elem}, size{a.size}{
    a.elem = nullptr;
    a.size = 0;
}

Vector& Vector::operator=(Vector&& a){
    delete[] elem;

    elem = a.elem;
    size = a.size;

    a.elem = nullptr;
    a.size = 0;

    return *this;
}

double& Vector::operator[](int i){ // TODO: throw errors
    return *(elem + i);
}

const double& Vector::operator[](int i) const{
    return *(elem + i);
}

Vector Vector::operator+(const Vector& b){
    // TODO: throw error if dimensions are wrong

    Vector result(size);

    for(int i = 0; i < size; i++){
        result[i] = (*this)[i] + b[i];
    }

    return result;
}

Vector Vector::operator-(const Vector& b){
    Vector result(size);

    for(int i = 0; i < size; i++){
        result[i] = (*this)[i] - b[i];
    }

    return result;
}

double Vector::operator*(const Vector& b){
    double result {};

    for(int i = 0; i < size; i++){
        result += (*this)[i] * b[i];
    }

    return result;
}

Vector Vector::operator*(const double& b){
    Vector result(size);

    for(int i = 0; i < size; i++){
        result[i] = (*this)[i] * b;
    }

    return result;
}

Vector& Vector::operator+=(const Vector b){
    for(int i = 0; i < size; i++){
        (*this)[i] += b[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector b){
    for(int i = 0; i < size; i++){
        (*this)[i] -= b[i];
    }

    return *this;
}

Vector& Vector::operator*=(const double b){
    for(int i = 0; i < size; i++){
        (*this)[i] *= b;
    }

    return *this;
}

int Vector::dim(){
    return size;
}

std::string Vector::toString(){
    std::string s {};
    
    s += '[';

    for(int i = 0; i < size - 1; i++){
        s += std::to_string((*this)[i]);
        s += ", ";
    }

    s += std::to_string((*this)[size - 1]);
    s += "]";

    return s;
}