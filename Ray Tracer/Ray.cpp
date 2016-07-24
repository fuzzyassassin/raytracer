//
//  Ray.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/7/16.
//
//

#include "Ray.hpp"
#include "Vector.hpp"

Ray::Ray(Vector position, Vector direction) {
    this->position = position;
    this->direction = direction.normalizedVector();
}

Vector Ray::Position() const {
    return position;
}

Vector Ray::Direction() const {
    return direction;
}

Vector Ray::FindPoint(GLfloat t) const {
    return position + (direction * t);
}

// Unfinished work for Ray intersection calculation

//Vector Ray::IntersectionPoint(const Ray& r1) {
//    I
//}
//
//
//
//GLfloat MinimumDistance(const Ray& r1, const Ray& r2) {
//    Vector v1 = r1.Direction();
//    Vector v2 = r2.Direction();
//    GLfloat dot = v1.dot(v2);
//    GLfloat dotSquared = dot * dot;
//    
//    // Lines are parallel
//    if (dotSquared == 1) {
//        return -1;
//    }
//    
//    Vector originDiff = r2.Position() - r1.Position();
//    
//    GLfloat t1 = dot * originDiff.dot(v2) - originDiff.dot(v1);
//    GLfloat t2 = originDiff.dot(v2) - dotSquared * originDiff.dot(v1);
//    
//    Vector point1 = r1.FindPoint(t1);
//    Vector point2 = r2.FindPoint(t2);
//    
//    GLfloat minimumDistance = (point1 - point2).length();
//    
//    return minimumDistance;
//}
//
//Ray CalculatReflectedRay(