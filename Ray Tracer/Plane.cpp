//
//  Plane.cpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 7/31/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#include "Plane.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include <cmath>

Plane::Plane() {
    _position = Vector(0, 0, 0);
    _normal = Vector(0, 1, 0);
    _material = Material();
}
Plane::Plane(Vector position, Vector normal) {
    _position = position;
    _normal = normal.NormalizedVector();
    _material = Material();
}
Plane::Plane(Vector position, Vector normal, Material mat) {
    _position = position;
    _normal = normal.NormalizedVector();
    _material = mat;
}

GLdouble Plane::RayIntersection(const Ray& r) const {
    GLdouble denom = r.Direction().Dot(_normal);
    GLdouble numer = (_position - r.Position()).Dot(_normal);
    
    GLdouble result = -1.0;
    
    // Parallel
    if (std::abs(denom) < _epsilon) {
        // Line is in the plane
        if (std::abs(numer) < _epsilon) {
            result = 0.0;
        }
        // Line never intersects
        else {
            result = -1.0;
        }
    }
    else {
        result = numer/denom;
    }
    return result;
}
Vector Plane::FindNormalAtPoint(const Vector& v) const {
    // Does not take into account above/below
//    Vector toPoint = v - _position;
//    if (_normal.Dot(toPoint) != 0.0) {
//        // FAIL
//    }
    
    return _normal;
}
