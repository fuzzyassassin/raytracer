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

GLfloat Sphere::rayIntersection(const Ray& r) const {
    Vector originDiff = r.Position() - center;
    
    // Becomes quadratic
    // Wiki point-line intersection
//    GLfloat a = r.Direction().dot(r.Direction());
    GLfloat b = r.Direction().dot(originDiff);
    GLfloat c = originDiff.dot(originDiff) - radius * radius;
    
    GLfloat discrim = b * b - c;
    GLfloat result;
    
    if (discrim < 0.0 + epsilon) {
        result = -1.0;
    }
    else if (std::abs(discrim) < epsilon) {
        result = -b;
    }
    else {
        GLfloat sqrtDiscrim = std::sqrt(discrim);
        // Lowest of the two that is greater than 0
        result = std::fmin(std::fmax(-b + sqrtDiscrim, 0), std::fmax(-b - sqrtDiscrim, 0));
    }
    
    if (result < 0) {
        return -1.0;
    }
    
    return result;
}

Vector Sphere::findNormalAtPoint(const Vector& v) const {
    GLfloat x = (v.x() - center.x()) / radius;
    GLfloat y = (v.y() - center.y()) / radius;
    GLfloat z = (v.z() - center.z()) / radius;
    return Vector(x, y, z);
}
