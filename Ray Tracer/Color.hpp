//
//  Color.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>
#include "Common.h"

#define RED 0    /* offset to red byte */
#define GREEN 1    /* offset to green byte */
#define BLUE 2    /* offset to blue byte */

class Color {
    
public:
    Color();
    Color(GLint r, GLint g, GLint b, GLint a);
    
    GLint R();
    GLint G();
    GLint B();
    GLint A();
    
    void Clamp();
    
    Color operator+(const Color& rhs) const;
    Color operator-(const Color& rhs) const;
    Color operator*(const Color& rhs) const; // Constant multiplication k*v
    Color operator*(GLdouble k) const;
    Color& operator+=(const Color& rhs);
    Color& operator-=(const Color& rhs);
    Color& operator*=(const Color& rhs);
    Color& operator*=(GLdouble k);
    
private:
    GLint _components[4];
};

#endif /* Color_hpp */
