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
    
    void SetX(GLdouble x);
    void SetY(GLdouble y);
    void SetZ(GLdouble z);
    GLdouble X() const;
    GLdouble Y() const;
    GLdouble Z() const;
    GLdouble Length() const;
    
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
    
    void Normalize();
    Vector NormalizedVector() const;
    Vector ProjectionOnto(const Vector& v1) const;
    Vector Cross(const Vector& v1) const;
    GLdouble Dot(const Vector& v1) const;
    Vector ReflectedAcross(const Vector& axis) const;
    
private:
    GLdouble _components[3];
    GLdouble _magnitude;
    
    void RecalculateLength();
};

Vector CalculateReflectedVector(const Vector& original, const Vector& axis);

#endif /* Vector_hpp */
