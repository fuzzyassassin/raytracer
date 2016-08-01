//
//  Sphere.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/12/16.
//
//

#include "Sphere.hpp"
#include "Vector.hpp"
#include <cmath>

Sphere::Sphere(Vector center, GLdouble radius) {
    _center = center;
    _radius = radius;
    _material = Material();
}
Sphere::Sphere(Vector center, GLdouble radius, Material mat) {
    _center = center;
    _radius = radius;
    _material = mat;
}

GLdouble Sphere::RayIntersection(const Ray& r) const {
    Vector originDiff = r.Position() - _center;
    
    // Becomes quadratic
    // Wiki point-line intersection
//    GLdouble a = r.Direction().dot(r.Direction());
    GLdouble b = r.Direction().Dot(originDiff);
    GLdouble c = originDiff.Dot(originDiff) - (_radius * _radius);
    
    GLdouble discrim = b * b - c;
    GLdouble result = -1.0;
    
    if (discrim < 0) {
        result = -1.0;
    }
    else {
        GLdouble sqrtDiscrim = std::sqrt(discrim);
        result = -b - sqrtDiscrim;
        if (result < _epsilon) {
            result = -b + sqrtDiscrim;
        }
    }
    
    if (result < _epsilon) {
        return -1.0;
    }
    
    return result;
}

Vector Sphere::FindNormalAtPoint(const Vector& v) const {
    Vector diff = v - _center;
    return diff.NormalizedVector();
}
