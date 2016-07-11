//
//  Shape.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/5/16.
//
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include "Vector.hpp"

class Shape {    
public:
    /*
     * Returns -1.0 if there's no intersection
     */
    virtual bool rayIntersection() = 0;
    virtual Vector findNormalAtPoint(const Vector& v) = 0;
    
protected:
    GLfloat epsilon = 0.001f;
};

#endif /* Shape_hpp */
