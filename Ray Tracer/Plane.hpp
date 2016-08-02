//
//  Plane.hpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 7/31/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>
#include "Ray.hpp"
#include "Shape.hpp"
#include "Vector.hpp"
#include "Material.hpp"

class Plane: public Shape {

public:
    Plane();
    Plane(Vector position, Vector normal);
    Plane(Vector position, Vector normal, Material mat);
    
    GLdouble RayIntersection(const Ray& r) const override;
    Vector FindNormalAtPoint(const Vector& v) const override;
    Vector FindNormalForIntersectingRay(const Ray& r) const override;
    
private:
    Vector _normal;
    Vector _position;
};

#endif /* Plane_hpp */
