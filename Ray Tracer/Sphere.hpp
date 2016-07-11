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
    Sphere(Vector center, GLfloat radius);
    Sphere(Vector center, GLfloat radius, Material mat);
    
    bool rayIntersection(const Ray& r);
    Vector findNormalAtPoint(const Vector& v);
    
private:
    Vector center;
    GLfloat radius;
    Material material;
};

#endif /* Sphere_hpp */
