//
//  Ray.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/7/16.
//
//

#include "Ray.hpp"

Ray::Ray(Vector position, Vector direction) {
    this->position = position;
    this->direction = direction.normalizedVector();
}

Vector Ray::FindPoint(GLfloat t) {
    return position + (direction * t);
}
