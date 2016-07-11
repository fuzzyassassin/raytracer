//
//  Vector.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/5/16.
//
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Common.h"

class Vector {

public:
    Vector();
    Vector(GLfloat x, GLfloat y, GLfloat z);
    Vector(const Vector &v);
    
    GLfloat x() const;
    GLfloat y() const;
    GLfloat z() const;
    
    GLfloat length();
    void normalize();
    
    void setX(GLfloat x);
    void setY(GLfloat y);
    void setZ(GLfloat z);
    
    bool operator==(const Vector& rhs);
    bool operator!=(const Vector& rhs);
    
    const Vector operator+() const; // Unary +
    Vector operator-() const; // Unary -
    Vector operator+(const Vector& rhs);
    Vector operator-(const Vector& rhs);
    Vector operator*(GLfloat k); // Constant multiplication k*v
    Vector operator/(GLfloat k); // Constant division v/k
    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector& operator*=(const GLfloat& v);
    Vector& operator/=(const GLfloat& v);
    
    Vector normalizedVector();
    Vector cross(const Vector& v1);
    GLfloat dot(const Vector& v1);
    
private:
    GLfloat components[3];
};

#endif /* Vector_hpp */
