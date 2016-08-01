//
//  Vector.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/5/16.
//
//

#ifndef Vector_hpp
#define Vector_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Common.h"

class Vector {

public:
    Vector();
    Vector(GLdouble x, GLdouble y, GLdouble z);
    Vector(const Vector &v);
    
    GLdouble x() const;
    GLdouble y() const;
    GLdouble z() const;
    
    GLdouble length() const;
    void normalize();
    
    void setX(GLdouble x);
    void setY(GLdouble y);
    void setZ(GLdouble z);
    
    bool operator==(const Vector& rhs) const;
    bool operator!=(const Vector& rhs) const;
    
    const Vector operator+() const; // Unary +
    Vector operator-() const; // Unary -
    Vector operator+(const Vector& rhs) const;
    Vector operator-(const Vector& rhs) const;
    Vector operator*(GLdouble k) const; // Constant multiplication k*v
    Vector operator/(GLdouble k) const; // Constant division v/k
    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector& operator*=(const GLdouble& v);
    Vector& operator/=(const GLdouble& v);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    
    Vector normalizedVector() const;
    Vector projectionOnto(const Vector& v1) const;
    Vector cross(const Vector& v1) const;
    GLdouble dot(const Vector& v1) const;
    Vector ReflectedAcross(const Vector& axis) const;
    
private:
    GLdouble components[3];
    GLdouble magnitude;
    
    void recalculateLength();
};

Vector CalculateReflectedVector(const Vector& original, const Vector& axis);

#endif /* Vector_hpp */
