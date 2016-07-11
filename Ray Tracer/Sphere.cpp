//
//  Sphere.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/12/16.
//
//

#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(Vector center, GLfloat radius) {
    this->center = center;
    this->radius = radius;
    this->material = Material();
}

bool Sphere::rayIntersection(const Ray& r) {
    Vector originDiff = r.Position() - center;
    
    // Becomes quadratic
    // Wiki point-line intersection
    GLfloat a = r.Direction().dot(r.Direction());
    GLfloat b = r.Direction().dot(originDiff);
    GLfloat c = originDiff.dot(originDiff) - radius * radius;
    
    GLfloat discrim = b * b - c;
    
    if (discrim < 0.0 + epsilon) {
        return -1.0;
    }
    else if (std::abs(discrim) < epsilon) {
        return -b;
    }
    else {
        GLfloat sqrtDiscrim = std::sqrt(discrim);
        return std::fmin(-b + sqrtDiscrim, -b - sqrtDiscrim);
    }
}

Vector Sphere::findNormalAtPoint(const Vector& v) {
    GLfloat x = (v.x() - center.x()) / radius;
    GLfloat y = (v.y() - center.y()) / radius;
    GLfloat z = (v.z() - center.z()) / radius;
    return Vector(x, y, z);
}
