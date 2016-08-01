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
    virtual GLdouble RayIntersection(const Ray& r) const = 0;
    
    virtual Vector FindNormalAtPoint(const Vector& v) const = 0;
    
    virtual Material Mat() const {
        return _material;
    }
    
protected:
    GLdouble _epsilon = 0.004f;
    Material _material;
};

#endif /* Shape_hpp */
