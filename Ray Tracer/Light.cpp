//
//  Light.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#include <cassert>
#include <cmath>
#include "Common.h"
#include "Light.hpp"
#include "Shape.hpp"
#include "Ray.hpp"

Light::Light() {
    _position = Vector(0, 0, 100);
    _ambient = Color(255, 0, 0, 1);
    _diffuse = Color(0, 255, 0, 1);
    _specular = Color(0, 0, 255, 1);
}

Light::Light(Vector position, Color ambient, Color diffuse, Color specular) {
    _position = position;
    _ambient = ambient;
    _diffuse = diffuse;
    _specular = specular;
}

Vector Light::Position() const {
    return _position;
}
Color Light::Ambient() const {
    return _ambient;
}
Color Light::Diffuse() const {
    return _diffuse;
}
Color Light::Specular() const {
    return _specular;
}

Color Light::CalculateAmbient(const Material& mat) const {
    Color color = _ambient * mat.Ambient();
    
//    return Color(0, 0, 0, 1);
    return color;
}

Color Light::CalculateDiffuse(const Material& mat, const Vector& normal, const Vector& toLight) const {
    Vector normalNormd = normal.NormalizedVector();
    Vector toLightNormd = -toLight.NormalizedVector();
    
    Color diffuse = _diffuse * mat.Diffuse() *  normalNormd.Dot(toLightNormd);
    
//    return Color(0, 0, 0, 1);
    return diffuse;
}

Color Light::CalculateSpecular(const Material& mat, const Vector& normal, const Vector& toLight, const Vector& toViewer) const {
    Vector halfway = -(toLight + toViewer).NormalizedVector();
    
    Color specular = _specular * mat.Specular() * pow(normal.NormalizedVector().Dot(halfway), 3.0f);
    
//    return Color(0, 0, 0, 1);
    return specular;
}

Color Light::Illuminate(const Shape* shape, const Vector& toViewer, const Vector& intersection) const {
    Vector toLightDistance = _position - intersection;
    Vector toLight = toLightDistance.NormalizedVector();
    
    Vector normal = shape->FindNormalAtPoint(intersection);

    Color color = CalculateDiffuse(shape->Mat(), normal, toLight) +
                  CalculateSpecular(shape->Mat(), normal, toLight, toViewer);
    
    return color;
}
