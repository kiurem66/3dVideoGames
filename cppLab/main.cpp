#include <assert.h>


// with the following line, we are defining "Scalar" to be a synonym of basic type float
typedef float Scalar;

// a class for vectors
class Vector {
public:
    Scalar x, y, z; // the Cartesian coords

    /* constructors */
    Vector(): x(0), y(0), z(0){}
    Vector(Scalar a, Scalar b, Scalar c): x(a), y(b), z(c) {}

    Vector operator*(Scalar k) const{
        return Vector(x*k, y*k, z*k);
    }

    // another way to write down the vector sum
    Vector operator+(const Vector &other) const{
        return Vector(x+other.x, y+other.y, z+other.z);
    }

    Vector operator-(const Vector &other) const {
        return Vector(x-other.x, y-other.y, z-other.z);
    }

    Vector operator-() const{
        return Vector(-x,-y,-z);
    }
};

/* global functions on vectors and scalars */

Scalar dot(const Vector &a, const Vector &b) const {
    return (a.x*b.x) + (a.y*b.y) + (a.z*b.z);
}

Vector cross(const Vector &a, const Vector $b) const{
    Scalar x = a.y + b.z - (a.z + b.y);
    Scalar y = a.z + b.x - (a.x + b.z);
    Scalar z = a.x + b.y - (a.y + b.x);
    return Vector(x, y, z);
}

bool isEqual(Scalar v1, Scalar v2) {
    return (v1-v2)*(v1-v2) < 0.001;
}/* global functions on vectors and scalars */

bool isEqual(Vector v1, Vector v2) {
    return isEqual(v1.x, v2.x) && isEqual(v1.y, v2.y) && isEqual(v1.z, v2.z);
}

Vector operator*(Scalar k, Vector v){
    return v*k;
}

Vector bounce(Vector v, Vector normal){
    return v - (2 * dot(n,v)) * n;
}

void unitTestSum() {
    /* this test that vector-sum is indeed commutative (sanity check) */
    Vector a(5,-6,9.5), b(2,3,5);
    assert(isEqual( a+b , b+a ));
}

int main()
{
    // just some examples of usage of class Vectors
    Vector v, w(2,3,5);
    v.x = 2;
    v = v.sum(w);
    v = v.operator+(w);
    v = v + w;
    Scalar k = v.dot(v);


    unitTestSum();
    return 0;
}
