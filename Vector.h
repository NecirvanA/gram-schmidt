#include <string>

class Vector{
    public:

    // ==================================================

    Vector(int s); // TODO: add list intialisation 
    ~Vector();
    
    Vector(const Vector& a); // copy constructor
    Vector& operator=(const Vector& a); // copy assignment

    Vector(Vector&& a); // move constructor
    Vector& operator=(Vector&& a); // move assignment

    // ==================================================

    double& operator[](int i);
    const double& operator[](int i) const;

    Vector operator+(const Vector& b);
    Vector operator-(const Vector& b);
    double operator*(const Vector& b); // dot product
    Vector operator*(const double& b); // scalar multiplication
    
    Vector& operator+=(const Vector b);
    Vector& operator-=(const Vector b);
    Vector& operator*=(const double b);

    int dim();
    std::string toString();

    private:
 
    int size;
    double* elem;
};