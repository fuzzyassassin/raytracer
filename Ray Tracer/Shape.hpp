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
#include "Ray.hpp"
#include "Material.hpp"

class Shape {    
public:
    virtual ~Shape() {};
    
    /*
     * Returns -1.0 if there's no positive t intersection
     */
    virtual GLdouble rayIntersection(const Ray& r) const = 0;
    
    virtual Vector findNormalAtPoint(const Vector& v) const = 0;
    
    virtual Material Mat() const {
        return material;
    }
    
protected:
    GLdouble epsilon = 0.004f;
    Material material;
};

#endif /* Shape_hpp */
