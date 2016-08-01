//
//  Sphere.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/12/16.
//
//

#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(Vector center, GLdouble radius) {
    this->center = center;
    this->radius = radius;
    this->material = Material();
}
Sphere::Sphere(Vector center, GLdouble radius, Material mat) {
    this->center = center;
    this->radius = radius;
    this->material = mat;
}

GLdouble Sphere::rayIntersection(const Ray& r) const {
    Vector originDiff = r.Position() - center;
    
    // Becomes quadratic
    // Wiki point-line intersection
//    GLdouble a = r.Direction().dot(r.Direction());
    GLdouble b = r.Direction().dot(originDiff);
    GLdouble c = originDiff.dot(originDiff) - (radius * radius);
    
    GLdouble discrim = b * b - c;
    GLdouble result;
    
    if (discrim < 0) {
        result = -1.0;
    }
    else {
        GLdouble sqrtDiscrim = std::sqrt(discrim);
        result = -b - sqrtDiscrim;
        if (result < epsilon) {
            result = -b + sqrtDiscrim;
        }
    }
    
    if (result < epsilon) {
        return -1.0;
    }
    
    return result;
}

Vector Sphere::findNormalAtPoint(const Vector& v) const {
    Vector diff = v - center;
    return diff.normalizedVector();
}
