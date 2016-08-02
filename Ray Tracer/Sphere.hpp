//
//  Sphere.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/12/16.
//
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>
#include "Ray.hpp"
#include "Shape.hpp"
#include "Vector.hpp"
#include "Material.hpp"

class Sphere: public Shape {
    
public:
    Sphere(Vector center, GLdouble radius);
    Sphere(Vector center, GLdouble radius, Material mat);
    
    GLdouble RayIntersection(const Ray& r) const override;
    Vector FindNormalAtPoint(const Vector& v) const override;
    Vector FindNormalForIntersectingRay(const Ray& r) const override;
    
private:
    Vector _center;
    GLdouble _radius;
};

#endif /* Sphere_hpp */
