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
    
    GLfloat rayIntersection(const Ray& r) const override;
    Vector findNormalAtPoint(const Vector& v) const override;
    
private:
    Vector center;
    GLfloat radius;
};

#endif /* Sphere_hpp */
