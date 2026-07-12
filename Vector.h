#include <string>
#pragma once

template <typename T>
class Vector{
    public:

    // ==================================================

    Vector();
    Vector(int s); // TODO: add list intialisation 
    ~Vector();
    
    Vector(const Vector<T>& a); // copy constructor
    Vector<T>& operator=(const Vector<T>& a); // copy assignment

    Vector(Vector<T>&& a); // move constructor
    Vector<T>& operator=(Vector<T>&& a); // move assignment

    // ==================================================

    T& operator[](int i);
    const T& operator[](int i) const;

    Vector<T> operator+(const Vector<T>& b);
    Vector<T> operator-(const Vector<T>& b);
    double operator*(const Vector<T>& b); // dot product
    Vector<T> operator*(const double& b); // scalar multiplication

    double operator*(const Vector<T>& b) const; // dot product
    Vector<T> operator*(const double& b) const; // scalar multiplication
    
    Vector<T>& operator+=(const Vector<T>& b);
    Vector<T>& operator-=(const Vector<T>& b);
    Vector<T>& operator*=(const double& b);

    int dim() const;
    std::string toString();
    void push_back(const T& a);

    private:
 
    int size;
    T* elem;
};

#include "Vector.cpp"